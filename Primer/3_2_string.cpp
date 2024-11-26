#include <iostream>
#include <string>
using namespace::std;
int main()
{
    string s2("value");     //直接初始化
    string s3="value";      //拷贝初始化
    string s1(10,'c');
    cout<<"s1="  <<s1
        <<"\ns2="<<s2
        <<"\ns3="<<s3<<'\n';
    string s4=string(10,'c');
    char t='t';
    char f='f';
    char a=t|f;//按位或
    bool b=t||f;//逻辑或
    char c=t & f;//按位与
    bool d=t&&f;//逻辑与
    cout<<"a="  <<a
        <<"\nb="<<b
        <<"\nc="<<c
        <<"\nd="<<d<<"\n";
    //等价于
    //string temp(10,'c');
    //string s4=temp;
    //不如s1的方法
    //cin>>s1;//读取到空格截止
    //cout<<s1<<'\n';
    //cin>>s2>>s3;
    //cout<<s2<<s3<<'\n';
    string word;
    while(getline(cin,word))
    {
        cout<<"word的长度为:"   <<word.size()
            <<"\nword是否为空:" <<word.empty();
            break;

    }
    while (cin>>word)
    {
        cout<<word<<'\n';
        for(int a=1;a<=4;a++)
        {
            cout<<"a="<<a<<endl;
            break;
        }
        cout<<"343-----------------\n";
        if(word=="cancel")
        {
            break;
        }
    }
    cout<<"<<----------->>\n";
    string line;
    while (getline(cin,line))
    {
        cout<<line<<'\n';
        break;
    }
    

    auto len=line.size();//size返回值为无符号整型(unsigned)
    string s6=s2+","+"hello";//不能把字面值与string直接相加
    string s5=s1+","+s2+'\n';//例如:string s1=“hello”+",";是非法的
    cout<<s5;//空格是分隔符,分隔每个数据，回车运行一次


    string str("some,string");
    for(auto c : str)//对于str中的每个字符
    {
        cout<<c<<'\n';//输出每个字符
    }


    string s("hello world!!!!");
    decltype(s.size()) punct_cnt=0;//punct_cnt的类型与s.size()的返回值类型相同
    for(auto c:s)//对于每个s中的字符
    {
        if(ispunct(c))//如果该字符是标点符号
        {
            punct_cnt++;//将标点符号计数值加一
        }
    }
    cout<<punct_cnt
        <<" punctuation characters in "
        <<s
        <<endl;
    

    for(auto &c : s)//对s中的每个字符(注意c是引用)
    {
        c=toupper(c);//c是一个引用，因此赋值语句将改变s的值
    }
    cout<<s<<endl;//将s中的字符大写后输出
    

    if(!s.empty())//判断s是否为空，为空则返回true
    {
        cout<<s[0]<<endl;
    }
    if(!s.empty())
    {
        s[0]=toupper(s[0]);//将第一个字符大写
    }
    cout<<s<<endl;
    
    string ab("some string");
    for(decltype(ab.size()) index=0;index != ab.size() && !isspace(ab[index]);++index)
    {
        ab[index]=toupper(ab[index]);//将空格前的字符大写，读取到空格结束
    }
    cout<<"ab="<<ab<<endl;


    const string hexdigits("0123456789ABCDEF");
    cout<<"Enter a serise of number between 0 and 15 "
        <<" separated by spaces. Hit ENTER when finished: "
        <<endl;
    string result;
    string::size_type n ;
    while(cin>>n)
    {
        if(n<hexdigits.size())
        {
            result += hexdigits[n];
        }
    }
    cout <<"you hex number is:"
         <<result
         <<endl;
}