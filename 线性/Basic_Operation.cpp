 // Basic_Operation.cpp 顺序表示的线性表(存储结构由c2.h定义)的基本操作
 void InitList(SqList &L) // 构造一个空的顺序线性表L
 { 
   L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
     exit(OVERFLOW); // 存储分配失败;OVERFLOW为一个宏定义，其值为3;退出程序，程序返回给操作系统的返回码是OVERFLOW
   L.length=0; // 空表长度为0
   L.listsize=LIST_INIT_SIZE; // 初始存储容量
 }

 void DestroyList(SqList &L)
 { // 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
   free(L.elem);
   L.elem=NULL;
   L.length=0;
   L.listsize=0;
 }

 void ClearList(SqList &L)
 { // 初始条件：顺序线性表L已存在。操作结果：将L重置为空表
   L.length=0;
 }

 Status ListEmpty(SqList L)
 { // 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { // 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数
   return L.length;
 }
Status GetElem(SqList L,int i,ElemType &e)
 {if(i<1||i>L.length)
 return ERROR;
 e=*(L.elem+i-1);
 return OK;
}
 
 int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // 初始条件：顺序线性表L已存在，compare()是数据元素判定函数
   // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
   //           若这样的数据元素不存在，则返回值为0。
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
   {   cout<<("请输入学生的学号："); 
	   cin>>e.num;
	   i=LocateElem(L,e,EqualNum);
	   if(i) { q=L.elem+i-1;  print(*q); }
	     else cout<<"所要查询的学生信息不存在！"<<endl;
   }
	else if(m==2)
	     {  cout<<("请输入学生的姓名："); 
	        cin>>e.name;
	        int i,j;
	        q=L.elem;
            for(i=1,j=0;i<=L.length;i++,q++) 
			    if(EqualName(*q,e)) {  print(*q); j++;  }
			if(j==0) cout<<"所要查询的学生信息不存在！"<<endl;
		 }
		   else { cout<<"选择有误！"<<endl; }
}
 
Status ListInsert(SqList &L,ElemType e) 
 { 
   int i;
   ElemType *newbase,*q,*p;
   i=LocateElem(L,e,cmp1);   // i的值为0或1-length 
   if(L.length==L.listsize) // 当前存储空间已满,增加分配
   {
     if(!(newbase=(ElemType *)realloc(L.elem,(L.listsize+LIST_INCREMENT)*sizeof(ElemType))))
       exit(OVERFLOW); // 存储分配失败
     L.elem=newbase; // 新基址
     L.listsize+=LIST_INCREMENT; // 增加存储容量
   }
   if(i)
   {  q=L.elem+i-1; // q为插入位置
      for(p=L.elem+L.length-1;p>=q;--p) *(p+1)=*p;// 插入位置及之后的元素下移
      *q=e; // 插入e
      ++L.length; // 表长增1
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
 { // 初始条件：顺序线性表L已存在
   // 操作结果：依次对L的每个数据元素调用函数vi()         
   ElemType *p;
   int i;
   if(ListEmpty(L))  cout<<"数据为空，无任何学生信息！"<<endl;
   p=L.elem;
   for(i=1;i<=L.length;i++)   vi(*p++);
   printf("\n");
}


