#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//定义数据类型
typedef int Elementype;

//定义节点结构
typedef struct Node {
    Elementype Element;
    struct Node *next;
}Node,*PNODE;

//定义队列结构体
typedef struct QNODE {
    PNODE Front,Rear;                           //队列头，尾指针
}Queue,*PQueue;

//声明函数体
void InitQueue(PQueue);                         //创建队列
int IsEmptyQueue(PQueue);                       //判断队列是否为空
void InsertQueue(PQueue, int val);              //入队
void DeleteQueue(PQueue,int *val);              //出队
void DestroyQueue(PQueue);                      //销毁队列
void TraverseQueue(PQueue);                     //遍历队列
void ClearQueue(PQueue);                        //清空队列
int LengthQueue(PQueue);                        //求队列长度




//定义初始化函数
void InitQueue(PQueue queue){
    queue->Front=queue->Rear=(PQueue)malloc(sizeof(Node));
    //头结点相当于哨兵结点的作用，不存储数据（区别于首结点
    if(queue->Front==NULL){                     //判断内存是否分配成功
        printf("创建队列失败，无法分配所需内存...\n");
        exit(-1);
    }
    queue->Front->next=NULL;                    //初始队列头结点指针指向空
    printf("创建队列成功...\n");
}

//定义判断队列是否为空
int IsEmptyQueue(PQueue queue){
    if(queue->Front==queue->Rear){
        printf("队列为空...\n");
        return 1;
    }else{
        return 0;
    }
}

//定义入队函数
//从队列尾部插入数据
void InsertQueue(PQueue queue,int val){
    PNODE p=(PNODE)malloc(sizeof(Node));           //创建一个新结点用于存放插入的元素
    if(p==NULL){
        printf("内存分配失败，无法插入新的结点：%d\n",val);
        exit(-1);
    }
    p->Element=val;                                 //把要插入的数据放到新申请的结点上的数据域
    p->next=NULL;                                   //讲新结点的next指向空
    queue->Rear->next=p;                            //将原先队尾的next指向新的结点
    queue->Rear=p;                                  //更新队尾指针，使其作为新的队尾结点
    printf("新的结点：%d插入队列成功。\n",val);
}

//定义出队函数
//从队列的首结点开始出队
//若出队成功，用val返回其值
void DeleteQueue(PQueue queue,int *val){
    if(IsEmptyQueue(queue)){
        printf("队列为空，无法完成出队操作...\n");
        exit(-1);
    }
    PNODE p = queue->Front->next;                   //临时指针
    *val = p->Element;                              //保存临时指针的值，一会要把它返回出去
    queue->Front->next=p->next;                     //更新了头结点
    if(queue->Rear==p)
        queue->Rear=queue->Front;
    free(p);                                        //释放p，也就是释放原来队列的头结点
    p=NULL;                                         //防止产生野指针
    printf("出栈成功，出栈值是：%d\n",*val);
}

//定义队列遍历函数
void TraverseQueue(PQueue queue){
    if(IsEmptyQueue(queue))
        exit(-1);
    PNODE p = queue->Front->next;                   //从队列的首结点开始遍历
    printf("遍历队列结果为：\n");
    while(p!=NULL){
        printf("%d ",p->Element);
        p=p->next;
    }
    printf("\n");
}

//定义销毁函数，包括头结点
void DestroyQueue(PQueue queue){
    //从头结点开始删除
    while(queue->Front!=NULL){
        queue->Rear=queue->Front->next;
        free(queue->Front);
        queue->Front=queue->Rear;
    }
    printf("销毁队列成功...\n");
}

//定义情况队列函数
void ClearQueue(PQueue queue){
    PNODE p = queue->Front->next;                   //临时指针
    PNODE q = NULL;                                 //临时指针
    queue->Rear=queue->Front;                       //使队尾指针指向头结点
    queue->Front->next=NULL;
    //从头结点开始清空
    while(p!=NULL){
        q=p;
        p=p->next;
        free(q);
    }
    printf("清空队列成功...\n");
}


int main(){
    int val = 0;                                    //创建临时变量
    Queue queue;                                    //创建队列变量
    InitQueue(&queue);                              //调用初始化队列函数
    IsEmptyQueue(&queue);                           //判断队列是否为空
    InsertQueue(&queue,100);                        //向队列中插入函数
    InsertQueue(&queue,300);                        //向队列中插入函数
    InsertQueue(&queue,500);                        //向队列中插入函数
    InsertQueue(&queue,900);                        //向队列中插入函数
    InsertQueue(&queue,200);                        //向队列中插入函数
    InsertQueue(&queue,700);                        //向队列中插入函数
    IsEmptyQueue(&queue);
    TraverseQueue(&queue);                          //遍历队列
    DeleteQueue(&queue,&val);                       //调用出队函数
    TraverseQueue(&queue);
    ClearQueue(&queue);                             //清空队列
    IsEmptyQueue(&queue);                           //判断是否为空
    DestroyQueue(&queue);                           //销毁队列

    return 0;
}






















