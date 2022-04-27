#include<stdio.h> 
#include<iostream> 
#include<string.h>
#include<conio.h> 
#define N 999 //定义最多的航班数
#define PRINT "%d\t%s\t%s\t%s\t\t%d\n",s[i].num,s[i].qidian,s[i].zhongdian,s[i].time,s[i].count // 宏定义输出格式
using namespace std;
struct air //定义结构体数组
{
	int num; //定义航班号
	char qidian[20]; //航班起始站
	char zhongdian[20]; //终点站
	char time[10]; //飞行时间
	int count; //机票数量
}s[N];
int i,m; //全局变量; m为航班数 
char hangbanhao[10];
bool admin();//管理员登录函数 
void add(); //函数声明增加航班信息函数
void delone();//删除航班信息 
void delall();//删除全部航班信息 
void modify();//修改航班信息 
void print(); //显示航班信息
void search(); //查找航班信息
void dingpiao(); //订票业务
void tuipiao(); //退票
void read(); //读取文件
void save(); //保存文件
void output(); //输出格式
void paixu(); //航班排序
void build(); //建立数据文件
void paixu1(); //按航班号从小到大排序
void paixu2(); //从大到小
