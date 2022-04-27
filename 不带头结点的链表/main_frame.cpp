// 利用无头结点的单链表结构处理学生健康登记表
 #include"c1.h"
 #include"c2-2.h"
 #include"Common_Function.cpp"
 #include"Basic_Operation.cpp" // 无头结点单链表的部分基本操作
 #include"Extend_Operation.cpp" // 无头结点单链表的扩展操作
int main()
 { // 表的初始记录
   stud student[4]={{"黄小宇",760631,'m',19,"计91",0},{"刘小红",780632,'f',19,"计91",2},
		    {"孟小平",790933,'f',20,"计91",0},{"李小明",790434,'m',17,"计91",1}};
   int i,j,flag=1;
   LinkList T,p,q;
   char filename[20];
   ElemType e;
   InitList(T); // 初始化链表
   while(flag)
   {
     cout<<"1:将结构体数组student中的记录按学号非降序插入链表"<<endl;
     cout<<"2:将文件中的记录按学号非降序插入链表"<<endl;
     cout<<"3:键盘输入新记录，并将其按学号非降序插入链表"<<endl;
     cout<<"4:删除链表中第一个有给定学号的记录"<<endl;
     cout<<"5:删除链表中第一个有给定姓名的记录"<<endl;
     cout<<"6:修改链表中第一个有给定学号的记录"<<endl;
     cout<<"7:修改链表中第一个有给定姓名的记录"<<endl;
     cout<<"8:查找链表中第一个有给定学号的记录"<<endl;
     cout<<"9:查找链表中第一个有给定姓名的记录"<<endl;
     cout<<"10:显示所有记录"<<endl;
     cout<<"11:将链表中的所有记录存入文件"<<endl;
     cout<<"12:结束"<<endl;
     cout<<"请选择操作命令: "<<endl;
     cin>>i;
     switch(i)
     {
       case 1: for(j=0;j<4;j++)
	         InsertAscend(T,student[j],cmp); 
	         break;
       case 2: cout<<"请输入文件名: ";
			   cin>>filename;
			if((fp=fopen(filename,"rb"))==NULL)
				printf("打开文件失败!\n");
			else
			{
				while(ReadFromFile(e))
				InsertAscend(T,e,cmp); 
				fclose(fp);
			}
	       break;
       case 3:  ReadIn(e);
			InsertAscend(T,e,cmp);
	       break;
       case 4:cout<<"请输入待删除记录的学号: ";
               cin>>e.num;
               if(!DeleteElem(T,e,EqualNum)) 
                 cout<<"没有学号为"<<e.num<<"的记录"<<endl;
	       break;
       case 5:cout<<"请输入待删除记录的姓名: ";
              cin>>e.name;
               if(!DeleteElem(T,e,EqualName)) 
             cout<<"没有姓名为"<<e.name<<"的记录"<<endl;
	           break;
       case 6:cout<<"请输入待修改记录的学号: ";
               cin>>e.num;
               if(!DeleteElem(T,e,EqualNum)) 
                 cout<<"没有学号为"<<e.num<<"的记录"<<endl;
               else
                 Modify(T,e);
	         break;
       case 7:cout<<"请输入待修记录的姓名:";
	          cin>>e.name;
	     	 if(!DeleteElem(T,e,EqualName)) 
                 cout<<"没有姓名为"<<e.name<<"的记录"<<endl;
               else
                 Modify(T,e);	   
	       break;
       case 8:cout<<"请输入待查找记录的学号:";
              cin>>e.num;
			  q=Point(T,e,EqualNum,p);
			  if(!q)
			  cout<<"没有学号为"<<e.num<<"的记录"<<endl;
			  else
			   print(q->data);
	       break;
       case 9:cout<<"请输入待查找记录的姓名:";
              cin>>e.name;
			  q=Point(T,e,EqualNum,p) ;
			  if(!q)
			  cout<<"没有姓名为"<<e.name<<"的记录"<<endl;
			  else
			   print(q->data);
	       break;
       case 10:
           ListTraverse(T,print) ;
	       break;
       case 11:cout<<"请输入文件名：";
	           cin>>filename;
			   if((fp=fopen(filename,"wb"))==NULL) 
			   cout<<"打开文件失败！"<<endl;
			   else
			   ListTraverse(T,WriteToFile);
			   fclose(fp);
	           break;
       case 12:flag=0;
     }
   }
   return 0;
 }

