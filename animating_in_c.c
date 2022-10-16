#include <stdio.h>

void drawBoxRight();
void drawBoxUp();
void drawBoxDown();
void drawBoxDiagonalRight();
void drawBoxDiagonalLeft();
void animateBox(int *);

static int forword = 0;
static int forwordD = 0;
static int backword = 40;
static int backwordD = 40;

int main()
{
  int choice = 0;
  printf("1. Draw Forword - 1  2. Draw Backword - 2  3. Draw Up - 3  4. Draw Down - 4 5. Draw Diagonal Right 6. Draw Diagonal Left\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  animateBox(&choice);
  return 0;
}

///////////////////// BOX ONE
void drawBoxRight()
{
  int i;
  for (i = 0; i < forword; i++)
    printf(" ");
  printf("----------\n");
  for (i = 0; i < forword; i++)
    printf(" ");
  printf("|        |\n");
  for (i = 0; i < forword; i++)
    printf(" ");
  printf("|        |\n");
  for (i = 0; i < forword; i++)
    printf(" ");
  printf("----------\n");
  forword++;
}
/////////////////////

///////////////////// BOX TWO
void drawBoxLeft()
{
  int i;
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("----------\n");
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("|        |\n");
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("|        |\n");
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("----------\n");
  backword--;
}
/////////////////////

///////////////////// BOX THREE
void drawBoxUp()
{
  int i;
  for (i = 0; i < forword; i++)
    printf("\n");
  printf("----------\n");
  printf("|        |\n");
  printf("|        |\n");
  printf("----------\n");
  for (i = 0; i < forword; i++)
    printf("\n");
  forword++;
}
/////////////////////

///////////////////// BOX FOUR
void drawBoxDown()
{
  int i;
  for (i = backword; i > 0; i--)
    printf("\n");
  printf("----------\n");
  printf("|        |\n");
  printf("|        |\n");
  printf("----------\n");
  for (i = backword; i > 0; i--)
    printf("\n");
  backword--;
}
/////////////////////

///////////////////// BOX FIVE
void drawBoxDiagonalRight()
{
  int i, j;
  for (i = 0; i < forword; i++)
    printf(" ");
  printf("----------\n");

  for (i = 0; i < forword; i++)
    printf(" ");
  printf("|        |\n");

  for (i = 0; i < forword; i++)
    printf(" ");
  printf("|        |\n");

  for (i = 0; i < forword; i++)
    printf(" ");
  printf("----------\n");
  for (j = 0; j < forwordD; j++)
    printf("\n");
  forword++;
  forwordD++;
}
/////////////////////

///////////////////// BOX SIX
void drawBoxDiagonalLeft()
{
  int i, j;
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("----------\n");
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("|        |\n");
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("|        |\n");
  for (i = backword; i > 0; i--)
    printf(" ");
  printf("----------\n");
  for (j = backwordD; j > 0; j--)
    printf("\n");
  backword--;
  backwordD--;
}
/////////////////////

void animateBox(int *choice)
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    switch (*choice)
    {
    case 1:
      drawBoxRight();
      break;
    case 2:
      drawBoxLeft();
      break;
    case 3:
      drawBoxUp();
      break;
    case 4:
      drawBoxDown();
      break;
    case 5:
      drawBoxDiagonalRight();
      break;
    case 6:
      drawBoxDiagonalLeft();
      break;
    }
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

/////////////////////