/**************************************/
/* aniascii.h */
/**************************************/

#ifndef _ANIASCII_H_
#define _ANIASCII_H_

/**************************************/
/* Utility functions */
/**************************************/

void cleanUp(int timeInMs);
void setColor(short foreground, short background);

/**************************************/
/* Main draw function */
/**************************************/

void draw(int columns, char (*artOne)[columns], char (*artTwo)[columns], int rowPosition, int columnPosition);

/**************************************/
/* Public interface */
/**************************************/

void animateAscii(int *choice, int *rows, int *columns, char (*artOne)[*columns], char (*artTwo)[*columns], int animationSpeed, int columnGap, int rowPosition, int columnPosition);

#endif

/**************************************/
/* EOF */
/**************************************/