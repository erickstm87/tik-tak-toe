#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
using namespace std;

vector<string> firstRow = {"_", "|", "_", "|", "_"};
vector<string> secondRow = {"_", "|", "_", "|", "_"};
vector<string> lastRow = {" ", "|", " ", "|", " "};

void printBoard();
void updateBoard(int row, int column, string playerType);
string playerChoose();
int columnConversion(int columnSelection);
int boardFull = 0;

int main() {
    printBoard();
    cout << "player 1 it's your turn" << endl;
    playerChoose();
    return 0;
}

void printBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout<< "    ";
        for(int j = 0; j < 5; j++) {   
          if(i == 2) {
            cout << lastRow[j];
          }
          else if(i == 1){
            cout << secondRow[j];
          }
          else if(i == 0) {
            cout << firstRow[j]; 
          }
        }
        cout << endl;
    }
}

string playerChoose() {
    bool X = true;
    while(boardFull < 9) {
        int rowChoice, columnChoice;

        if(X) {
          cout << " player1 which row?" << endl;
          cin >> rowChoice;
          cout << "player1 which column?" << endl;
          cin >> columnChoice;
          columnChoice = columnConversion(columnChoice);
          X = !X;
          updateBoard(rowChoice, columnChoice, "X");
        }
        else {
          cout << " player2 which row?" << endl;
          cin >> rowChoice;
          cout << "player2 which column?" << endl;
          cin >> columnChoice;
          X = !X;
          columnChoice = columnConversion(columnChoice);
          updateBoard(rowChoice, columnChoice, "O");
        }
        boardFull++;
    }
    return "something";
}

void updateBoard(int row, int column, string playerType) {
    switch(row) { 
      case(1):
        firstRow[column] = playerType;
        printBoard();
        break;
      case(2):
        secondRow[column] = playerType;
        printBoard();
        break;
      case(3):
        lastRow[column] = playerType;
        printBoard();
        break;
      default:
        cout << "please choose one, two, or three" << endl;
        break;
    }
    return;
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
          cout << "please select something valid";
          break;
    }
    return columnSelection;
}
