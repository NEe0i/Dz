#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';
bool gameOver = false;

void drawBoard() {
    cout << "  Крестики-нолики (3x3)  " << endl;
    cout << "Игрок 1: X | Игрок 2: O" << endl << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
    cout << "     |     |     " << endl << endl;
}

bool checkWin() {
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i+1] and board[i+1] == board[i+2]) return true;
    }
    for (int i = 0; i < 3; ++i) {
        if (board[i] == board[i+3] and board[i+3] == board[i+6]) return true;
    }
    if (board[0] == board[4] and board[4] == board[8]) return true;
    if (board[2] == board[4] and board[4] == board[6]) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 9; ++i) {
        if (board[i] >= '1' and board[i] <= '9') {
            return false;
        }
    }
    return true;
}

void makeMove() {
    int move;
    cout << "Ход игрока " << currentPlayer << ". Введите номер ячейки (1-9): ";
    cin >> move;

    if (move >= 1 and move <= 9 and board[move - 1] >= '1' and board[move - 1] <= '9') {
        board[move - 1] = currentPlayer;
        if (checkWin()) {
            drawBoard();
            cout << "Игрок " << currentPlayer << " победил! " << endl;
            gameOver = true;
        } else if (checkDraw()) {
            drawBoard();
            cout << "Ничья!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    } else {
        cout << "Неверный ход. Попробуйте еще раз." << endl;
    }
}

int main() {
    while (!gameOver) {
        drawBoard();
        makeMove();
    }

    return 0;
}
