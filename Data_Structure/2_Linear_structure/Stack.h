#include <iostream>
#include "Vector.h"

//运算符总数
typedef enum{ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator;//运算符集合
const char pri[9][9] = { //运算符优先等级 [栈顶][当前]  (换行代表下一行)
   /*              |-------------------- 当 前 运 算 符 --------------------| */
   /*              +      -      *      /      ^      !      (      )      \0 */
   /* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
   /* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
   /* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
   /* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
   /* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
   /* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
   /* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
   /* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
   /* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};

Operator optr2rank ( char op ) { 
   switch ( op ) {
      case '+' : return ADD; 
      case '-' : return SUB; 
      case '*' : return MUL; 
      case '/' : return DIV; 
      case '^' : return POW; 
      case '!' : return FAC; 
      case '(' : return L_P; 
      case ')' : return R_P; 
      case '\0': return EOE; 
      default  : exit(-1);;
   }
}

char priority ( char op1, char op2 ) 
{ return pri[optr2rank ( op1 ) ][optr2rank ( op2 ) ]; }

template <typename T>
class Stack: public Vector<T>  //将向量的首/末端作为栈底/顶
{
    public://size(),empty()以及其它开放接口，均可直接沿用
        void push(T const& e)//入栈，等效于将新元素作为向量的末尾元素插入
        {
            insert(size(), e);
        }
        T pop()//出栈:等效于删除向量的末元素
        {
            return remove(size() - 1);
        }
        T& top()//取顶:直接返回向量的末元素
        {
            return (*this) [size() - 1];
        }
};

//使用栈结构，先进后出
void convert (Stack<char>& S, _int64 n, int base)//十进制正整数n到base进制的转换(递归版)
{//0 < n, 1 < base <= 16,新进制下的数位符号,可视base取值范围适当扩充
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if(0 < n)//在尚有余数之前，反复的 (tips : 是不是很像高中学的除数取余)
    {
        S.push(digit[n % base]);//逆向记录当前最低位，再
        convert(S, n / base, base);//通过递归得到所有更高位
    }
}//新进制下由高到低的各数位,自顶而下保存于栈S中

void convert2 (Stack<char> S, _int64 n, int base)//进制转换(迭代版)
{//0 < n, 1 < base <= 16,新进制下的数位符号,可视base取值范围适当扩充
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(n > 0)//由高到低，逐一计算出新机制下的各数位
    {
        int remainder = (int) (n % base);
        S.push(digit[remainder]);//余数[当前位]入栈
        n /= base;//n更新为其对base的除商
    }
}//新进制下由高到低的各位数，自顶而下保存于栈S中

void trim (const char exp[], int& lo, int& hi)//删除exp[lo, hi]不含括号的最长前缀，后缀
{
    while ( (lo <= hi) && (exp[lo] != '(') && (exp[lo] != ')')) lo++;//查找第一个和
    while ( (lo <= hi) && (exp[hi] != '(') && (exp[hi] != ')')) hi--;//最后一个括号
}
int divide(const char exp[], int lo, int hi)//切分exp[lo, hi], 使exp匹配仅当子表达式匹配
{
    int mi = lo;
    int crc = 1;//crc为[lo，mi]范围内左,右括号数目之差
    while((0 < crc) && (++mi < hi))//逐个检查各字符，直到左,右括号数目相等,或者越界
    {//左右括号分别计数
        if(exp[mi] == ')')
        {
            crc--;
        }
        if(exp[mi] == '(')
        {
            crc++;
        }
    }
    return mi;//若mi <= hi,则为合法切分点;否则,意味着局部不可能匹配
}
bool paren (const char exp[], int lo, int hi)//检查表达式exp[lo, hi]是否括号匹配(递归版)
{
    trim(exp, lo, hi);
    if(lo > hi)//清除不含括号的前缀，后缀
    {
        return true;
    }
    if(exp[lo] != '(')//首字符非左括号,则必不匹配
    {
        return false;
    }
    if(exp[hi] != ')')//末字符非右括号,则必不匹配
    {
        return false;
    }
    int mi = divide (exp, lo, hi);//确定适当的切分点
    if(mi > hi)//切分点不合法,意味着局部以至整体不匹配
    {
        return false;
    }
    return paren(exp, lo + 1, mi - 1) && paren(exp, mi + 1, hi);//分别检查左右子表达式
}

bool paren2 (const char exp[], int lo, int hi)//表达式括号匹配检查,可兼顾三种括号
{
    Stack<char> S;//使用栈记录已发现但尚未匹配的左括号
    for(int i = lo; i <= hi; i++)//逐一检查当前字符
    {
        switch(exp[i])//左括号直接进栈;右括号若与栈顶失配,则表达式必不匹配
        {
            case '(': case '[': case '{': S.push(exp[i]); break; 
            case ')': if((S.empty()) || ('(' != S.pop())) return false; break;
            case ']': if((S.empty()) || ('[' != S.pop())) return false; break;
            case '}': if((S.empty()) || ('{' != S.pop())) return false; break;
            default: break;//非括号字符一律忽略
        }
    }
    return S.empty();//整个表达式扫描过后,栈中若仍残留(左)括号,则不匹配;否则(栈空)匹配
}


template <typename T>
void print(Stack<T> s)
{
    for(int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i] << ",";
    }
    cout << endl;
}

void append ( char* rpn, double opnd ) { 
   char buf[64];
   if ( ( int ) opnd < opnd ) sprintf ( buf, "%6.2f \0", opnd ); 
   else                       sprintf ( buf, "%d \0", ( int ) opnd ); 
   strcat ( rpn, buf ); 
}

void append ( char* rpn, char optr ) { 
   int n = strlen ( rpn ); 
   sprintf ( rpn + n, "%c \0", optr ); 
}

double calcu ( double a, char op, double b ) { 
   switch ( op ) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if ( 0==b ) exit ( -1 ); return a/b; 
      case '^' : return pow ( a, b );
      default  : exit ( -1 );
   }
}


_int64 facI ( int n ) { _int64 f = 1; while ( n > 1 ) f *= n--; return f; }

double calcu ( char op, double b ) { 
   switch ( op ) {
      case '!' : return ( double ) facI ( ( int ) b ); 
      default  : exit ( -1 );
   }
}


void readNumber ( char*& p, Stack<double>& stk ) { 
   stk.push ( ( double ) ( *p - '0' ) ); 
   while ( isdigit ( * ( ++p ) ) ) 
      stk.push ( stk.pop() * 10 + ( *p - '0' ) ); 
   if ( '.' == *p ) { 
      double fraction = 1; 
      while ( isdigit ( * ( ++p ) ) ) 
         stk.push ( stk.pop() + ( *p - '0' ) * ( fraction /= 10 ) ); 
   }
}

float evaluate(char* S, char* & RPN)//中缀表达式求值,并转化为逆波兰表达式(后缀表达式)
{
    Stack<double> opnd;//运算数栈
    Stack<char> optr;//算数符栈
    optr.push('\0');//尾哨兵'\0'也作为头哨兵首先入栈
    while(!optr.empty())//逐个处理各符号，直至运算符栈空
    {
        if( isdigit(*S))//若当前字符为操作数,则
        {
            readNumber(S, opnd);//读入(可能多位的)操作数
            append(RPN, opnd.top());//并将其接至RPN末尾
        }
        else//若当前字符为运算符，则视其与栈顶运算符之间优先级的高低
        {
            switch (priority(optr.top(), *S))
            {
            case '<'://栈顶运算符优先级更低时
                optr.push(*S);
                S++;//计算推迟，当前运算符进栈
                break;
            case '='://优先级相等(当前运算符为右括号或者尾部哨兵'\0')时
                optr.pop();
                S++;//脱括号并接收下一个字符
                break;
            case '>'://栈顶运算符优先级更高时,可实施相应的计算,并将结果重新入栈
                {
                    char op = optr.pop();//栈顶运算符出栈并续接至RPN末尾
                    append(RPN, op);
                    if('!' == op)//若属于一元运算符
                    {
                        float pOpnd = opnd.pop();//只需要取出一个操作数,并
                        opnd.push(calcu(op, pOpnd));//实施一元计算,结果入栈
                    }
                    else//对于其它(二元)运算符
                    {
                        float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();//取出后，前操作数
                        opnd.push(calcu(pOpnd1, op, pOpnd2));//实施二元计算，结果入栈
                    }
                }
                break;
            default:
                exit(-1);//逢语法错误，不做处理直接退出
            }//switch
        }
    }//while
    return opnd.pop();//弹出并返回最后的计算结果
}

