// ������ͷ���ĵ�����ṹ����ѧ�������ǼǱ�
 #include"c1.h"
 #include"c2-2.h"
 #include"Common_Function.cpp"
 #include"Basic_Operation.cpp" // ��ͷ��㵥����Ĳ��ֻ�������
 #include"Extend_Operation.cpp" // ��ͷ��㵥�������չ����
int main()
 { // ��ĳ�ʼ��¼
   stud student[4]={{"��С��",760631,'m',19,"��91",0},{"��С��",780632,'f',19,"��91",2},
		    {"��Сƽ",790933,'f',20,"��91",0},{"��С��",790434,'m',17,"��91",1}};
   int i,j,flag=1;
   LinkList T,p,q;
   char filename[20];
   ElemType e;
   InitList(T); // ��ʼ������
   while(flag)
   {
     cout<<"1:���ṹ������student�еļ�¼��ѧ�ŷǽ����������"<<endl;
     cout<<"2:���ļ��еļ�¼��ѧ�ŷǽ����������"<<endl;
     cout<<"3:���������¼�¼�������䰴ѧ�ŷǽ����������"<<endl;
     cout<<"4:ɾ�������е�һ���и���ѧ�ŵļ�¼"<<endl;
     cout<<"5:ɾ�������е�һ���и��������ļ�¼"<<endl;
     cout<<"6:�޸������е�һ���и���ѧ�ŵļ�¼"<<endl;
     cout<<"7:�޸������е�һ���и��������ļ�¼"<<endl;
     cout<<"8:���������е�һ���и���ѧ�ŵļ�¼"<<endl;
     cout<<"9:���������е�һ���и��������ļ�¼"<<endl;
     cout<<"10:��ʾ���м�¼"<<endl;
     cout<<"11:�������е����м�¼�����ļ�"<<endl;
     cout<<"12:����"<<endl;
     cout<<"��ѡ���������: "<<endl;
     cin>>i;
     switch(i)
     {
       case 1: for(j=0;j<4;j++)
	         InsertAscend(T,student[j],cmp); 
	         break;
       case 2: cout<<"�������ļ���: ";
			   cin>>filename;
			if((fp=fopen(filename,"rb"))==NULL)
				printf("���ļ�ʧ��!\n");
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
       case 4:cout<<"�������ɾ����¼��ѧ��: ";
               cin>>e.num;
               if(!DeleteElem(T,e,EqualNum)) 
                 cout<<"û��ѧ��Ϊ"<<e.num<<"�ļ�¼"<<endl;
	       break;
       case 5:cout<<"�������ɾ����¼������: ";
              cin>>e.name;
               if(!DeleteElem(T,e,EqualName)) 
             cout<<"û������Ϊ"<<e.name<<"�ļ�¼"<<endl;
	           break;
       case 6:cout<<"��������޸ļ�¼��ѧ��: ";
               cin>>e.num;
               if(!DeleteElem(T,e,EqualNum)) 
                 cout<<"û��ѧ��Ϊ"<<e.num<<"�ļ�¼"<<endl;
               else
                 Modify(T,e);
	         break;
       case 7:cout<<"��������޼�¼������:";
	          cin>>e.name;
	     	 if(!DeleteElem(T,e,EqualName)) 
                 cout<<"û������Ϊ"<<e.name<<"�ļ�¼"<<endl;
               else
                 Modify(T,e);	   
	       break;
       case 8:cout<<"����������Ҽ�¼��ѧ��:";
              cin>>e.num;
			  q=Point(T,e,EqualNum,p);
			  if(!q)
			  cout<<"û��ѧ��Ϊ"<<e.num<<"�ļ�¼"<<endl;
			  else
			   print(q->data);
	       break;
       case 9:cout<<"����������Ҽ�¼������:";
              cin>>e.name;
			  q=Point(T,e,EqualNum,p) ;
			  if(!q)
			  cout<<"û������Ϊ"<<e.name<<"�ļ�¼"<<endl;
			  else
			   print(q->data);
	       break;
       case 10:
           ListTraverse(T,print) ;
	       break;
       case 11:cout<<"�������ļ�����";
	           cin>>filename;
			   if((fp=fopen(filename,"wb"))==NULL) 
			   cout<<"���ļ�ʧ�ܣ�"<<endl;
			   else
			   ListTraverse(T,WriteToFile);
			   fclose(fp);
	           break;
       case 12:flag=0;
     }
   }
   return 0;
 }

