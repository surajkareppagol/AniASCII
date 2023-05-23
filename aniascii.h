/*********************************************
 *  Function Declarations
 *********************************************/

#ifndef _ANIASCII_H_
#define _ANIASCII_H_

/*********************************************
 *  Utility Functions
 *********************************************/

void cleanUp(int timeInMs);
void setColor(short foreground, short background);

/*********************************************
 *  Animation Main Function
 *********************************************/

void drawRight(int columns, char (*artOne)[columns], char (*artTwo)[columns]);
void drawLeft(int columns, char (*artOne)[columns], char (*artTwo)[columns]);
void drawUpDownAndDiagonal(int columns, char (*artOne)[columns], char (*artTwo)[columns], int rowPosition, int columnPosition);

/*********************************************
 *  API - Ascii Animation
 *********************************************/

void animateAscii(int *choice, int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns], int animationSpeed, int columnGap);

#endif

/*********************************************
 *  EOF
 *********************************************/