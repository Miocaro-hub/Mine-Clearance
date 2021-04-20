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
	//�׵���Ϣ�洢 1.������ 2.�Ų���
	//�ֱ���һ�����飬һ����������Ѿ����úõ��׵���Ϣ��һ����������Ų�����׵���Ϣ
	//ֻ��Ҫ����Ҵ�ӡ�����ڶ����Ų�����Ϣ������,��һ�����ں�̨
	char mine[ROWS][COLS] = { 0 };  //11��11������
	char show[ROWS][COLS] = { 0 };

	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL); //����Ҫ��ӡ��Ȧ
	//printf("\n");
	DisplayBoard(show, ROW, COL);
	printf("\n");

	//������
	SetMine(mine,ROW,COL);
	//ɨ��
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		    case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
			default:
				printf("ѡ�����������ѡ��!\n");
				break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}