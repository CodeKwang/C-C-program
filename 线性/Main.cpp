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
   cout<<"          ѧ���ɼ�����ϵͳ"<<endl;
   cout<<"        ********************        "<<endl;
   k=3;
   while(k>0)
   { cout<<"\n        �������û�����";//�û���Ϊadmin
     cin>>user;
     cout<<"        ���������룺"; //����Ϊ888888 
     //��������� 
	 j=0;
     while ((ps[j]=getch())!='\r')
     {cout<<'*';j++;}
     if(ps[j]='\0')   cout<<endl;
    
     //������룬���ֲ���ʾ����*****��ʽ��ʾ 
     if((strcmp(user,"admin")==0)&&(strcmp(ps,"888888")==0)) 
     {InitList(L);
     cout<<endl;
      while(1)
      {
        cout<<("**************************************\n");
        cout<<("*           1---�ɼ�����             *\n");
        cout<<("*           2---�ɼ���ѯ             *\n");
        cout<<("*��������   3---�ɼ�����             *\n");
        cout<<("*           4---�ɼ�ɾ��             *\n");
        cout<<("*           5---�ɼ����             *\n");
        cout<<("*           0---�˳�                 *\n");
        cout<<("**************************************\n");
        cout<<("���������ѡ��(0---5)��");                             
        cin>>choice;
        switch(choice)
        {   case 1:input(e); ListInsert(L,e); break;
             
            case 2:cout<<("***************\n");
                   cout<<("*   1--ѧ��   *\n");
                   cout<<("*   2--����   *\n");
                   cout<<("***************\n");
                   cout<<("��ѡ���ѯ�Ĺؼ��֣�");
			       cin>>m;
			       search(L,m);
			       break;
             
			case 3: 
			       cout<<("***************\n");
                   cout<<("*   1--��ѧ   *\n");
                   cout<<("*   2--����   *\n");
                   cout<<("*   3--��ѧ   *\n");
                   cout<<("*   4--ƽ���� *\n");
                   cout<<("*   5--�ܷ�   *\n");
                   cout<<("***************\n");
			       cout<<("��ѡ������Ĺؼ��֣�");
			       cin>>n;
                   sort(L,n); 
                   break;
            case 4:cout<<("��������Ҫɾ����ѧ����ѧ�ţ�"); 
			       cin>>e.num; 
				   ListDelete(L,e); 
				   break;
            case 5: ListTraverse(L,print);break; 
            case 0: exit(1);break;
            default:cout<<("�������,����������!\n");
		}
	}
}
      else //�˻���������������Ĵ��� 
	  {  k--;
	  if(k!=0)  cout<<"\n �û���������������������룡����ʣ"<<k<<"�λ���"<<endl;           
	   else cout<<"�û�������������޷���½ϵͳ��" ;
	  }
	 }
 return 0;
}

   



  
  
  
  
  
