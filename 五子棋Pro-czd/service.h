#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<mmsystem.h>  
#pragma comment (lib,"Winmm.lib")
#define R 13
#define unit 41
#define unit_ai 42
#define blank_1 71
#define blank_2 69
#define blank_3 67
#define blank_4 66

extern int turn, map[100][100];
extern int size;
extern int record[2][1000];
extern int music;
extern int flag;

void start();   //�����Ƿ񲥷����ּ������˵�����

void init();    //��ʼ��������Ϣ

void board();   //�������˶�ս������