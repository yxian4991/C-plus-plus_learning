/*
 Written in 2018-12-15
 just show system  time by some formats.
 a key is <ctime>,time_t...and strftime
*/ 



#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string  Get_Current_Date();

int main()
{

    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    cout << "1970 到目前经过秒数:" << now << endl;
    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    cout << "本地日期和时间：" << dt << endl;
    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间：" << dt << endl;

    tm *ltm = localtime(&now);
    // 输出 tm 结构的各个组成部分
    cout << "年: " << 1900 + ltm->tm_year << endl;
    cout << "月: " << 1 + ltm->tm_mon << endl;
    cout << "日: " << ltm->tm_mday << endl;
    cout << "时间: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
    // 将当前日期以 20** - ** - ** 格式输出,可以利用strftime函数完成其他形式的输出
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", ltm);
    cout << tmp<< endl;
//cout << Get_Current_Date().c_str() << endl;

    getchar();
    return 0;
}


//将时间以某种显示格式输出的函数
string  Get_Current_Date()
{
    time_t nowtime;
    nowtime = time(NULL); //获取日历时间   
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
    return tmp;
}
