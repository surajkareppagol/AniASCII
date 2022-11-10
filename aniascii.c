#include <stdio.h>
#include <ctype.h>
#define MAX 60

static int forward = 0;
static int forwardD = 0;
static int backward = 20;
static int backwardD = 20;
int turn = 0;

// Six functions for animation of forward, backward, upward, downward
// diagonal right and diagonal left
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

void drawDiagonalRight(int arrRows, int arrCols, char artOne[MAX][MAX], char artTwo[MAX][MAX])
{
  int i, j;
  drawRight(arrRows, arrRows, artOne, artTwo);
  for (j = 0; j < forwardD; j++)
    printf("\n");
  forwardD++;
}

void drawDiagonalLeft(int arrRows, int arrCols, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  drawLeft(arrRows, arrRows, artOne, artTwo);
  for (j = backwardD; j > 0; j--)
    printf("\n");
  backwardD--;
}

// animate() function, it shuold be called from main()
// It accepts the animation choice, two ascii arts, Number of columns and rows,
// time to stop animation, animation speed
void animate(int *choice, char artOne[MAX][MAX], char artTwo[MAX][MAX], int arrRows, int arrCols, int stopAnimationAfter, char animationSpeed)
{
  int i, j, k, speed;
  if (tolower(animationSpeed) == 'l')
    speed = 100000000;
  else if (tolower(animationSpeed) == 'm')
    speed = 40000000;
  else if (tolower(animationSpeed) == 'h')
    speed = 10000000;
  else
    speed = 100000000;
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
    for (k = 0; k < speed; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}
