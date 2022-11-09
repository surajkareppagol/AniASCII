#include <stdio.h>
#define MAX 60

static int forword = 0;
static int forwordD = 0;
static int backword = 20;
static int backwordD = 20;
int turn = 0;

///////////////////// BOX ONE
void drawRight(int arrCols, int arrRows, char artOne[MAX][MAX], char artTwo[MAX][MAX])
{
  int i, j;
  if (!turn)
  {
    for (i = 0; i < arrCols; i++)
    {
      for (j = 0; j < forword; j++)
        printf(" ");
      printf("%s\n", artOne[i]);
    }
    forword++;
    turn = 1;
  }
  else if (turn)
  {
    for (i = 0; i < arrCols; i++)
    {
      for (j = 0; j < forword; j++)
        printf(" ");
      printf("%s\n", artTwo[i]);
    }
    forword++;
    turn = 0;
  }
}
/////////////////////

///////////////////// BOX TWO
void drawLeft(int arrCols, int arrRows, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  if (!turn)
  {
    for (i = 0; i < arrCols; i++)
    {
      for (j = backword; j > 0; j--)
        printf(" ");
      printf("%s\n", artOne[i]);
    }
    backword--;
    turn = 1;
  }
  else if (turn)
  {
    for (i = 0; i < arrCols; i++)
    {
      for (j = backword; j > 0; j--)
        printf(" ");
      printf("%s\n", artTwo[i]);
    }
    backword--;
    turn = 0;
  }
}
/////////////////////

///////////////////// BOX THREE
void drawUp(int arrCols, int arrRows, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  if (!turn)
  {
    for (i = 0; i < forword; i++)
      printf("\n");
    for (j = 0; j < arrCols; j++)
      printf("%s\n", artOne[j]);
    for (i = 0; i < forword; i++)
      printf("\n");
    forword++;
    turn = 1;
  }
  else if (turn)
  {
    for (i = 0; i < forword; i++)
      printf("\n");
    for (j = 0; j < arrCols; j++)
      printf("%s\n", artTwo[j]);
    for (i = 0; i < forword; i++)
      printf("\n");
    forword++;
    turn = 1;
  }
}
/////////////////////

///////////////////// BOX FOUR
void drawDown(int arrCols, int arrRows, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  if (!turn)
  {
    for (i = backword; i > 0; i--)
      printf("\n");
    for (j = 0; j < arrCols; j++)
      printf("%s\n", artOne[j]);
    for (i = backword; i > 0; i--)
      printf("\n");
    backword--;
    turn = 1;
  }
  else if (turn)
  {
    for (i = backword; i > 0; i--)
      printf("\n");
    for (j = 0; j < arrCols; j++)
      printf("%s\n", artOne[j]);
    for (i = backword; i > 0; i--)
      printf("\n");
    backword--;
    turn = 0;
  }
}
/////////////////////

///////////////////// BOX FIVE
void drawDiagonalRight(int arrCols, int arrRows, char artOne[MAX][MAX], char artTwo[MAX][MAX])
{
  int i, j;
  drawRight(arrCols, arrRows, artOne, artTwo);
  for (j = 0; j < forwordD; j++)
    printf("\n");
  forwordD++;
}
/////////////////////

///////////////////// BOX SIX
void drawDiagonalLeft(int arrCols, int arrRows, char artOne[][MAX], char artTwo[][MAX])
{
  int i, j;
  drawLeft(arrCols, arrRows, artOne, artTwo);
  for (j = backwordD; j > 0; j--)
    printf("\n");
  backwordD--;
}
/////////////////////

void animate(int *choice, char artOne[MAX][MAX], char artTwo[MAX][MAX], int arrCols, int arrRows)
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    switch (*choice)
    {
    case 1:
      drawRight(arrCols, arrRows, artOne, artTwo);
      break;
    case 2:
      drawLeft(arrCols, arrRows, artOne, artTwo);
      break;
    case 3:
      drawUp(arrCols, arrRows, artOne, artTwo);
      break;
    case 4:
      drawDown(arrCols, arrRows, artOne, artTwo);
      break;
    case 5:
      drawDiagonalRight(arrCols, arrRows, artOne, artTwo);
      break;
    case 6:
      drawDiagonalLeft(arrCols, arrRows, artOne, artTwo);
      break;
    }
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

/////////////////////
