#ifndef _HORIZONTAL_MENU_H
#define _HORIZONTAL_MENU_H
#include "Point.h"

#define ITEMS_COUNT 10
#define ITEMS_CONTENT_SIZE 128

typedef struct _horizontalMenu{
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE];
	int count;
	int selectedIndex;
	Point startPositionToPrint;
}HorizontalMenu;

void HorizontalMenu_Create(HorizontalMenu* horizontalMenu, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint);
void HorizontalMenu_Print(HorizontalMenu* horizontalMenu);
int HorizontalMenu_ProcessKey(HorizontalMenu* horizontalMenu);
const char* HorizontalMenu_GetSelectedContent(HorizontalMenu* horizontalMenu);

#endif