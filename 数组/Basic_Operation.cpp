int search(student stu[],int n,int m)
{ int i=0;
   if(m==1)
   {   int num;
       cout<<("请输入学生的学号："); 
	   cin>>num;
	   while(i<n&&!(num==stu[i].num))
	   i++;
	   if(i<n)
	     { print(stu[i]); }
	   else
	     cout<<"所要查询的学生信息不存在！"<<endl;
   }
	else if(m==2)
	     {  student stud;
		    cout<<("请输入学生的姓名："); 
	        cin>>stud.name;
	        int j; 
              for(i=0,j=0;i<=n;i++) 
			{if((strcmp(stu[i].name,stud.name))==0) { print(stu[i]);j++; }}
			if(j==0) cout<<"所要查询的学生信息不存在！"<<endl;
		 }
	     else { cout<<"选择有误！"<<endl; }
}

 int Delete(student stu[],int n,int num) 
 {int i;  
 student stud;
   while(i<n&&!(num==stu[i].num))
	   i++;
	   if(i<n)
	     {
		   for(i;i<n;i++)
		    {stud=stu[i]; stu[i]=stu[i+1]; stu[i+1]=stud;}
		   for(i=0;i<=n-2;i++)   print(stu[i]);
		  return 1;} 
		 
	   else
	     {cout<<"所要删除的学生信息不存在！"<<endl;
	     return 0;} 
} 

void sort(student stu[],int m,int n)
{ int i,j;
   student stud;
    for(j=0;j<m-1;j++)
      for(i=0;i<m-1-j;i++)
          if(stu[i].score[n-1]<stu[i+1].score[n-1])
          {  stud=stu[i]; stu[i]=stu[i+1];stu[i+1]=stud;
		  }
    for(int t=0;t<=m-1;t++)   print(stu[t]);
}

 void Traverse(student stu[],int n)
 { student stud;        
   int i,j;
   for(j=0;j<n-1;j++)
      for(i=0;i<n-1-j;i++)
          if(stu[i].num>stu[i+1].num)
          {  stud=stu[i]; stu[i]=stu[i+1];stu[i+1]=stud;
		  }
   for(int i=0;i<=n-1;i++)   print(stu[i]);
   cout<<endl; 
} 
