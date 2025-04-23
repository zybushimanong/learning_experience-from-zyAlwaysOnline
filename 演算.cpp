//所有运算符重载
# include <iostream>
using namespace std;

class Person
{
public:
      Person():m(0){} //写默认构造是一个好习惯  可以避免创建对象时忘传参的错误
      Person(int a):m(a) {} //所有构造函数都不能有返回值，因为其作用是初始化对象

      int m;//这里为了省事写为public，实际写成private的话加一个get函数

//成员函数篇：

        //自增运算符重载
//      Person& operator++()
//      {
//            m++;
//            return *this;
//      }

        //赋值运算符重载
        Person& operator=(const Person& p2)
        {
              if (this != &p2)//防止自赋值，与以后动态内存有关
              {
                    this->m = p2.m;
              }
              return *this;
        }

        //下标运算符重载  在成员函数中实现(一般两个版本都写，会分别调用)
        int& operator[](int len)
        {
              return arr[len];
        }
        const int& operator[](int len) const
        {
              return arr[len];
        }

          //函数调用运算符重载
          int operator()(Person& p1, Person& p2)
          {
                return p1.m + p2.m;
          }
};

//全局函数篇：

ostream& operator<<(ostream& out, const Person& p) //由于加法运算符重载中返回的是临时对象，其被当做常量处理，故此处要加上const
{
      out << p.m;
      return out;
}

istream& operator>>(istream& in, Person& p) //这里不能用const，因为要输入而修改
{
      in >> p.m;
      return in;
}

Person operator+(const Person& p1, const Person& p2)
//利用const是好习惯  传参时const:避免修改值+可以传入常量  函数后const():避免修改值+可以让常量对象调用
{
      Person temp(p1.m+p2.m);//写了含参构造就不能用.来初始化对象了，需要传参
      return temp;
}

Person operator/(const Person& p1, const Person& p2) //const + 返回值 实现链式
{
      Person temp(p1.m / p2.m);
      return temp;//临时变量，不能返回地址/引用
}

Person operator%(const Person& p1, const Person& p2)
{
      Person temp(p1.m % p2.m);
      return temp;
}

//前置
Person& operator++(Person& p1) //如果按照上面const写法，既不能实现链式，也不能++操作(const 不能修改值)
{
      //Person *temp = new Person(p1.m);//指针要用 new 来赋初值 或者 (Person p;  Person *temp = p;  temp->m = 20);
      //创建指针并为创建实体变量，不调用无参构造，仅存储地址
      ++p1.m;
      return p1;
}

//后置
Person operator++(Person& p1, int) //在此处不需要填补占位参数，而且占位参数一定要写在后置自增中！ 这是规定！
{
      Person temp = p1;
      p1.m++;
      return temp;
}

//关系—相等
bool isSame(Person& p1, Person& p2)
{
      return (p1.m == p2.m); //当bool类型函数只有一个返回值时，式子成立返回的是true，反之false
}

void test()
{
      Person p1(10);
      Person p2(3);
      Person p3(2);
      //加法运算符重载
//      cout << p1 + p2 + p3 << endl;//对于成员函数是前者在调用

      //除法运算符重载
//      cout << (p1 / p2) / p3 << endl;

      //自增，自减运算符重载
//      cout << ++(++p1) << endl;
//      cout << p1++ << endl;
//      cout << p1 << endl;
      //由于后置自增返回的是自增前的值，主播也没有什么好办法实现多自增

      //取余运算符重载
//      cout << (p1 % p2) % p3 << endl;

      //左移运算符重载
//      cout << p1 << endl;

      //右移运算符重载
//      Person p4;
//      cin >> p4;
//      cout << p4 << endl;
      //关系运算符重载
//      if (p1 == p2)
//            cout << "Yes" << endl;
//      else
//            cout << "No"  << endl;

      //赋值运算符重载(不能用全局函数)
//      p1 = p2 = p3;
//      cout << p1.m << endl;
      //下标运算符重载  codeblocks貌似不认可全局函数形式的下标运算符重载
      //这里需要创建数组来实现，此处不再赘述

      //函数调用运算符重载  类内更常用
//      cout << Person()(p1, p2) << endl;  //匿名函数对象
}

int main()
{
      test();

      return 0;
}
