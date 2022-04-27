#include"Base.h"

void read() //读取文件函数
{
	FILE *fp;
	if((fp=fopen("hangban.dat","rb"))==NULL)
	{
		cout<<" 创建文件失败 ! "<<endl;
		getchar();
		return;
	}
	i=0;
	while(!feof(fp))
	{
		fread(&s[i],sizeof(struct air),1,fp); //逐块读取数据
		i++; 
		m++; //计算存在航班数
	}
	m--;
	fclose(fp);
}

bool admin()//管理员登录函数 
{
	int k=3;
	while(k>0)
	{ 	
		 int j=0; 
		 char ad[10],ps[8];
		 cout<<endl;
		 cout<<"请输入管理员名：";//管理员名为admin
	     cin>>ad;
	     cout<<"请输入密码："; //密码为888888 
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
	     if((strcmp(ad,"admin")==0)&&(strcmp(ps,"888888")==0))
	     { 
		 	return true; 
		 }
		 else //账户或密码输入有误的处理 
		  {  
			  k--;
			  if(k!=0)  cout<<"\n 管理员名或密码错误，请重新输入！（还剩"<<k<<"次机会"<<endl;           
			   else cout<<"管理员名或密码错误，无法登录系统！"<<endl;
		  }
    } 
    return false;
}

void save() //保存函数
{
	FILE *fp;
	if((fp=fopen("hangban.dat","wb"))==NULL)
	{
		cout<<" 创建文件失败 ! "<<endl;
		getchar();
		return;
	}
	for(i=0;i<m;i++) //逐块保存数据
		fwrite(&s[i],sizeof(struct air),1,fp);
	fclose(fp);
}

void add() //增加航班信息函数
{
	char a[10]="n"; 
	do{
		cout<<" 请依次输入您要增加的航班信息 (以回车键结束 ): "<<endl; //打印提示信息
		cout<<"----------------------------------------------------"<<endl;
		cout<<" 请输入航班号 : ";
		cin>>s[m].num; //读取航班号
		cout<<" 请输入起始站 : ";
		cin>>s[m].qidian; //读取起始站
		cout<<" 请输入终点站 : ";
		cin>>s[m].zhongdian; //读取终点站
		cout<<" 请输入时间 : ";
		cin>>s[m].time; //读取时间
		cout<<" 请输入机票数 : ";
		cin>>s[m].count; //读取机票数
		m++;
		cout<<" 添加完毕 ,是否继续添加 ?请键入 y 或 n 以回车键结束 :"<<endl;
		cin>>a;
	}while(!strcmp(a,"y")); //判断是否继续添加
}

void delone()//删除航班信息函数 
{
	print();
	int n,k,h,t=0;
	char a[10]="n";
	do
	{	
		do
		{
			cout<<"请输入要删除的航班号： ";
			cin>>k; 
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) 
				{
					cout<<"您要删除的航班信息为 : "<<endl;
					cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl;
					printf(PRINT);//显示信息
					t=1; 
					break; 
				}
			}
			if(t==1){//退出do...while()
				break;
			}
			cout<<"对不起，没有您需要的信息！ "<<endl;
			cout<<" 是否重新查找 ?请键入 y 或 n 以回车键结束 "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// 判定是否重新查找
		for(n=i;n<m-1;n++){
			s[n].count=s[n+1].count;
			s[n].num=s[n+1].num;
			strcpy(s[n].qidian,s[n+1].qidian);
			strcpy(s[n].time,s[n+1].time);
			strcpy(s[n].zhongdian,s[n+1].zhongdian);
		}
		cout<<"航班号为："<<k<<"已经被删除"<<endl;
		m--; 
		cout<<" 是否继续删除其他航班的信息 ?请输入 y 或 n 以回车键结束 : "<<endl;
		cin>>a;
	}while(!strcmp(a,"y"));
}
void delall()//删除全部航班信息
{
	char a[10]="n";
	print();
	cout<<"是否要删除全部航班信息？？？(请键入 y 或 n以及回车)"<<endl;
	cin>>a;
	if(!strcmp(a,"y"))
	{
		m=0;
		cout<<"全部航班已被删除！！！"; 
	}
	else
	{
		cout<<"没删除任何信息！！"<<endl; 
	}
}

void modify()//修改航班信息 
{
	int n,k,h,t=0;
	char a[10]="y";
	do
	{	
		do
		{
			cout<<"请输入要修改的航班号： ";
			cin>>k; 
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) 
				{
					cout<<"您要修改的航班信息为 : "<<endl;
					cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl;
					printf(PRINT);//显示信息
					t=1; 
					break; 
				}
			}
			if(t==1){
				break;
			}
			cout<<"对不起，没有您需要的信息！ "<<endl;
			cout<<" 是否重新查找 ?请键入 y 或 n 以回车键结束 "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// 判定是否重新查找 
		int num,count;
		char qidian[20],zhongdian[20], time[10]; 
		cout<<" 请依次输入您要修改的航班信息 (以回车键结束 ): "<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<" 请输入航班号 : ";
		cin>>num; //读取航班
		s[i].num=num;
		cout<<" 请输入起始站 : ";
		cin>>qidian; 
		strcmp(s[i].qidian,qidian);
		cout<<" 请输入终点站 : ";
		cin>>zhongdian; 
		strcpy(s[i].zhongdian,zhongdian);
		cout<<" 请输入时间 : ";
		cin>>time;
		strcpy(s[i].time,time);
		cout<<" 请输入机票数 : ";
		cin>>count; 
		s[i].count=count;
		cout<<"您修改完的航班信息为 : "<<endl;
		cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl;
		printf(PRINT);//显示信息
		cout<<" 是否继续修改其他航班的信息 ?请输入 y 或 n 以回车键结束 : "<<endl;
		cin>>a;
	}while(!strcmp(a,"y")); //判定是否继续订票
 } 

void output() //输出格式函数
{
	cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl; //信息标题
	for(i=0;i<m;i++)
		printf(PRINT);// 打印出信息
}

void print() //显示航班信息函数
{
	cout<<"目前我们有如下航班："<<endl;
	output(); //调用输出格式函数
	getchar();
}

void search() //查询函数
{
	int n;
	do
	{
		cout<<"请输入航班号： ";
		cin>>n; //输入查询的航班号
		for(i=0;i<m;i++)
		{
			if(s[i].num==n) //按航班号判定输出条件
			{
				cout<<"您所查找的航班信息为 : "<<endl;
				cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl;
				printf(PRINT); //显示信息
				cout<<"查询完毕，按回车键继续 "<<endl;
				getchar();
				getchar();
				return;
			}
		}
		cout<<"对不起，没有您需要的信息！ "<<endl;
		cout<<" 是否重新查找 ?请键入 y 或 n 以回车键结束 "<<endl;
		cin>>hangbanhao;
	}while(!strcmp(hangbanhao,"y"));// 判定是否重新查找
} 

void dingpiao() //订票业务函数
{
	print();
	int n,k,h,t=0;
	char a[10]="y";
	do
	{	
		do
		{
			cout<<"请要订航班号： ";
			cin>>k; 
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) 
				{
					cout<<"您要订的航班信息为 : "<<endl;
					cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl;
					printf(PRINT);//显示信息
					t=1; 
					break; 
				}
			}
			if(t==1){
				break;
			}
			cout<<"对不起，没有您需要的信息！ "<<endl;
			cout<<" 是否重新查找 ?请键入 y 或 n 以回车键结束 "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// 判定是否重新查找
		cout<<" 请输入您要订的机票数(以回车键结束)：";
		cin>>n; //输入所订机票数
		if(n<=0) //判定机票数是否出错
		{
			cout<<" 输入错误！至少需订 1 张机票。"<<endl;
		}
		else if(s[i].count==0)// 判定机票是否售完
		{
			cout<<" 对不起，你所选择的航班的机票已售完 ！"<<endl;
			break;
		}
		else if(s[i].count!=0&&s[i].count>=n) //判定机票数是否大于等于订票数
		{
			s[i].count=s[i].count-n;
			cout<<" 订票成功 ! "<<endl;
		}
		else if(s[i].count<n)// 判定机票数是否小于订票数
		{
			cout<<" 对不起，你所选择的航班只剩"<<s[i].count<<"张机票 "<<endl;
			cout<<"是否需要重新输入机票数 ?请输入 y 或 n 以回车键结束 : "<<endl;// 判定是否重新输入订票数
			cin>>a;
		}
		cout<<" 是否需要订其他航班的机票 ?请输入 y 或 n 以回车键结束 : "<<endl;
		cin>>a;
	}while(!strcmp(a,"y")); //判定是否继续订票
}

void tuipiao() //退票函数
{
	int n,k,t=0;
	char a[10];
	do
	{
		do
		{
			cout<<"请要退航班号： ";
			cin>>k; //输入查询的航班号
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) //按航班号判定输出条件
				{
					cout<<"您要退的航班信息为 : "<<endl;
					cout<<"航班号\t起始站\t终点站\t时间\t\t机票数"<<endl;
					printf(PRINT);//显示信息
					t=1; 
					break; 
				}
			}
			if(t==1){
				break;
			}
			cout<<"对不起，没有您需要的信息！ "<<endl;
			cout<<" 是否重新查找 ?请键入 y 或 n 以回车键结束 "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// 判定是否重新查找
		cout<<" 请输入您要退的机票数目： "<<endl;
		scanf("%d",&n); //输入所退票数
		if(n<=0) //判定票数是否有效
			cout<<" 输入错误！至少需退 1 张机票。 "<<endl;
		else
		{
			s[i].count=s[i].count+n;
			cout<<" 退票成功 ! "<<endl;
		}
		cout<<" 是否继续？ 请键入 y 或 n 以回车键结束 : "<<endl; //判定是否继续退票
		cin>>a;
	}while(!strcmp(a,"y")); //判定并跳出循环
}

void paixu() //排序函数
{
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"1. 按航班号从小到大排序"<<endl; 
	cout<<"2. 按航班号从大到小排序"<<endl;
	cout<<"***********************************************"<<endl;
	cout<<" 请在 1-2 中选择以回车键结束：";
	cin>>n; //输入排序方式
	switch(n)
	{
		case 1:paixu1();// 调用从小到大排序函数
		break;
		case 2:paixu2();// 调用从大到小排序函数
		break;
	}
	cout<<" 排序后的航班信息为 :"<<endl;
	output(); //显示排序后航班信息
	cout<<"请按回车键结束 "<<endl;
	getchar();
	getchar();
}
void paixu1() //从小到大排序函数
{
	int k,j; 
	struct air t;
	for(i=0;i<m;i++) //选择法排序
	{
		k=i;
		for(j=i+1;j<m;j++)
			if(s[k].num>s[j].num)
				k=j;
		if(i!=k)
		{
			t=s[k];
			s[k]=s[i];
			s[i]=t;
		}
	}
}
void paixu2() //从大到小排序函数
{
	int k,j;
	struct air t;
	for(i=0;i<m;i++)
	{
		k=i;
		for(j=i+1;j<m;j++)
			if(s[k].num<s[j].num)
				k=j;
		if(i!=k)
		{
			t=s[k];
			s[k]=s[i];
			s[i]=t;
		}
	}
}

