#include <stdio.h>
#include <ctype.h>
#define RESET "\033[0m"

static int forward = 0;
static int forwardDiagonal = 0;
static int backward = 20;
static int backwardD = 20;
int turn = 0, i, j;

/*********************************************
 *  Animation Main Function
 *********************************************/

void drawRight(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns])
{
  for (i = 0; i < *rows; i++)
  {
    for (j = 0; j < forward; j++)
      printf(" ");
    if (!turn)
      printf("%s\n", artOne[i]);
    else
      printf("%s\n", artTwo[i]);
  }
  forward++;
  (turn == 0) ? (turn = 1) : (turn = 0);
}

void drawLeft(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns])
{
  for (i = 0; i < *rows; i++)
  {
    for (j = backward; j > 0; j--)
      printf(" ");
    if (!turn)
      printf("%s\n", artOne[i]);
    else
      printf("%s\n", artTwo[i]);
  }
  backward--;
  (turn == 0) ? (turn = 1) : (turn = 0);
}

void drawUp(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns])
{
  for (i = 0; i < forward; i++)
    printf("\n");
  for (j = 0; j < *rows; j++)
    if (!turn)
      printf("%s\n", artOne[j]);
    else
      printf("%s\n", artTwo[j]);
  for (i = 0; i < forward; i++)
    printf("\n");
  forward++;
  (turn == 0) ? (turn = 1) : (turn = 0);
}

void drawDown(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns])
{
  for (i = backward; i > 0; i--)
    printf("\n");
  for (j = 0; j < *rows; j++)
    if (!turn)
      printf("%s\n", artOne[j]);
    else
      printf("%s\n", artTwo[j]);
  for (i = backward; i > 0; i--)
    printf("\n");
  backward--;
  (turn == 0) ? (turn = 1) : (turn = 0);
}

void drawDiagonalRight(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns])
{
  int j;
  drawRight(rows, columns, artOne, artTwo);
  for (j = 0; j < forwardDiagonal; j++)
    printf("\n");
  forwardDiagonal++;
}

void drawDiagonalLeft(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns])
{
  int j;
  drawLeft(rows, columns, artOne, artTwo);
  for (j = backwardD; j > 0; j--)
    printf("\n");
  backwardD--;
}

/*********************************************
 *  API - Ascii Animation
 *********************************************/

void animateAscii(int *choice, int *rows, int *columns, int stopAnimationAfter, int animationSpeed, char (*artOne)[*columns], char (*artTwo)[*columns], char *color)
{
  printf("%s", color);
  int i, j, k;
  for (i = 0; i < stopAnimationAfter; i++)
  {
    switch (*choice)
    {
    case 1:
      drawRight(rows, columns, artOne, artTwo);
      break;
    case 2:
      drawLeft(rows, columns, artOne, artTwo);
      break;
    case 3:
      drawUp(rows, columns, artOne, artTwo);
      break;
    case 4:
      drawDown(rows, columns, artOne, artTwo);
      break;
    case 5:
      drawDiagonalRight(rows, columns, artOne, artTwo);
      break;
    case 6:
      drawDiagonalLeft(rows, columns, artOne, artTwo);
      break;
    }
    for (k = 0; k < animationSpeed; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
  printf(RESET);
}

/*********************************************
 *  EOF
 *********************************************/