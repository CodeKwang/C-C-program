#include"Base.h"

void read() //��ȡ�ļ�����
{
	FILE *fp;
	if((fp=fopen("hangban.dat","rb"))==NULL)
	{
		cout<<" �����ļ�ʧ�� ! "<<endl;
		getchar();
		return;
	}
	i=0;
	while(!feof(fp))
	{
		fread(&s[i],sizeof(struct air),1,fp); //����ȡ����
		i++; 
		m++; //������ں�����
	}
	m--;
	fclose(fp);
}

bool admin()//����Ա��¼���� 
{
	int k=3;
	while(k>0)
	{ 	
		 int j=0; 
		 char ad[10],ps[8];
		 cout<<endl;
		 cout<<"���������Ա����";//����Ա��Ϊadmin
	     cin>>ad;
	     cout<<"���������룺"; //����Ϊ888888 
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
	     if((strcmp(ad,"admin")==0)&&(strcmp(ps,"888888")==0))
	     { 
		 	return true; 
		 }
		 else //�˻���������������Ĵ��� 
		  {  
			  k--;
			  if(k!=0)  cout<<"\n ����Ա��������������������룡����ʣ"<<k<<"�λ���"<<endl;           
			   else cout<<"����Ա������������޷���¼ϵͳ��"<<endl;
		  }
    } 
    return false;
}

void save() //���溯��
{
	FILE *fp;
	if((fp=fopen("hangban.dat","wb"))==NULL)
	{
		cout<<" �����ļ�ʧ�� ! "<<endl;
		getchar();
		return;
	}
	for(i=0;i<m;i++) //��鱣������
		fwrite(&s[i],sizeof(struct air),1,fp);
	fclose(fp);
}

void add() //���Ӻ�����Ϣ����
{
	char a[10]="n"; 
	do{
		cout<<" ������������Ҫ���ӵĺ�����Ϣ (�Իس������� ): "<<endl; //��ӡ��ʾ��Ϣ
		cout<<"----------------------------------------------------"<<endl;
		cout<<" �����뺽��� : ";
		cin>>s[m].num; //��ȡ�����
		cout<<" ��������ʼվ : ";
		cin>>s[m].qidian; //��ȡ��ʼվ
		cout<<" �������յ�վ : ";
		cin>>s[m].zhongdian; //��ȡ�յ�վ
		cout<<" ������ʱ�� : ";
		cin>>s[m].time; //��ȡʱ��
		cout<<" �������Ʊ�� : ";
		cin>>s[m].count; //��ȡ��Ʊ��
		m++;
		cout<<" ������ ,�Ƿ������� ?����� y �� n �Իس������� :"<<endl;
		cin>>a;
	}while(!strcmp(a,"y")); //�ж��Ƿ�������
}

void delone()//ɾ��������Ϣ���� 
{
	print();
	int n,k,h,t=0;
	char a[10]="n";
	do
	{	
		do
		{
			cout<<"������Ҫɾ���ĺ���ţ� ";
			cin>>k; 
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) 
				{
					cout<<"��Ҫɾ���ĺ�����ϢΪ : "<<endl;
					cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl;
					printf(PRINT);//��ʾ��Ϣ
					t=1; 
					break; 
				}
			}
			if(t==1){//�˳�do...while()
				break;
			}
			cout<<"�Բ���û������Ҫ����Ϣ�� "<<endl;
			cout<<" �Ƿ����²��� ?����� y �� n �Իس������� "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// �ж��Ƿ����²���
		for(n=i;n<m-1;n++){
			s[n].count=s[n+1].count;
			s[n].num=s[n+1].num;
			strcpy(s[n].qidian,s[n+1].qidian);
			strcpy(s[n].time,s[n+1].time);
			strcpy(s[n].zhongdian,s[n+1].zhongdian);
		}
		cout<<"�����Ϊ��"<<k<<"�Ѿ���ɾ��"<<endl;
		m--; 
		cout<<" �Ƿ����ɾ�������������Ϣ ?������ y �� n �Իس������� : "<<endl;
		cin>>a;
	}while(!strcmp(a,"y"));
}
void delall()//ɾ��ȫ��������Ϣ
{
	char a[10]="n";
	print();
	cout<<"�Ƿ�Ҫɾ��ȫ��������Ϣ������(����� y �� n�Լ��س�)"<<endl;
	cin>>a;
	if(!strcmp(a,"y"))
	{
		m=0;
		cout<<"ȫ�������ѱ�ɾ��������"; 
	}
	else
	{
		cout<<"ûɾ���κ���Ϣ����"<<endl; 
	}
}

void modify()//�޸ĺ�����Ϣ 
{
	int n,k,h,t=0;
	char a[10]="y";
	do
	{	
		do
		{
			cout<<"������Ҫ�޸ĵĺ���ţ� ";
			cin>>k; 
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) 
				{
					cout<<"��Ҫ�޸ĵĺ�����ϢΪ : "<<endl;
					cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl;
					printf(PRINT);//��ʾ��Ϣ
					t=1; 
					break; 
				}
			}
			if(t==1){
				break;
			}
			cout<<"�Բ���û������Ҫ����Ϣ�� "<<endl;
			cout<<" �Ƿ����²��� ?����� y �� n �Իس������� "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// �ж��Ƿ����²��� 
		int num,count;
		char qidian[20],zhongdian[20], time[10]; 
		cout<<" ������������Ҫ�޸ĵĺ�����Ϣ (�Իس������� ): "<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<" �����뺽��� : ";
		cin>>num; //��ȡ����
		s[i].num=num;
		cout<<" ��������ʼվ : ";
		cin>>qidian; 
		strcmp(s[i].qidian,qidian);
		cout<<" �������յ�վ : ";
		cin>>zhongdian; 
		strcpy(s[i].zhongdian,zhongdian);
		cout<<" ������ʱ�� : ";
		cin>>time;
		strcpy(s[i].time,time);
		cout<<" �������Ʊ�� : ";
		cin>>count; 
		s[i].count=count;
		cout<<"���޸���ĺ�����ϢΪ : "<<endl;
		cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl;
		printf(PRINT);//��ʾ��Ϣ
		cout<<" �Ƿ�����޸������������Ϣ ?������ y �� n �Իس������� : "<<endl;
		cin>>a;
	}while(!strcmp(a,"y")); //�ж��Ƿ������Ʊ
 } 

void output() //�����ʽ����
{
	cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl; //��Ϣ����
	for(i=0;i<m;i++)
		printf(PRINT);// ��ӡ����Ϣ
}

void print() //��ʾ������Ϣ����
{
	cout<<"Ŀǰ���������º��ࣺ"<<endl;
	output(); //���������ʽ����
	getchar();
}

void search() //��ѯ����
{
	int n;
	do
	{
		cout<<"�����뺽��ţ� ";
		cin>>n; //�����ѯ�ĺ����
		for(i=0;i<m;i++)
		{
			if(s[i].num==n) //��������ж��������
			{
				cout<<"�������ҵĺ�����ϢΪ : "<<endl;
				cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl;
				printf(PRINT); //��ʾ��Ϣ
				cout<<"��ѯ��ϣ����س������� "<<endl;
				getchar();
				getchar();
				return;
			}
		}
		cout<<"�Բ���û������Ҫ����Ϣ�� "<<endl;
		cout<<" �Ƿ����²��� ?����� y �� n �Իس������� "<<endl;
		cin>>hangbanhao;
	}while(!strcmp(hangbanhao,"y"));// �ж��Ƿ����²���
} 

void dingpiao() //��Ʊҵ����
{
	print();
	int n,k,h,t=0;
	char a[10]="y";
	do
	{	
		do
		{
			cout<<"��Ҫ������ţ� ";
			cin>>k; 
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) 
				{
					cout<<"��Ҫ���ĺ�����ϢΪ : "<<endl;
					cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl;
					printf(PRINT);//��ʾ��Ϣ
					t=1; 
					break; 
				}
			}
			if(t==1){
				break;
			}
			cout<<"�Բ���û������Ҫ����Ϣ�� "<<endl;
			cout<<" �Ƿ����²��� ?����� y �� n �Իس������� "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// �ж��Ƿ����²���
		cout<<" ��������Ҫ���Ļ�Ʊ��(�Իس�������)��";
		cin>>n; //����������Ʊ��
		if(n<=0) //�ж���Ʊ���Ƿ����
		{
			cout<<" ������������趩 1 �Ż�Ʊ��"<<endl;
		}
		else if(s[i].count==0)// �ж���Ʊ�Ƿ�����
		{
			cout<<" �Բ�������ѡ��ĺ���Ļ�Ʊ������ ��"<<endl;
			break;
		}
		else if(s[i].count!=0&&s[i].count>=n) //�ж���Ʊ���Ƿ���ڵ��ڶ�Ʊ��
		{
			s[i].count=s[i].count-n;
			cout<<" ��Ʊ�ɹ� ! "<<endl;
		}
		else if(s[i].count<n)// �ж���Ʊ���Ƿ�С�ڶ�Ʊ��
		{
			cout<<" �Բ�������ѡ��ĺ���ֻʣ"<<s[i].count<<"�Ż�Ʊ "<<endl;
			cout<<"�Ƿ���Ҫ���������Ʊ�� ?������ y �� n �Իس������� : "<<endl;// �ж��Ƿ��������붩Ʊ��
			cin>>a;
		}
		cout<<" �Ƿ���Ҫ����������Ļ�Ʊ ?������ y �� n �Իس������� : "<<endl;
		cin>>a;
	}while(!strcmp(a,"y")); //�ж��Ƿ������Ʊ
}

void tuipiao() //��Ʊ����
{
	int n,k,t=0;
	char a[10];
	do
	{
		do
		{
			cout<<"��Ҫ�˺���ţ� ";
			cin>>k; //�����ѯ�ĺ����
			for(i=0;i<m;i++)
			{
				if(s[i].num==k) //��������ж��������
				{
					cout<<"��Ҫ�˵ĺ�����ϢΪ : "<<endl;
					cout<<"�����\t��ʼվ\t�յ�վ\tʱ��\t\t��Ʊ��"<<endl;
					printf(PRINT);//��ʾ��Ϣ
					t=1; 
					break; 
				}
			}
			if(t==1){
				break;
			}
			cout<<"�Բ���û������Ҫ����Ϣ�� "<<endl;
			cout<<" �Ƿ����²��� ?����� y �� n �Իس������� "<<endl;
			cin>>hangbanhao;
		}while(!strcmp(hangbanhao,"y"));// �ж��Ƿ����²���
		cout<<" ��������Ҫ�˵Ļ�Ʊ��Ŀ�� "<<endl;
		scanf("%d",&n); //��������Ʊ��
		if(n<=0) //�ж�Ʊ���Ƿ���Ч
			cout<<" ��������������� 1 �Ż�Ʊ�� "<<endl;
		else
		{
			s[i].count=s[i].count+n;
			cout<<" ��Ʊ�ɹ� ! "<<endl;
		}
		cout<<" �Ƿ������ ����� y �� n �Իس������� : "<<endl; //�ж��Ƿ������Ʊ
		cin>>a;
	}while(!strcmp(a,"y")); //�ж�������ѭ��
}

void paixu() //������
{
	int n;
	cout<<"***********************************************"<<endl;
	cout<<"1. ������Ŵ�С��������"<<endl; 
	cout<<"2. ������ŴӴ�С����"<<endl;
	cout<<"***********************************************"<<endl;
	cout<<" ���� 1-2 ��ѡ���Իس���������";
	cin>>n; //��������ʽ
	switch(n)
	{
		case 1:paixu1();// ���ô�С����������
		break;
		case 2:paixu2();// ���ôӴ�С������
		break;
	}
	cout<<" �����ĺ�����ϢΪ :"<<endl;
	output(); //��ʾ����󺽰���Ϣ
	cout<<"�밴�س������� "<<endl;
	getchar();
	getchar();
}
void paixu1() //��С����������
{
	int k,j; 
	struct air t;
	for(i=0;i<m;i++) //ѡ������
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
void paixu2() //�Ӵ�С������
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

