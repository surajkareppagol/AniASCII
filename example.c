#include <stdio.h>
#include <ncurses.h>
#include "aniascii.h"

/*********************************************
 *  Main Function
 *********************************************/

int main()
{
  initscr();
  int rows = 4, columns = 16;
  char artOne[][16] = {
      {"  ______       "},
      {" /|_||_\\`.__  "},
      {"(   _    _ _\\ "},
      {"=`-(_)--(_)-'  "}};

  char artTwo[][16] = {
      {"  ______       "},
      {" /|_||_\\`.__  "},
      {"(          _\\ "},
      {"=`-<->--<->-'  "}};

  setColor(COLOR_WHITE, COLOR_BLACK);

  int choice = 0;
  printw("| 1.Forward | 2.Backward | 3.Upward | 4.Downward | 5.Diagonal Right | 6.Diagonal Left |\n");
  printw("ENTER THE CHOICE : ");
  scanw("%d", &choice);
  clear();
  refresh();
  animateAscii(&choice, &rows, &columns, artOne, artTwo, 100, 10);
  return 0;
}

/*********************************************
 *  EOF
 *********************************************/