#include "service.h"
#include "person.h"
#include "computer.h"

int check(int p, int q)       //检测是否赢棋
{
	int now = map[p][q];        // (p,q)对应棋子颜色
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size - 4; j++)
			if (map[i][j] == now&&map[i][j + 1] == now&&map[i][j + 2] == now&&map[i][j + 3] == now&&map[i][j + 4] == now)
				return 1;
	for (int j = 1; j <= size; j++)
		for (int i = 1; i <= size - 4; i++)
			if (map[i][j] == now&&map[i + 1][j] == now&&map[i + 2][j] == now&&map[i + 3][j] == now&&map[i + 4][j] == now)
				return 1;
	for (int i = p - 4, j = q - 4; i <= p + 4, j <= q + 4; i++, j++)
		if (map[i][j] == now&&map[i + 1][j + 1] == now&&map[i + 2][j + 2] == now&&map[i + 3][j + 3] == now&&map[i + 4][j + 4] == now)
			return 1;
	for (int i = p - 4, j = q + 4; i <= p + 4, j >= q - 4; i++, j--)
		if (map[i][j] == now&&map[i + 1][j - 1] == now&&map[i + 2][j - 2] == now&&map[i + 3][j - 3] == now&&map[i + 4][j - 4] == now)
			return 1;
	return 0;
}

void regret()
{
	if (turn == 0) return;         //无子状态不能悔棋
	board();
	int x, y;
	turn--;
	x = record[0][turn];
	y = record[1][turn];
	record[0][turn] = 0;
	record[1][turn] = 0;
	map[x / unit][y / unit] = 0;               //清除最后一个子
	for (int i = 0; i <= turn - 1; i++)      //重画棋盘
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

void save()
{
	FILE *fout;
	fout = fopen("..\\save.txt", "w");             //将棋局信息存储到save.txt
	fprintf(fout, "%d\n", turn);                 //轮次信息
	for (int i = 0; i <= turn - 1; i++)
		fprintf(fout, "%d %d ", record[0][i], record[1][i]);    //下棋顺序及位置坐标
	for (int i = 1; i <= size; i++)            //棋盘信息
	{
		fprintf(fout, "\n");
		for (int j = 1; j <= size; j++)
			fprintf(fout, "%d ", map[i][j]);
	}
	fclose(fout);
}

void read()
{
	FILE *fin;
	fin = fopen("..\\save.txt", "r");   //读取save.txt中棋局信息
	fscanf(fin, "%d", &turn);
	for (int i = 0; i <= turn-1 ; i++)
		fscanf(fin, "%d%d", &record[0][i], &record[1][i]);
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			fscanf(fin, "%d", &map[i][j]);
	for (int i = 0; i <= turn-1; i++)               //根据棋局信息画子
	{
		if (i % 2 == 0)
			setfillcolor(BLACK);
		else
			setfillcolor(WHITE);
		circle(record[0][i], record[1][i], R);
		fillcircle(record[0][i],record[1][i],R);
	}
	fclose(fin);
}
void click()
{
	MOUSEMSG m;
	int x, y, p, q;
	while (true)
	{
		flag = 0;
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_RBUTTONDOWN:
		{
			regret();         //悔棋
			break;
		}
		case WM_LBUTTONDOWN:     //检测鼠标信息左键按下
		{
			if (m.x < 700)
			{
				x = m.x;
				y = m.y;

				if (x <= (blank_1 + unit / 2)) x = blank_1;           //棋盘位置坐标及像素坐标进行换算
				else
					x = ((x - unit / 2 - blank_1) / unit + 1)*unit + blank_1;

				if (y <= (blank_2 + unit / 2)) y = blank_2;
				else
					y = ((y - unit / 2 - blank_2) / unit + 1)*unit + blank_2;

				p = x / unit;
				q = y / unit;
				if (p < 1 || p>15 || q < 1 || q>15)
					break;
				if (turn % 2 == 0 && !map[p][q])
				{
					setfillcolor(BLACK);
					map[p][q] = 1;
					flag = 1;
				}

				else if (turn % 2 == 1 && !map[p][q])
				{
					setfillcolor(WHITE);
					map[p][q] = 2;
					flag = 1;
				}
				if (flag == 1)    //成功落子
				{
					circle(x, y, R);
					fillcircle(x, y, R);
					record[0][turn] = x;
					record[1][turn] = y;
					if (check(p, q))
					{

						flag = 1 + map[p][q];   //更新flag
						break;
					}
					turn++;   //更新轮次
				}
				break;
			}
			else if (m.x >= 954 && m.x <= 1156 && m.y >= 223 && m.y <= 291)   //悔棋
				regret();
			else if (m.x >= 886 && m.x <= 1088 && m.y >= 332 && m.y <= 396)   //认输
			{
				if (turn % 2 == 1)
				{
					flag = 2;
					break;
				}
				else
				{
					flag = 3;
					break;
				}
			}
			else if (m.x >= 818 && m.x <= 1018 && m.y >= 445 && m.y <= 508 || turn == (size*size - 1))    //和棋
			{
				MessageBox(NULL, TEXT("双方和棋！"), TEXT("五子棋Pro   --我嘞个栋"), MB_OK | MB_SETFOREGROUND);  //弹窗提示
				flag = -1;
				return;
			}
			else if (m.x >= 754 && m.x <= 950 && m.y >= 553 && m.y <= 618)   //返回
			{
				if (MessageBox(NULL, TEXT("确定退出此局？"), TEXT("五子棋Pro   --我嘞个栋"), MB_YESNO | MB_SETFOREGROUND) == IDYES)   //提示信息
				{
					flag = 5;
					return;
				}

			}
			else if (m.x >= 764 && m.x <= 858 && m.y >= 201 && m.y <= 255)         //  存档
			{
				save();
				MessageBox(NULL, TEXT("存档成功！"), TEXT("五子棋Pro   --我嘞个栋"), MB_OK | MB_SETFOREGROUND);  //提示信息
			}
		}
		}
		if (flag >= 2)
		{

			if (flag == 2)
				MessageBox(NULL, TEXT("恭喜黑棋获得胜利！"), TEXT("五子棋Pro   --我嘞个栋"), MB_OK | MB_SETFOREGROUND);
			else
				MessageBox(NULL, TEXT("恭喜白棋获得胜利！"), TEXT("五子棋Pro   --我嘞个栋"), MB_OK | MB_SETFOREGROUND);
			return;
		}

	}
	system("pause");
	closegraph();
}

