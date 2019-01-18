#include<bits/stdc++.h>

using namespace std;

const int MAXLISTSIZE=100;

template<class ElemType>
class SqStack
{
private:
    ElemType *base;   // ջ��ָ��
    ElemType *top;   // ջ��ָ��
    int maxSize;        // ��������洢����(��sizeof(ElemType)Ϊ��λ
public:
    //��ʼ��˳��ջ
    SqStack(int ms = 20);
    //ɾ��˳��ջ
    ~SqStack()
    {
        StackDestroy();
    }
    //��˳��ջ��Ϊ�ձ�
    bool StackClear( );
    //����˳��ջ�ĳ���
    int StackLength() const
    {
        return top - base;
    }
    //����˳��ջ�ĳ���
    //bool SetListLength(int len);
    //�ж�˳��ջ�Ƿ�Ϊ��ջ
    bool StackisEmpty() const
    {
        return top == base;
    }
    //�ж�˳��ջ�Ƿ�Ϊ��ջ
    bool StackFull() const;
    //��e����ջ��Ԫ��
    bool GetTop(ElemType &e) const;
    //��ջ
    bool push(ElemType &e);
    //��ջ
    bool pop(ElemType &e);
    //����˳��ջ
    bool StackDestroy();
    //����˳��ջ
    void StackTraverse() const;
    //ջ�ռ�ӱ�
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

/* ������Ľ�㶨�� */
template<class ElemType>
struct LinkNode
{
    ElemType data;
    LinkNode<ElemType> *next;
    LinkNode(LinkNode<ElemType> *ptr = NULL)
    {
        next = ptr;   //���캯��1�����ڹ���ͷ���
    }
    LinkNode(const ElemType &item, LinkNode<ElemType> *ptr = NULL) //���캯��2�����ڹ����������
    //�����������е��β�������Ĭ��ֵ�����Ǵ�Ĭ��ֵ�Ĳ�����Ҫ�ź���
    {
        next = ptr;
        data = item;
    }
    ElemType getData()
    {
        return data;   //ȡ�ý���е�����
    }
    void SetLink( LinkNode<ElemType> *link )
    {
        next = link;    //�޸Ľ���next��
    }
    void SetLink( ElemType value )
    {
        data = value;    //�޸Ľ���next��
    }
};

//��ͷ���ĵ�����
template<class ElemType>
class LinkList
{
private:
    LinkNode<ElemType> *head;   // ͷ���
    LinkNode<ElemType> *tail;   // β���
public:
    //�޲����Ĺ��캯��
    LinkList()
    {
        head = new LinkNode<ElemType>;
    }
    //�������Ĺ��캯��
    LinkList(const ElemType &item)
    {
        head = new LinkNode<ElemType>(item);
    }
    //�������캯��
    LinkList(LinkList<ElemType> &List);
    //���غ���:��ֵ
    //LinkList<ElemType>& operator=(LinkList<ElemType> &List);
    //��������
    void ListDestroy();
    //�������
    void ListClear();
    //��������ĳ���
    int ListLength() const;
    //�ж������Ƿ�Ϊ�ձ�
    bool ListEmpty() const;
    //���׽ڵ�֮ǰ����һ�����
    bool InsFirst( ElemType e );
    //��ȡ����ͷ���
    LinkNode<ElemType>* GetHead()
    {
        return head;
    }
    //��������ͷ���
    void SetHead(LinkNode<ElemType> *p)
    {
        head = p;
    }
    //��ȡ����β���
    LinkNode<ElemType>* GetTail()
    {
        return tail;
    }
    //��e��������ĵ�i��Ԫ��
    ElemType GetElem(int pos);
    //������ĵ�pos��λ��֮ǰ����eԪ��
    bool ListInsert_prior(int pos,ElemType e);
    //������ĵ�pos��λ��֮�����eԪ��
    bool ListInsert_next(int pos,ElemType e);
    //ɾ��������׽��
    //bool DelFirst( ElemType &e);
    //��ͷ���뷨��̬��������
    void CreateList_Head(int n, ElemType *A);
    //��β���뷨��̬��������
    void CreateList_Tail(int n, ElemType *A);
    //ɾ������ĵ�pos��λ�õ�Ԫ��
    ElemType ListDelete(int pos);
    //compare�����������ж�a��b�Ƿ����
    //bool compare(ElemType a, ElemType *b);
    //����Ų��ң�������ĵ�һ����㿪ʼ���жϵ�ǰ����Ƿ��ǵ�i����
    //���ǣ��򷵻ظý����������ֵ�����������һ����ֱ���������û�е�i�����ʱ���ؿա�
    bool FindElem( int k, ElemType &e);
    //bool compare(ElemType a, ElemType *b);
    //��ֵ���ң�����λ��������ĵ�һ����㿪ʼ���жϵ�ǰ���ֵ�Ƿ����e��
    //���ǣ��򷵻ظý�����ţ����������һ����ֱ����������Ҳ���ʱ����0��
    int SearchElem( const ElemType &e) const;
    //���������������Ԫ�ص�ǰ������Ԫ�ص�ֵ
    bool PriorElem(ElemType cur_e, ElemType &pri_e);
    //���������������Ԫ�صĺ������Ԫ�ص�ֵ
    bool NextElem(LinkNode<ElemType> *p, ElemType &e);
    //��������
    bool ListTraverse() const;
};

template<class ElemType>
void  LinkList<ElemType>::ListDestroy()//��������
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
void  LinkList<ElemType>::ListClear()//�������
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
int  LinkList<ElemType>::ListLength()const//��������ĳ���
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
bool  LinkList<ElemType>::ListEmpty()const//�ж������Ƿ�Ϊ�ձ�
{
    if(head->next==NULL)
        return true;
    return false;
}

template<class ElemType>
bool  LinkList<ElemType>::InsFirst(ElemType e)//���׽��֮ǰ����һ�����
{
    struct LinkNode<ElemType> *p;
    p=new LinkNode<ElemType>();
    if(!p)
        return false;//����洢�ռ�ʧ��
    p->data=e;//�����½ڵ�dataֵ
    p->next=head->next;
    head->next=p;//���½ڵ�����׽ڵ�֮ǰ���½ڵ������ͷ�ڵ����
    if(head==tail)
        tail=p;//���ԭ���������ǿ�������ҲҪ����β����ָ��
    return true;
}

template<class ElemType>
ElemType LinkList<ElemType>::GetElem(int pos)//��e��������ĵ�i��Ԫ��
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
bool LinkList<ElemType>::ListInsert_prior(int pos,ElemType e)//������ĵ�pos��λ��֮ǰ����eԪ��
{
    int i=0;
    struct LinkNode<ElemType> *p=head,*store;

    while(p&&i<pos-1)
    {
        p=p->next;
        i++;
    }
    if(!p->next||(i>pos-1))//���������ζ�Ŵ���Ĳ���pos�Ĵ�С�Ѿ�����������ĳ��Ȼ�С��1
        return false;

    store=new LinkNode<ElemType>();
    if(!store)
        return false;//����洢�ռ�ʧ��

    store->data=e;
    store->next=p->next;
    p->next=store;
    p=p->next;
    return true;
}

template<class ElemType>
bool LinkList<ElemType>::ListInsert_next(int pos,ElemType e)//������ĵ�pos��λ��֮�����eԪ��
{
    int i=0;
    struct LinkNode<ElemType> *p=head,*store;


    while(p&&i<pos+1)
    {
        p=p->next;
        i++;
    }
    if(!p->next||(i>pos-1))//���������ζ�Ŵ���Ĳ���pos�Ĵ�С�Ѿ�����������ĳ��Ȼ�С��1
        return false;

    store=new LinkNode<ElemType>();
    if(!store)
        return false;//����洢�ռ�ʧ��

    store->data=e;
    store->next=p->next;
    p->next=store;
    p=p->next;
    return true;
}

template<class ElemType>
void LinkList<ElemType>::CreateList_Head(int n,ElemType *A)//��ͷ���뷨��̬��������
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
void LinkList<ElemType>::CreateList_Tail(int n,ElemType *A)//��β���뷨��̬��������
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
ElemType LinkList<ElemType>::ListDelete(int pos)//ɾ������ĵ�pos��λ�õ�Ԫ��
{
    LinkNode<ElemType> *p=head,*q;
    int i=0;
    while(p->next&&i<pos-1)//���ҵ���pos-1�����
    {
        p=p->next;
        i++;
    }
    if(!p->next||(i>pos-1))//���������ζ�Ŵ���Ĳ���pos�Ĵ�С�Ѿ�����������ĳ��Ȼ�С��1
        return false;
    q=p->next;
    p->next=q->next;
    if(q==tail)
        tail=p;
    delete q;
    return true;
}

//����Ų��ң�������ĵ�һ����㿪ʼ���жϵ�ǰ����Ƿ��ǵ�i����
//���ǣ��򷵻ظý����������ֵ�����������һ����ֱ���������û�е�i�����ʱ���ؿա�
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

//��ֵ���ң�����λ��������ĵ�һ����㿪ʼ���жϵ�ǰ���ֵ�Ƿ����e��
//���ǣ��򷵻ظý�����ţ����������һ����ֱ����������Ҳ���ʱ����0��
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
bool LinkList<ElemType>::PriorElem(ElemType cur_e, ElemType &pri_e)//���������������Ԫ�ص�ǰ������Ԫ�ص�ֵ
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
bool LinkList<ElemType>::NextElem(LinkNode<ElemType> *p, ElemType &e)//���������������Ԫ�صĺ�������Ԫ�ص�ֵ
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
bool LinkList<ElemType>::ListTraverse() const//��������
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

//�жϵ������ǰn������Ƿ����ĶԳ�
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
