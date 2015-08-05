#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "HorizontalMenu.h"
#include "Util.h"

enum KeyCode{
	ENTER = 13, LEFT = 75, RIGHT = 77
};

enum Boolean{
	False, True
};

void HorizontalMenu_Create(HorizontalMenu* horizontalMenu, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint){
	int i;
	for (i = 0; i < count; i++){
		strcpy(horizontalMenu->items[i], items[i]);
	}
	horizontalMenu->count = count;
	horizontalMenu->selectedIndex = 0;
	horizontalMenu->startPositionToPrint.x = startPositionXToPrint;
	horizontalMenu->startPositionToPrint.y = startPositionYToPrint;
}

void HorizontalMenu_Print(HorizontalMenu* horizontalMenu){
	int i;
	Point startPositionToPrint = horizontalMenu->startPositionToPrint;
	CursorUtil_Hide();
	for (i = 0; i < horizontalMenu->count; i++){
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y);
		startPositionToPrint.x += strlen(horizontalMenu->items[i]) + 4;
		if (i == horizontalMenu->selectedIndex){
			FontUtil_ChangeFontColor(WHITE_INVERSION);
		}
		else{
			FontUtil_ChangeFontColor(WHITE);
		}
		printf("%s", horizontalMenu->items[i]);
	}
	FontUtil_ChangeFontColor(WHITE);
}

int HorizontalMenu_ProcessKey(HorizontalMenu* horizontalMenu){
	while (True){
		if (_kbhit()){
			int key = _getch();
			if (key == ENTER){
				break;
			}
			switch (key){
			case 0xE0:
				if (_kbhit()){
					switch (_getch()){
					case LEFT:
						horizontalMenu->selectedIndex = (horizontalMenu->selectedIndex - 1 + horizontalMenu->count) % horizontalMenu->count;
						HorizontalMenu_Print(horizontalMenu);
						break;
					case RIGHT:
						horizontalMenu->selectedIndex = (horizontalMenu->selectedIndex + 1) % horizontalMenu->count;
						HorizontalMenu_Print(horizontalMenu);
						break;
					}
				}
				break;
			}
		}
	}
	return horizontalMenu->selectedIndex;
}

const char* HorizontalMenu_GetSelectedContent(HorizontalMenu* horizontalMenu){
	return horizontalMenu->items[horizontalMenu->selectedIndex];
}
