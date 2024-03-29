﻿/***
第四节 可变参模板
（4）可变参类模板：允许模板定义中包含0到多个（任意个）模板参数。
参数包展开方式有多种。介绍典型的展开方式。
（4.1）通过递归继承方式展开类型、非类型、模板模板参数包
1：类型模板参数包的展开一例
有时只写类模板声明而不写类模板定义的手法非常重要,靠这种手段能够帮助排错。
目前讲解的范例取材于C++标准库中的tuple(元组)
2：非类型模板参数包展开一例
3：模板模板参数包的展开一例
//ParentMM<int>
//ParentMM<int,deque>
//ParentMM<int,list,deque>
//ParentMM<int,vector,list,deque>
//myclasst3<int, vector, list, deque>
***/


#include <iostream>
#include <vector>
#include <list>
#include <deque>

//#include <boost/type_index.hpp>
using namespace std;
//#pragma warning(disable : 4996)

//非类型模板参数包展开一例
namespace _nmsp1
{
	//主模板定义（泛化版本的类模板）
	template <typename ...Args>
	class myclasst
	{
	public:
		myclasst()
		{
			printf("myclasst::myclasst()泛化版本执行了,this = %p\n", this);
		}
	};
	//template <typename ...Args>class myclasst; //主模板声明(前向声明/前置声明)

	template <typename First, typename ... Others>
	class myclasst<First, Others...> :private myclasst<Others...>  //偏特化
	{
	public:
		myclasst() :m_i(0)
		{
			printf("myclasst::myclasst()偏特化版本执行了，this = %p,sizeof...(Others)=%d\n", this, sizeof...(Others));
		}

		myclasst(First parf, Others... paro) :m_i(parf), myclasst<Others...>(paro...)
		{
			printf("myclasst::myclasst(parf,...paro)执行了,this = %p\n", this);
			cout << "m_i = " << m_i << endl;
		}
		
		First m_i;
	};

	template<>
	class myclasst<>    //一个特殊的特化版本,看起来象全特化,不是全特化,可变参模板不存在全特化
	{
	public:
		myclasst()
		{
			printf("myclasst::myclasst()特殊的特化版本执行了,this = %p\n", this);
		}
	};

	/*
	template <typename ...Args1, typename ... Args2>
	class myclasst2 {};
	
	template <typename ...Args, typename U>
	class myclasst3 {};
	*/
}

//类型模板参数包的展开一例
namespace _nmsp2
{
	//主模板定义(泛化版本的类模板)
	template <int ...FTArgs>            //int 替换为auto也可以
	class myclasst2
	{
	public:
		myclasst2()
		{
			printf("myclasst2::myclasst2()泛化版本执行了,this = %p\n", this);
		}
	};
	
	template <int First,int ...Others> //int替换成auto也没问题
	class myclasst2<First, Others...> :private myclasst2<Others...> //偏特化
	{
	public:
		myclasst2()
		{
			printf("myclasst2::myclasst2()偏特化版本执行了，this = %p,sizeof...(Others)=%d,First=%d\n", this, sizeof...(Others),First);
		}
	};

}

//模板模板参数包的展开一例
namespace _nmsp3
{
	//泛化版本
	template<typename T,
			 template<typename> typename... Container>
	class ParentMM
	{
	public:
		ParentMM()
		{
			printf("ParentMM::ParentMM()泛化版本执行了,this = %p\n", this);
		}
	};

	template<typename T,
		     template<typename> typename FirstContainer,
		     template<typename> typename... OtherContainers>
	class ParentMM<T, FirstContainer, OtherContainers...> :private ParentMM<T, OtherContainers...> //偏特化
	{
	public:
		ParentMM()
		{
			printf("ParentMM::ParentMM()偏特化版本执行了，this = %p,sizeof...(OtherContainers)=%d\n", this, sizeof...(OtherContainers));
			m_container.push_back(12);
		}

		FirstContainer<T>  m_container;
	};

	template<typename T,
		     template<typename> typename... Container>
	class myclasst3 :private ParentMM<T, Container...>
	{
	public:
		myclasst3()
		{
			printf("myclasst3::myclasst3()执行了，this = %p,T的类型是:%s，Container参数个数是%d个\n",
				   this, typeid(T).name(), sizeof...(Container));   //以后会用boost库中的type_id_with_cvr<.......>().pretty_name()。
		}
	};

}

int main()
{
	_nmsp1::myclasst<int, float, double> myc;
	//_nmsp1::myclasst<int, float, double> myc(12,13.5,23);

	_nmsp2::myclasst2<12, 18, 23> myc2;
	//_nmsp3::myclasst3<int, vector, list, deque> myc3;

	return 0;
}

