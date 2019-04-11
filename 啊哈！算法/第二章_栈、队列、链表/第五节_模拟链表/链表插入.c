/*
具体原理:
第一个整形数组data是用来存放序列中具体数字的，另外一个整形数组right用来存放
当前序列中每一个元素右边元素在数组data中的位置的。
*/

#include <stdio.h>
int main()
{
	int data[101],right[101];
	int i,n,t,len;
	//读入已有的数
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
		scanf("%d",&data[i]);
	len = n;
	//初始化数组right
	for(i = 1; i <= n; i++)
	{
		if(i != n)
			right[i] = i + 1;
		else
			right[i] = 0;
	}
	//直接在数组data的末尾增加一个数
	len++;
	scanf("%d",&data[len]);
	//从链表的头部开始遍历
	t = 1;
	while(t != 0)
	{
		if(data[right[t]] > data[len])//如果当前结点下一个结点的值大于待插入数，将数插入到中间
		{
			right[len] = right[t];//新插入数的下一个结点标号等于当前结点的下一个结点编号
			right[t] = len;//当前结点的下一个结点编号就是新插入数的编号
			break;//插入完成跳出循环
		}
		t = right[t];//实现往后查找
	}
	//输出链表中所有的数
	t = 1;
	while(t != 0)
	{
		printf("%d ",data[t]);
		t = right[t];
	}
	getchar();
	getchar();
	return 0;
}
/************************************************
 示例输入：                                     *
	9 											*
	2 3 5 8 9 10 18 26 32 						*
	6					                	    *
示例输出：                                      *
	2 3 5 6 8 9 10 18 26 32         		    *
*************************************************/