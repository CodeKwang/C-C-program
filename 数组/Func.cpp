void print(student stu)
 {
   cout<<"学号："<< stu.num<<","<<"姓名："<< stu.name<<","<<"数学："<<stu.score[0]<<","<<"物理："<< stu.score[1];
   cout<<","<<"化学："<< stu.score[2]<<","<<"总分："<< stu.score[3]<<","<<"平均分："<< stu.score[4]<<endl; 
 }
 void input(student stu[],int i)
{ 
 cout<<"请输入学号：";
 cin>>stu[i].num;
 cout<<"请输入姓名：" ;
 cin>>stu[i].name;
 cout<<"请输入数学：" ;
 cin>>stu[i].score[0];
 cout<<"请输入物理：";
 cin>>stu[i].score[1];
 cout<<"请输入化学：";
 cin>>stu[i].score[2];  
 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
 stu[i].score[4]=(stu[i].score[3])/3;
}

 
