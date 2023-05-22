#include <stdio.h>
#include "aniascii.h"

/*********************************************
 *  Main Function
 *********************************************/

int main()
{
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
  int choice = 0;
  printf("| 1.Forward | 2.Backward | 3.Upward | 4.Downward | 5.Diagonal Right | 6.Diagonal Left |\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  animateAscii(&choice, &rows, &columns, 100, FAST, artOne, artTwo, WHITE);
  return 0;
}
