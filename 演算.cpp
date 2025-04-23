//�������������
# include <iostream>
using namespace std;

class Person
{
public:
      Person():m(0){} //дĬ�Ϲ�����һ����ϰ��  ���Ա��ⴴ������ʱ�����εĴ���
      Person(int a):m(a) {} //���й��캯���������з���ֵ����Ϊ�������ǳ�ʼ������

      int m;//����Ϊ��ʡ��дΪpublic��ʵ��д��private�Ļ���һ��get����

//��Ա����ƪ��

        //�������������
//      Person& operator++()
//      {
//            m++;
//            return *this;
//      }

        //��ֵ���������
        Person& operator=(const Person& p2)
        {
              if (this != &p2)//��ֹ�Ը�ֵ�����Ժ�̬�ڴ��й�
              {
                    this->m = p2.m;
              }
              return *this;
        }

        //�±����������  �ڳ�Ա������ʵ��(һ�������汾��д����ֱ����)
        int& operator[](int len)
        {
              return arr[len];
        }
        const int& operator[](int len) const
        {
              return arr[len];
        }

          //�����������������
          int operator()(Person& p1, Person& p2)
          {
                return p1.m + p2.m;
          }
};

//ȫ�ֺ���ƪ��

ostream& operator<<(ostream& out, const Person& p) //���ڼӷ�����������з��ص�����ʱ�����䱻�������������ʴ˴�Ҫ����const
{
      out << p.m;
      return out;
}

istream& operator>>(istream& in, Person& p) //���ﲻ����const����ΪҪ������޸�
{
      in >> p.m;
      return in;
}

Person operator+(const Person& p1, const Person& p2)
//����const�Ǻ�ϰ��  ����ʱconst:�����޸�ֵ+���Դ��볣��  ������const():�����޸�ֵ+�����ó����������
{
      Person temp(p1.m+p2.m);//д�˺��ι���Ͳ�����.����ʼ�������ˣ���Ҫ����
      return temp;
}

Person operator/(const Person& p1, const Person& p2) //const + ����ֵ ʵ����ʽ
{
      Person temp(p1.m / p2.m);
      return temp;//��ʱ���������ܷ��ص�ַ/����
}

Person operator%(const Person& p1, const Person& p2)
{
      Person temp(p1.m % p2.m);
      return temp;
}

//ǰ��
Person& operator++(Person& p1) //�����������constд�����Ȳ���ʵ����ʽ��Ҳ����++����(const �����޸�ֵ)
{
      //Person *temp = new Person(p1.m);//ָ��Ҫ�� new ������ֵ ���� (Person p;  Person *temp = p;  temp->m = 20);
      //����ָ�벢Ϊ����ʵ��������������޲ι��죬���洢��ַ
      ++p1.m;
      return p1;
}

//����
Person operator++(Person& p1, int) //�ڴ˴�����Ҫ�ռλ����������ռλ����һ��Ҫд�ں��������У� ���ǹ涨��
{
      Person temp = p1;
      p1.m++;
      return temp;
}

//��ϵ�����
bool isSame(Person& p1, Person& p2)
{
      return (p1.m == p2.m); //��bool���ͺ���ֻ��һ������ֵʱ��ʽ�ӳ������ص���true����֮false
}

void test()
{
      Person p1(10);
      Person p2(3);
      Person p3(2);
      //�ӷ����������
//      cout << p1 + p2 + p3 << endl;//���ڳ�Ա������ǰ���ڵ���

      //�������������
//      cout << (p1 / p2) / p3 << endl;

      //�������Լ����������
//      cout << ++(++p1) << endl;
//      cout << p1++ << endl;
//      cout << p1 << endl;
      //���ں����������ص�������ǰ��ֵ������Ҳû��ʲô�ð취ʵ�ֶ�����

      //ȡ�����������
//      cout << (p1 % p2) % p3 << endl;

      //�������������
//      cout << p1 << endl;

      //�������������
//      Person p4;
//      cin >> p4;
//      cout << p4 << endl;
      //��ϵ���������
//      if (p1 == p2)
//            cout << "Yes" << endl;
//      else
//            cout << "No"  << endl;

      //��ֵ���������(������ȫ�ֺ���)
//      p1 = p2 = p3;
//      cout << p1.m << endl;
      //�±����������  codeblocksò�Ʋ��Ͽ�ȫ�ֺ�����ʽ���±����������
      //������Ҫ����������ʵ�֣��˴�����׸��

      //�����������������  ���ڸ�����
//      cout << Person()(p1, p2) << endl;  //������������
}

int main()
{
      test();

      return 0;
}
