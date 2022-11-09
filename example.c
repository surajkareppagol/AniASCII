#include <stdio.h>
#include "aniascii.h"
#define MAX 60

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
  printf("1. Draw Forword  2. Draw Backword  3. Draw Up 4. Draw Down 5. Draw Diagonal Right 6. Draw Diagonal Left\n");
  printf("ENTER THE CHOICE : ");
  scanf("%d", &choice);
  animate(&choice, artOne, artTwo, 4, 15);
  return 0;
}
