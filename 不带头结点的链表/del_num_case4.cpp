  case 4: cout<<"�������ɾ����¼��ѧ��: ";
	           cin>>e.num;
	           if(!DeleteElem(T,e,EqualNum)) 
		          cout<<"û��ѧ��Ϊ"<<e.num<<"�ļ�¼"<<endl;
	           break;
	           
// ���� DeleteElem�Ķ���
Status DeleteElem(LinkList &L,ElemType &e,Status(*equal)(ElemType,ElemType))
 { // ɾ����L�����������Ľ�㣬������TRUE�����޴˽�㣬�򷵻�FALSE��
   // ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
   LinkList p,q;
   q=Point(L,e,equal,p);
   if(q) // �ҵ��˽�㣬��qָ��ý��
   {
     if(p) // �ý�㲻����Ԫ��㣬pָ����ǰ��
       ListDelete(p,2,e); // ��p��Ϊͷָ��,ɾ����2�����
     else // �ý������Ԫ���
       ListDelete(L,1,e);
     return TRUE;
   }
   return FALSE;
 } 
 //���� Point(L,e,equal,p)�Ķ���
 LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
 { // ���ұ�L�����������Ľ�㡣���ҵ�������ָ��ý���ָ�룬pָ��ý���ǰ��
   //���ý������Ԫ��㣬��p=NULL�����L�������������Ľ�㣬�򷵻�NULL��p�޶��塣
   // ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
   int i,j;
   i=LocateElem(L,e,equal);  //��i���ڵ��ѧ��==ָ��ѧ�� 
   if(i) // �ҵ�
   {
     if(i==1) // ����Ԫ���
     {
       p=NULL;
       return L;
     }
     p=L;
     for(j=2;j<i;j++)
       p=p->next;        //pָ�����������Ľڵ��ǰ�� 
     return p->next;
   }
   return NULL; // û�ҵ�
 } 
