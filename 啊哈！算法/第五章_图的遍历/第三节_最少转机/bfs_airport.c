/*
使用广度优先搜索求转机次数最少，不考虑之间距离
*/
#include "stdio.h"
struct note
{
	int x;//城市编号
	int s;//转机次数
};
int main()
{
	struct note que[2501];
	int e[51][51] = {0},book[51] = {0};
	int head,tail;
	int i,j,n,m,a,b,cur,start,end,flag = 0;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	//初始化二维矩阵
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= n;j++)
		{
			if(i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 99999999;//我们这里假设99999999为正无穷大
			}
		}
	}

	//城市之间的航班
	for(i = 1;i <= m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1;//这里是无向图，所以e[b][a]也要赋值为1
	}

	//队列初始化
	head = 1;
	tail = 1;

	//从start号城市出发，将start号城市加入队列
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;//标记start号城市已在队列中

	//当队列不为空时循环
	while(head < tail)
	{
		cur = que[head].x;//当前队列中城市的编号
		for(j = 1; j <= n; j++)//从1~n依次尝试
		{
			//从城市cur到城市j是否有航班并且判断城市j是否已经在队列中
			if(e[cur][j] != 99999999 && book[j] == 0)
			{
				//如果从城市cur到城市j并且城市j不在队列中，则将j号城市入列
				que[tail].x = j;
				que[tail].s = que[head].s + 1;//转机次数加1
				tail++;
				//标记城市j已在队列中
				book[j] = 1;
			}
			//如果到达目标城市，停止扩展，任务结束，退出循环
			if(que[tail - 1].x == end)//tail表示最后一位的下一位，所以此处要减1 
			{
				//注意下面两句话的位置千万不能写颠倒了
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			break;
		}
		head++;//注意这地方，千万不能忘记当一个点扩展结束后，head++才能继续扩展
	}
	//打印队列中末尾最后一个(目标城市)的转机次数
	//注意tail指向的队列末尾(即最后一位)的下一个位置，所以这需要-1
	printf("%d",que[tail - 1].s );
	getchar();getchar();
	return 0;
}
/*
示例输入：
5 7 1 5   //5表示有5个城市(城市编号为1~5),7表示有7条航线，1表示起点城市，5表示目标城市
1 2 
1 3
2 3
2 4 
3 4
3 5
4 5
示例输出：
2
*/