 // 几个常用的函数
 Status EqualNum(ElemType c1,ElemType c2)
 { // 判断是否相等的函数
   if(c1.num==c2.num)
     return TRUE;
   else
     return FALSE;
 }
 
 Status EqualName(ElemType c1,ElemType c2)
 { // 判断是否相等的函数
   if(strcmp(c1.name,c2.name))
     return FALSE;
   else
     return TRUE;
 }

 
 Status cmp1(ElemType a,ElemType b)
 { 
   if(a.num>b.num)
     return TRUE;
   else
     return FALSE;
 }
Status cmp2(ElemType a,ElemType b)
 { 
   if(a.num<b.num)
     return TRUE;
   else
     return FALSE;
 }
 void print(ElemType c)
 {
   cout<<"学号："<<c.num<<","<<"姓名："<<c.name<<","<<"数学："<<c.score[0]<<","<<"物理："<<c.score[1]<<","<<"化学："<<c.score[2]<<","<<"总分："<<c.score[3]<<","<<"平均分："<<c.score[4]<<endl; 
 }
 
 void input(ElemType &e)
{ cout<<"请输入学号：";
cin>>e.num;
cout<<"请输入姓名：" ;
cin>>e.name;
 cout<<"请输入数学：" ;
 cin>>e.score[0];
 cout<<"请输入物理：";
 cin>>e.score[1];
 cout<<"请输入化学：";
 cin>>e.score[2];  
 e.score[3]=e.score[0]+e.score[1]+e.score[2];
 e.score[4]=(e.score[3])/3;
}

 
