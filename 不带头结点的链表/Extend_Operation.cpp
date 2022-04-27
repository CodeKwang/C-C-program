void InsertAscend(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType))
{ // ���ؼ��ַǽ���e�����L������compare()����ֵΪ�β�1�Ĺؼ���-�β�2�Ĺؼ���
	LinkList q=L;
	if(!L||compare(e,L->data)<=0) // ����ջ�e�Ĺؼ���С�ڵ����׽��Ĺؼ���
		ListInsert(L,1,e); // ��e���ڱ�ͷ���� Basic_Operation.cpp ��
	else
	{
		while(q->next&&compare(q->next->data,e)<0) // q����β�����q����һ���ؼ���<e�Ĺؼ���
			q=q->next;
		ListInsert(q,2,e); // ����q��ָ����(��q��Ϊͷָ��)
	}
}

Status ReadFromFile(ElemType &e)
 { //��fpָ�����ļ���ȡ�����Ϣ��e 
   int i;
   i=fread(&e,sizeof(ElemType),1,fp);
   if(i==1) //��ȡ�ļ��ɹ� 
     return OK;
   else
     return ERROR;
 }
 void WriteToFile(ElemType e)
{fwrite(&e,sizeof(ElemType),1,fp);
}

LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
{ // ���ұ�L�����������Ľ�㡣���ҵ�������ָ��ý���ָ�룬pָ��ý���ǰ��(���ý����
	// ��Ԫ��㣬��p=NULL)�����L�������������Ľ�㣬�򷵻�NULL��p�޶��塣
	// ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
	int i,j;
	i=LocateElem(L,e,equal);
	if(i) // �ҵ�
	{
		if(i==1) // ����Ԫ���
		{
			p=NULL;
			return L;
		}
		p=L;
		for(j=2;j<i;j++)
			p=p->next;
		return p->next;
	}
	return NULL; // û�ҵ�
}
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
int Modify(LinkList &L,ElemType e)
 { //�޸Ľ�����ݣ�����ѧ�Ž����ǽ����������L
   char s[80];
    print(e); //��ʾԭ���� 
   cout<<"��������޸�������ݣ����޸ĵ���س�������ԭֵ:"<<endl;
   //�޸Ŀ�ʼ 
     gets(s); 
   cout<<"����������: ";
     gets(s);
    if(strlen(s))
     strcpy(e.name,s);
     
   cout<<"������ѧ��: ";
     gets(s);
   if(strlen(s))
     e.num=atol(s);
     
   cout<<"�������Ա�";
     gets(s) ;
   if(strlen(s))
     e.sex=s[0];
     
   cout<<"����������: ";
     gets(s) ; 
   if(strlen(s))
     e.age=atoi(s);
     
   cout<<"������༶: ";
      gets(s) ; 
   if(strlen(s))
     strcpy(e.Class,s);
     
   cout<<"�����뽡��״��:"<<sta[0]<<sta[1]<<sta[2];
      gets(s) ; 
   if(strlen(s))
     e.health=atoi(s);
	  //�޸���� 
   InsertAscend(L,e,cmp); //��q��ָ�������ݰ�ѧ�ŷǽ������L
 }

