#include<bits/stdc++.h>

using namespace std;

const int MAXLISTSIZE=100;

template<class ElemType>
class SqStack
{
private:
    ElemType *base;   // 栈底指针
    ElemType *top;   // 栈顶指针
    int maxSize;        // 允许的最大存储容量(以sizeof(ElemType)为单位
public:
    //初始化顺序栈
    SqStack(int ms = 20);
    //删除顺序栈
    ~SqStack()
    {
        StackDestroy();
    }
    //将顺序栈置为空表
    bool StackClear( );
    //返回顺序栈的长度
    int StackLength() const
    {
        return top - base;
    }
    //设置顺序栈的长度
    //bool SetListLength(int len);
    //判断顺序栈是否为空栈
    bool StackisEmpty() const
    {
        return top == base;
    }
    //判断顺序栈是否为满栈
    bool StackFull() const;
    //用e返回栈顶元素
    bool GetTop(ElemType &e) const;
    //入栈
    bool push(ElemType &e);
    //出栈
    bool pop(ElemType &e);
    //销毁顺序栈
    bool StackDestroy();
    //遍历顺序栈
    void StackTraverse() const;
    //栈空间加倍
    bool DoubleSpace();
};
template<class ElemType>
SqStack<ElemType>::SqStack(int maxsize)
{
    if(maxsize==0)
    {
        maxsize=MAXLISTSIZE;
    }
    base=new ElemType[maxsize];
    if(!base)
    {
        exit(0);
    }
    top=base;
    maxSize=maxsize;
}

template<class ElemType>
bool SqStack<ElemType>::StackClear( )
{
    if(!top)
    {
        return false;
    }
    top=base;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::StackFull() const
{
    return top-base==maxSize;
}

template<class ElemType>
bool SqStack<ElemType>::GetTop(ElemType &e) const
{
    if(StackisEmpty())
    {
        return false;
    }
    e=*(top-1);
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::push(ElemType &e)
{
    if(StackFull())
    {
        return false;
    }
    *top++=e;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::pop(ElemType &e)
{
    if(StackisEmpty())
    {
        return false;
    }
    e=*--top;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::StackDestroy()
{
    if(base)
    {
        delete base;
        maxSize=0;
        base=top=NULL;
    }
    return true;
}

template<class ElemType>
void SqStack<ElemType>::StackTraverse() const
{
    ElemType *now;
    now=base;
    while(top!=now)
    {
        cout<<*now++;
    }
    cout<<endl;
}

template<class ElemType>
bool SqStack<ElemType>::DoubleSpace()
{
    top=new ElemType[maxSize];
    if(!top)
    {
        exit(0);
    }
    return true;
}

template<class ElemType>
void Invert_Input(SqStack<ElemType>&S)
{
    string s;
    getline(cin,s);
    int len=s.length();
    for(int i=len-1; i>=0; i--)
    {
        S.push(s[i]);
    }
}

/* 单链表的结点定义 */
template<class ElemType>
struct LinkNode
{
    ElemType data;
    LinkNode<ElemType> *next;
    LinkNode(LinkNode<ElemType> *ptr = NULL)
    {
        next = ptr;   //构造函数1，用于构造头结点
    }
    LinkNode(const ElemType &item, LinkNode<ElemType> *ptr = NULL) //构造函数2，用于构造其他结点
    //函数参数表中的形参允许有默认值，但是带默认值的参数需要放后面
    {
        next = ptr;
        data = item;
    }
    ElemType getData()
    {
        return data;   //取得结点中的数据
    }
    void SetLink( LinkNode<ElemType> *link )
    {
        next = link;    //修改结点的next域
    }
    void SetLink( ElemType value )
    {
        data = value;    //修改结点的next域
    }
};

//带头结点的单链表
template<class ElemType>
class LinkList
{
private:
    LinkNode<ElemType> *head;   // 头结点
    LinkNode<ElemType> *tail;   // 尾结点
public:
    //无参数的构造函数
    LinkList()
    {
        head = new LinkNode<ElemType>;
    }
    //带参数的构造函数
    LinkList(const ElemType &item)
    {
        head = new LinkNode<ElemType>(item);
    }
    //拷贝构造函数
    LinkList(LinkList<ElemType> &List);
    //重载函数:赋值
    //LinkList<ElemType>& operator=(LinkList<ElemType> &List);
    //销毁链表
    void ListDestroy();
    //清空链表
    void ListClear();
    //返回链表的长度
    int ListLength() const;
    //判断链表是否为空表
    bool ListEmpty() const;
    //在首节点之前插入一个结点
    bool InsFirst( ElemType e );
    //获取链表头结点
    LinkNode<ElemType>* GetHead()
    {
        return head;
    }
    //设置链表头结点
    void SetHead(LinkNode<ElemType> *p)
    {
        head = p;
    }
    //获取链表尾结点
    LinkNode<ElemType>* GetTail()
    {
        return tail;
    }
    //用e返回链表的第i个元素
    ElemType GetElem(int pos);
    //在链表的第pos个位置之前插入e元素
    bool ListInsert_prior(int pos,ElemType e);
    //在链表的第pos个位置之后插入e元素
    bool ListInsert_next(int pos,ElemType e);
    //删除链表的首结点
    //bool DelFirst( ElemType &e);
    //表头插入法动态生成链表
    void CreateList_Head(int n, ElemType *A);
    //表尾插入法动态生成链表
    void CreateList_Tail(int n, ElemType *A);
    //删除链表的第pos个位置的元素
    ElemType ListDelete(int pos);
    //compare函数，用来判断a和b是否相等
    //bool compare(ElemType a, ElemType *b);
    //按序号查找，从链表的第一个结点开始，判断当前结点是否是第i个，
    //若是，则返回该结点的数据域的值；否则继续后一个，直至表结束。没有第i个结点时返回空。
    bool FindElem( int k, ElemType &e);
    //bool compare(ElemType a, ElemType *b);
    //按值查找，即定位。从链表的第一个结点开始，判断当前结点值是否等于e。
    //若是，则返回该结点的序号；否则继续后一个，直至表结束。找不到时返回0。
    int SearchElem( const ElemType &e) const;
    //返回链表给定数据元素的前驱数据元素的值
    bool PriorElem(ElemType cur_e, ElemType &pri_e);
    //返回链表给定数据元素的后继数据元素的值
    bool NextElem(LinkNode<ElemType> *p, ElemType &e);
    //遍历链表
    bool ListTraverse() const;
};

template<class ElemType>
void  LinkList<ElemType>::ListDestroy()//销毁链表
{
    struct LinkNode<ElemType> *p;
    while(head)
    {
        p=head;
        head=p->next;
        delete p;
    }
    head=NULL;
}

template<class ElemType>
void  LinkList<ElemType>::ListClear()//清空链表
{
    struct LinkNode<ElemType> *p;
    p=head->next;
    while(p!=NULL)
    {
        head->next=p->next;
        delete p;
        p=head->next;
    }
}

template<class ElemType>
int  LinkList<ElemType>::ListLength()const//返回链表的长度
{
    int len=0;
    struct LinkNode<ElemType> *p;
    p=head->next;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

template<class ElemType>
bool  LinkList<ElemType>::ListEmpty()const//判断链表是否为空表
{
    if(head->next==NULL)
        return true;
    return false;
}

template<class ElemType>
bool  LinkList<ElemType>::InsFirst(ElemType e)//在首结点之前插入一个结点
{
    struct LinkNode<ElemType> *p;
    p=new LinkNode<ElemType>();
    if(!p)
        return false;//分配存储空间失败
    p->data=e;//给予新节点data值
    p->next=head->next;
    head->next=p;//将新节点插入首节点之前，新节点紧跟在头节点后面
    if(head==tail)
        tail=p;//如果原来的链表是空链表，则也要处理尾部的指针
    return true;
}

template<class ElemType>
ElemType LinkList<ElemType>::GetElem(int pos)//用e返回链表的第i个元素
{
    int i=1;
    struct LinkNode<ElemType> *p;
    p=head->next;
    while(p!=NULL&&i<pos)
    {
        p=p->next;
        i++;
    }
    return p->data;
}

template<class ElemType>
bool LinkList<ElemType>::ListInsert_prior(int pos,ElemType e)//在链表的第pos个位置之前插入e元素
{
    int i=0;
    struct LinkNode<ElemType> *p=head,*store;

    while(p&&i<pos-1)
    {
        p=p->next;
        i++;
    }
    if(!p->next||(i>pos-1))//这种情况意味着传入的参数pos的大小已经超过了链表的长度或小于1
        return false;

    store=new LinkNode<ElemType>();
    if(!store)
        return false;//分配存储空间失败

    store->data=e;
    store->next=p->next;
    p->next=store;
    p=p->next;
    return true;
}

template<class ElemType>
bool LinkList<ElemType>::ListInsert_next(int pos,ElemType e)//在链表的第pos个位置之后插入e元素
{
    int i=0;
    struct LinkNode<ElemType> *p=head,*store;


    while(p&&i<pos+1)
    {
        p=p->next;
        i++;
    }
    if(!p->next||(i>pos-1))//这种情况意味着传入的参数pos的大小已经超过了链表的长度或小于1
        return false;

    store=new LinkNode<ElemType>();
    if(!store)
        return false;//分配存储空间失败

    store->data=e;
    store->next=p->next;
    p->next=store;
    p=p->next;
    return true;
}

template<class ElemType>
void LinkList<ElemType>::CreateList_Head(int n,ElemType *A)//表头插入法动态生成链表
{
    LinkNode<ElemType> *p;
    int i;
    for(i=0; i<n; i++)
    {
        p=new LinkNode<ElemType>();

        p->data=A[i];
        p->next=head->next;
        head->next=p;
        if(i==0)
            tail=p;
    }
}

template<class ElemType>
void LinkList<ElemType>::CreateList_Tail(int n,ElemType *A)//表尾插入法动态生成链表
{
    LinkNode<ElemType> *p,*t;
    t=head;
    int i;
    for(i=0; i<n; i++)
    {
        p=new LinkNode<ElemType>();

        p->data=A[i];
        t->next=p;
        t=p;
    }
    t->next=NULL;
    tail=t;
}

template<class ElemType>
ElemType LinkList<ElemType>::ListDelete(int pos)//删除链表的第pos个位置的元素
{
    LinkNode<ElemType> *p=head,*q;
    int i=0;
    while(p->next&&i<pos-1)//先找到第pos-1个结点
    {
        p=p->next;
        i++;
    }
    if(!p->next||(i>pos-1))//这种情况意味着传入的参数pos的大小已经超过了链表的长度或小于1
        return false;
    q=p->next;
    p->next=q->next;
    if(q==tail)
        tail=p;
    delete q;
    return true;
}

//按序号查找，从链表的第一个结点开始，判断当前结点是否是第i个，
//若是，则返回该结点的数据域的值；否则继续后一个，直至表结束。没有第i个结点时返回空。
template<class ElemType>
bool LinkList<ElemType>::FindElem( int k, ElemType &e)
{
    LinkNode<ElemType> *p=head;
    int i=1;
    while(p->next&&i<k)
    {
        p=p->next;
        i++;
    }
    if(!p||i>k)
        return false;
    e=p->data;
    return true;
}

//按值查找，即定位。从链表的第一个结点开始，判断当前结点值是否等于e。
//若是，则返回该结点的序号；否则继续后一个，直至表结束。找不到时返回0。
template<class ElemType>
int LinkList<ElemType>::SearchElem( const ElemType &e) const
{
    LinkNode<ElemType> *p=head;
    int i=1;
    while(p->next&&e!=p->data)
    {
        p=p->next;
        i++;
    }
    if(!p)
        return 0;
    return i;
}

template<class ElemType>
bool LinkList<ElemType>::PriorElem(ElemType cur_e, ElemType &pri_e)//返回链表给定数据元素的前驱数据元素的值
{
    LinkNode<ElemType> *p=head,*q;
    int i=1;
    while(p->next&&cur_e!=p->data)
    {
        q=p;
        p=p->next;
        i++;
    }
    if(!p)
        return false;
    pri_e=q->data;
}

template<class ElemType>
bool LinkList<ElemType>::NextElem(LinkNode<ElemType> *p, ElemType &e)//返回链表给定数据元素的后驱数据元素的值
{
    LinkNode<ElemType> *q=head;
    int i=1;
    while(q->next&&q->data!=p->data)
    {
        q=q->next;
        i++;
    }
    if(!q)
        return false;
    q=q->next;
    e=q->data;
}

template<class ElemType>
bool LinkList<ElemType>::ListTraverse() const//遍历链表
{
    if(ListEmpty())
        return false;
    LinkNode<ElemType> *p=head->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return true;

}

//判断单链表的前n个结点是否中心对称
template<class ElemType>
bool Judge_Symmetry(LinkList<ElemType> &L, int num)
{
    LinkNode<ElemType> *p=L.GetHead()->next;
    int i,mid=num/2;
    if(num>L.ListLength()||num<0)
        return false;
    SqStack<char> S;
    for(i=0;i<mid;i++)
    {
        S.push(p->data);
        p=p->next;
    }

    if(num%2!=0)
    {
        i++;
        p=p->next;
    }

    char c;
    for(;i<num;i++)
    {
        S.pop(c);
        if(c!=p->data)
            return false;
        p=p->next;
    }

    return true;
}


int main()
{
    int n,spot;
    LinkList<char>L;
    cin>>n;
    char A[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cin>>spot;
    L.CreateList_Tail(n,A);
    L.ListTraverse();
    if(Judge_Symmetry(L,spot))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
