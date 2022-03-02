#include "Game.h"

Game::Game()
    :score{0}, speed{200}, run{true} {

    do {
        system("cls");
        board = Board(20, 20);
        correr();
    } while(regame());

}


void Game::correr() {
    while (!game_over()) {
        curr_piece = Piece(Cell((board.get_width()-1)/2, board.get_height(), 'O'));
        while (!hit_built_puntos()) {
            speed = 200;
            ClearScreen();
            curr_piece.caer();
            score += board.remover_fila();
            board.refresh();
            refresh_final_puntos();
            draw();
            controles();
            Sleep(speed);

        }
    }
}

bool Game::game_over() {
    for (const auto &pnt : board.get_built_puntos())
        if (pnt.get_y() >= board.get_height() - 2) {
            return true;
        }
    return false;
}

bool Game::regame() {
    std::cout << "======Game over======" << std::endl;
    std::cout << "volver a jugar ?? (y/n) " << std::endl;
    char c{};
    bool isvalid{false};
    do {
        std::cin >> c;
        if (c == 'y')
            return true;
        else if (c == 'n')
            return false;
        else {
            std::cout << "invalid entry\n";
            isvalid = true;
        }
    } while(isvalid);
}

bool Game::hit_built_puntos() {

    for (const auto &next_piece_pnt : curr_piece.next_caer_body()) {
        //hit the ground
        if (next_piece_pnt.get_y() == 0) {
            board.insert_to_built_puntos(curr_piece.get_body());
            return true;
        }
        //hit built points
        for (const auto &built_pnt : board.get_built_puntos())
            if (next_piece_pnt == built_pnt) {
                board.insert_to_built_puntos(curr_piece.get_body());
                return true;
            }
    }

    return false;
}

bool Game::chequear_mover(enum move_direction dir) {
    for (const auto &next_piece_pnt : curr_piece.next_mover_body(dir)) {
        if (next_piece_pnt.get_x() == 0 || next_piece_pnt.get_x() == (board.get_width() - 1))
            return false;

        for (const auto &built_pnt : board.get_built_puntos())
            if (built_pnt == next_piece_pnt)
                return false;
    }

    curr_piece.move(dir);
    return true;
}

bool Game::chequear_rotacion() {
    for (const auto &next_piece_pnt : curr_piece.next_rotar_body()) {
        if (next_piece_pnt.get_x() == 0 || next_piece_pnt.get_x() == (board.get_width() - 1))
            return false;

        for (const auto &built_pnt : board.get_built_puntos())
            if (built_pnt == next_piece_pnt)
                return false;
    }

    curr_piece.rotate();
    return true;
}

void Game::refresh_final_puntos() {

    final_puntos = board.get_all_puntos();
    for (auto &final_pnt : final_puntos)
        for (auto piece_pnt : curr_piece.get_body())
            if (final_pnt == piece_pnt)
                final_pnt = piece_pnt;
}

void Game::draw() {
    for (int i{board.get_height() - 1}; i >= 0 ; i--) {
        for (int j{0}; j < board.get_width(); j++) {
            auto t = std::find(final_puntos.begin(), final_puntos.end(), Cell(j, i));
            std::cout << t->get_tipo();
        }
        std::cout << std::endl;
    }
    std::cout << "\n Score = " << score << std::endl;
}

void Game::controles() {
    if (GetAsyncKeyState(VK_UP))
            chequear_rotacion();
        else if (GetAsyncKeyState(VK_DOWN))
            speed = 10;
        else if (GetAsyncKeyState(VK_RIGHT))
            chequear_mover(right);
        else if (GetAsyncKeyState(VK_LEFT))
            chequear_mover(left);
        else if (GetAsyncKeyState('P')) {

        }
}

void Game::ClearScreen() {

    COORD cursorPosition;   cursorPosition.X = 0;   cursorPosition.Y = 0;   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
