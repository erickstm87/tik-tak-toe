#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
using namespace std;

vector<string> firstRow = {"_", "|", "_", "|", "_"};
vector<string> secondRow = {"_", "|", "_", "|", "_"};
vector<string> lastRow = {" ", "|", " ", "|", " "};
vector<vector<string>> boardRows= {firstRow, secondRow, lastRow};

void printBoard();
void playerChoose();
bool updateBoard(int row, int column, string playerType);
int columnConversion(int columnSelection);
// bool checkWinner();
bool gameOver = false;
int boardFull = 0;

int main() {
    printBoard();
    cout << "player 1 it's your turn" << endl;
    playerChoose();
    return 0;
}

void printBoard() {
    cout << endl;
    for(int i = 0; i < boardRows.size(); i++) {
        for(int j = 0; j < boardRows[i].size(); j++) {
            cout << boardRows[i][j];
        }
        cout << endl;
    }
}

void playerChoose() {
    bool X = true;
    string playerMark;
    string player1, player2;
    bool successfulTurn = false;
    while(boardFull < 9) {
        int rowChoice, columnChoice;
        if(X) {
          playerMark = "X"
          cout << "player1 which row?" << endl;
          cin >> rowChoice;
          cout << "player1 which column?" << endl;
        }
        else {
          playerMark = "O"
          cout << "player2 which row?" << endl;
          cin >> rowChoice;
          cout << "player2 which column?" << endl;
        }
        cin >> columnChoice;
        columnChoice = columnConversion(columnChoice);
        successfulTurn = updateBoard(rowChoice, columnChoice, playerMark);
        if(successfulTurn) {
          X = !X; // flip the player from 1 to 2
          boardFull++; // only increment the turn if it was a valid selection
        }
        else {
            cout << "please enter valid values" << endl;
            continue;
        }
    }
}

bool updateBoard(int row, int column, string playerType) {
    bool goodTurn = false;
    vector<string> rowSelected;
    row-=1;
    if((boardRows[row][column] == "_" || boardRows[row][column] == " ") && row <= 2) {
        boardRows[row][column] = playerType;

        printBoard();
        goodTurn = true;
    }
    else {
        cout << "that spot is taken" << endl;
    }

    return goodTurn;
}

int columnConversion(int columnSelection) {
    switch(columnSelection) {
        case(1):
          columnSelection = 0;
          break;
        case(2):
          columnSelection = 2;
          break;
        case(3):
          columnSelection = 4;
          break;
        default:
          cout << "please select something valid" << endl;
          break;
    }
    return columnSelection;
}

// bool checkWinner() {
//     if()
//     return false;
// }