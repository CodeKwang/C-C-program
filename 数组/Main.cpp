#include"C1.h"
#include"C2.h"
#include"Func.cpp" 
#include"Basic_Operation.cpp"
int main()
{      
   char user[10],ps[8];
   int i=0;
   int j,k,m,n,choice,num;
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
     {student stu[100];
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
        {   case 1:input(stu,i); i++; break;
             
            case 2:cout<<("***************\n");
                   cout<<("*   1--ѧ��   *\n");
                   cout<<("*   2--����   *\n");
                   cout<<("***************\n");
                   cout<<("��ѡ���ѯ�Ĺؼ��֣�");
			       cin>>m;
			       search(stu,i,m);
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
                   sort(stu,i,n); 
                   break;
            case 4:cout<<("��������Ҫɾ����ѧ����ѧ�ţ�"); 
			       cin>>num; 
				   if(1==Delete(stu,i,num)) i--;
				   break;
            case 5: Traverse(stu,i);break; 
            case 0: exit(1);break;
            default:cout<<("�������,����������!\n");
		}
	 }
	 }
      else //�˻���������������Ĵ��� 
	  {  
	  k--;
	  if(k!=0)  cout<<"\n �û���������������������룡����ʣ"<<k<<"�λ���"<<endl;           
	   else cout<<"�û�������������޷���½ϵͳ��" ;
	  }
    }
    return 0;
 }
