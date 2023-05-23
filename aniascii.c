#include <ctype.h>
#include <ncurses.h>
#include "stdio.h"

int turn = 0, i, j;
int termRows = 0, termColumns = 0;
int artRows = 0, artColumns = 0;
int changeColumnPosition = 0;

static int forward = 0;
static int backward = 0;

/*********************************************
 *  Utility Function
 *********************************************/

void cleanUp(int timeInMs)
{
  napms(timeInMs);
  clear();
  refresh();
}

void setColor(short foreground, short background)
{
  if (!has_colors())
    printw("Terminal doesn't support colors.");
  start_color();
  init_pair(1, foreground, background);
  bkgd(COLOR_PAIR(1));
}

/*********************************************
 *  Animation Main Function
 *********************************************/

void drawForward(int columns, char (*artOne)[columns], char (*artTwo)[columns])
{
  for (i = 0; i < artRows; i++)
  {
    for (j = 0; j < forward; j++)
      printw(" ");
    if (!turn)
      printw("%s\n", artOne[i]);
    else
      printw("%s\n", artTwo[i]);
  }
  refresh();
  forward++;
  turn = !turn;
}

void drawBackward(int columns, char (*artOne)[columns], char (*artTwo)[columns])
{
  for (i = 0; i < artRows; i++)
  {
    for (j = backward; j > 0; j--)
      printw(" ");
    if (!turn)
      printw("%s\n", artOne[i]);
    else
      printw("%s\n", artTwo[i]);
  }
  refresh();
  backward--;
  turn = !turn;
}

void drawUpDownAndDiagonal(int columns, char (*artOne)[columns], char (*artTwo)[columns], int rowPosition, int columnPosition)
{
  for (j = 0; j < artRows; j++)
  {
    move(rowPosition++, columnPosition);
    if (!turn)
      printw("%s\n", artOne[j]);
    else
      printw("%s\n", artTwo[j]);
  }
  refresh();
  forward++;
  turn = !turn;
}

/*********************************************
 *  API - Ascii Animation
 *********************************************/

void animateAscii(int *choice, int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns], int animationSpeed, int columnGap)
{
  attron(COLOR_PAIR(1));
  getmaxyx(stdscr, termRows, termColumns);

  backward = termColumns - *columns;
  artRows = *rows;
  artColumns = *columns;
  changeColumnPosition = columnGap;

  if (*choice == 1)
  {
    while (forward != termColumns + 1 - artColumns)
    {
      drawForward(artColumns, artOne, artTwo);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 2)
  {
    while (backward != 0)
    {
      drawBackward(artColumns, artOne, artTwo);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 3)
  {
    for (i = termRows - artRows - 1; i > 0; i--)
    {
      drawUpDownAndDiagonal(artColumns, artOne, artTwo, i, columnGap);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 4)
  {
    for (i = 0; i < termRows - artRows; i++)
    {
      drawUpDownAndDiagonal(artColumns, artOne, artTwo, i, columnGap);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 5)
  {
    for (i = termRows - artRows - 1; i > 0; i--)
    {
      drawUpDownAndDiagonal(artColumns, artOne, artTwo, i, changeColumnPosition++);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 6)
  {
    for (i = 0; i < termRows - artRows; i++)
    {
      drawUpDownAndDiagonal(artColumns, artOne, artTwo, i, changeColumnPosition++);
      cleanUp(animationSpeed);
    }
  }

  attroff(COLOR_PAIR(1));
  endwin();
}

/*********************************************
 *  EOF
 *********************************************/