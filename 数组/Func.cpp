void print(student stu)
 {
   cout<<"ѧ�ţ�"<< stu.num<<","<<"������"<< stu.name<<","<<"��ѧ��"<<stu.score[0]<<","<<"����"<< stu.score[1];
   cout<<","<<"��ѧ��"<< stu.score[2]<<","<<"�ܷ֣�"<< stu.score[3]<<","<<"ƽ���֣�"<< stu.score[4]<<endl; 
 }
 void input(student stu[],int i)
{ 
 cout<<"������ѧ�ţ�";
 cin>>stu[i].num;
 cout<<"������������" ;
 cin>>stu[i].name;
 cout<<"��������ѧ��" ;
 cin>>stu[i].score[0];
 cout<<"����������";
 cin>>stu[i].score[1];
 cout<<"�����뻯ѧ��";
 cin>>stu[i].score[2];  
 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
 stu[i].score[4]=(stu[i].score[3])/3;
}

 
