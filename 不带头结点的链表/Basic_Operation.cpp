 // 带头结点的单链表(存储结构由c2-2.h定义)的部分基本操作(9个)
 #define DestroyList ClearList // DestroyList()和ClearList()的操作是一样的 
 void InitList(LinkList &L)
 { /* 操作结果：构造一个空的线性表L */
   L=NULL; /* 指针为空 */
 }

 void ClearList(LinkList &L) /* 改变L,L为NULL */
 { /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
   LinkList p;
   while(L) /* L不空 */
   {
     p=L; //p指向首元结点
	 L=L->next; //L指向第2结点（新首元结点） 
     free(p);  
   }
 }

 Status ListEmpty(LinkList L)
 { /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
   if(L) /* 非空 */
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
   int i=0;
   LinkList p=L; /* p指向第一个结点 */
   while(p) /* 没到表尾 */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType &e) 
 { /* L为不带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
   int j=1; /* j为计数器 */
   LinkList p=L; /* p指向第一个结点 */
   if(i<1)  return ERROR; //i值不合法 
   while(p&&j<i) /* 顺指针向后查找,直到p指向第i个元素或p为空 */
   {
     p=p->next;
     j++;
   }
   if(j==i) /* 第i个元素存在 */
   { e=p->data; /* 取第i个元素 */
     return OK;
   }
   else return ERROR;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* 初始条件: 线性表L已存在,compare()是数据元素判定函数(满足为1,否则为0) */
   /* 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。 */
   /*           若这样的数据元素不存在,则返回值为0 */
   int i=0;
   LinkList p=L;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* 找到这样的数据元素 */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status ListInsert(LinkList &L,int i,ElemType e) 
 { /* 在不带头结点的单链线性表L中第i个位置之前插入元素e */
   int j=1;
   LinkList p=L,s;
   if(i<1)  return ERROR; //i的值不合法
   s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
   s->data=e; /* 给s的data成员赋值*/
   if(i==1)//插在表头 
   { s->next=L;
     L=s; //改变L 
   } 
   else
   {
      while(p&&j<i-1) /* 寻找第i-1个结点 */
      {
        p=p->next;  
        j++;      //若p指向第i-3个结点，则j=i-3 
      }
      if(!p) /* i大于表长+1 */
        return ERROR;
      s->next=p->next; //此时p指向第i-1个结点 
      p->next=s;
   } 
   return OK;
 }

 Status ListDelete(LinkList &L,int i,ElemType &e) 
 { // 在不带头结点的单链线性表L中，删除第i个元素,并由e返回其值 
   int j=1;
   LinkList p=L,q;
   if(i==1) //删除第1个结点 
   {
   	 L=p->next; //L指向第2个结点
	 e=p->data;
	 free(p); //删除并释放第1个结点 
   }
   else
   {
   	  while(p->next&&j<i-1) // 寻找第i个结点,并令p指向第i-1个结点 
      {
        p=p->next;
        j++;  //若p指向第i-3个结点，则j=i-3
      }
      //j=i-1,循环停止,此时p指向第i-1个结点 
      if(!p->next||j>i-1) // 删除位置不合理 
        return ERROR;
      q=p->next; // 删除并释放第i个结点 
      p->next=q->next;
      e=q->data;
      free(q);
   } 
   return OK;
 }

 Status ListTraverse(LinkList L,void(*vi)(ElemType))
  {  // vi的形参类型为ElemType 
    //初始条件：线性表L已存在 
   //操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 
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
 { //初始条件: 线性表L已存在 
   // 操作结果: 若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱, 
   //          返回OK;否则操作失败,pre_e无定义,返回INFEASIBLE 
   LinkList q,p; // p指向第一个结点 
   while(p->next) //p当前所指结点有后继 
   {
     q=p->next; // q为p的后继 
     if((q->data).num==cur_e.num)
     {
       pre_e=p->data;
       return OK;
     }
     p=q; // p向后移 
   }
   return INFEASIBLE;
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
 { // 初始条件：线性表L已存在 
   // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
   //           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE 
   LinkList p=L; // p指向第一个结点 
   while(p->next) // p当前所指结点有后继 
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
