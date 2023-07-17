/**************************************/
/* aniascii.c */
/**************************************/

#include <ctype.h>
#include <ncurses.h>

int turn = 0, i, j;
int termRows = 0, termColumns = 0;
int artRows = 0, artColumns = 0;
int changeColumnPosition = 0;
int counter = 0;

/**************************************/
/* Utility functions */
/**************************************/

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

/**************************************/
/* Main draw function */
/**************************************/

void draw(int columns, char (*artOne)[columns], char (*artTwo)[columns], int rowPosition, int columnPosition)
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
  turn = !turn;
}

/**************************************/
/* Public interface */
/**************************************/

void animateAscii(int *choice, int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns], int animationSpeed, int columnGap,
                  int rowPosition, int columnPosition)
{
  attron(COLOR_PAIR(1));
  getmaxyx(stdscr, termRows, termColumns);

  if (*choice == 2)
  {
    counter = termColumns - *columns;
    if (columnPosition != -1)
      counter = columnPosition;
  }

  artRows = *rows;
  artColumns = *columns;
  changeColumnPosition = columnGap;

  if (*choice == 1)
  {
    int stopAt = termColumns + 1 - artColumns - columnPosition;
    while (counter != stopAt)
    {
      move(rowPosition, columnPosition++);
      draw(artColumns, artOne, artTwo, rowPosition, columnPosition);
      counter++;
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 2)
  {
    while (counter != 0)
    {
      move(rowPosition, columnPosition--);
      draw(artColumns, artOne, artTwo, rowPosition, columnPosition);
      counter--;
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 3)
  {
    for (i = termRows - artRows - 1; i > 0; i--)
    {
      draw(artColumns, artOne, artTwo, i, columnGap);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 4)
  {
    for (i = 0; i < termRows - artRows; i++)
    {
      draw(artColumns, artOne, artTwo, i, columnGap);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 5)
  {
    for (i = termRows - artRows - 1; i > 0; i--)
    {
      draw(artColumns, artOne, artTwo, i, changeColumnPosition++);
      cleanUp(animationSpeed);
    }
  }

  if (*choice == 6)
  {
    for (i = 0; i < termRows - artRows; i++)
    {
      draw(artColumns, artOne, artTwo, i, changeColumnPosition++);
      cleanUp(animationSpeed);
    }
  }

  attroff(COLOR_PAIR(1));
  endwin();
}

/**************************************/
/* EOF */
/**************************************/