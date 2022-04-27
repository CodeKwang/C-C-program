 // Basic_Operation.cpp ˳���ʾ�����Ա�(�洢�ṹ��c2.h����)�Ļ�������
 void InitList(SqList &L) // ����һ���յ�˳�����Ա�L
 { 
   L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
     exit(OVERFLOW); // �洢����ʧ��;OVERFLOWΪһ���궨�壬��ֵΪ3;�˳����򣬳��򷵻ظ�����ϵͳ�ķ�������OVERFLOW
   L.length=0; // �ձ���Ϊ0
   L.listsize=LIST_INIT_SIZE; // ��ʼ�洢����
 }

 void DestroyList(SqList &L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
   free(L.elem);
   L.elem=NULL;
   L.length=0;
   L.listsize=0;
 }

 void ClearList(SqList &L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   L.length=0;
 }

 Status ListEmpty(SqList L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
   return L.length;
 }
Status GetElem(SqList L,int i,ElemType &e)
 {if(i<1||i>L.length)
 return ERROR;
 e=*(L.elem+i-1);
 return OK;
}
 
 int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
   // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
   ElemType *p;
   int i=1; 
   p=L.elem;
   while(i<=L.length&&!compare(*p++,e))
   i++;
   if(i<=L.length)
   return i;
   else
   return 0;   
 }

int search(SqList L,int m)
{  ElemType e,*q;
   int i;
   if(m==1)
   {   cout<<("������ѧ����ѧ�ţ�"); 
	   cin>>e.num;
	   i=LocateElem(L,e,EqualNum);
	   if(i) { q=L.elem+i-1;  print(*q); }
	     else cout<<"��Ҫ��ѯ��ѧ����Ϣ�����ڣ�"<<endl;
   }
	else if(m==2)
	     {  cout<<("������ѧ����������"); 
	        cin>>e.name;
	        int i,j;
	        q=L.elem;
            for(i=1,j=0;i<=L.length;i++,q++) 
			    if(EqualName(*q,e)) {  print(*q); j++;  }
			if(j==0) cout<<"��Ҫ��ѯ��ѧ����Ϣ�����ڣ�"<<endl;
		 }
		   else { cout<<"ѡ������"<<endl; }
}
 
Status ListInsert(SqList &L,ElemType e) 
 { 
   int i;
   ElemType *newbase,*q,*p;
   i=LocateElem(L,e,cmp1);   // i��ֵΪ0��1-length 
   if(L.length==L.listsize) // ��ǰ�洢�ռ�����,���ӷ���
   {
     if(!(newbase=(ElemType *)realloc(L.elem,(L.listsize+LIST_INCREMENT)*sizeof(ElemType))))
       exit(OVERFLOW); // �洢����ʧ��
     L.elem=newbase; // �»�ַ
     L.listsize+=LIST_INCREMENT; // ���Ӵ洢����
   }
   if(i)
   {  q=L.elem+i-1; // qΪ����λ��
      for(p=L.elem+L.length-1;p>=q;--p) *(p+1)=*p;// ����λ�ü�֮���Ԫ������
      *q=e; // ����e
      ++L.length; // ����1
   }
      else
	  {  if(L.length==0) {  *L.elem=e; ++L.length;  } 
	       else {  *(L.elem+L.length)=e;  ++L.length;  }
	  } 
   return OK;
}
 void ListDelete(SqList &L,ElemType &e) 
{    
    int i; 
 ElemType *p,*q;
 i=LocateElem(L,e,EqualNum);
 if(i)
 {  p=L.elem+i-1;
    e=*p;
    q=L.elem+L.length-1;
    while(p<q)
    {*p=*(p+1);
     p++;
	}
	L.length--; 
}
}
void sort(SqList L,int n)
{ int i,j;
   ElemType e; 
        for(j=0;j<L.length-1;j++)
         { for(i=0;i<L.length-1-j;i++)
          if((L.elem+i)->score[n-1]<(L.elem+i+1)->score[n-1])
          {  e=*(L.elem+i); *(L.elem+i)=*(L.elem+i+1); *(L.elem+i+1)=e;
		  }
}
}
 void ListTraverse(SqList L,void(*vi)(ElemType))
 { // ��ʼ������˳�����Ա�L�Ѵ���
   // ������������ζ�L��ÿ������Ԫ�ص��ú���vi()         
   ElemType *p;
   int i;
   if(ListEmpty(L))  cout<<"����Ϊ�գ����κ�ѧ����Ϣ��"<<endl;
   p=L.elem;
   for(i=1;i<=L.length;i++)   vi(*p++);
   printf("\n");
}


