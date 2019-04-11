/*对所有的边进行n-1次的松弛操作
检测一个图是否有负权回路：如果在n-1松弛之后最短路仍然会发生变化，则改图必然存在负权回路
在实际操作中，Bellman-Ford算法经常会在未达到n-1轮松弛前就已经计算出最短路，n-1其实是最大值
因此可以添加一个变量check用来标记数组dis在本轮松弛中是否发生了变化，如果没有发生变化，则可以提前跳出循环
*/
#include "stdio.h"
int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10],check,flag;
	int inf = 99999999;//用inf(infinity的缩写)存储一个我们认识的无穷大
	//读入n和m，n表示顶点个数，m表示边的条数
	scanf("%d %d",&n,&m);

	//读入边
	for(i = 1;i <= m;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}

	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
	for(i = 1;i <= n;i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	//Bellman-Ford算法核心语句
	for(k = 1;k <= n - 1;k++)
	{
		check = 0;//用来标记在本轮松弛中数组dis是否会发生更新
		//进行一轮松弛
		for(i = 1;i <= m;i++)
		{
			if(dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;//数组dis发生更新，改变check的值
			}
		}
		//松弛完毕后检测数组dis是否有更新
		if(check == 0)
		{
			break;//如果数组dis没有更新，提前退出循环结束算法
		}
	}
	//检测负权回路
	flag = 0;
	for(i = 1;i <= m;i++)
	{
		if(dis[v[i]] > dis[u[i]] + w[i])
		{
			flag = 1;
		}	
	}
	if(flag == 1)
	{
		printf("此图含有负权回路" );
	}
	else
	{
		//输出最终结果
		for(i = 1;i <= n;i++)
		{
			printf("%4d",dis[i]);
		}
	}
	getchar();getchar();
	return 0;
}
/*
示例输入：
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
示例输出：
0 -3 -1 2 4
*/