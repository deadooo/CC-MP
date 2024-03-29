#include <stdio.h>
#define MAX 36
#define TRUE 1
#define FALSE !TRUE

int main() {
  int good, over, next;
  int a, b, c, d;
  int x, y; // Player Coords

  char F[6][6]; // Display Board

  int S[MAX][2] = {{1, 1}, {1, 3}}; // {{x, y}, {x, y}};
  int C[2][2];                      // Player X/O Valid Moves

  int F1[6][6] = {0}, F2[6][6] = {0}, F3[6][6], C1[MAX][2] = {0},
      C2[MAX][2] = {0}; // Variables

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
    printf("Enter row: ");
    scanf("%d", &y);
  } while (y < 0 || y > 6);

  do {
    printf("\nEnter col: ");
    scanf("%d", &x);
  } while (x < 0 || x > 6);

  // check if F[y][x] is empty
  // if F3[y][x] is empty = null, then put O or X
  //

  return 0;
}
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
