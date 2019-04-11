/*
多源最短路径：求任意两个点之间的路径
核心代码只有五行：
for(k = 1;k <= n;k++)
	for(i = 1;i <= n;i++)
		for(j = 1;j <= n;j++)
			if(e[i][j] > e[i][k] + e[k][j])
				e[i][j] = e[i][k] + e[k][j];
基本思想：最开始只允许经过1过一号顶点进行中转，接下来只允许经过1号和2号进行中转。。。允许经过1~n号所有顶点进行中转，
求任意两点之间的最短路径。用一句话概括就是：从i号顶点到j号顶点只经过前k号顶点的最短路程，是一种“动态规划”的思想
*/
#include "stdio.h"
int main()
{
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf = 99999999;//用inf(infinity的缩写)存储一个我们认识的正无穷
	//读入n和m,n表示顶点个数，m表示边的条数
	scanf("%d %d",&n,&m);

	//初始化
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
				e[i][j] = inf;
			}
		}
	}

	//读入边
	for(i = 1; i <= m; i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2] = t3; 
	}

	//Floyd-Warshall算法核心语句
	for(k = 1; k <= n; k++)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	//输出最终结果
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			printf("%3d",e[i][j]);
		}
		printf("\n");
	}
	getchar();getchar(); 
	return 0;
}
/*
示例输入：
4 8         //第一行数位n和m，n表示顶点个数，m表示边的条数
1 2 2       //分别为t1，t2，t3表示顶点t1到顶点t2的路程是t3
1 3 6
1 4 4 
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
示例输出：
0 2 5 4
9 0 3 4
6 8 0 1
5 7 10 0
*/