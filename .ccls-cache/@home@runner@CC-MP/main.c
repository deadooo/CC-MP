#include <math.h>
#include <stdio.h>
#define MAX 36
#define TRUE 1
#define FALSE !TRUE
#define playerX 1
#define playerO 2

void dispBoard(int F3[][6]);
int checkS(int S[][6][2], int C[][2], int inp_row, int inp_col);

int main() {
  int good, over, next;
  int a, b, c, d;
  int row, col, // Player Coords
      player = playerX;

  char F[6][6]; // Display Board

  int S[4][6][2] = {
      {{1, 1}, {1, 3}, {2, 2}, {3, 1}, {3, 3}},
      {{4, 4}, {4, 6}, {5, 5}, {6, 4}, {6, 6}},
      {{1, 5}, {2, 4}, {2, 5}, {2, 6}, {3, 5}},
      {{4, 1}, {4, 3}, {5, 1}, {5, 3}, {6, 1}, {6, 3}}}; // {{x, y}, {x, y}};

  printf("(%d, %d)\n", S[0][0][0], S[0][0][1]);

  int C[2][2]; // Player X/O Valid Moves

  int F1[6][6] = {0}, F2[6][6] = {0}, F3[6][6] = {0}, C1[MAX][2] = {0},
      C2[MAX][2] = {0}; // Variables
  int C1_index = 0, C2_index = 0;

  int svalue = checkS(S, C, row, col);
  int index1 = 0, indexC1 = 0, index2 = 0, indexC2 = 0;
  /*

  F3
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      if (F[i][j] == F[x][y]){
        F[i][j]


      }
    }
  }

  x y
  1 3
  F3[y][x] = O;

  F3[x][y] = null;

  if (F3[x][y] == null)

  F3
  board

  x y  - -
  0 0, 0 1, 0 2


  */
  good = next = over = FALSE;
  do {
    dispBoard(F3);
    printf("Enter Valid Coords (row, column): \n\n");
    do {
      printf("Enter row: ");
      scanf("%d", &row);
    } while (row < 0 && row >= 6);

    do {
      printf("\nEnter col: ");
      scanf("%d", &col);
    } while (col < 0 && col >= 6);

    c = ((fabs(row - 3)) / 2) + 1;
    d = ((fabs(col - 3)) / 2) + 1;

    // SpaceChecker
    if (F3[row][col] == 0) {
      F3[row][col] = player;

      if (player == playerX) {
        C1[C1_index][0] = c;
        C1[C1_index][1] = d;
        C1_index++;
        player = playerO;
      } else {
        C2[C2_index][0] = c;
        C2[C2_index][1] = d;

        C2_index++;
        player = playerX;
      }
    }
    // Check if in S Board

    // Storing Values in C1 & C2 (current scores)

    int svalue = checkS(S, C, row, col);
    if (F3[row][col] != 0 && player == playerX && svalue == 1) {
      index1++; // comparison for scores for both players
      if (index1 > 36)
        indexC1++;
      if (indexC1 > 2)
        indexC1 = 0;
    }
    if (F3[row][col] != 0 && player == playerO && svalue == 1) {
      index2++;
      if (index2 > 36)
        indexC2++;
      if (indexC2 > 2)
        indexC2 = 0;
    }
    printf("Player 1 Score: %d\n", index1);
    printf("Player 2 Score: %d\n", index2);
  } while (!over);
  // comparing scores
  if (index1 > index2) {
    printf("Player 1 wins");
  }
  if (index2 > index1) {
    printf("Player 2 wins");
  }

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

//   X O
//   O X
/*Checking S
for (i = 0; i < n; i++){

  while ()
}

*/
/* Linear Search
      for (i =0; i < n; i++)
      {
        for (j = 0; j < 2; j++)
          if (S[i][j] == x)
      }

      for (i = 0; i < 2; i++){
        num = i;
        if(S[i][num] == x){
          num++;
          if(S[i][num]){
            printf("Found");
          }else{
            num--;
          }
        }
      }



        */
// whole board
//  {(1,1), (1,2), (1,3), (1,4), (1,5), (1,6)},
//  {(2,1), (2,2), (2,3), (2,4), (2,5), (2,6)},
//  {(3,1), (3,2), (3,3), (3,4), (3,5), (3,6)},
//  {(4,1), (4,2), (4,3), (4,4), (4,5), (4,6)},
//  {(5,1), (5,2), (5,3), (5,4), (5,5), (5,6)},
//  {(6,1), (6,2), (6,3), (6,4), (6,5), (6,6)};

// correct values

/*
{
{(1,1), (1, 3), (2, 2), (3, 1), (3, 3)},
  {(4, 4), (4, 6), (5, 5), (6, 4), (6,6)},
  {(1, 5), (2, 4), (2, 5), (2, 6), (3, 5)},
  {(4, 1), (4, 3), (5, 1), (5, 3), (6, 1), (6, 3)}
}
*/

// FINISHED(USED)
/* for C1 && C2
int index1 = 0, C1_2 = 0, index2 = 0, C2_2 = 0;
  if (F3[row][col] != NULL && player == playerX){
    C1[index1][C1_2] == c;
    C1_2++;
    index1++;
    if (C1_2 > 2)
      C1_2 = 0;
    }
  if (F3[row][col] != NULL && player == playerO){
    C2[index2][C2_2] == c;
    index2++;
    C2_2++;
    if (C2_2 > 2)
      C2_2 = 0;
  }
*/
