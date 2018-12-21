#include "service.h"
#include "person.h"
#include "computer.h"

int check(int p, int q)       //����Ƿ�Ӯ��
{
	int now = map[p][q];        // (p,q)��Ӧ������ɫ
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
	if (turn == 0) return;         //����״̬���ܻ���
	board();
	int x, y;
	turn--;
	x = record[0][turn];
	y = record[1][turn];
	record[0][turn] = 0;
	record[1][turn] = 0;
	map[x / unit][y / unit] = 0;               //������һ����
	for (int i = 0; i <= turn - 1; i++)      //�ػ�����
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
	fout = fopen("..\\save.txt", "w");             //�������Ϣ�洢��save.txt
	fprintf(fout, "%d\n", turn);                 //�ִ���Ϣ
	for (int i = 0; i <= turn - 1; i++)
		fprintf(fout, "%d %d ", record[0][i], record[1][i]);    //����˳��λ������
	for (int i = 1; i <= size; i++)            //������Ϣ
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
	fin = fopen("..\\save.txt", "r");   //��ȡsave.txt�������Ϣ
	fscanf(fin, "%d", &turn);
	for (int i = 0; i <= turn-1 ; i++)
		fscanf(fin, "%d%d", &record[0][i], &record[1][i]);
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			fscanf(fin, "%d", &map[i][j]);
	for (int i = 0; i <= turn-1; i++)               //���������Ϣ����
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
			regret();         //����
			break;
		}
		case WM_LBUTTONDOWN:     //��������Ϣ�������
		{
			if (m.x < 700)
			{
				x = m.x;
				y = m.y;

				if (x <= (blank_1 + unit / 2)) x = blank_1;           //����λ�����꼰����������л���
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
				if (flag == 1)    //�ɹ�����
				{
					circle(x, y, R);
					fillcircle(x, y, R);
					record[0][turn] = x;
					record[1][turn] = y;
					if (check(p, q))
					{

						flag = 1 + map[p][q];   //����flag
						break;
					}
					turn++;   //�����ִ�
				}
				break;
			}
			else if (m.x >= 954 && m.x <= 1156 && m.y >= 223 && m.y <= 291)   //����
				regret();
			else if (m.x >= 886 && m.x <= 1088 && m.y >= 332 && m.y <= 396)   //����
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
			else if (m.x >= 818 && m.x <= 1018 && m.y >= 445 && m.y <= 508 || turn == (size*size - 1))    //����
			{
				MessageBox(NULL, TEXT("˫�����壡"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);  //������ʾ
				flag = -1;
				return;
			}
			else if (m.x >= 754 && m.x <= 950 && m.y >= 553 && m.y <= 618)   //����
			{
				if (MessageBox(NULL, TEXT("ȷ���˳��˾֣�"), TEXT("������Pro   --���ϸ���"), MB_YESNO | MB_SETFOREGROUND) == IDYES)   //��ʾ��Ϣ
				{
					flag = 5;
					return;
				}

			}
			else if (m.x >= 764 && m.x <= 858 && m.y >= 201 && m.y <= 255)         //  �浵
			{
				save();
				MessageBox(NULL, TEXT("�浵�ɹ���"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);  //��ʾ��Ϣ
			}
		}
		}
		if (flag >= 2)
		{

			if (flag == 2)
				MessageBox(NULL, TEXT("��ϲ������ʤ����"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);
			else
				MessageBox(NULL, TEXT("��ϲ������ʤ����"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);
			return;
		}

	}
	system("pause");
	closegraph();
}

