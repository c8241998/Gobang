#include "service.h"
#include "person.h"
#include "computer.h"


void regret_ai(int first)   //first����������Ϣ  0�������� 1�û�����
{
	if (turn == 0 || turn == 1) return;   //����״̬ ���ܻ���
	loadimage(NULL, TEXT("..\\�˻�.jpg"));  //��������
	
	int x, y;       //������Ϣ

	turn--;;
	x = record[0][turn];
	y = record[1][turn];
	record[0][turn] = 0;
	record[1][turn] = 0;
	map[x / unit][y / unit] = 0;         //������һ����

	turn--;;
	x = record[0][turn];
	y = record[1][turn];
	record[0][turn] = 0;
	record[1][turn] = 0;
	map[x / unit][y / unit] = 0;        //��������ڶ�����

	if (first == 0)  // ��������
	{
		for (int i = 0; i <= turn - 1; i++)            //�ػ�����
		{
			if (i % 2 == 0)
			{
				setfillcolor(BLACK);
				x = record[0][i];
				y = record[1][i];
			}

			else if (i % 2 == 1)
			{
				setfillcolor(WHITE);
				x = record[0][i];
				y = record[1][i];
			}
			circle(x, y, R);
			fillcircle(x, y, R);
		}
	}

	if (first == 1)  // �û�����
	{
		for (int i = 1; i <= turn - 1; i++)
		{
			if (i % 2 == 0)
			{
				setfillcolor(WHITE);
				x = record[0][i];
				y = record[1][i];
			}

			else if (i % 2 == 1)
			{
				setfillcolor(BLACK);
				x = record[0][i];
				y = record[1][i];
			}
			circle(x, y, R);
			fillcircle(x, y, R);
		}
	}


}

int value(int n, int x, int y)  //��ʶ��n ����Ϊ2 ����Ϊ1         x,yΪ��������
{
	int live4 = 0,live3=0,sleep4=0;
	int sum = 0, oppo;            //oppo ����
	if (n == 1) oppo = 2; else oppo = 1;
	if (map[x][y] != 0) return -100000;    //�Ѿ����� ��ֹ��

	map[x][y] = n;  //����˴�����

	//����
	if (check(x, y))
		if (n == 2) sum += 30000; else sum += 10000;


	//  ���� 1
	if (x >= 2 && x <= 11 && map[x - 1][y] == 0 && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == n&&map[x + 4][y] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 5 && x <= 14 && map[x + 1][y] == 0 && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == n&&map[x - 4][y] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (y >= 2 && y <= 11 && map[x][y - 1] == 0 && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == n&&map[x][y + 4] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (y >= 5 && y <= 14 && map[x][y + 1] == 0 && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == n&&map[x][y - 4] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 2 && x <= 11 && y >= 5 && y <= 14 && map[x - 1][y + 1] == 0 && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == n&&map[x + 4][y - 4] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 2 && x <= 11 && y >= 2 && y <= 11 && map[x - 1][y - 1] == 0 && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == n&&map[x + 4][y + 4] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 5 && x <= 14 && y >= 2 && y <= 11 && map[x + 1][y - 1] == 0 && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == n&&map[x - 4][y + 4] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 5 && x <= 14 && y >= 5 && y <= 14 && map[x + 1][y + 1] == 0 && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == n&&map[x - 4][y - 4] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	//  ���� 2
	if (x >= 3 && x <= 12 && map[x - 2][y] == 0 && map[x - 1][y] == n && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 4 && x <= 13 && map[x + 2][y] == 0 && map[x + 1][y] == n && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (y >= 3 && y <= 12 && map[x][y - 2] == 0 && map[x][y - 1] == n && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (y >= 4 && y <= 13 && map[x][y + 2] == 0 && map[x][y + 1] == n && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 3 && x <= 12 && y >= 4 && y <= 13 && map[x - 2][y + 2] == 0 && map[x - 1][y + 1] == n && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 3 && x <= 12 && y >= 3 && y <= 12 && map[x - 2][y - 2] == 0 && map[x - 1][y - 1] == n && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 4 && x <= 13 && y >= 3 && y <= 12 && map[x + 2][y - 2] == 0 && map[x + 1][y - 1] == n && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}
	if (x >= 4 && x <= 13 && y >= 4 && y <= 13 && map[x + 2][y + 2] == 0 && map[x + 1][y + 1] == n && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == 0)
		{if (n == 2) sum += 4000; else sum += 3000;live4++;}


	//����1   {if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 2 && x <= 12 && map[x - 1][y] == 0 && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 4 && x <= 14 && map[x + 1][y] == 0 && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (y >= 2 && y <= 12 && map[x][y - 1] == 0 && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (y >= 4 && y <= 14 && map[x][y + 1] == 0 && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 2 && x <= 12 && y >= 4 && y <= 14 && map[x - 1][y + 1] == 0 && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 2 && x <= 12 && y >= 2 && y <= 12 && map[x - 1][y - 1] == 0 && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 4 && x <= 14 && y >= 2 && y <= 12 && map[x + 1][y - 1] == 0 && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 4 && x <= 14 && y >= 4 && y <= 14 && map[x + 1][y + 1] == 0 && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	//����2
	if (x >= 3 && x <= 13 && map[x - 2][y] == 0 && map[x - 1][y] == n && map[x + 1][y] == n&&map[x + 2][y] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (y >= 3 && y <= 13 && map[x][y - 2] == 0 && map[x][y - 1] == n && map[x][y + 1] == n&&map[x][y + 2] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 3 && x <= 13 && y >= 3 && y <= 13 && map[x - 2][y + 2] == 0 && map[x - 1][y + 1] == n && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}
	if (x >= 3 && x <= 13 && y >= 3 && y <= 13 && map[x + 2][y - 2] == 0 && map[x + 1][y - 1] == n && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == 0)
		{if (n == 1&&turn<=6) sum += 250; else if(n==1) sum += 80;else sum+=110;live3++;}


	//  ����1
	if (x >= 2 && x <= 11 && map[x - 1][y] == 0 && map[x + 1][y] == n&&map[x + 2][y] == 0 && map[x + 3][y] == n&&map[x + 4][y] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 5 && x <= 14 && map[x + 1][y] == 0 && map[x - 1][y] == n&&map[x - 2][y] == 0 && map[x - 3][y] == n&&map[x - 4][y] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (y >= 2 && y <= 11 && map[x][y - 1] == 0 && map[x][y + 1] == n&&map[x][y + 2] == 0 && map[x][y + 3] == n&&map[x][y + 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (y >= 5 && y <= 14 && map[x][y + 1] == 0 && map[x][y - 1] == n&&map[x][y - 2] == 0 && map[x][y - 3] == n&&map[x][y - 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 2 && x <= 11 && y >= 5 && y <= 14 && map[x - 1][y + 1] == 0 && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == 0 && map[x + 3][y - 3] == n&&map[x + 4][y - 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 2 && x <= 11 && y >= 2 && y <= 11 && map[x - 1][y - 1] == 0 && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == 0 && map[x + 3][y + 3] == n&&map[x + 4][y + 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 5 && x <= 14 && y >= 2 && y <= 11 && map[x + 1][y - 1] == 0 && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == 0 && map[x - 3][y + 3] == n&&map[x - 4][y + 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 5 && x <= 14 && y >= 5 && y <= 14 && map[x + 1][y + 1] == 0 && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == 0 && map[x - 3][y - 3] == n&&map[x - 4][y - 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	// ����2
	if (x >= 3 && x <= 12 && map[x - 2][y] == 0 && map[x - 1][y] == n && map[x + 1][y] == 0 && map[x + 2][y] == n&&map[x + 3][y] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 4 && x <= 13 && map[x + 2][y] == 0 && map[x + 1][y] == n && map[x - 1][y] == 0 && map[x - 2][y] == n&&map[x - 3][y] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (y >= 3 && y <= 12 && map[x][y - 2] == 0 && map[x][y - 1] == n && map[x][y + 1] == 0 && map[x][y + 2] == n&&map[x][y + 3] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (y >= 4 && y <= 13 && map[x][y + 2] == 0 && map[x][y + 1] == n && map[x][y - 1] == 0 && map[x][y - 2] == n&&map[x][y - 3] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 3 && x <= 12 && y >= 4 && y <= 13 && map[x - 2][y + 2] == 0 && map[x - 1][y + 1] == n && map[x + 1][y - 1] == 0 && map[x + 2][y - 2] == n&&map[x + 3][y - 3] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 3 && x <= 12 && y >= 3 && y <= 12 && map[x - 2][y - 2] == 0 && map[x - 1][y - 1] == n && map[x + 1][y + 1] == 0 && map[x + 2][y + 2] == n&&map[x + 3][y + 3] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 4 && x <= 13 && y >= 3 && y <= 12 && map[x + 2][y - 2] == 0 && map[x + 1][y - 1] == n && map[x - 1][y + 1] == 0 && map[x - 2][y + 2] == n&&map[x - 3][y + 3] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 4 && x <= 13 && y >= 4 && y <= 13 && map[x + 2][y + 2] == 0 && map[x + 1][y + 1] == n && map[x - 1][y - 1] == 0 && map[x - 2][y - 2] == n&&map[x - 3][y - 3] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	//  ����3
	if (x >= 2 && x <= 11 && map[x - 1][y] == 0 && map[x + 1][y] == 0 && map[x + 2][y] == n && map[x + 3][y] == n&&map[x + 4][y] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 5 && x <= 14 && map[x + 1][y] == 0 && map[x - 1][y] == 0 && map[x - 2][y] == n && map[x - 3][y] == n&&map[x - 4][y] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (y >= 2 && y <= 11 && map[x][y - 1] == 0 && map[x][y + 1] == 0 && map[x][y + 2] == n && map[x][y + 3] == n&&map[x][y + 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (y >= 5 && y <= 14 && map[x][y + 1] == 0 && map[x][y - 1] == 0 && map[x][y - 2] == n && map[x][y - 3] == n&&map[x][y - 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 2 && x <= 11 && y >= 5 && y <= 14 && map[x - 1][y + 1] == 0 && map[x + 1][y - 1] == 0 && map[x + 2][y - 2] == n && map[x + 3][y - 3] == n&&map[x + 4][y - 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 2 && x <= 11 && y >= 2 && y <= 11 && map[x - 1][y - 1] == 0 && map[x + 1][y + 1] == 0 && map[x + 2][y + 2] == n && map[x + 3][y + 3] == n&&map[x + 4][y + 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 5 && x <= 14 && y >= 2 && y <= 11 && map[x + 1][y - 1] == 0 && map[x - 1][y + 1] == 0 && map[x - 2][y + 2] == n && map[x - 3][y + 3] == n&&map[x - 4][y + 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	if (x >= 5 && x <= 14 && y >= 5 && y <= 14 && map[x + 1][y + 1] == 0 && map[x - 1][y - 1] == 0 && map[x - 2][y - 2] == n && map[x - 3][y - 3] == n&&map[x - 4][y - 4] == 0)
		{if (n == 1) sum += 80; else sum += 110;live3++;}
	

	//���
	if (x >= 1 && x <= 13 && map[x - 1][y] == 0 && map[x + 1][y] == n&&map[x + 2][y] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (x >= 3 && x <= 14 && map[x + 1][y] == 0 && map[x - 1][y] == n&&map[x - 2][y] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (y >= 1 && y <= 13 && map[x][y - 1] == 0 && map[x][y + 1] == n&&map[x][y + 2] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (y >= 3 && y <= 14 && map[x][y + 1] == 0 && map[x][y - 1] == n&&map[x][y - 2] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (x >= 1 && x <= 13 && y >= 3 && y <= 14 && map[x - 1][y + 1] == 0 && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (x >= 1 && x <= 13 && y >= 1 && y <= 13 && map[x - 1][y - 1] == 0 && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (x >= 3 && x <= 14 && y >= 1 && y <= 13 && map[x + 1][y - 1] == 0 && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == 0)
		if (n == 1) sum += 70; else sum += 90;
	if (x >= 3 && x <= 14 && y >= 3 && y <= 14 && map[x + 1][y + 1] == 0 && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == 0)
		if (n == 1) sum += 70; else sum += 90;


	//����1
	if (x >= 2 && x <= 11 && map[x - 1][y] == oppo && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == n&&map[x + 4][y] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 5 && x <= 14 && map[x + 1][y] == oppo && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == n&&map[x - 4][y] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 2 && y <= 11 && map[x][y - 1] == oppo && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == n&&map[x][y + 4] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 5 && y <= 14 && map[x][y + 1] == oppo && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == n&&map[x][y - 4] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 2 && x <= 11 && y >= 5 && y <= 14 && map[x - 1][y + 1] == oppo && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == n&&map[x + 4][y - 4] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 2 && x <= 11 && y >= 2 && y <= 11 && map[x - 1][y - 1] == oppo && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == n&&map[x + 4][y + 4] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 5 && x <= 14 && y >= 2 && y <= 11 && map[x + 1][y - 1] == oppo && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == n&&map[x - 4][y + 4] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 5 && x <= 14 && y >= 5 && y <= 14 && map[x + 1][y + 1] == oppo && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == n&&map[x - 4][y - 4] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	//����2
	if (x >= 3 && x <= 12 &&map[x -2][y] == oppo&& map[x - 1][y] == n && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] ==0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 4 && x <= 13 &&map[x +2][y] == oppo&& map[x + 1][y] == n && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 3 && y <= 12 && map[x][y-2] == oppo && map[x][y - 1] == n&&map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 4 && y <= 13 && map[x][y + 2] == oppo && map[x][y + 1] == n&&map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 3 && x <= 12 && y >= 4 && y <= 13 && map[x - 2][y + 2] == oppo && map[x - 1][y + 1] == n&&map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 3 && x <= 12 && y >= 3 && y <= 12 && map[x - 2][y - 2] == oppo && map[x - 1][y - 1] == n&&map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 4 && x <= 13 && y >= 3 && y <= 12 && map[x +2][y +2] == oppo && map[x + 1][y + 1] == n&&map[x - 1][y -1] == n&&map[x - 2][y -2] == n&&map[x - 3][y - 3] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 4 && x <= 13 && y >= 4 && y <= 13 && map[x + 2][y - 2] == oppo && map[x + 1][y - 1] == n&&map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	//����3
	if (x >= 4 && x <= 13 && map[x - 3][y] == oppo&& map[x - 2][y] == n && map[x -1][y] == n&&map[x + 1][y] == n&&map[x + 2][y] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 3 && x <= 12 && map[x + 3][y] == oppo&& map[x + 2][y] == n && map[x +1][y] == n&&map[x - 1][y] == n&&map[x - 2][y] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 4 && y <= 13 && map[x][y - 3] == oppo && map[x][y - 2] == n&&map[x][y - 1] == n&&map[x][y + 1] == n&&map[x][y + 2] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 3 && y <= 12 && map[x][y + 3] == oppo && map[x][y + 2] == n&&map[x][y + 1] == n&&map[x][y - 1] == n&&map[x][y - 2] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 4 && x <= 13 && y >= 3 && y <= 12 && map[x - 3][y + 3] == oppo && map[x - 2][y + 2] == n&&map[x - 1][y + 1] == n&&map[x + 1][y - 1] == n&&map[x + 2][y - 2] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 4 && x <= 13 && y >= 4 && y <= 13 && map[x - 3][y - 3] == oppo && map[x - 2][y - 2] == n&&map[x - 1][y - 1] == n&&map[x + 1][y + 1] == n&&map[x + 2][y + 2] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 3 && x <= 12 && y >= 4 && y <= 13 && map[x + 3][y + 3] == oppo && map[x + 2][y + 2] == n&&map[x + 1][y + 1] == n&&map[x - 1][y - 1] == n&&map[x - 2][y - 2] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 3 && x <= 12 && y >= 3 && y <= 12 && map[x + 3][y - 3] == oppo && map[x + 2][y - 2] == n&&map[x + 1][y - 1] == n&&map[x - 1][y + 1] == n&&map[x - 2][y + 2] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	//����4
	if (x >= 5 && x <= 15 && map[x - 3][y] == n&& map[x - 2][y] == n && map[x - 1][y] == n&&map[x + 0][y] == n&&map[x + 1][y] == 0&&map[x - 4][y] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 2 && x <= 11 && map[x + 3][y] == n&& map[x + 2][y] == n && map[x + 1][y] == n&&map[x - 0][y] == n&&map[x -1][y] == 0&&map[x + 4][y] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 5 && y <= 15 && map[x][y - 3] == n && map[x][y - 2] == n&&map[x][y - 1] == n&&map[x][y + 1] == n&&map[x][y + 0] == 0&&map[x][y -4] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 2 && y <= 11 && map[x][y + 3] == n && map[x][y + 2] == n&&map[x][y + 1] == n&&map[x][y - 0] == n&&map[x][y - 1] == 0&&map[x][y +4] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 5 && x <= 15 && y >= 2 && y <= 11 && map[x - 3][y + 3] == n && map[x - 2][y + 2] == n&&map[x - 1][y + 1] == n&&map[x + 1][y - 1] == 0&&map[x -4][y +4] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 5 && x <= 15 && y >= 5 && y <= 15 && map[x - 3][y - 3] == n && map[x - 2][y - 2] == n&&map[x - 1][y - 1] == n&&map[x + 1][y + 1] == 0 &&map[x -4][y -4] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 2 && x <= 11 && y >= 5 && y <= 15 && map[x + 3][y + 3] == n && map[x + 2][y + 2] == n&&map[x + 1][y + 1] == n&&map[x - 1][y - 1] == 0 &&map[x+4][y+4] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 2 && x <= 11 && y >= 2 && y <= 11 && map[x + 3][y - 3] == n && map[x + 2][y - 2] == n&&map[x + 1][y - 1] == n&&map[x - 1][y + 1] == 0 &&map[x +4][y -4] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	//����
	if (x >= 6 && x <= 15 && map[x - 4][y] == n&& map[x - 3][y] == n&& map[x - 2][y] == n && map[x - 1][y] == 0&&map[x - 5][y] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 1 && x <= 11 && map[x + 4][y] == n&& map[x + 3][y] == n&& map[x + 2][y] == n && map[x + 1][y] == 0&&map[x + 5][y] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (y >= 6 && y <= 15 && map[x][y - 4] == n&& map[x][y - 3] == n && map[x][y - 2] == n&&map[x][y - 1] == 0&&map[x][y - 5] == oppo)
		{if (n == 1) sum += 70; else sum += 80; sleep4++;}
	if (y >= 1 && y <= 11 && map[x][y + 4] == n && map[x][y + 3] == n&&map[x][y + 2] == n&&map[x][y + 1] == 0&&map[x][y + 5] == oppo)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 6 && x <= 15 && y >= 1 && y <= 11 && map[x - 5][y + 5] == oppo && map[x - 4][y + 4] == n&&map[x - 3][y + 3] == n&&map[x - 2][y + 2] == n&&map[x - 1][y + 1] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 6 && x <= 15 && y >= 6 && y <= 15 && map[x - 5][y - 5] == oppo && map[x - 4][y - 4] == n&&map[x - 3][y - 3] == n&&map[x - 2][y - 2] == n&&map[x - 1][y - 1] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 1 && x <= 11 && y >= 6 && y <= 15 && map[x + 5][y + 5] == oppo && map[x + 4][y + 4] == n&&map[x + 3][y + 3] == n&&map[x + 2][y + 2] == n&&map[x + 1][y + 1] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}
	if (x >= 1 && x <= 11 && y >= 1 && y <= 11 && map[x + 5][y - 5] == oppo && map[x + 4][y - 4] == n&&map[x + 3][y - 3] == n&&map[x + 2][y - 2] == n&&map[x + 1][y - 1] == 0)
		{if (n == 1) sum += 200; else sum += 200;sleep4++;}

	//����
	if (x >= 1 && x <= 12 && map[x - 1][y] == oppo && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (x >= 4 && x <= 14 && map[x + 1][y] == oppo && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (y >= 1 && y <= 12 && map[x][y - 1] == oppo && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (y >= 4 && y <= 14 && map[x][y + 1] == oppo && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (x >= 1 && x <= 12 && y >= 4 && y <= 14 && map[x - 1][y + 1] == oppo && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (x >= 1 && x <= 12 && y >= 1 && y <= 12 && map[x - 1][y - 1] == oppo && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (x >= 4 && x <= 14 && y >= 1 && y <= 12 && map[x + 1][y - 1] == oppo && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == 0)
		if (n == 1) sum += 60; else sum += 70;
	if (x >= 4 && x <= 14 && y >= 4 && y <= 14 && map[x + 1][y + 1] == oppo && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == 0)
		if (n == 1) sum += 60; else sum += 70;


	//�߶�
	if (x >= 1 && x <= 13 && map[x - 1][y] == oppo && map[x + 1][y] == n&&map[x + 2][y] == 0)
		sum += 50;
	if (x >= 3 && x <= 14 && map[x + 1][y] == oppo && map[x - 1][y] == n&&map[x - 2][y] == 0)
		sum += 50;
	if (y >= 1 && y <= 13 && map[x][y - 1] == oppo && map[x][y + 1] == n&&map[x][y + 2] == 0)
		sum += 50;
	if (y >= 3 && y <= 14 && map[x][y + 1] == oppo && map[x][y - 1] == n&&map[x][y - 2] == 0)
		sum += 50;
	if (x >= 1 && x <= 13 && y >= 3 && y <= 14 && map[x - 1][y + 1] == oppo && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == 0)
		sum += 50;
	if (x >= 1 && x <= 13 && y >= 1 && y <= 13 && map[x - 1][y - 1] == oppo && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == 0)
		sum += 50;
	if (x >= 3 && x <= 14 && y >= 1 && y <= 13 && map[x + 1][y - 1] == oppo && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == 0)
		sum += 50;
	if (x >= 3 && x <= 14 && y >= 3 && y <= 14 && map[x + 1][y + 1] == oppo && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == 0)
		sum += 50;

	if (n == 2)
	{

		//����
		if (x >= 1 && x <= 11 && map[x - 1][y] == oppo && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == n&&map[x + 4][y] == oppo)
			sum += -30;
		if (x >= 5 && x <= 14 && map[x + 1][y] == oppo && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == n&&map[x - 4][y] == oppo)
			sum += -30;
		if (y >= 1 && y <= 11 && map[x][y - 1] == oppo && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == n&&map[x][y + 4] == oppo)
			sum += -30;
		if (y >= 5 && y <= 14 && map[x][y + 1] == oppo && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == n&&map[x][y - 4] == oppo)
			sum += -30;
		if (x >= 1 && x <= 11 && y >= 5 && y <= 14 && map[x - 1][y + 1] == oppo && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == n&&map[x + 4][y - 4] == oppo)
			sum += -30;
		if (x >= 1 && x <= 11 && y >= 1 && y <= 11 && map[x - 1][y - 1] == oppo && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == n&&map[x + 4][y + 4] == oppo)
			sum += -30;
		if (x >= 5 && x <= 14 && y >= 1 && y <= 11 && map[x + 1][y - 1] == oppo && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == n&&map[x - 4][y + 4] == oppo)
			sum += -30;
		if (x >= 5 && x <= 14 && y >= 5 && y <= 14 && map[x + 1][y + 1] == oppo && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == n&&map[x - 4][y - 4] == oppo)
			sum += -30;

		//����
		if (x >= 1 && x <= 12 && map[x - 1][y] == oppo && map[x + 1][y] == n&&map[x + 2][y] == n&&map[x + 3][y] == oppo)
			sum += -30;
		if (x >= 4 && x <= 14 && map[x + 1][y] == oppo && map[x - 1][y] == n&&map[x - 2][y] == n&&map[x - 3][y] == oppo)
			sum += -30;
		if (y >= 1 && y <= 12 && map[x][y - 1] == oppo && map[x][y + 1] == n&&map[x][y + 2] == n&&map[x][y + 3] == oppo)
			sum += -30;
		if (y >= 4 && y <= 14 && map[x][y + 1] == oppo && map[x][y - 1] == n&&map[x][y - 2] == n&&map[x][y - 3] == oppo)
			sum += -30;
		if (x >= 1 && x <= 12 && y >= 4 && y <= 14 && map[x - 1][y + 1] == oppo && map[x + 1][y - 1] == n&&map[x + 2][y - 2] == n&&map[x + 3][y - 3] == oppo)
			sum += -30;
		if (x >= 1 && x <= 12 && y >= 1 && y <= 12 && map[x - 1][y - 1] == oppo && map[x + 1][y + 1] == n&&map[x + 2][y + 2] == n&&map[x + 3][y + 3] == oppo)
			sum += -30;
		if (x >= 4 && x <= 14 && y >= 1 && y <= 12 && map[x + 1][y - 1] == oppo && map[x - 1][y + 1] == n&&map[x - 2][y + 2] == n&&map[x - 3][y + 3] == oppo)
			sum += -30;
		if (x >= 4 && x <= 14 && y >= 4 && y <= 14 && map[x + 1][y + 1] == oppo && map[x - 1][y - 1] == n&&map[x - 2][y - 2] == n&&map[x - 3][y - 3] == oppo)
			sum += -30;
	}

	map[x][y] = 0;   //�������
	if ((sleep4&&live3) || (live4&&live3) || (sleep4&&live4) || sleep4 >= 2 || live4 >= 2)
	{
		if (n == 2) sum= 3900; else sum= 3100;
	}
	if (live3 >= 2)
	{
		if (n == 2) sum= 2850; else sum= 2800;
	}
	return sum+rand()%10;
}

int bestplace()
{
	int max1 = -10000, max2 = -10000, t;
	int x1 = 1, y1 = 1, x2 = 1, y2 = 1;
	
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)           //��������
		{
			if (map[i][j] == 0)
			{
				t = value(2, i, j);  //����
				if (t > max1)        //�˴���������  ���¼�¼
				{
					max1 = t;
					x1 = i;
					y1 = j;
				}
				t = value(1, i, j);  //����
				if (t > max2)        //�˴����ظ���  ���¼�¼
				{
					max2 = t;
					x2 = i;
					y2 = j;
				}
			}
		}
	if (max1 >= max2) return (x1 * 100 + y1);        //������������
	else return (x2 * 100 + y2);                     //���ظ�������
	//return ((rand() % 15+1) *100 + (rand()%15+1));
}

void AI()
{
	MOUSEMSG m;
	int x, y, p, q;
	int p_color, c_color;             //p_color ����ִ����ɫ  c_color �û�ִ����ɫ
	int first = -1;                   //���б�ʶ��   0�������� 1�������
	srand(unsigned(time(NULL)));      //��ʼ��ʱ������

	if (turn == 0)             //��������
	{
		p = 8;                //������������
		q = 8;
		map[p][q] = 2;
		x = blank_3 + (p - 1)*unit_ai;
		y = blank_4 + (q - 1)*unit_ai;
		setfillcolor(BLACK);
		circle(x, y, R);
		fillcircle(x, y, R);

		record[0][turn] = x;
		record[1][turn] = y;
		turn++;

		c_color = BLACK;
		p_color = WHITE;
		first = 0;
	}
	else    //�û�����
	{
		p_color = BLACK;
		c_color = WHITE;
		first = 1;
	}

	while (true)
	{
		if (first) flag = 0;
		else flag = -5;

		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
		{
			if (m.x < 700)
			{
				x = m.x;
				y = m.y;

				if (x <= (blank_3 + unit_ai / 4)) x = blank_1;                            // ��������������������л���
				else
					x = ((x - unit_ai / 2 - blank_3) / unit_ai + 1)*unit_ai + blank_3;

				if (y <= (blank_4 + unit_ai / 2)) y = blank_4;
				else
					y = ((y - unit_ai / 2 - blank_4) / unit_ai + 1)*unit_ai + blank_4;

				p = x / unit_ai;           //�洢��������
				q = y / unit_ai;
				if (p < 1 || p>15 || q < 1 || q>15)
					break;

				if (turn % 2 == 1 && map[p][q] == 0)
				{
					setfillcolor(p_color);
					map[p][q] = 1;

					circle(x, y, R);
					fillcircle(x, y, R);

					record[0][turn] = x;
					record[1][turn] = y;

					if (check(p, q))          //Ӯ��
					{

						flag += 2;
						break;
					}
					turn++;
					while (1)
					{
						p = bestplace();
						q = p % 100;
						p = p / 100;
						if (map[p][q] == 0) break;
					}
					map[p][q] = 2;
					x = blank_3 + (p - 1)*unit_ai;
					y = blank_4 + (q - 1)*unit_ai;
					setfillcolor(c_color);
					circle(x, y, R);
					fillcircle(x, y, R);

					record[0][turn] = x;
					record[1][turn] = y;

					if (check(p, q))
					{

						flag += 3;
						break;
					}
					turn++;
					if (turn >= size*size - 1)
					{
						MessageBox(NULL, TEXT("���壡"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);
						return;
					}
				}



				break;
			}
			else if (m.x >= 809 && m.x <= 1008 && m.y >= 460 && m.y <= 523)          //����
				regret_ai(first);

			else if (m.x >= 746 && m.x <= 941 && m.y >= 574 && m.y <= 632)           //����
			{
				if (MessageBox(NULL, TEXT("ȷ���˳��˾֣�"), TEXT("������Pro   --���ϸ���"), MB_YESNO | MB_SETFOREGROUND) == IDYES)
				{
					flag = 5;
					return;
				}

			}
		}
		}
		if (abs(flag) == 2 || abs(flag) == 3)
		{
			if (flag == 2 || flag == -2)
				MessageBox(NULL, TEXT("��ϲ������ʤ����"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);
			else if (flag == 3 || flag == -3)
				MessageBox(NULL, TEXT("��ϲ������ʤ����"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);
			return;
		}

	}
	system("pause");
	closegraph();
}