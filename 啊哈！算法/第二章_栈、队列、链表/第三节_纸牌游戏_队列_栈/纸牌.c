/*队列、栈的综合应用*/

/*
游戏规则：
将一副扑克牌平均分成两份，每人各拿一份。小哼拿出第一张扑克牌放在桌上，然后小哈也拿出手中的第一张扑克牌，
并放在小哼刚打出的扑克牌的上面，就像这样两人交替出牌。出牌时，如果某人打出的牌与桌上的某张牌的牌面相同时，
即可将两张相同牌及其中间所夹牌全部取走，并依次放到自己手中牌的末尾。当任意一人手中的牌全部取出时，游戏结束，对手获胜。
*/

/********************************************
示例输入：									*
	2 4 1 2 5 6								*
	3 1 3 5 6 4								*
示例输出：									*
	小哼win									*
	小哼当前手中的牌是 5 6 2 3 1 4 6 5		*
	桌上的牌是 2 1 3 4						*
********************************************/
#include <stdio.h>
struct queue//队列 
{
	int data[1000];
	int head;
	int tail;
};//不要忘记分号

struct stack//堆栈 
{
	int data[10];
	int top;
};

int main()
{
	struct queue q1,q2;
	struct stack s;
	int book[10];
	int i,t;

	//初始化队列
	q1.head=1; q1.tail=1;//小哼
	q2.head=1; q2.tail=1;//小哈
	//初始化栈过·		
	s.top=0;
	//初始化用来标记的数组，用来标记哪些牌已经在桌上
	for(i=1;i<=9;i++)
		book[i]=0;//初始化桌面尚还未有任何牌 
	//依次向队列插入6个数
	//小哼手上的6张牌
	for(i=1;i<=6;i++)
	{
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	//小哈手上的6张牌
	for(i=1;i<=6;i++)
	{
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}

	//开始游戏
	while(q1.head < q1.tail && q2.head < q2.tail ) //当队列不为空的时候执行循环，即两者手上都有牌
	{
		t = q1.data[q1.head];//小哼出一张牌
		//判断小哼当前打出的牌是否能赢牌
		if(book[t]==0) //表明桌上没有牌面为t的牌
		{
			//小哼此轮没有赢牌
			q1.head++; //小哼已经打出一张牌，所以要把打出的牌出队
			s.top++;//桌面多一张牌 
			s.data[s.top] = t; //再把打出的牌放到桌上，即入栈
			book[t] = 1; //标记桌上现在已经有牌面为t的牌
		}
		else
		{
			//小哼此轮可以赢牌
			q1.head++;//小哼已经打出一张牌，所以要把打出的牌出队
			q1.data[q1.tail] = t;//紧接着把打出的牌放到手中牌的末尾
			q1.tail++;//小哼打出的牌放在手牌后 
			while(s.data[s.top] != t) //把桌上可以赢得的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]] = 0;//拿走的牌取消标记
				q1.data[q1.tail] = s.data[s.top];//依次放入队尾
				q1.tail++;//从桌面上赢取牌 
				s.top--; //桌面上少一张牌，即栈中少了一张牌，所以栈顶要减1
			}
		}
		t = q2.data[q2.head]; //小哈出一张牌
		//判断小哈当前打出的牌是否能赢牌
		if(book[t] == 0) //表明桌上没有牌面为t的牌
		{
			//小哈此轮没有赢牌
			q2.head++; //小哈已经打出一张牌，所以要把打出的牌出队
			s.top++;//桌面上增加一张牌 
			s.data[s.top] = t; //再把打出的牌放到桌上，即入栈
			book[t] = 1; //标记桌上现在已经有牌面为t的牌
		}
		else
		{
			//小哈此轮可以赢牌
			q2.head++;//小哈已经打出一张牌，所以要把打出的牌出队
			q2.data[q2.tail] = t;//紧接着把打出的牌放到手中牌的末尾
			q2.tail++;//小哈把打出的牌放在手牌末尾 
			while(s.data[s.top] != t) //把桌上可以赢得的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]] = 0;//取消拿走牌的标记
				q2.data[q2.tail] = s.data[s.top];//依次放入队尾
				q2.tail++;//小哈手牌加1 
				s.top--;//桌面上牌数减1 
			}
		}
	}
	if(q2.head == q2.tail)//小哈手中没有牌了 
	{
		printf("小哼win\n");
		printf("小哼当前手中的牌是");
		for(i = q1.head; i <= q1.tail - 1; i++)//此处tail-1因为tail表示队列最后一位的下一位 
			printf(" %d",q1.data[i]);
		if(s.top > 0) //如果桌上有牌则依次输出桌上的牌
		{
			printf("\n桌上的牌是");
			for(i = 1; i <= s.top; i++)
				printf(" %d",s.data[i]);
		}
		else
			printf("\n桌上已经没有牌了");
	}
	else//小哼手中没有牌了 
	{
		printf("小哈win\n");
		printf("小哈当前手中的牌是");
		for(i = q2.head; i <= q2.tail - 1; i++)
			printf(" %d",q2.data[i]);
		if(s.top > 0) //如果桌上有牌则依次输出桌上的牌
		{
			printf("\n桌上的牌是");
			for( i =1; i<= s.top; i++)
				printf(" %d",s.data[i]);
		}
		else
			printf("\n桌上已经没有牌了");
	}
	getchar();getchar();
	return 0;
}
