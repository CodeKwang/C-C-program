#include<stdio.h> 
#include<iostream> 
#include<string.h>
#include<conio.h> 
#define N 999 //�������ĺ�����
#define PRINT "%d\t%s\t%s\t%s\t\t%d\n",s[i].num,s[i].qidian,s[i].zhongdian,s[i].time,s[i].count // �궨�������ʽ
using namespace std;
struct air //����ṹ������
{
	int num; //���庽���
	char qidian[20]; //������ʼվ
	char zhongdian[20]; //�յ�վ
	char time[10]; //����ʱ��
	int count; //��Ʊ����
}s[N];
int i,m; //ȫ�ֱ���; mΪ������ 
char hangbanhao[10];
bool admin();//����Ա��¼���� 
void add(); //�����������Ӻ�����Ϣ����
void delone();//ɾ��������Ϣ 
void delall();//ɾ��ȫ��������Ϣ 
void modify();//�޸ĺ�����Ϣ 
void print(); //��ʾ������Ϣ
void search(); //���Һ�����Ϣ
void dingpiao(); //��Ʊҵ��
void tuipiao(); //��Ʊ
void read(); //��ȡ�ļ�
void save(); //�����ļ�
void output(); //�����ʽ
void paixu(); //��������
void build(); //���������ļ�
void paixu1(); //������Ŵ�С��������
void paixu2(); //�Ӵ�С
