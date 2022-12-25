/*
 * Thread.cpp
 *
 *  Created on: Jul 8, 2021
 *      Author: TEST
 */
#include "main.h"

#include"Sqlist.hpp"


extern "C" void StartDefaultTask(void *argument)
{
	Sqlist<int,100>	sqlisti; //顺序表对象sqlist的元素为整型

	int i,j,a[10]={2,3,5,7,11,13,17,19,23,29};

	for(j=0;j<10;j++)
	{
		if(!sqlisti.Insert(a[j],j))
		{
			//printf"数据太多表放不下！"
			break;
		}
	}
	sqlisti[10]=31;
	i=18;
	if(sqlisti.IsIn(i))
	//形参为引用，所以实参不可用整数常量
	{
		sqlisti.IsEmpty();
	}
	else
	{
		sqlisti.IsFull();
	}
}


