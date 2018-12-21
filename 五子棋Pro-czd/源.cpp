#include "service.h"
#include "person.h"
#include "computer.h"
int turn = 0;                     //turn 对轮次计数
int map[100][100] = { 0 };        //根据坐标记录棋局信息  0无子 1黑子 2白子
int size = 15;                    //棋盘边长大小
int record[2][1000] = { 0 };      //根据下子顺序记录棋局 存储下子位置的坐标
int music = 1;                    //音乐播放标识符 1播放 -1停止播放  （默认播放）
int flag = 0;
//                flag 标识符    -3 用户赢棋（人机） -2 电脑赢棋（人机） 
//                               -1 和棋（人人）  1 成功下棋（人人）  2 黑棋胜（人人） 3 白棋胜（人人）  4 再来一局（人人）  5 退出此局（人人&人机）

int main()
{
	IMAGE img;
	initgraph(1220, 720);              //初始化图形界面  1220*720
	start();                           //加载主菜单
	//MessageBox(NULL, TEXT("欢迎使用五子棋Pro"), TEXT("五子棋Pro   --我嘞个栋"), MB_OK | MB_SETFOREGROUND);             //弹窗欢迎
	
	while (1)
	{
		start();
		Sleep(10);

		int menu = 0;          //标识符    记录是否显示主界面
		while (1)
		{
			if (menu) break;       //标识符为1 跳出循环 显示主界面
			MOUSEMSG m;
			m = GetMouseMsg();     //记录鼠标信息
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:    // 检测到左键按下
			{
				if (m.x >= 712 && m.x <= 1171 && m.y >= 303 && m.y <= 367||flag==-1||flag==4)         //  人人对战
				{
					loadimage(&img, _T("..\\flash1.jpg"));
					putimage(700, 270, &img);
					Sleep(50);
					init();    //初始化
					board();   //加载棋盘
					click();   //人人对战函数
					if (flag == 5)         //检测到返回键 退出棋局
					{
						menu = 1;
						break;
					}
					if (MessageBox(NULL, TEXT("是否再玩一局"), TEXT("五子棋Pro   --我嘞个栋"), MB_YESNO | MB_SETFOREGROUND) == IDNO)  //棋局结束 询问是否再玩一局
					{
						menu = 1;
						break;
					}
					else flag=4;   //再来一局
				}

				if (m.x >= 712 && m.x <= 1171 && m.y >= 369 && m.y <= 437)    //人机对战
				{
					loadimage(&img, _T("..\\flash2.jpg"));
					putimage(700, 270, &img);
					Sleep(40);
					while (1)
					{
						init();       //初始化
						loadimage(NULL, TEXT("..\\人机.jpg"));       //加载棋盘
						if (MessageBox(NULL, TEXT("是否先行"), TEXT("五子棋Pro   --我嘞个栋"), MB_YESNO | MB_SETFOREGROUND) == IDYES)   //用户先行
							turn = 1;
						else turn = 0;             //电脑先行

						AI();		//人机对战主函数

						if (flag == 5)		//退出此局
						{
							menu = 1;
							break;
						}
						if (MessageBox(NULL, TEXT("是否再玩一局"), TEXT("五子棋Pro   --我嘞个栋"), MB_YESNO | MB_SETFOREGROUND) == IDNO)	//棋局结束 询问是否再玩一局
						{
							menu = 1;
							break;
						}
					}
				}

				if (m.x >= 712 && m.x <= 1171 && m.y >= 448 && m.y <= 509 || flag == -1)            //加载存档
				{
					loadimage(&img, _T("..\\flash3.jpg"));
					putimage(700, 270, &img);
					Sleep(50);
					board();		//加载棋盘
					read();			//读取棋局信息

					click();		//人人对战开始

					if (flag == 5)		//退出此局
					{
						menu = 1;
						break;
					}
					if (MessageBox(NULL, TEXT("是否再玩一局"), TEXT("五子棋Pro   --我嘞个栋"), MB_YESNO | MB_SETFOREGROUND) == IDNO) //棋局结束 询问是否再玩一局
					{
						menu = 1;
						break;
					}
					else flag = 4;			//再玩一局
				}

				if (m.x >= 712 && m.x <= 1171 && m.y >= 512 && m.y <= 580)		//帮助信息
				{
					loadimage(&img, _T("..\\flash4.jpg"));
					putimage(700, 270, &img);
					Sleep(50);
					loadimage(NULL, _T("..\\帮助信息.jpg"));			//加载帮助信息页面
					while (1)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
							if (m.x >= 925 && m.x <= 1081 && m.y >= 577 && m.y <= 627)		//返回键
						{
							menu = 1;
							break;
						}
					}
					if (menu) break;
				}
				if (m.x >= 712 && m.x <= 1171 && m.y >= 586 && m.y <= 645)		//音乐播放&暂停
				{
					music = -music;		//标识符切换
					if (music == -1)
					{
						mciSendString(_T("stop mymusic"), NULL, 0, NULL);    //停止播放
						
					}
					if (music == 1)
					{
						mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);   //单曲循环播放
					}
					if (music==1) loadimage(NULL, TEXT("..\\音乐on.jpg"));  //加载主菜单
					else loadimage(NULL, TEXT("..\\音乐off.jpg"));          //加载主菜单
					menu = 1;
				}
				break;
			}
			}

		}
	}
	
}