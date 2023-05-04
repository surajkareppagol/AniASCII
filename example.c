#include <stdio.h>
#include "aniascii.h"

/*********************************************
 *  Main Function
 *********************************************/

int main()
{
  char artOne[MAX][MAX] = {
      {"  ______      "},
      {" /|_||_\\`.__  "},
      {"(   _    _ _\\ "},
      {"=`-(_)--(_)-' "}};

  char artTwo[MAX][MAX] = {
      {"  ______      "},
      {" /|_||_\\`.__  "},
      {"(          _\\ "},
      {"=`-<->--<->-' "}};
  int choice = 0;
  printf("| 1.Forward | 2.Backward | 3.Upward | 4.Downward | 5.Diagonal Right | 6.Diagonal Left |\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  animateAscii(&choice, artOne, artTwo, 4, 15, 100, MEDIUM, GREEN);
  return 0;
}
