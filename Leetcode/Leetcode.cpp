// Leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include "百鸡问题.h"
#include "selectsort.h"
#include "bubblesort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "horner.h"
#include "insertsort.h"
#include "pack.h"

void sort_test() {
	int a[] = { 6,32,4,73,2,1 ,9,12 };
	// 选择排序
	SelectSort(a, 6);

	// 冒泡排序
	BubbleSort(a, 6);

	// 归并排序
	mergeSort(a, 0, 7);

	// 堆排序
	HeapSort(a, 8);

	// 插入排序
	insertsort(a, 8);

	// 快速排序


	for (int i = 0;i < 8;i++) {
		printf("%d\n", a[i]);
	}
}

int main()
{
	
	return 0;
}





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
