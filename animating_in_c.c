#include <stdio.h>

static int x = 0;
static int y = 40;

void drawBoxOne()
{
  int i;
  for (i = 0; i < x; i++)
    printf(" ");
  printf("----------\n");
  for (i = 0; i < x; i++)
    printf(" ");
  printf("|        |\n");
  for (i = 0; i < x; i++)
    printf(" ");
  printf("|        |\n");
  for (i = 0; i < x; i++)
    printf(" ");
  printf("----------\n");
  x++;
}

void drawBoxLeft()
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    drawBoxOne();
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

void drawBoxTwo()
{
  int i;
  for (i = y; i > 0; i--)
    printf(" ");
  printf("----------\n");
  for (i = y; i > 0; i--)
    printf(" ");
  printf("|        |\n");
  for (i = y; i > 0; i--)
    printf(" ");
  printf("|        |\n");
  for (i = y; i > 0; i--)
    printf(" ");
  printf("----------\n");
  y--;
}

void drawBoxRight()
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    drawBoxTwo();
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

void drawBoxThree()
{
  int i;
  for (i = 0; i < x; i++)
    printf("\n");
  printf("----------\n");
  // for (i = 0; i < x; i++)
  //   printf("\n");
  printf("|        |\n");
  // for (i = 0; i < x; i++)
  //   printf("\n");
  printf("|        |\n");
  // for (i = 0; i < x; i++)
  //   printf("\n");
  printf("----------\n");
  for (i = 0; i < x; i++)
    printf("\n");
  x++;
}

void drawBoxUp()
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    drawBoxThree();
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

void drawBoxFour()
{
  int i;
  for (i = y; i > 0; i--)
    printf("\n");
  printf("----------\n");
  // for (i = y; i > 0; i--)
  //   printf(" ");
  printf("|        |\n");
  // for (i = y; i > 0; i--)
  //   printf(" ");
  printf("|        |\n");
  // for (i = y; i > 0; i--)
  //   printf(" ");
  printf("----------\n");
  for (i = y; i > 0; i--)
    printf("\n");
  y--;
}

void drawBoxDown()
{
  int i, j, k;
  for (i = 0; i < 100; i++)
  {
    drawBoxFour();
    for (k = 0; k < 90000000; k++)
      ;
    for (j = 0; j < 50; j++)
      printf("\n");
  }
}

int main()
{
  int choice = 0;
  printf("1. Draw Box - 1  2. Draw Box - 2  3. Draw Box - 3  4. Draw Box - 4\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  if (choice == 1)
    drawBoxLeft();
  else if (choice == 2)
    drawBoxRight();
  else if (choice == 3)
    drawBoxUp();
  else if (choice == 4)
    drawBoxDown();
  return 0;
}