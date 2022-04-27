 // 几个常用的函数
 Status EqualNum(ElemType c1,ElemType c2)
 { // 判断是否相等的函数
   if(c1.num==c2.num)
     return TRUE;
   else
     return FALSE;
 }
Status EqualName(ElemType c1,ElemType c2)
{ 
  if(strcmp(c1.name,c2.name))
     return FALSE;
  else
     return TRUE;
}
 int cmp(ElemType c1,ElemType c2)
 {
    return(int)(c1.num-c2.num);
 }
 void ReadIn(ElemType &e)
 {
   cout<<"请输入姓名: ";
   cin>>e.name;
   cout<<"请输入学号: ";
   cin>>e.num;
   cout<<"请输入性别；";
   cin>>e.sex;
   cout<<"请输入年龄: ";
   cin>>e.age;
   cout<<"请输入班级: ";
   cin>>e.Class;
   cout<<"请输入健康状况；"<<sta[0]<<sta[1]<<sta[2]<<endl;
   cin>>e.health;
 }

 void print(ElemType c)
 {cout<<"姓名："<<c.name<<" 学号："<<c.num<<" 性别："<<c.sex<<" 年龄："<<c.age<<" 班级："<<c. Class<<" 健康状况："<<c.health<<endl; 
 }

 void print2(ElemType c)
 {
   printf("%c ",c);
 }

 void print1(ElemType &c)
 {
   printf("%d ",c);
 }
