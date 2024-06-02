#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Base
{
    // 1. ��������� "next" � ������� ������
    Base* next;
public:
    Base()
    {
        next = 0;
    }
    void setNext(Base* n)
    {
        cout << next;
        next = n;
        cout << next;
    }
    void add(Base* n)
    {
        if (next)
            next->add(n);
        else
            next = n;
    }
    // 2. ����� �������� ������, ������������ ������ next-�������
    virtual void handle(int i)
    {
        cout << next;
        next->handle(i);
    }
};

class Handler1 : public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            // 3. 3 �� 4 �������� �� ������������
            cout << "H1 passsed " << i << "  ";
            // 3. � ���������� �������� ������
            Base::handle(i);
        }
        else
            cout << "H1 handled " << i << "  ";
    }
};

class Handler2 : public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H2 passsed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H2 handled " << i << "  ";
    }
};

class Handler3 : public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H3 passsed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H3 handled " << i << "  ";
    }
};

int main()
{
    srand(time(0));
    Handler1 root;
    Handler2 two;
    Handler3 thr;
    root.add(&two);
    root.add(&thr);
    thr.setNext(&root);
    for (int i = 1; i < 10; i++)
    {
        root.handle(i);
        cout << '\n';
    }
}