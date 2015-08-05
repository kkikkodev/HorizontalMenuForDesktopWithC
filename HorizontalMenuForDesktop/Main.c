#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HorizontalMenu.h"

int main(int argc, char* argv[]){
	HorizontalMenu horizontalMenu = { 0, };
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE] = { '\0', };
	int i;
	int count;
	int startPositionXToPrint;
	int startPositionYToPrint;
	int selectedIndex;
	printf("메뉴 개수 입력 : ");
	scanf("%d", &count);
	printf("메뉴 시작 위치 입력 (x, y)\n콘솔 창 크기 벗어나지 않도록 주의 : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("메뉴 내용들 입력\n");
	for (i = 0; i < count; i++){
		printf("%d 번째 : ex) [1] 메뉴 1 : ", i + 1);
		fgets(items[i], ITEMS_CONTENT_SIZE, stdin);
		items[i][strlen(items[i]) - 1] = '\0';
	}
	system("cls");
	HorizontalMenu_Create(&horizontalMenu, items, count, startPositionXToPrint, startPositionYToPrint);
	HorizontalMenu_Print(&horizontalMenu);
	selectedIndex = HorizontalMenu_ProcessKey(&horizontalMenu);
	printf("\n\n선택된 메뉴 내용 : %s\n", HorizontalMenu_GetSelectedContent(&horizontalMenu));
	return 0;
}