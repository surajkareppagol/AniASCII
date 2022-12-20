#define MAX 60
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"

void colorPrint(char *);
void colorReset();
void drawRight(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawUp(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawDown(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawDiagonalRight(int, int, char artOne[][MAX], char artTwo[][MAX]);
void drawDiagonalLeft(int, int, char artOne[][MAX], char artTwo[][MAX]);
void animate(int *, char artOne[][MAX], char artTwo[][MAX], int, int, int, char animationSpeed);