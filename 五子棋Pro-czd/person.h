extern int turn, map[100][100];
extern int size;
extern int record[2][1000];
extern int music;
extern int flag;


int check(int p, int q);  //检查棋局中是否出现五子连珠

void regret();            //实现人人对战中的悔棋功能

void click();             //人人对战的主函数

void save();              //保存当前棋局

void read();			  //读取txt中存档