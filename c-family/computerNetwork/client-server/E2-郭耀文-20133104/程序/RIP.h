#define RIP_SIZE 25
typedef struct RIP
{
	char destintion[4];
	int  distance;
	char next[4];
}Rip,* RipPoint;
void copyRip(RipPoint to,RipPoint from,const int length);
RipPoint initSer( int * lenth);

RipPoint initCli( int * lenth);

void change(RipPoint rp, int lenth, char * from);

int addOneItem(RipPoint rp, int * length, RipPoint oneRp);

int getTargetPosition(RipPoint rp, int length, char * destintion);

int merge(RipPoint ownRP,int ownLen,RipPoint getRP,int getLen);

void showRipTable(RipPoint rp,int length);
