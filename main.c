#include <math.h>
#include <stdio.h>
#define MAX 36
#define TRUE 1
#define FALSE !TRUE
#define playerX 1
#define playerO 2

void dispBoard(int F3[][6]);
int checkS(int S[][6][2], int C[][2], int inp_row, int inp_col);
int gameOver(int F3[][6], int C1[][2], int C2[][2]);

int main() {
  int good, over, next;
  int a, b, c, d;
  int row, col, // Player Coords
      player = playerX;

  char F[6][6]; // Display Board

  int S[4][6][2] = {
      {{1, 1}, {1, 3}, {2, 2}, {3, 1}, {3, 3}}, // Quadrant II (All works)
      {{4, 4}, {4, 6}, {5, 5}, {6, 4}, {6, 6}}, //  Quadrant IV(All Works)
      {{5, 1}, {4, 2}, {5, 2}, {6, 2}, {5, 3}}, // Quadrant III
      {{1, 4}, {1, 5}, {1, 6}, {3, 4}, {3, 5}, {3, 6}}}; // Quadrant I
  int C[2][2]; // Player X/O Valid Moves

  int F1[36][2] = {0}, F2[36][2] = {0}, F3[6][6] = {0}, C1[21][2] = {0},
      C2[21][2] = {0}; // Variables
  int C1_index = 0, C2_index = 0;
  int F1_index = 0, F2_index = 0;

  int svalue = checkS(S, C, row, col);
  int index1 = 0, indexC1 = 0, index2 = 0, indexC2 = 0;

  good = next = over = FALSE;
  do {
    dispBoard(F3);
    printf("Enter Valid Coords (row, column): \n\n");
    do {
      printf("Enter row: ");
      scanf("%d", &row);
    } while (row < 1 || row > 6);

    do {
      printf("\nEnter col: ");
      scanf("%d", &col);
    } while (col < 1 || col > 6);

    c = (int)((fabs(row - 3)) / 2) + 1;
    d = (int)((fabs(col - 3)) / 2) + 1;

    // SpaceChecker
    row--;
    col--;
    if (F3[row][col] == 0) {
      F3[row][col] = player;

      if (player == playerX) {
        F1[F1_index][0] = row;
        F1[F1_index][1] = col;
        C1[C1_index][0] = c;
        C1[C1_index][1] = d;

        F1_index++;
        C1_index++;
        player = playerO;
      } else {
        F2[F2_index][0] = row;
        F2[F2_index][1] = col;
        C2[C2_index][0] = c;
        C2[C2_index][1] = d;

        F2_index++;
        C2_index++;
        player = playerX;
      }

      // Storing Values in C1 & C2 (current scores)
      // once all wincons are met, make a condition to end game
      int svalue = checkS(S, C, row, col);
      if (F3[row][col] != 0 && player != playerX && svalue == 1) {
        C1[index1][0] = c;
        C1[index1][1] = d;
        index1++; // comparison for scores for both players
        if (index1 > 36)
          indexC1++;
        if (indexC1 > 2)
          indexC1 = 0;
      }
      if (F3[row][col] != 0 && player != playerO && svalue == 1) {
        C2[index2][0] = c;
        C2[index2][1] = d;
        index2++;
        if (index2 > 36)
          indexC2++;
        if (indexC2 > 2)
          indexC2 = 0;
      }
      printf("Player 1 Score: %d\n", index1);
      printf("Player 2 Score: %d\n", index2);
    }
  } while (!over || gameOver(F3, C1, C2));
  // comparing scores
  return 0;
} // end of main

void dispBoard(int F3[][6]) {

  // board maker
  int row, col, col2;
  char playerr;
  printf(" Tic Tac Toe but not really\n\n");
  // prints topmost row
  printf("\n+");
  for (col = 0; col < 6; col++)
    printf("---+");
  printf("\n");

  for (row = 0; row < 6; row++) {
    // prints one row of characters with spacing
    printf("|");
    for (col = 0; col < 6; col++) {
      if (F3[row][col] == 1)
        playerr = 'O';
      else if (F3[row][col] == 2)
        playerr = 'X';
      else
        playerr = ' ';
      printf(" %c |", playerr);
    }
    printf("\n");

    // prints the lower border of the current index
    printf("+");
    for (col2 = 0; col2 < 6; col2++)
      printf("---+");
    printf("\n");
  }
}

int checkS(int S[][6][2], int C[][2], int inp_row, int inp_col) {
  inp_row++;
  inp_col++;
  int row, col, f; // f determines the x and y in (x, y)
  {

    for (row = 0; row < 4; row++) {
      for (col = 0; col < 6; col++) {
        if (S[row][col][0] == inp_row && S[row][col][1] == inp_col) {
          return 1;
        }
      }
    }

    return 0;
  }
}

// Check C1 and C2 with the most Pairs = to P
int gameOver(int F3[][6], int C1[][2], int C2[][2]) {
  int xPointsA = 0;
  int xPointsB = 0;
  int xPointsC = 0;
  int xPointsD = 0;

  int oPointsA = 0;
  int oPointsB = 0;
  int oPointsC = 0;
  int oPointsD = 0;

  int difference = 0;
  int tempX1 = 0, tempX2 = 0, tempO1 = 0, tempO2 = 0;

  int count = 0;
  for (int i = 0; i < 6; ++i) {
    if (F3[i][0] + F3[i][1] > 0) {
      count++;
    }
  }

  if (count == 36) {
    for (int i = 0; i < 36; i++) {
      if (C1[i][0] == 1 && C1[i][1] == 1) { // (1,1)
        xPointsA++;
      } else if (C1[i][0] == 2 && C1[i][1] == 2) { // (2,2)
        xPointsB++;
      } else if (C1[i][0] == 1 && C1[i][1] == 2) { // (1, 2)
        xPointsC++;
      } else if (C1[i][0] == 2 && C1[i][1] == 1) { //(2, 1)
        xPointsD++;
      } else {
      }
      // O below
      if (C2[i][0] == 1 && C1[i][1] == 1) {
        if (C1[i][0] == 1 && C1[i][1] == 1) { // (1,1)
          oPointsA++;
        } else if (C1[i][0] == 2 && C1[i][1] == 2) { // (2,2)
          xPointsB++;
        } else if (C1[i][0] == 1 && C1[i][1] == 2) { // (1, 2)
          oPointsC++;
        } else if (C1[i][0] == 2 && C1[i][1] == 1) { //(2, 1)
          oPointsD++;
        } else {
        }
      }
    }

    if (xPointsA > 0 && xPointsB > 0) {
      if (xPointsA > xPointsB) {
        difference = xPointsA - xPointsB;
        tempX1 = xPointsA - difference;
      } else if (xPointsB > xPointsA) {
        difference = xPointsB - xPointsA;
        tempX1 = xPointsB - difference;
      } else { // Tie
        tempX1 = xPointsA;
      }
    }
    difference = 0;
    if (xPointsC > 0 && xPointsD > 0) {
      if (xPointsC > xPointsD) {
        difference = xPointsC - xPointsD;
        tempX2 = xPointsC - difference;
      } else if (xPointsD > xPointsC) {
        difference = xPointsD - xPointsC;
        tempX2 = xPointsD - difference;
      } else { // Tie
        tempX2 = xPointsC;
      }
    }
    // O below
    difference = 0;
    if (oPointsA > 0 && oPointsB > 0) {
      if (oPointsA > oPointsB) {
        difference = oPointsA - oPointsB;
        tempO1 = oPointsA - difference;
      } else if (oPointsB > oPointsA) {
        difference = oPointsB - oPointsA;
        tempO1 = oPointsB - difference;
      } else { // Tie
        tempO1 = oPointsA;
      }
    }
    difference = 0;
    if (oPointsC > 0 && oPointsD > 0) {
      if (oPointsC > oPointsD) {
        difference = oPointsC - oPointsD;
        tempO2 = oPointsC - difference;
      } else if (oPointsD > oPointsC) {
        difference = oPointsD - oPointsC;
        tempO2 = oPointsD - difference;
      } else { // Tie
        tempO2 = oPointsC;
      }
    }

    // determine winner
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    if (tempX1 + tempX2 > tempO1 + tempO2) {
      printf("Player X, You Are The Winner.");
      return 0;
    } else {
      printf("Player O, You Are The Winner.");
      return 0;
    }
  }
  return 1;
  // hello
}
