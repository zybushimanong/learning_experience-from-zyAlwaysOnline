//�������������
# include <iostream>
using namespace std;

class Person
{
public:
      Person():m(0){} //дĬ�Ϲ�����һ����ϰ��
      Person(int a):m(a) {} //���й��캯���������з���ֵ����Ϊ�������ǳ�ʼ������

      int m;//����Ϊ��ʡ��дΪpublic��ʵ��д��private�Ļ���һ��get����
};

ostream& operator<<(ostream& cout, const Person& p) //���ڼӷ�����������з��ص�����ʱ�����䱻�������������ʴ˴�Ҫ����const
{
      cout << p.m;
      return cout;
}

Person operator+(const Person& p1, const Person& p2)
//����const�Ǻ�ϰ��  ����ʱconst:�����޸���+���Դ��볣��  ������const():�����޸�ֵ+�����ó����������
{
      Person temp(p1.m+p2.m);//д�˺��ι���Ͳ�����.����ʼ�������ˣ���Ҫ����
      return temp;
}

void test()
{
      Person p1(10);
      Person p2(5);
      //�ӷ����������
      cout << p1 + p2 << endl;//���ڳ�Ա������ǰ���ڵ���
      //�������������
      //�������Լ����������
      //ȡ�����������
      //�������������
      //�������������
      //��ϵ���������
      //��ֵ���������
      //�±����������
      //�����������������
}

int main()
{
      test();

      return 0;
}


//����ʹ������
