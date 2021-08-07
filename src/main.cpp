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
int boardFull = 0;
bool gameOver = false;
bool checkRow(string playerMark);
bool checkColumn(string playerMark);
bool checkDiagonal(string playerMark);

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
    string playerMark, playerTurn;
    bool successfulTurn = false;
    while(boardFull < 9) {
        int rowChoice, columnChoice;
        if(X) {
          playerMark = "X";
          playerTurn = "player1";
        }
        else {
          playerMark = "O";
          playerTurn = "player2";
        }
        cout << playerTurn << " which row?" << endl;
        cin >> rowChoice;
        cout << playerTurn << " which column?" << endl;
        cin >> columnChoice;
        if(rowChoice > 3 || rowChoice < 1 || columnChoice > 3 || columnChoice < 1) {
            cout << "please enter valid values" << endl;
            continue;
        }
        columnChoice = columnConversion(columnChoice); // needed to account for weird position given | and _
        successfulTurn = updateBoard(rowChoice, columnChoice, playerMark);
        if(successfulTurn) {
          X = !X; // flip the player from 1 to 2
          boardFull++; // only increment the turn if it was a valid selection
          checkRow(playerMark);
          checkColumn(playerMark);
          checkDiagonal(playerMark);
        }
        
        if(gameOver) {
            X = !X;
            cout << "Game over " << playerTurn << " won" << endl;
            return;
        }
    }
    cout << "cat's game you both lost" << endl;
    
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

bool checkRow(string playerMark) { 
  int counter;
  for(int i = 0; i < boardRows.size(); i++) {
    counter = 0;
    for(int j = 0; j < boardRows[i].size(); j++) {
        if(boardRows[i][j] == playerMark) {
            counter += 1;
        }
        if(counter == 3) {
            gameOver = true;
        }
    }
  }
  return gameOver;
}

bool checkColumn(string playerMark) {
  int counter = 0;
  for(int i = 0; i < boardRows.size(); i++) {
      if(boardRows[i][0] == playerMark) {
          counter += 1;
      }
      else if(boardRows[i][1] == playerMark) {
          counter += 1;
      }
      else if(boardRows[i][2] == playerMark) {
          counter += 1;
      }
  }
  if(counter == 3) {
      gameOver = true;
  }
  return gameOver;
}

bool checkDiagonal(string playerMark) {
  // check left to right
  if(boardRows[0][0] == playerMark && boardRows[1][2] == playerMark && boardRows[2][4] == playerMark) {
      gameOver = true;
  }
  // check right to left
  else if(boardRows[0][4] == playerMark && boardRows[1][2] == playerMark && boardRows[2][0] == playerMark) {
      gameOver = true;
  }
  return gameOver;
}