#include "service.h"
#include "person.h"
#include "computer.h"

void start()
{
	mciSendString(TEXT("open ..\\���۳���.mp3 alias mymusic"), NULL, 0, NULL);    //�������ļ�
	if (music == 1)
	{
		mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);     //�������� 
		loadimage(NULL, TEXT("..\\����on.jpg"));
	}

	else
	{
		mciSendString(_T("close mymusic"), NULL, 0, NULL);             //ֹͣ����
		loadimage(NULL, TEXT("..\\����off.jpg"));
	}
}

void init()
{
	turn = 0;                             //��ʼ��
	memset(map, 0, sizeof(map));
	memset(record, 0, sizeof(record));
}
void board()
{
	IMAGE wallpaper;
	loadimage(&wallpaper, TEXT("..\\1.jpg"));
	putimage(0, 0, &wallpaper);
}