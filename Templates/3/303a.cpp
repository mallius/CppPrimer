#include <iostream>
#include <initializer_list>
#include <boost/type_index.hpp>

using namespace std;
//#pragma warning(disable : 4996) 

//函数模板
//template <typename T,unsigned L1> //L1就是数组长度
template <typename T>
//void myfunc(T&& tmprv) 
void myfunc(T  tmprv)
//void myfunc(T (&tmprv)[L1] )
//void myfunc(std::initializer_list<T>  tmprv)
{
	cout << "~~~" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<T>().pretty_name() << endl; //显示T的类型
	cout << "tmprv=" << type_id_with_cvr<decltype(tmprv)>().pretty_name() << endl; //显示tmprv的类型
	cout << "---" << endl;

	//tmprv = nullptr;
	//*tmprv = 'Y'; //编译报错：error C3892: “tmprv”: 不能给常量赋值

	//tmprv = 12;
	//int& tmpvaluec = tmprv;
	//tmpvaluec = 1200;

	//cout << L1 << endl;
}

template <typename T>
//void tf(const T& tmprv) //这里把auto替换成T,xy就相当于这里的tmprv
void tf(T&& tmprv)
{
	cout << "~~~~~~" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<T>().pretty_name() << endl; //显示T的类型
	cout << "tmprv=" << type_id_with_cvr<decltype(tmprv)>().pretty_name() << endl; //显示tmprv的类型
	cout << "------" << endl;
}

void testFunc() {}

int main()
{ 	
	/*(2.1)引用或指针类型*/
	int i = 18;       //i的类型是int
	const int j = i;  //j的类型是const int
	const int& k = i; //k的类型是const int &
	
	myfunc(i);        //T = int & ，tmprv = int &
	myfunc(j);        //T = int const & ,tmprv = int const &
	myfunc(k);        //T = int const & ,tmprv = int const &
	myfunc(100);      //T = int ,tmprv = int &&
	

	/*
	int i = 18;       //i的类型是int
	const int j = i;  //j的类型是const int
	const int& k = i; //k的类型是const int &
	myfunc(i);        //T = int  ，tmprv = int 
	myfunc(j);        //T = int  ，tmprv = int 
	myfunc(k);        //T = int  ，tmprv = int 
	*/

	//int& m = i;	
	//myfunc<int &>(m);

	
	char mystr[] = "I Love China";
	
	//第一个const表示p指向的目标中的内容不能通过p改变
	//第二个const表示p指向一个内容后，p不可以再指向其他内容（p不可以指向不同目标）
	const char* const p = mystr; 
	                             
	//T = char const *, tmprv=char const * ，传递给myfunc后，第二个const没有了，第一个const是保留的。
	//这表示进入到myfunc函数模板内部后，tmprv指向的内容不能通过tmprv改变，但是tmprv可以指向其他内存地址。
	//也就是说tmprv(p)的常量性被忽略了，而tmprv（p）所指向的内容的常量性会被保留。 
	//结论记一下：如果传递的是const char *或者const char[],这个const会被保留。
	myfunc(p);
	

	
	int m = 180;
	myfunc(std::ref(m)); //std::ref和std::cref象对象包装器，编译器通过创建一个 class std::reference_wrapper<T>类型的对象
	                      //T=class std::reference_wrapper<int> ,tmprv=class std::reference_wrapper<int>
	cout << "m=" << m << endl;
	

	/*
	const char mystr[] = "I Love China!";
	myfunc(mystr); //T=char const *  , tmprv=char const *
	*/
	/*
	const char mystr[] = "I Love China!";
	myfunc(mystr); //T=char const [14],tmprv=char const (&)[14]--(&)代表数组的一个引用。
	*/

	//myfunc(testFunc); //T=void (__cdecl*)(void),tmprv=void (__cdecl*)(void)
	//myfunc(testFunc); //T=void __cdecl(void),tmprv=void (__cdecl&)(void)——tmprv是一个函数引用类型：void(&)(void)

	//myfunc({1,2,3}); //T=int,tmprv=class std::initializer_list<int>


	//（3）auto类型常规推断:用于变量的自动类型推断
	//auto有一个类型，x也有 一个类型。x =int ,auto = int。
	auto x = 27;            //x = int,auto =int
	const auto x2 = x;      //估计x2 = const int,auto =int
	const auto& xy = x;     //这个auto并不是传值方式，估计xy = const int &，auto = int
	auto xy2 = xy;          //估计xy2 = int,auto =int;。

	using boost::typeindex::type_id_with_cvr;	
	cout << "xy2=" << type_id_with_cvr<decltype(xy2)>().pretty_name() << endl; 

	tf(x);                //实参中给的是x；  T=int，tmprv=int const &

	auto& xy3 = xy;         //估计：xy3 = const int &,auto = const int。针对auto类型：引用会被丢弃，const属性会被保留。
	auto y = new auto(100); //估计：y = int *，auto = int *，auto可以用于new。
	const auto* xp = &x;    //估计：xp = cont int *,auto = int
	auto* xp2 = &x;         //估计：xp2 = int *,auto = int
	auto xp3 = &x;          //估计：xp3 = int *，auto = int * ，xp3不声明为指针，也能推导出指针类型。
	
	auto&& wnyy0 = 222;     //估计：万能引用，222是右值，auto = int,wnyy0 = int &&（右值引用类型）
	auto&& wnyy1 = x;       //估计：万能引用，x是左值，所以：auto  = int &，wnyy1 = int &。
	auto&& wnyy2 = x2;      //编译器推断：auto = int const &，wnyy2 = int const &。
	tf(x2);

	return 0;
}


