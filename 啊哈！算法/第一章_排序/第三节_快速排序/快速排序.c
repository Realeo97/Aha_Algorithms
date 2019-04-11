/**********************************************************************************************************
关键字：基准数，先从右找比基准数小的数，再从左往右找比基准数大的数，交换。当左右相遇则相遇点与基准数交换。*
因此快速排序的最差时间复杂度和冒泡排序是一样的，都是 O(N2)，											  *
它的平均时间复杂度为 O (NlogN)。                                                                          *
其实快速排序是基于一种叫做“二分”的思想。                                                                  *
示例输入：                                                                                                *
	10                                                                                                    *
	6 1 2 7 9 3 4 5 10 8                                                                                  *
示例输出：                                                                                                *
	1 2 3 4 5 6 7 8 9 10                                                                                  *
***********************************************************************************************************/
#include<stdio.h>
int arry[101],num;//定义全局变量，这两个变量需要在子函数中使用

void quicksort(int left,int right)
{
	//例：第一趟前数据 6 1 2 7 9 3 4 5 10 8 
	int basic_num,left_b,right_b,temp;
	if(left > right)
	{
		return;
	}

	basic_num = arry[left];//以最左端的数作为基数
	left_b = left;//左侧哨兵找大于基数的数
	right_b = right;//右侧哨兵找小于基数的数
	while (left_b != right_b)//哨兵不碰面就继续寻找
	{
		while(arry[right_b] >= basic_num && right_b > left_b)//先右侧哨兵开始寻找小于基数的数，寻找条件：大于基数且位置大于左哨兵
		{
			right_b--;//右侧哨兵左移
		}
		while(arry[left_b] <= basic_num && left_b < right_b)//后左侧哨兵开始寻找大于基数的数
		{
			left_b++;//左侧哨兵右移
		}
		if (left_b < right_b)//各自寻找到目标后，只要左侧哨兵未与右侧哨兵碰面则交换两个哨兵寻得的数
		{
			temp = arry[left_b];
			arry[left_b] = arry[right_b];
			arry[right_b] = temp;
		}	
	}
	//两个哨兵碰面后基数与碰面所在的数交换
	arry[left] = arry[left_b];
	arry[left_b] = basic_num;
	//递归使得第一次交换后形成的以第一次基数为分割的两个序列如：3 1 2 5 4 6 9 7 10 8
	quicksort(left,left_b - 1);//基数6左侧的序列继续以3为基数继续探测
	quicksort(right_b + 1,right);//基数6右侧的序列继续以9为基数继续探测
	return;
}
int main ()
{
	int i;
	scanf("%d", &num);//输入排列数的个数
	for ( i = 1; i <= num; i++)
	{
		scanf("%d", &arry[i]);
	}
	quicksort(1,num);//调用快速排序子程序
	for ( i = 1; i <= num; i++)
	{
		printf("%d ",arry[i] );
	}
	getchar();getchar();
	return 0;
}
