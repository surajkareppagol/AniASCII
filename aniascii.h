/*********************************************
 *  Function Declarations
 *********************************************/

#ifndef _ANIASCII_H_
#define _ANIASCII_H_

#define SLOW 80000000
#define MEDIUM 40000000
#define FAST 20000000

/*********************************************
 *  ANSI COLOR CODES
 *********************************************/

#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

/*********************************************
 *  Animation Main Function
 *********************************************/

void drawRight(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns]);
void drawUp(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns]);
void drawDown(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns]);
void drawDiagonalRight(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns]);
void drawDiagonalLeft(int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns]);

/*********************************************
 *  API - Ascii Animation
 *********************************************/

void animateAscii(int *, int *rows, int *columns, int, int, char (*artOne)[*columns], char (*artTwo)[*columns], char *);

#endif

/*********************************************
 *  EOF
 *********************************************/