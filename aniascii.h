/*********************************************
 *  Function Declarations
 *********************************************/

#ifndef _ANIASCII_H_
#define _ANIASCII_H_

#define MAX 60
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define SLOW 100000000
#define MEDIUM 40000000
#define FAST 10000000

/*********************************************
 *  Animation Main Function
 *********************************************/

void drawRight(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawUp(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawDown(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawDiagonalRight(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawDiagonalLeft(int, int, char artOne[][MAX], char artTwo[][MAX]);

/*********************************************
 *  API - Ascii Animation
 *********************************************/

void animateAscii(int *, char artOne[][MAX], char artTwo[][MAX], int, int, int, int, char *);

#endif

/*********************************************
 *  EOF
 *********************************************/