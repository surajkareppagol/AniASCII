#include <stdio.h>
#include <ctype.h>
#define MAX 60

static int forward = 0;
static int forwardD = 0;
static int backward = 20;
static int backwardD = 20;
int turn = 0;

// Print color.
void colorPrint(char *color)
{
  printf("%s", color);
}

// Reset color.
void colorReset()
{
  printf("\033[0m");
}

// Six functions for animation of forward, backward, upward, downward
// diagonal right and diagonal left

// Draw from left to right at bottom
void drawRight(int arrRows, int arrCols, char artOne[MAX][MAX], char artTwo[MAX][MAX])
{
  int i, j;
  for (i = 0; i < arrRows; i++)
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

// Draw from right to left at bottom
void drawLeft(int arrRows, int arrCols, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  for (i = 0; i < arrRows; i++)
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

// Draw from bottom to top
void drawUp(int arrRows, int arrCols, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  for (i = 0; i < forward; i++)
    printf("\n");
  for (j = 0; j < arrRows; j++)
    if (!turn)
      printf("%s\n", artOne[j]);
    else
      printf("%s\n", artTwo[j]);
  for (i = 0; i < forward; i++)
    printf("\n");
  forward++;
  (turn == 0) ? (turn = 1) : (turn = 0);
}

// Draw from top to bottom
void drawDown(int arrRows, int arrCols, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  for (i = backward; i > 0; i--)
    printf("\n");
  for (j = 0; j < arrRows; j++)
    if (!turn)
      printf("%s\n", artOne[j]);
    else
      printf("%s\n", artTwo[j]);
  for (i = backward; i > 0; i--)
    printf("\n");
  backward--;
  (turn == 0) ? (turn = 1) : (turn = 0);
}

// Draw diagonal form left to right
void drawDiagonalRight(int arrRows, int arrCols, char artOne[MAX][MAX], char artTwo[MAX][MAX])
{
  int i, j;
  drawRight(arrRows, arrRows, artOne, artTwo);
  for (j = 0; j < forwardD; j++)
    printf("\n");
  forwardD++;
}

// Draw diagonal form right to left
void drawDiagonalLeft(int arrRows, int arrCols, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  drawLeft(arrRows, arrRows, artOne, artTwo);
  for (j = backwardD; j > 0; j--)
    printf("\n");
  backwardD--;
}

// animate() function, it should be called from main()
// It accepts the animation choice, two ascii arts, Number of columns and rows,
// time to stop animation, animation speed
void animate(int *choice, char artOne[MAX][MAX], char artTwo[MAX][MAX], int arrRows, int arrCols, int stopAnimationAfter, int animationSpeed)
{
  int i, j, k;
  for (i = 0; i < stopAnimationAfter; i++)
  {
    switch (*choice)
    {
    case 1:
      drawRight(arrRows, arrCols, artOne, artTwo);
      break;
    case 2:
      drawLeft(arrRows, arrCols, artOne, artTwo);
      break;
    case 3:
      drawUp(arrRows, arrCols, artOne, artTwo);
      break;
    case 4:
      drawDown(arrRows, arrCols, artOne, artTwo);
      break;
    case 5:
      drawDiagonalRight(arrRows, arrCols, artOne, artTwo);
      break;
    case 6:
      drawDiagonalLeft(arrRows, arrCols, artOne, artTwo);
      break;
    }
    for (k = 0; k < animationSpeed; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}
