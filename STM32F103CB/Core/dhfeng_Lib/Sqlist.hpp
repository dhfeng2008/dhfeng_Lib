/*
 * Sqlist.hpp
 *
 *  Created on: 2022年12月15日
 *      Author: Administrator
 */

#ifndef SQLIST_HPP_
#define SQLIST_HPP_

#include<stddef.h>

template<class T>
class Sqlist
{
public:
    Sqlist(int size)
    {
        last=-1;
        Maxsize=size;
    }//初始化为空表
    int   Length()const;  //计算表长度
    int   Locate(T& x)const;//寻找x在表中位置（下标）
    bool  IsIn(T& x);//判断x是否在表中
    bool  Insert(T& x,int i);//x插入到列表中第i个位置处（下标）
    bool  Remove(T& x); //删除x
    int   Next(T& x);//寻找x的后继位置
    int   Prior(T& x);//寻找下x的前驱位置
    bool  IsEmpty(){return last==-1;}//判断表是否空
    bool  IsFull(){return last==Maxsize-1;}//判断表是否满
    T     Get(int i){return (i<0)||(i>last)?NULL:slist[i];}
    T&    operator[](int i);//重载下标运算符[]
    bool  clear();
	int   list_delete(int pos);
    bool  empty();
	int   show();
	int   purge();//净化，去除相同的元素；
private:
	 T slist[Maxsize];   //存放顺序表的数组
	 int Maxsize;    //最大可容纳的项数
	 int last;       //已存表项的最后位置
};


template<class T,int size>
int Sqlist<T,size>::Length()const
{
	return last+1;
}

template<class T,int size>
int Sqlist<T,size>::Locate(T& x)const
{
    //注意格式：const表示该函数的this指针为常量指针，
    //即被访问对象的数据不能被修改，
    //如被修改，编译器会警告，防止编程时失误
    int i=0;
    while(i<=last&&slist[i]!=x)
    	i++;//顺序查找是否有x
    if(i>last)
    	return -1;//未找到，返回-1
    else
    	return i;//找到，返回下标
}

template<class T,int size>
bool Sqlist<T,size>::Insert(T& x,int i)
{
	int j;
	if((i<0)||(i>last+1)||(last==Maxsize-1)) //插入位置不合理，不能插入（稳健性）
		return false;
	else
	{
		last++;
		for(j=last;j>i;j--)
			slist[j]=slist[j-1];	//从表最后位置向前依次后移，空出指定位置
		slist[i]=x;

		return true;
	}
}

template<class T,int size>
bool Sqlist<T,size>::IsIn(T & x)
{
  int i=0;
  bool found=0;
  while(i<=last&&!found)//换了一种方法来查找
  {
	  if(slist[i]!=x)
		  i++;
	  else
		  found=1;	//找到
  }
  return found;
}


template<class T,int size>
bool Sqlist<T,size>::Remove(T & x)
{
	int i=Locate(x),j;//先去找x在哪个位置
	if(i>=0)
	{
		last--;
		for(j=i;j<=last;j++)
			slist[j]=slist[j+1];	//依次前移，保证表连续
		return true;
	}
	return false;//表中不存在x;
}

template<class T,int size>
int Sqlist<T,size>::Next(T & x)
{
	int i=Locate(x);
	if(i>=0&&i<last)
		return i+1;//x后继位置
	else
		return -1;//x不在表中，或在表末尾
}

template<class T,int size>
int Sqlist<T,size>::Prior(T & x)
{
	int i=Locate(x);
	if(i>0&&i<=last)
		return i-1;//x前驱位置
	else
		return -1;//x不在表中，或在表头
}

template<class T,int size>
T& Sqlist<T,size>::operator[](int i)
{
	if(i>last+1||i<0||i>=Maxsize)
	{
        //下标超出了范围；
		;
	}
	if(i>last)
		last++;	//下标运算符[],只能增加表的元素，不能减少；
	return slist[i];
}

template<class T,int size>
bool Sqlist<T,size>::clear()
{
	if(this==NULL)
		return -1;
	memset(this,0,sizeof(T)*size+sizeof(Maxsize));
		last=-1;
	return 0;
}

template<class T,int size>
bool Sqlist<T,size>::empty()
{
	if(last==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T,int size>
int Sqlist<T,size>::show()
{
	int i;
	if(this==NULL)
	{
		//printf("list is NULL\n");
		return -1;
	}
	if(last==-1)
	{
		//printf("list is empty\n");
	}
	for(i=0;i<=last;i++)
	{
		printf("%d",slist[i]);
	}
	//puts("");
	return 0;
}

template<class T,int size>
int   Sqlist<T,size>::list_delete(int pos)
{
	int i;
	if(last==-1)
	{
		//pritnf("list is empty\n");
		return -1;
	}
	//pos [0,last]
	if((pos<0)||(pos>last))
	{
		//printf("delete pos is invalid\n");
		return -1;
	}

	//move [pos+1,last]
	for(i=pos+1;i<=last;i++)
	{
		slist[i-1]=slist[i];
	}
}



template<class T,int size>
int  Sqlist<T,size>::purge()
{
	int i;
	int j;
	if(last==0)
	{
		return 0;
	}
	i=1;
	while(i<=last)
	{
		j=i-1;
		while(j>=0)
		{
			if(slist(j)==slist(i))
			{
//				list_delete(i)
				break;
			}
			else
			{
				j--;
			}
		}
		if(j<0)
		{
			i++;
		}
	}
	return 0;
}

class Int_Sqlist : public Sqlist<int,100>
{
public:
//	int  list_merge(Int_Sqlist& L)
//	{
//		int i=0;
//		int ret;
//		while(i<=L->last)
//		{
//			ret=Locate(L->slist(i));
//			if(ret==-1)
//			{
//				if(Insert(L->slist(i),last+1)==false);
//				{
//					return -1;
//				}
//			}
//			i++;
//		}
//		return 0;
//	}
};


#endif /* SQLIST_HPP_ */
