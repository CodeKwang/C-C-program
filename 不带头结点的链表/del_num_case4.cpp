  case 4: cout<<"请输入待删除记录的学号: ";
	           cin>>e.num;
	           if(!DeleteElem(T,e,EqualNum)) 
		          cout<<"没有学号为"<<e.num<<"的记录"<<endl;
	           break;
	           
// 函数 DeleteElem的定义
Status DeleteElem(LinkList &L,ElemType &e,Status(*equal)(ElemType,ElemType))
 { // 删除表L中满足条件的结点，并返回TRUE；如无此结点，则返回FALSE。
   // 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
   LinkList p,q;
   q=Point(L,e,equal,p);
   if(q) // 找到此结点，且q指向该结点
   {
     if(p) // 该结点不是首元结点，p指向其前驱
       ListDelete(p,2,e); // 将p作为头指针,删除第2个结点
     else // 该结点是首元结点
       ListDelete(L,1,e);
     return TRUE;
   }
   return FALSE;
 } 
 //函数 Point(L,e,equal,p)的定义
 LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
 { // 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱
   //若该结点是首元结点，则p=NULL。如表L中无满足条件的结点，则返回NULL，p无定义。
   // 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
   int i,j;
   i=LocateElem(L,e,equal);  //第i个节点的学号==指定学号 
   if(i) // 找到
   {
     if(i==1) // 是首元结点
     {
       p=NULL;
       return L;
     }
     p=L;
     for(j=2;j<i;j++)
       p=p->next;        //p指向满足条件的节点的前驱 
     return p->next;
   }
   return NULL; // 没找到
 } 
