#include <stdio.h>

void drawBoxRight(int, int, char art[][12]);
void drawBoxUp(int, int, char art[][12]);
void drawBoxDown(int, int, char art[][12]);
void drawBoxDiagonalRight(int, int, char art[][12]);
void drawBoxDiagonalLeft(int, int, char art[][12]);
void animateBox(int *, char art[][12]);

static int forword = 0;
static int forwordD = 0;
static int backword = 40;
static int backwordD = 40;

int main()
{
  char artBox[4][12] = {
      {"----------"},
      {"|        |"},
      {"|        |"},
      {"----------"}};
  int choice = 0;
  printf("1. Draw Forword  2. Draw Backword  3. Draw Up 4. Draw Down 5. Draw Diagonal Right 6. Draw Diagonal Left\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  animateBox(&choice, artBox);
  return 0;
}

///////////////////// BOX ONE
void drawBoxRight(int arrCols, int arrRows, char art[4][12])
{
  int i, j;
  for (i = 0; i < arrCols; i++)
  {
    for (j = 0; j < forword; j++)
      printf(" ");
    printf("%s\n", art[i]);
  }
  forword++;
}
/////////////////////

///////////////////// BOX TWO
void drawBoxLeft(int arrCols, int arrRows, char art[4][12])
{
  int i, j;
  for (i = 0; i < arrCols; i++)
  {
    for (j = backword; j > 0; j--)
      printf(" ");
    printf("%s\n", art[i]);
  }
  backword--;
}
/////////////////////

///////////////////// BOX THREE
void drawBoxUp(int arrCols, int arrRows, char art[4][12])
{
  int i, j;
  for (i = 0; i < forword; i++)
    printf("\n");
  for (j = 0; j < arrCols; j++)
    printf("%s\n", art[j]);
  for (i = 0; i < forword; i++)
    printf("\n");
  forword++;
}
/////////////////////

///////////////////// BOX FOUR
void drawBoxDown(int arrCols, int arrRows, char art[4][12])
{
  int i, j;
  for (i = backword; i > 0; i--)
    printf("\n");
  for (j = 0; j < arrCols; j++)
    printf("%s\n", art[j]);
  for (i = backword; i > 0; i--)
    printf("\n");
  backword--;
}
/////////////////////

///////////////////// BOX FIVE
void drawBoxDiagonalRight(int arrCols, int arrRows, char art[4][12])
{
  int i, j;
  drawBoxRight(4, 4, art);
  for (j = 0; j < forwordD; j++)
    printf("\n");
  forwordD++;
}
/////////////////////

///////////////////// BOX SIX
void drawBoxDiagonalLeft(int arrCols, int arrRows, char art[4][12])
{
  int i, j;
  drawBoxLeft(4, 4, art);
  for (j = backwordD; j > 0; j--)
    printf("\n");
  backwordD--;
}
/////////////////////

void animateBox(int *choice, char artboxes[4][12])
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    switch (*choice)
    {
    case 1:
      drawBoxRight(4, 4, artboxes);
      break;
    case 2:
      drawBoxLeft(4, 4, artboxes);
      break;
    case 3:
      drawBoxUp(4, 4, artboxes);
      break;
    case 4:
      drawBoxDown(4, 4, artboxes);
      break;
    case 5:
      drawBoxDiagonalRight(4, 4, artboxes);
      break;
    case 6:
      drawBoxDiagonalLeft(4, 4, artboxes);
      break;
    }
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

/////////////////////
