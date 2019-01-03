/*
 *Written in 2018-01-03
 *show how to use "try-catch" to deal with some exceptions
 *also show how to build a "class" in c++
*/
#include <iostream>
#include <exception>
using namespace std;

class MyException
{
public:
    //构造函数
    MyException(const char *message)
        : message_(message) //使用列表赋值
    {
        cout << "MyException ..." << endl;
    }
    //拷贝构造函数
    MyException(const MyException &other) : message_(other.message_)
    {
        cout << "Copy MyException ..." << endl;
    }
    //析构函数
    virtual ~MyException()//虚函数用于继承重载
    {
        cout << "~MyException ..." << endl;
    }
    //成员函数
    //每个标准库异常类都定义了名为 what 的成员函数
    //这些函数没有参数，返回值是 C 风格字符串（即 const char *）
    const char *what() const
    {
        return message_.c_str();
    }
private:
    string message_;
};

class MyExceptionD : public MyException//公有继承
{
public:
    MyExceptionD(const char *message)
        : MyException(message)
    {
        cout << "MyExceptionD ..." << endl;
    }
    MyExceptionD(const MyExceptionD &other)
        : MyException(other)
    {
        cout << "Copy MyExceptionD ..." << endl;
    }
    ~MyExceptionD()
    {
        cout << "~MyExceptionD ..." << endl;
    }
};

void fun(int n) throw (int, MyException, MyExceptionD)
{
    if (n == 1)
    {
        throw 1;
    }
    else if (n == 2)
    {
        throw MyException("test Exception");
    }
    else if (n == 3)
    {
        throw MyExceptionD("test ExceptionD");
    }

}

void fun2() throw()//不抛出任何异常
{

}

int main(void)
{
    try
    {
        fun(2);
	fun2();
    }

    catch (int n)
    {
        cout << "catch int ..." << endl;
        cout << "n=" << n << endl;
    }
    catch (MyExceptionD &e)
    {
        cout << "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    catch (MyException &e)
    {
        cout << "catch MyException ..." << endl;
        cout << e.what() << endl;
    }

    return 0;
}
