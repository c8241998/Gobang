extern int turn, map[100][100];
extern int size;
extern int record[2][1000];
extern int music;
extern int flag;



void regret_ai(int first);   //�˻���ս��ʵ�ֻ��幦��

int value(int n, int x, int y);   //���������ĳ��ļ�ֵ

void AI();   //�˻���ս��������

int bestplace();  //ѡ��������ӵ�