#include"Command_operation.cpp" 
int main() //主函数
{
	//char user[10],ps[8];
    cout<<"        ********************        "<<endl;
    cout<<"           飞机订票系统"<<endl;
    cout<<"        ********************        "<<endl;
    int k=3;
    while(k>0)
	{ 	
		 char user[10],ps[8];
		 int j=0;
		 cout<<endl;
		 cout<<"        请输入用户名：";//用户名为user 
	     cin>>user;
	     cout<<"        请输入密码："; //密码为888888 
	     //密码的输入 
	    while((ps[j]=getch())!='\r')
	    {
	        if(ps[j]=='\b')//判断是否为退格 
	        {
	            if(j==0) //若j为零时，警告 
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
	     //完成输入，但又不显示，以*****形式显示 
	     if((strcmp(user,"user")==0)&&(strcmp(ps,"888888")==0))
	     {
			int ch;
			read();
			while(1){
				cout<<endl<<endl;
				cout<<"        欢迎使用航班订票系统 !"<<endl;
				cout<<"******************************************"<<endl;
				cout<<" 1.增加航班信息"<<endl;
				cout<<" 2.删除航班信息"<<endl;
				cout<<" 3.删除全部航班信息"<<endl;
				cout<<" 4.修改航班信息"<<endl;
				cout<<" 5.浏览航班信息"<<endl;
				cout<<" 6.查找航班信息"<<endl;
				cout<<" 7.航班排序 (按航班号 )"<<endl;
				cout<<" 8.办理订票业务"<<endl; 
				cout<<" 9.办理退票业务"<<endl;
				cout<<" 0.退出系统 (exit)"<<endl;
				cout<<"*******************************************"<<endl;
				cout<<" 请在 0-9 中选择以回车键结束：";
				cin>>ch;
				switch(ch)
				{
					case 1: 
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"拥有管理员权限！进行增加操作"<<endl; 
							add();//调用增加函数 
							save();//调用保存函数  
							break;	
						}
						else
						{
							cout<<"没有管理员权限！！！"<<endl;
							break;	
						}
						break;
					}
					case 2: 
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"拥有管理员权限！进行删除操作"<<endl;
							delone();//调用删除函数 
							save();//调用保存函数 
							break;	
						}
						else
						{
							cout<<"没有管理员权限！！！"<<endl;
							break;	
						}
						break;
					} 
					case 3:
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"拥有管理员权限！进行删除全部信息操作"<<endl;
							delall();//调用删除全部信息函数 
							save();//调用保存函数  
							break;	
						}
						else
						{
							cout<<"没有管理员权限！！！"<<endl;
							break;	
						}
						break;
					}
					case 4:
					{
						if(admin()==true)
						{
							cout<<endl;
							cout<<"拥有管理员权限！进行修改操作"<<endl; 
							modify();//调用修改函数 
							save();//调用保存函数  
							break;	
						}
						else
						{
							cout<<"没有管理员权限！！！！"<<endl;
							break;	
						}
					}
					case 5:print(); //调用显示函数 
						   cout<<endl;
						   break;
					case 6:search(); //调用查找函数 
						   break;
					case 7:paixu(); //调用排序函数
						   break;
					case 8:dingpiao(); //调用订票函数 
							save();//调用保存函数 
						   break;
					case 9:tuipiao(); //调用退票函数 
							save();//调用保存函数 
						   break;
					case 0: save(); //调用保存函数 
						   cout<<" 谢谢使用，再见！ "<<endl;
						   return 0;//退出系统
					default:cout<<"请重新0-9内选择！！！"<<endl<<endl;
							break;
						   
				}
			}
		}
		else //账户或密码输入有误的处理 
		  {  
			  k--;
			  if(k!=0)  cout<<"\n 用户名或密码错误，请重新输入！（还剩"<<k<<"次机会）"<<endl;           
			   else cout<<"用户名或密码错误，无法登录系统！"<<endl;
		  }
	}
}

