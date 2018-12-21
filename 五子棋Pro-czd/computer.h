extern int turn, map[100][100];
extern int size;
extern int record[2][1000];
extern int music;
extern int flag;



void regret_ai(int first);   //人机对战中实现悔棋功能

int value(int n, int x, int y);   //计算棋局中某点的价值

void AI();   //人机对战的主函数

int bestplace();  //选择最佳落子点