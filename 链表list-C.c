#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//定义数据类型，可以根据需要进行其他类型的定义
typedef int ElementType;

//链表结点定义
typedef struct ListNode {
	ElementType Element;							//数据域
	struct ListNode* Next;									//指向下一个结点的指针
}Node,*PNode;

//操作函数声明
PNode CreateList(void);								//创建链表
void TraverseList(PNode List);						//遍历链表
void InsertList(PNode List,int pos,int val);		//插入链表
void DeleteTheList(PNode List);						//删除整个链表
void DeleteList(PNode List,int pos);				//删除链表中某个位置元素
PNode FindList(PNode List);							//链表查询函数


int main()
{
    PNode List = CreateList();
	TraverseList(List);
	FindList(List);
	InsertList(List,3,100);
	TraverseList(List);
	DeleteList(List,3);
	DeleteTheList(List);
	TraverseList(List);
    return 0;
}

//具体实现
PNode CreateList(void){
	int len;										//定义链表长度
	int val;										//用于存放结点数值
	PNode PHead = (PNode)malloc(sizeof(Node));		//创建分配一个头结点内存空间
	if(PHead==NULL){
		printf("空间分配失败..\n");
		exit(-1);
	}
	PNode PTail =PHead;								//链表的尾结点，初始化使其指向头结点
	printf("请输入结点个数：\n");
	scanf("%d",&len);								//接收结点个数
	for(int i = 0; i < len;i++){
		PNode PNew = (PNode)malloc(sizeof(Node));
		if(PNew == NULL){
			printf("新节点分配内存失败...\n");
			exit(-1);
		}
		printf("请输入第%d个结点的数据：\n",i+1);
		scanf("%d",&val);
		PNew->Element = val;
		PTail->Next = PNew;
		PNew->Next=NULL;
		PTail = PNew;
	}
	printf("链表创建成功！\n");
	return PHead;
}

//定义链表遍历函数
void TraverseList(PNode List){
	PNode p = List->Next;							//首结点赋值给临时结点
	printf("遍历链表的值为：\n");
	if(p==NULL)
		printf("     链表为空");
	while(p!=NULL){
		printf("%d ",p->Element);
		p=p->Next;
	}
	printf("\n");
}

//定义链表查询函数
PNode FindList(PNode List){
	PNode p = List->Next;							//定义临时指针p指向首结点的地址
	int num = 0;									//用于记录链表结点的位置
	int val = 0;									//用于存放需要查询的值
	printf("请输入要查询的数字：\n");
	scanf("%d",&val);								//接收需要查询的数
	while(p!=NULL && p->Element!=val){
		p=p->Next;
		++num;
	}
	if(p!=NULL)
		printf("找到的结点为：%d\n",num+1);
	else
		printf("为找到该值！\n");
	return p;
}


//定义链表插入函数
void InsertList(PNode List,int pos,int val){
	int position = 0;
	PNode p = List;									//定义结点p指向头结点
	//寻找pos结点的前驱结点
	while(p!=NULL && position<pos-1){
		p=p->Next;
		++position;
	}
	PNode Tmp = (PNode)malloc(sizeof(Node));		//分配临时结点用于存储需要插入的数据
	if(Tmp==NULL){
		printf("内存分配失败，无法插入数据\n");
		exit(-1);
	}
	//插入结点
	Tmp->Element = val;
	Tmp->Next = p->Next;
	p->Next = Tmp;
}

//定义删除整个链表
void DeleteTheList(PNode List){
	PNode p,Tmp;
	p=List->Next;									//定义p指向链表的第一个结点
	List->Next = NULL;
	while(p!=NULL){
		Tmp = p->Next;								//Tmp指向要删除的结点的下一个结点
		free(p);									//释放指针p所指向的结点
		p=Tmp;										//重新赋值
	}
	printf("链表删除成功\n");
}

//定义删除链表元素函数
//删除链表中第pos结点
void DeleteList(PNode List,int pos){
	int position=0;
	PNode p = List;
	while(p!=NULL && position<pos-1){
		p = p->Next;
		++position;
	}
	//删除结点
	PNode Tmp = p->Next;
	p->Next = Tmp->Next;
	free(Tmp);
	Tmp=NULL;
}
