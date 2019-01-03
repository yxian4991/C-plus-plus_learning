/*
 * Written in 2019-01-03
 * just note an example showing how to interact with a file
 * the key is <fstream>
*/
#include <iostream>
#include <fstream>
using namespace std;

//向文件内部写入数据
int file_write(string filepath)
{
    char data[100];
    //向文件写入数据
    ofstream outfile;
    outfile.open(filepath);
    if(!outfile)
    {  cerr<<"no file opened !"<<endl;}
    cout << "Writing to the file" << endl;
    cout << "Enter your name:" << endl;
    cin.getline(data,100);
    outfile << data << endl;
    cout << "Enter your age:" << endl;
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();
    return 0;
}
//从文件读出数据
string file_read(string filepath)
{
    char data[100];
    //从文件读取数据
    ifstream infile;
    infile.open(filepath);
    if(!infile)
    {  cerr<<"no file opened !"<<endl;}
    cout << "Reading from the file" << endl;
    //循环条件读取文本.会重复读取最后一个数据，
    //使用流迭代器istream_iterator<> 好像可以避免重复？待研究
    //或者采用file_copy函数里的循环方法
    while(infile.peek() != EOF){
    infile >> data ;
    cout << data << endl;
    }

    //读取文本到返回值，与上面的循环读取方法只能二选一，只能有一个读取
    //利用了迭代器iterator，这条语句的具体原理待理解
    string readStr((std::istreambuf_iterator<char>(infile)),  std::istreambuf_iterator<char>()); 
    cout << "readStr:" <<endl<< readStr << endl;
    return readStr;
    infile.close();
}


//将数据从文件1复制到另一文件2中
int file_copy(string filepath1,string filepath2)
{
    char data[100];
    ifstream infile;
    ofstream outfile;
    infile.open(filepath1);
    outfile.open(filepath2);
    if(!infile)
	    return -1;
    if(!outfile)
	    return -2;
    cout << "copying from file1 to file2" << endl;
    while (infile>>data)
    {
        cout << data << endl;
        outfile << data << endl;
    }
    infile.close();
    outfile.close();
    return 1;
}

//测试上述读写文件，与文件数据复制
int main(int argc, char* argv[])
{
    file_write("./test1.txt");
    file_read("./test1.txt");
    file_copy("./test1.txt","./test2.txt");

    getchar();
    return 0;
}
