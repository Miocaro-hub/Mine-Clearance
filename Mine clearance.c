#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("**********************\n");
	printf("*** 1.play  0.exit ***\n");
	printf("**********************\n");
}

void game()
{
	//雷的信息存储 1.布置雷 2.排查雷
	//分别用一个数组，一个用来存放已经布置好的雷的信息，一个用来存放排查出来雷的信息
	//只需要给玩家打印出来第二个排查雷信息的数组,另一个放在后台
	char mine[ROWS][COLS] = { 0 };  //11×11的数组
	char show[ROWS][COLS] = { 0 };

	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL); //不需要打印外圈
	//printf("\n");
	DisplayBoard(show, ROW, COL);
	printf("\n");

	//布置雷
	SetMine(mine,ROW,COL);
	//扫雷
	DisplayBoard(mine, ROW, COL);

	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		    case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
			default:
				printf("选择错误，请重新选择!\n");
				break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}