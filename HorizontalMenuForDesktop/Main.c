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
	printf("�޴� ���� �Է� : ");
	scanf("%d", &count);
	printf("�޴� ���� ��ġ �Է� (x, y)\n�ܼ� â ũ�� ����� �ʵ��� ���� : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("�޴� ����� �Է�\n");
	for (i = 0; i < count; i++){
		printf("%d ��° : ex) [1] �޴� 1 : ", i + 1);
		fgets(items[i], ITEMS_CONTENT_SIZE, stdin);
		items[i][strlen(items[i]) - 1] = '\0';
	}
	system("cls");
	HorizontalMenu_Create(&horizontalMenu, items, count, startPositionXToPrint, startPositionYToPrint);
	HorizontalMenu_Print(&horizontalMenu);
	selectedIndex = HorizontalMenu_ProcessKey(&horizontalMenu);
	printf("\n\n���õ� �޴� ���� : %s\n", HorizontalMenu_GetSelectedContent(&horizontalMenu));
	return 0;
}