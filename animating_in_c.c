#include <stdio.h>

static int x = 0;
static int y = 100;

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

int main()
{
  int choice = 0;
  printf("1. Draw Box - 1  2. Draw Box - 2\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  if (choice == 1)
    drawBoxLeft();
  else if (choice == 2)
    drawBoxRight();
  return 0;
}