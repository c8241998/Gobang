#include "service.h"
#include "person.h"
#include "computer.h"
int turn = 0;                     //turn ���ִμ���
int map[100][100] = { 0 };        //���������¼�����Ϣ  0���� 1���� 2����
int size = 15;                    //���̱߳���С
int record[2][1000] = { 0 };      //��������˳���¼��� �洢����λ�õ�����
int music = 1;                    //���ֲ��ű�ʶ�� 1���� -1ֹͣ����  ��Ĭ�ϲ��ţ�
int flag = 0;
//                flag ��ʶ��    -3 �û�Ӯ�壨�˻��� -2 ����Ӯ�壨�˻��� 
//                               -1 ���壨���ˣ�  1 �ɹ����壨���ˣ�  2 ����ʤ�����ˣ� 3 ����ʤ�����ˣ�  4 ����һ�֣����ˣ�  5 �˳��˾֣�����&�˻���

int main()
{
	IMAGE img;
	initgraph(1220, 720);              //��ʼ��ͼ�ν���  1220*720
	start();                           //�������˵�
	//MessageBox(NULL, TEXT("��ӭʹ��������Pro"), TEXT("������Pro   --���ϸ���"), MB_OK | MB_SETFOREGROUND);             //������ӭ
	
	while (1)
	{
		start();
		Sleep(10);

		int menu = 0;          //��ʶ��    ��¼�Ƿ���ʾ������
		while (1)
		{
			if (menu) break;       //��ʶ��Ϊ1 ����ѭ�� ��ʾ������
			MOUSEMSG m;
			m = GetMouseMsg();     //��¼�����Ϣ
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:    // ��⵽�������
			{
				if (m.x >= 712 && m.x <= 1171 && m.y >= 303 && m.y <= 367||flag==-1||flag==4)         //  ���˶�ս
				{
					loadimage(&img, _T("..\\flash1.jpg"));
					putimage(700, 270, &img);
					Sleep(50);
					init();    //��ʼ��
					board();   //��������
					click();   //���˶�ս����
					if (flag == 5)         //��⵽���ؼ� �˳����
					{
						menu = 1;
						break;
					}
					if (MessageBox(NULL, TEXT("�Ƿ�����һ��"), TEXT("������Pro   --���ϸ���"), MB_YESNO | MB_SETFOREGROUND) == IDNO)  //��ֽ��� ѯ���Ƿ�����һ��
					{
						menu = 1;
						break;
					}
					else flag=4;   //����һ��
				}

				if (m.x >= 712 && m.x <= 1171 && m.y >= 369 && m.y <= 437)    //�˻���ս
				{
					loadimage(&img, _T("..\\flash2.jpg"));
					putimage(700, 270, &img);
					Sleep(40);
					while (1)
					{
						init();       //��ʼ��
						loadimage(NULL, TEXT("..\\�˻�.jpg"));       //��������
						if (MessageBox(NULL, TEXT("�Ƿ�����"), TEXT("������Pro   --���ϸ���"), MB_YESNO | MB_SETFOREGROUND) == IDYES)   //�û�����
							turn = 1;
						else turn = 0;             //��������

						AI();		//�˻���ս������

						if (flag == 5)		//�˳��˾�
						{
							menu = 1;
							break;
						}
						if (MessageBox(NULL, TEXT("�Ƿ�����һ��"), TEXT("������Pro   --���ϸ���"), MB_YESNO | MB_SETFOREGROUND) == IDNO)	//��ֽ��� ѯ���Ƿ�����һ��
						{
							menu = 1;
							break;
						}
					}
				}

				if (m.x >= 712 && m.x <= 1171 && m.y >= 448 && m.y <= 509 || flag == -1)            //���ش浵
				{
					loadimage(&img, _T("..\\flash3.jpg"));
					putimage(700, 270, &img);
					Sleep(50);
					board();		//��������
					read();			//��ȡ�����Ϣ

					click();		//���˶�ս��ʼ

					if (flag == 5)		//�˳��˾�
					{
						menu = 1;
						break;
					}
					if (MessageBox(NULL, TEXT("�Ƿ�����һ��"), TEXT("������Pro   --���ϸ���"), MB_YESNO | MB_SETFOREGROUND) == IDNO) //��ֽ��� ѯ���Ƿ�����һ��
					{
						menu = 1;
						break;
					}
					else flag = 4;			//����һ��
				}

				if (m.x >= 712 && m.x <= 1171 && m.y >= 512 && m.y <= 580)		//������Ϣ
				{
					loadimage(&img, _T("..\\flash4.jpg"));
					putimage(700, 270, &img);
					Sleep(50);
					loadimage(NULL, _T("..\\������Ϣ.jpg"));			//���ذ�����Ϣҳ��
					while (1)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
							if (m.x >= 925 && m.x <= 1081 && m.y >= 577 && m.y <= 627)		//���ؼ�
						{
							menu = 1;
							break;
						}
					}
					if (menu) break;
				}
				if (m.x >= 712 && m.x <= 1171 && m.y >= 586 && m.y <= 645)		//���ֲ���&��ͣ
				{
					music = -music;		//��ʶ���л�
					if (music == -1)
					{
						mciSendString(_T("stop mymusic"), NULL, 0, NULL);    //ֹͣ����
						
					}
					if (music == 1)
					{
						mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);   //����ѭ������
					}
					if (music==1) loadimage(NULL, TEXT("..\\����on.jpg"));  //�������˵�
					else loadimage(NULL, TEXT("..\\����off.jpg"));          //�������˵�
					menu = 1;
				}
				break;
			}
			}

		}
	}
	
}