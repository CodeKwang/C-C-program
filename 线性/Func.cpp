 // �������õĺ���
 Status EqualNum(ElemType c1,ElemType c2)
 { // �ж��Ƿ���ȵĺ���
   if(c1.num==c2.num)
     return TRUE;
   else
     return FALSE;
 }
 
 Status EqualName(ElemType c1,ElemType c2)
 { // �ж��Ƿ���ȵĺ���
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
   cout<<"ѧ�ţ�"<<c.num<<","<<"������"<<c.name<<","<<"��ѧ��"<<c.score[0]<<","<<"����"<<c.score[1]<<","<<"��ѧ��"<<c.score[2]<<","<<"�ܷ֣�"<<c.score[3]<<","<<"ƽ���֣�"<<c.score[4]<<endl; 
 }
 
 void input(ElemType &e)
{ cout<<"������ѧ�ţ�";
cin>>e.num;
cout<<"������������" ;
cin>>e.name;
 cout<<"��������ѧ��" ;
 cin>>e.score[0];
 cout<<"����������";
 cin>>e.score[1];
 cout<<"�����뻯ѧ��";
 cin>>e.score[2];  
 e.score[3]=e.score[0]+e.score[1]+e.score[2];
 e.score[4]=(e.score[3])/3;
}

 
