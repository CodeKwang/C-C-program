#include"C1.h"
#include"C2.h"
#include"Func.cpp" 
#include"Basic_Operation.cpp"
using namespace std;
int main()
{
   SqList L;
   ElemType e;
   char user[10],ps[8];
   Status i;
   int j,k,m,n,choice;
   cout<<"        ********************        "<<endl;
   cout<<"          学生成绩管理系统"<<endl;
   cout<<"        ********************        "<<endl;
   k=3;
   while(k>0)
   { cout<<"\n        请输入用户名：";//用户名为admin
     cin>>user;
     cout<<"        请输入密码："; //密码为888888 
     //密码的输入 
	 j=0;
     while ((ps[j]=getch())!='\r')
     {cout<<'*';j++;}
     if(ps[j]='\0')   cout<<endl;
    
     //完成输入，但又不显示，以*****形式显示 
     if((strcmp(user,"admin")==0)&&(strcmp(ps,"888888")==0)) 
     {InitList(L);
     cout<<endl;
      while(1)
      {
        cout<<("**************************************\n");
        cout<<("*           1---成绩输入             *\n");
        cout<<("*           2---成绩查询             *\n");
        cout<<("*　　　　   3---成绩排序             *\n");
        cout<<("*           4---成绩删除             *\n");
        cout<<("*           5---成绩输出             *\n");
        cout<<("*           0---退出                 *\n");
        cout<<("**************************************\n");
        cout<<("请输入你的选择(0---5)：");                             
        cin>>choice;
        switch(choice)
        {   case 1:input(e); ListInsert(L,e); break;
             
            case 2:cout<<("***************\n");
                   cout<<("*   1--学号   *\n");
                   cout<<("*   2--姓名   *\n");
                   cout<<("***************\n");
                   cout<<("请选择查询的关键字：");
			       cin>>m;
			       search(L,m);
			       break;
             
			case 3: 
			       cout<<("***************\n");
                   cout<<("*   1--数学   *\n");
                   cout<<("*   2--物理   *\n");
                   cout<<("*   3--化学   *\n");
                   cout<<("*   4--平均分 *\n");
                   cout<<("*   5--总分   *\n");
                   cout<<("***************\n");
			       cout<<("请选择排序的关键字：");
			       cin>>n;
                   sort(L,n); 
                   break;
            case 4:cout<<("请输入所要删除的学生的学号："); 
			       cin>>e.num; 
				   ListDelete(L,e); 
				   break;
            case 5: ListTraverse(L,print);break; 
            case 0: exit(1);break;
            default:cout<<("输入错误,请重新输入!\n");
		}
	}
}
      else //账户或密码输入有误的处理 
	  {  k--;
	  if(k!=0)  cout<<"\n 用户名或密码错误，请重新输入！（还剩"<<k<<"次机会"<<endl;           
	   else cout<<"用户名或密码错误，无法登陆系统！" ;
	  }
	 }
 return 0;
}

   



  
  
  
  
  
