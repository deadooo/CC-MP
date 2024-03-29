#include <stdio.h>
#define MAX 36
#define TRUE 1
#define FALSE !TRUE

int main() {
  int good, over, next;
  int a, b, c, d;
  int row, col, player_move = 1; // Player Coords

  char F[6][6]; // Display Board

  int S[MAX][2] = {{1, 1}, {1, 3}}; // {{x, y}, {x, y}};
  int C[2][2];                      // Player X/O Valid Moves

  int F1[6][6] = {0}, F2[6][6] = {0}, F3[6][6], C1[MAX][2] = {0},
      C2[MAX][2] = {0}; // Variables
  int C1_index = 0, C2_index = 0;
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
    printf("Enter Valid Coords (row, column): \n\n");
    do {
      printf("Enter row: ");
      scanf("%d", &row);
    } while (row < 0 || row > 6);

    do {
      printf("\nEnter col: ");
      scanf("%d", &col);
    } while (col < 0 || col > 6);

    c = ((row - 3) / 2) + 1;
    d = ((col - 3) / 2) + 1;

  } while (c > 2 || d > 2); // Limiter

  if (F3[row][col] == NULL) {
    F3[row][col] = player_move;

    if (player_move == 1) {
      C1[C1_index][0] = c;
      C1[C1_index][1] = d;
      C1_index++;
      player_move--;
    } else {
      C2[C2_index][0] = c;
      C2[C2_index][1] = d;

      C2_index++;
      player_move++;
    }
  }
  // check if F[row][col] is empty
  // if F3[row][col] is empty = null, then put 1 and 0
  // C1 and C2 stores the value if its correct
  // loops till F3 is all null
  // C1 > C2, p1 wins vice versa
  return 0;
}
/* for C1
for (i = 0; i < n; i++){
  if (F3[row][col] != NULL && F3[row][col] == S[i][j])

    }
  if (F3[row][cow] != NULL && F3 == S[i][j])
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
