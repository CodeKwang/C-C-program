#include"Command_operation.cpp" 
int main() //������
{
	//char user[10],ps[8];
    cout<<"        ********************        "<<endl;
    cout<<"           �ɻ���Ʊϵͳ"<<endl;
    cout<<"        ********************        "<<endl;
    int k=3;
    while(k>0)
	{ 	
		 char user[10],ps[8];
		 int j=0;
		 cout<<endl;
		 cout<<"        �������û�����";//�û���Ϊuser 
	     cin>>user;
	     cout<<"        ���������룺"; //����Ϊ888888 
	     //��������� 
	    while((ps[j]=getch())!='\r')
	    {
	        if(ps[j]=='\b')//�ж��Ƿ�Ϊ�˸� 
	        {
	            if(j==0) //��jΪ��ʱ������ 
	            {
	                printf("\a");
	                continue;
	            }
	            j=j-1;
	            printf("\b \b");
	        }
	        else
	        {
	            j=j+1;
	            printf("*");
	        }
	    }
	    if(ps[j]='\0')   cout<<endl;
	     //������룬���ֲ���ʾ����*****��ʽ��ʾ 
	     if((strcmp(user,"user")==0)&&(strcmp(ps,"888888")==0))
	     {
			int ch;
			read();
			while(1){
				cout<<endl<<endl;
				cout<<"        ��ӭʹ�ú��ඩƱϵͳ !"<<endl;
				cout<<"******************************************"<<endl;
				cout<<" 1.���Ӻ�����Ϣ"<<endl;
				cout<<" 2.ɾ��������Ϣ"<<endl;
				cout<<" 3.ɾ��ȫ��������Ϣ"<<endl;
				cout<<" 4.�޸ĺ�����Ϣ"<<endl;
				cout<<" 5.���������Ϣ"<<endl;
				cout<<" 6.���Һ�����Ϣ"<<endl;
				cout<<" 7.�������� (������� )"<<endl;
				cout<<" 8.����Ʊҵ��"<<endl; 
				cout<<" 9.������Ʊҵ��"<<endl;
				cout<<" 0.�˳�ϵͳ (exit)"<<endl;
				cout<<"*******************************************"<<endl;
				cout<<" ���� 0-9 ��ѡ���Իس���������";
				cin>>ch;
				switch(ch)
				{
					case 1: 
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"ӵ�й���ԱȨ�ޣ��������Ӳ���"<<endl; 
							add();//�������Ӻ��� 
							save();//���ñ��溯��  
							break;	
						}
						else
						{
							cout<<"û�й���ԱȨ�ޣ�����"<<endl;
							break;	
						}
						break;
					}
					case 2: 
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"ӵ�й���ԱȨ�ޣ�����ɾ������"<<endl;
							delone();//����ɾ������ 
							save();//���ñ��溯�� 
							break;	
						}
						else
						{
							cout<<"û�й���ԱȨ�ޣ�����"<<endl;
							break;	
						}
						break;
					} 
					case 3:
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"ӵ�й���ԱȨ�ޣ�����ɾ��ȫ����Ϣ����"<<endl;
							delall();//����ɾ��ȫ����Ϣ���� 
							save();//���ñ��溯��  
							break;	
						}
						else
						{
							cout<<"û�й���ԱȨ�ޣ�����"<<endl;
							break;	
						}
						break;
					}
					case 4:
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"ӵ�й���ԱȨ�ޣ������޸Ĳ���"<<endl; 
							modify();//�����޸ĺ��� 
							save();//���ñ��溯��  
							break;	
						}
						else
						{
							cout<<"û�й���ԱȨ�ޣ�������"<<endl;
							break;	
						}
					}
					case 5:print(); //������ʾ���� 
						   cout<<endl;
						   break;
					case 6:search(); //���ò��Һ��� 
						   break;
					case 7:paixu(); //����������
						   break;
					case 8:dingpiao(); //���ö�Ʊ���� 
							save();//���ñ��溯�� 
						   break;
					case 9:tuipiao(); //������Ʊ���� 
							save();//���ñ��溯�� 
						   break;
					case 0: save(); //���ñ��溯�� 
						   cout<<" ллʹ�ã��ټ��� "<<endl;
						   return 0;//�˳�ϵͳ
					default:cout<<"������0-9��ѡ�񣡣���"<<endl<<endl;
							break;
						   
				}
			}
		}
		else //�˻���������������Ĵ��� 
		  {  
			  k--;
			  if(k!=0)  cout<<"\n �û���������������������룡����ʣ"<<k<<"�λ��ᣩ"<<endl;           
			   else cout<<"�û�������������޷���¼ϵͳ��"<<endl;
		  }
	}
}

