 // �������õĺ���
 Status EqualNum(ElemType c1,ElemType c2)
 { // �ж��Ƿ���ȵĺ���
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
   cout<<"����������: ";
   cin>>e.name;
   cout<<"������ѧ��: ";
   cin>>e.num;
   cout<<"�������Ա�";
   cin>>e.sex;
   cout<<"����������: ";
   cin>>e.age;
   cout<<"������༶: ";
   cin>>e.Class;
   cout<<"�����뽡��״����"<<sta[0]<<sta[1]<<sta[2]<<endl;
   cin>>e.health;
 }

 void print(ElemType c)
 {cout<<"������"<<c.name<<" ѧ�ţ�"<<c.num<<" �Ա�"<<c.sex<<" ���䣺"<<c.age<<" �༶��"<<c. Class<<" ����״����"<<c.health<<endl; 
 }

 void print2(ElemType c)
 {
   printf("%c ",c);
 }

 void print1(ElemType &c)
 {
   printf("%d ",c);
 }
