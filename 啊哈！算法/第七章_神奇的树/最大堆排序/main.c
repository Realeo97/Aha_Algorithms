/*堆排序的时间复杂度和快速排序一样也是O(NlogN)*/
#include "stdio.h"
int h[101];//用来存放堆的数组
int n;//用来存储堆中元素的个数，也就是堆的大小

//交换函数，用来交换堆中两个元素的值
void swap(int x,int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
}

//向下调整函数
void siftdown(int i)//传入一个需要向下调整的节点编号i，这里传入1，即从堆的顶点开始向下调整
{
	int t,flag = 0;//flag用来标记算法需要继续向下调整
	//当i节点有儿子(其实是至少有左儿子)并且有需要继续调整的时候循环执行
	while(i * 2 <= n && flag == 0)
	{
		//首先判断它和左儿子的关系，并用t记录值较小的节点编号
		if(h[i] < h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		//如果它有右儿子，再对右儿子进行讨论
		if(i * 2 + 1 <= n)
		{
			//如果右儿子的值更小，更新较小的节点编号
			if(h[t] < h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}
		//如果发现最小的节点编号不是自己，说明子节点中有比父节点更小的
		if(t != i)
		{
			swap(t,i);//交换它们，注意swap需要自己来写
			i = t;//更新i为刚才与它交换的儿子节点的编号，便于接下来继续向下调整
		}
		else
		{
			flag = 1;//否则说明当前的父节点已经比两个儿子节点都要小了，不需要再进行调整了
		}
	}
	return;
}

//建立堆的函数
void creat()
{
	int i;
	//从最后一个非叶节点到第一个节点依次进行向下调整
	for(i = n / 2;i >= 1;i--)
	{
		siftdown(i);
	}
	return;
}

//堆排序
void heapsort()
{
	while(n > 1)
	{
		swap(1,n);
		n--;
		siftdown(1);
	}
	return;
}

int main()
{
	int i,num;
	//读入要排序的数字的个数
	scanf("%d",&num);

	for(i = 1;i <= num;i++)
	{
		scanf("%d",&h[i]);
	}
	n = num;

	//建堆
	creat();

	//堆排序
	heapsort();

	//输出
	for(i = 1;i <= num;i++)
	{
		printf("%3d",h[i]);
	}
	getchar();getchar();
	return 0;
}
/*
示例输入：
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
示例输出：
1 2 5 7 12 17 19 22 25 28 36 46 92 99
*/