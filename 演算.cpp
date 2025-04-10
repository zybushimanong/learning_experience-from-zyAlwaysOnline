//所有运算符重载
# include <iostream>
using namespace std;

class Person
{
public:
      Person():m(0){} //写默认构造是一个好习惯
      Person(int a):m(a) {} //所有构造函数都不能有返回值，因为其作用是初始化对象

      int m;//这里为了省事写为public，实际写成private的话加一个get函数
};

ostream& operator<<(ostream& cout, const Person& p) //由于加法运算符重载中返回的是临时对象，其被当做常量处理，故此处要加上const
{
      cout << p.m;
      return cout;
}

Person operator+(const Person& p1, const Person& p2)
//利用const是好习惯  传参时const:避免修改至+可以传入常量  函数后const():避免修改值+可以让常量对象调用
{
      Person temp(p1.m+p2.m);//写了含参构造就不能用.来初始化对象了，需要传参
      return temp;
}

void test()
{
      Person p1(10);
      Person p2(5);
      //加法运算符重载
      cout << p1 + p2 << endl;//对于成员函数是前者在调用
      //除法运算符重载
      //自增，自减运算符重载
      //取余运算符重载
      //左移运算符重载
      //右移运算符重载
      //关系运算符重载
      //赋值运算符重载
      //下标运算符重载
      //函数调用运算符重载
}

int main()
{
      test();

      return 0;
}


//类内使用数组
