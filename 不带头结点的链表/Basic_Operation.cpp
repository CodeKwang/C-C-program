 // ��ͷ���ĵ�����(�洢�ṹ��c2-2.h����)�Ĳ��ֻ�������(9��)
 #define DestroyList ClearList // DestroyList()��ClearList()�Ĳ�����һ���� 
 void InitList(LinkList &L)
 { /* �������������һ���յ����Ա�L */
   L=NULL; /* ָ��Ϊ�� */
 }

 void ClearList(LinkList &L) /* �ı�L,LΪNULL */
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   LinkList p;
   while(L) /* L���� */
   {
     p=L; //pָ����Ԫ���
	 L=L->next; //Lָ���2��㣨����Ԫ��㣩 
     free(p);  
   }
 }

 Status ListEmpty(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L) /* �ǿ� */
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList p=L; /* pָ���һ����� */
   while(p) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType &e) 
 { /* LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
   int j=1; /* jΪ������ */
   LinkList p=L; /* pָ���һ����� */
   if(i<1)  return ERROR; //iֵ���Ϸ� 
   while(p&&j<i) /* ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ�� */
   {
     p=p->next;
     j++;
   }
   if(j==i) /* ��i��Ԫ�ش��� */
   { e=p->data; /* ȡ��i��Ԫ�� */
     return OK;
   }
   else return ERROR;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* ��ʼ����: ���Ա�L�Ѵ���,compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
   /* �������: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز�����,�򷵻�ֵΪ0 */
   int i=0;
   LinkList p=L;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* �ҵ�����������Ԫ�� */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status ListInsert(LinkList &L,int i,ElemType e) 
 { /* �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
   int j=1;
   LinkList p=L,s;
   if(i<1)  return ERROR; //i��ֵ���Ϸ�
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ��s��data��Ա��ֵ*/
   if(i==1)//���ڱ�ͷ 
   { s->next=L;
     L=s; //�ı�L 
   } 
   else
   {
      while(p&&j<i-1) /* Ѱ�ҵ�i-1����� */
      {
        p=p->next;  
        j++;      //��pָ���i-3����㣬��j=i-3 
      }
      if(!p) /* i���ڱ�+1 */
        return ERROR;
      s->next=p->next; //��ʱpָ���i-1����� 
      p->next=s;
   } 
   return OK;
 }

 Status ListDelete(LinkList &L,int i,ElemType &e) 
 { // �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ 
   int j=1;
   LinkList p=L,q;
   if(i==1) //ɾ����1����� 
   {
   	 L=p->next; //Lָ���2�����
	 e=p->data;
	 free(p); //ɾ�����ͷŵ�1����� 
   }
   else
   {
   	  while(p->next&&j<i-1) // Ѱ�ҵ�i�����,����pָ���i-1����� 
      {
        p=p->next;
        j++;  //��pָ���i-3����㣬��j=i-3
      }
      //j=i-1,ѭ��ֹͣ,��ʱpָ���i-1����� 
      if(!p->next||j>i-1) // ɾ��λ�ò����� 
        return ERROR;
      q=p->next; // ɾ�����ͷŵ�i����� 
      p->next=q->next;
      e=q->data;
      free(q);
   } 
   return OK;
 }

 Status ListTraverse(LinkList L,void(*vi)(ElemType))
  {  // vi���β�����ΪElemType 
    //��ʼ���������Ա�L�Ѵ��� 
   //�������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� 
   LinkList p=L;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   cout<<endl;
   return OK;
 }
 
 Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
 { //��ʼ����: ���Ա�L�Ѵ��� 
   // �������: ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��, 
   //          ����OK;�������ʧ��,pre_e�޶���,����INFEASIBLE 
   LinkList q,p; // pָ���һ����� 
   while(p->next) //p��ǰ��ָ����к�� 
   {
     q=p->next; // qΪp�ĺ�� 
     if((q->data).num==cur_e.num)
     {
       pre_e=p->data;
       return OK;
     }
     p=q; // p����� 
   }
   return INFEASIBLE;
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
 { // ��ʼ���������Ա�L�Ѵ��� 
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
   //           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE 
   LinkList p=L; // pָ���һ����� 
   while(p->next) // p��ǰ��ָ����к�� 
   {
     if((p->data).num==cur_e.num)
     {
       next_e=p->next->data;
       return OK;
     }
     p=p->next;
   }
   return INFEASIBLE;
 }
