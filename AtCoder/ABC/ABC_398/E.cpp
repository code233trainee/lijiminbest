// #include<stdio.h>
// #include<stdlib.h>
// #define MAXSIZE 20
// typedef struct Student{
// int num;
// char*name;
// float score;
// }Student;

// typedef Student Elemtype;

// typedef struct SqList{
//   Elemtype data[MAXSIZE];
// int length;
// }SqList;
// void ListPrint(SqList*L)
// {
// if(L->length==0){
// printf("表为空\n.");
// return;}

// for(int i=0;i<L->length;i++){
//         printf("序号：%d\t学号：%d\t姓名：%s\t成绩：%.2f\n",
//                i+1,L->data[i].num,L->data[i].name,L->data[i].score);
// }
// }
// int ListInsert(SqList *L,int pos,int Lnum,char*Lname,float Lscore){
// Student temp={Lnum,Lname,Lscore};
// if(L->length==MAXSIZE||pos<0||pos>L->length+1){
//     printf("插入失败！\n");
//     return 0;
// }

// if (pos!=0&&pos!=L->length+1){
//     for(int i=L->length-1;i>=pos-1;i--){
//         L->data[i+1]=L->data[i];
//     }
// }
// else if(pos==0){
//     pos=L->length+1;
// }
// L->data[pos-1]=temp;
// L->length++;
// return 1;
// }
// void showMenu(){
//     printf("---------------------\n");
//     printf("-----1按名字查询-----\n");
//     printf("-----2按学号查询-----\n");
//     printf("---3按序号插入信息---\n");
//     printf("---4按序号删除信息---\n");
//     printf("--5显示所有学生信息--\n");
//     printf("---6按序号合并信息---\n");
//     printf("-------0退出---------\n");
//     printf("选择要进行的操作（输入0~6的整数）:");
// }
// void LocateList(SqList  *L,char *Sname){
// if(L->length==0){
//     printf("查找失败\n");
//     return;
// }
// for(int i=0;i<L->length;i++){
//     if(strcmp(L->data[i].name,Sname)==0)
// }
// }
// int main()
// {
//     SqList*Lp;
//     Lp=(SqList*)malloc(sizeof(SqList));
//     if(!Lp){
//         printf("空间分配失败！\n");
//         return 0;
//     }
//     Lp->length=0;
//     Lp->data[0].num=1001;
//     Lp->data[0].name="李华";
//     Lp->data[0].score=90;
//     Lp->length++;

//     Student stu1={1002,"王红",88};
//     Lp->data[1]=stu1;
//     Lp->length++;

//     Student stu2={1003,"江夏",89};
//     Lp->data[2]=stu2;
//     Lp->length++;


//     for(int i=0;i<Lp->length;i++){
//         printf("序号：%d\t学号：%d\t姓名：%s\t成绩：%.2f\n",
//                i+1,Lp->data[i].num,Lp->data[i].name,Lp->data[i].score);
//     }
//     showMenu();
//     int ch=0;
//     while(1){
//     showMenu();
//     }
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    
    return 0;
}