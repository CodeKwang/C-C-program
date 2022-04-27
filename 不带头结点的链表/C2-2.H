 // c2-2.h 线性表的单链表存储结构
  struct stud // 记录的结构
 {
   char name[9]; // 包括'\0'
   long num;
   char sex;
   int age;
   char Class[5]; // 包括'\0'
   int health;
 };
  char sta[3][9]={"健康  ","一般  ","神经衰弱"}; // 健康状况(3类)
 typedef stud ElemType; // 链表结点元素类型为结构体
 struct LNode
 {
   ElemType data;
   LNode *next;
 };
 typedef LNode *LinkList; // 另一种定义LinkList的方法
 FILE *fp; // 全局变量
