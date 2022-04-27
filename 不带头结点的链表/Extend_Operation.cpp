void InsertAscend(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType))
{ // 按关键字非降序将e插入表L。函数compare()返回值为形参1的关键字-形参2的关键字
	LinkList q=L;
	if(!L||compare(e,L->data)<=0) // 链表空或e的关键字小于等于首结点的关键字
		ListInsert(L,1,e); // 将e插在表头，在 Basic_Operation.cpp 中
	else
	{
		while(q->next&&compare(q->next->data,e)<0) // q不是尾结点且q的下一结点关键字<e的关键字
			q=q->next;
		ListInsert(q,2,e); // 插在q所指结点后(将q作为头指针)
	}
}

Status ReadFromFile(ElemType &e)
 { //由fp指定的文件读取结点信息到e 
   int i;
   i=fread(&e,sizeof(ElemType),1,fp);
   if(i==1) //读取文件成功 
     return OK;
   else
     return ERROR;
 }
 void WriteToFile(ElemType e)
{fwrite(&e,sizeof(ElemType),1,fp);
}

LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
{ // 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是
	// 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
	// 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
	int i,j;
	i=LocateElem(L,e,equal);
	if(i) // 找到
	{
		if(i==1) // 是首元结点
		{
			p=NULL;
			return L;
		}
		p=L;
		for(j=2;j<i;j++)
			p=p->next;
		return p->next;
	}
	return NULL; // 没找到
}
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
int Modify(LinkList &L,ElemType e)
 { //修改结点内容，并按学号将结点非降序插入链表L
   char s[80];
    print(e); //显示原内容 
   cout<<"请输入待修改项的内容，不修改的项按回车键保持原值:"<<endl;
   //修改开始 
     gets(s); 
   cout<<"请输入姓名: ";
     gets(s);
    if(strlen(s))
     strcpy(e.name,s);
     
   cout<<"请输入学号: ";
     gets(s);
   if(strlen(s))
     e.num=atol(s);
     
   cout<<"请输入性别：";
     gets(s) ;
   if(strlen(s))
     e.sex=s[0];
     
   cout<<"请输入年龄: ";
     gets(s) ; 
   if(strlen(s))
     e.age=atoi(s);
     
   cout<<"请输入班级: ";
      gets(s) ; 
   if(strlen(s))
     strcpy(e.Class,s);
     
   cout<<"请输入健康状况:"<<sta[0]<<sta[1]<<sta[2];
      gets(s) ; 
   if(strlen(s))
     e.health=atoi(s);
	  //修改完毕 
   InsertAscend(L,e,cmp); //把q所指结点的内容按学号非降序插入L
 }

