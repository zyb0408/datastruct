#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<sstream>

using namespace std;

/* �����еĽ�㶨�� */
template<class ElemType>
struct BinaryTreeLinkQueueNode
{
    ElemType data;
    BinaryTreeLinkQueueNode<ElemType> *next;
    BinaryTreeLinkQueueNode(BinaryTreeLinkQueueNode<ElemType> *ptr = NULL)
    {
        next = ptr;   //���캯��1�����ڹ���ͷ���
    }
    BinaryTreeLinkQueueNode(const ElemType &item, BinaryTreeLinkQueueNode<ElemType> *ptr = NULL) //���캯��2�����ڹ����������
    //�����������е��β�������Ĭ��ֵ�����Ǵ�Ĭ��ֵ�Ĳ�����Ҫ�ź���
    {
        next = ptr;
        data = item;
    }
    ElemType getData()
    {
        return data;   //ȡ�ý���е�����
    }
    void SetLink(BinaryTreeLinkQueueNode<ElemType> *link)
    {
        next = link;    //�޸Ľ���next��
    }
    void SetData(ElemType value)
    {
        data = value;    //�޸Ľ���data��
    }
};
//��ͷ����������
template<class ElemType>
class BinaryTreeLinkQueue
{
private:
    BinaryTreeLinkQueueNode<ElemType> *front;   // ��ͷָ��
    BinaryTreeLinkQueueNode<ElemType> *rear;   // ��βָ��
    int length;   //���е�ǰԪ�ظ���
public:
    //�޲����Ĺ��캯��
    BinaryTreeLinkQueue();
    //����������
    bool LinkQueueDestroy();
    //�������
    bool LinkQueueClear();
    //���������еĳ���
    int QueueLength() const
    {
        return length;
    }
    //�ж��������Ƿ�Ϊ�ն���
    bool QueueisEmpty() const;
    //���
    bool EnQueue(ElemType &e);
    //����
    bool DeQueue(ElemType &e);
    //��ȡ������ͷ���ָ��
    BinaryTreeLinkQueueNode<ElemType>* GetFront()
    {
        return front;
    }
    //��ȡ��ͷԪ��
    ElemType GetFrontData()
    {
        return front->data;
    }
    //��ȡ�����ж�βָ��
    BinaryTreeLinkQueueNode<ElemType>* GetRear()
    {
        return rear;
    }
    //����������
    bool QueueTraverse() const;
};
template<class ElemType>
BinaryTreeLinkQueue<ElemType>::BinaryTreeLinkQueue()//�޲����Ĺ��캯��
{
    BinaryTreeLinkQueueNode<ElemType> *p=new BinaryTreeLinkQueueNode<ElemType>();
    p->next=NULL;
    front=rear=new BinaryTreeLinkQueueNode<ElemType>();
    if(!front||!rear)
        exit(0);
    length=0;
    rear=front=p;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::LinkQueueDestroy()//����������
{
    BinaryTreeLinkQueueNode<ElemType> *p;
    if(!front)
        return false;
    while(front->next)  //���������У��ͷ������е����н��
    {
        p=front->next;
        front->next=p->next;
        delete(p);
    }
    //free(front); //�ͷ������е�ͷ���
    front=rear=NULL;
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::LinkQueueClear()//���������
{
    if(!front)
        return false;
    front=rear;
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::QueueisEmpty() const//�ж��������Ƿ�Ϊ�ն���
{
    return rear==front;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::EnQueue(ElemType &e)  //���
{
    BinaryTreeLinkQueueNode<ElemType> *p=new BinaryTreeLinkQueueNode<ElemType>();
    if(!p)
        return false;
    p->data=e;
    p->next=NULL;
    rear->next=p; //�޸�β����ָ��
    rear=p;  //�ƶ���βָ��
    length++;
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::DeQueue(ElemType &e)  //����
{
    if(QueueisEmpty())
    {
        return false;
    }
    BinaryTreeLinkQueueNode<ElemType> *p=front->next;
    e=p->data;  //��e������ӵ�����
    front->next=p->next;  //�޸�ͷ����ָ��
    if(rear==p)
        rear=front;
    length--;
    free(p);
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::QueueTraverse() const  //����������
{
    if(QueueisEmpty())
        return false;
    BinaryTreeLinkQueueNode<ElemType> *p=front->next;
    while(p->next)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<p->data<<endl;
    return true;
}


/* �����Ľ�㶨�� */
template<class ElemType>
struct BinaryTreeNode
{
    ElemType data;
    BinaryTreeNode<ElemType> *Lkid, *Rkid;
    BinaryTreeNode() : Lkid(NULL), Rkid(NULL) {} //���캯��1�����ڹ�������
    BinaryTreeNode(const ElemType &item, BinaryTreeNode<ElemType> *Lptr = NULL, BinaryTreeNode<ElemType> *Rptr = NULL) //���캯��2�����ڹ����������
    //�����������е��β�������Ĭ��ֵ�����Ǵ�Ĭ��ֵ�Ĳ�����Ҫ�ź���
    {
        Lkid = Lptr;
        Rkid = Rptr;
        data = item;
    }

    ElemType getData()
    {
        return data;   //ȡ�ý���е�����
    }
    void SetLkid( BinaryTreeNode<ElemType> *link )
    {
        Lkid = link;    //�޸Ľ���������
    }
    void SetRkid( BinaryTreeNode<ElemType> *link )
    {
        Rkid = link;    //�޸Ľ����Һ�����
    }
    void SetData( ElemType value )
    {
        data = value;    //�޸Ľ���data��
    }
    BinaryTreeNode<ElemType> * GetLkid() const
    {
        return Lkid;   //��ȡ���ӽ��
    }
    BinaryTreeNode<ElemType> * GetRkid() const
    {
        return Rkid;   //��ȡ���ӽ��
    }
};
//������
template<class ElemType>
class BinaryTree
{
private:
    BinaryTreeNode<ElemType> *root;   // ͷָ��

    void BinaryTreeDestroy_Cursive(BinaryTreeNode<ElemType> *T); //���������ݹ�׼����private��
    bool checkEqual(const BinaryTreeNode<ElemType> *root1, const BinaryTreeNode<ElemType> *root2);//�����==���غ������ݹ鲿�֣�˽�г�Ա������

public:
    //�޲����Ĺ��캯��
    BinaryTree():root(NULL) {}
    //�������Ĺ��캯��
    BinaryTree(const ElemType &item)
    {
        root = new BinaryTreeNode<ElemType>(item);
    }
    //������
    void makeBinaryTree( const ElemType &item, BinaryTree &left, BinaryTree &right);
    //��������
    //~BinaryTree(){BinaryTreeDestroy();}
    //������
    bool BinaryTreeDestroy();
    //��������
    bool KidTreeDestroy(BinaryTreeNode<ElemType> * root, int flag);
    //������Ԫ��ֵxΪ�����ģ��ӣ��������ĸ߶ȣ��ݹ飩
    int GetBinaryTreeHeight_Cursive( BinaryTreeNode<ElemType> *T, ElemType &x ) const;
    //ͳ�ƽ�����
    int BinaryTreeSize( BinaryTreeNode<ElemType> *T ) const;
    //ͳ�ƶ�Ϊ2�Ľ�����
    int CountDegreeTwo( BinaryTreeNode<ElemType> *T ) const;
    //�ж϶������Ƿ�Ϊ��
    bool BinaryTreeisEmpty() const
    {
        return root == NULL;
    }
    //��ȡ�����Ԫ��ֵ
    ElemType GetRootData() const
    {
        return root->data;
    }
    //��Ԫ��ֵΪx�Ľ�����¸�ֵ
    void Assign_NodeData( BinaryTreeNode<ElemType> *root,ElemType &x,ElemType &value);
    //����ֵΪx�Ľ���λ�ã��ݹ飩
    void Location_Cursive( BinaryTreeNode<ElemType> *root,const ElemType &x,BinaryTreeNode<ElemType> * &location);
    //����ֵΪx�Ľ��ĺ��ӽ���ָ�루flag=0�����ӣ�flag=1���Һ��ӣ�
    BinaryTreeNode<ElemType> *Location_Kid(BinaryTreeNode<ElemType> * parent, int flag) const;
    //����Ԫ��ֵxΪ������λ�ò�����������ǣ�flag=0����������flag=1����������
    bool Insert_KidTree(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *kid,int flag);
    //���ø����
    void SetRoot(BinaryTreeNode<ElemType> * p)
    {
        root = p;
    }
    //��ȡ�����
    BinaryTreeNode<ElemType> * GetRoot() const
    {
        return root;
    }
    //��ȡ�����
    void GetParent_Cursive(BinaryTreeNode<ElemType> * parent, ElemType &x, BinaryTreeNode<ElemType> * &result) const;
    //ǰ�����
    bool PreOrderTraverse(BinaryTreeNode<ElemType> *T,bool(*visit)(BinaryTreeNode<ElemType> *T)) const;  //ǰ��������ݹ飩
    //�������
    bool InOrderTraverse(BinaryTreeNode<ElemType> *T,bool(*visit)(BinaryTreeNode<ElemType> *T)) const;  //����������ݹ飩
    //�������
    bool PostOrderTraverse(BinaryTreeNode<ElemType> *T,bool(*visit)(BinaryTreeNode<ElemType> *T)) const;  //����������ݹ飩
    //����״��ӡ������������״���ݹ�};
    void Print_BinaryTree(BinaryTreeNode<ElemType> *root, int i); //����״��ӡ������������״���ݹ飩
    //�����������Ĵ洢�ṹ
    BinaryTreeNode<ElemType>* CreateBinaryTree(ElemType x[], ElemType &empty, int &n);
    //��α�������Ա����
    bool LayerOrderTraverse(bool (*visit)(BinaryTreeNode<ElemType> *T)) const;
    //����ֵΪx�Ľ��ĺ��ӽ���ָ�루flag=0�����ӣ�flag=1���Һ��ӣ�
    void Location_Kid(BinaryTreeNode<ElemType> *T,ElemType &x,int flag,BinaryTreeNode<ElemType> *&location) const;
    //����ָ��ֵΪx�Ľ����ֵܽ���ָ�루flag=0�����ֵܣ�flag=1�����ֵܣ�
    BinaryTreeNode<ElemType> *Get_Sibling(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *location,int flag)const;
    //�ж��Ƿ�����ȫ������
    bool IsCompleteTree() const;
    //�����==���غ���
    bool operator ==(const BinaryTree<ElemType> &T);
};


template<class ElemType>
void PreOrderTraverse(BinaryTreeNode<ElemType> *T)//ǰ�����
{
    if(T)
    {
        cout<<T->data<<" ";
        PreOrderTraverse(T->Lkid);
        PreOrderTraverse(T->Rkid);
    }
    //return true;
}

template<class ElemType>
void InOrderTraverse(BinaryTreeNode<ElemType> *T)//�������
{
    if(T)
    {
        InOrderTraverse(T->Lkid);
        cout<<T->data<<" ";
        InOrderTraverse(T->Rkid);
    }
    //return true;
}

template<class ElemType>
void PostOrderTraverse(BinaryTreeNode<ElemType> *T)//�������
{
    if(T)
    {
        PostOrderTraverse(T->Lkid);
        PostOrderTraverse(T->Rkid);
        cout<<T->data<<" ";
    }
    //return true;
}

//�����������Ĵ洢�ṹ ����ǲ��֣��û�������
template<class ElemType>
void CreateTree(BinaryTree<ElemType> &T, ElemType &str, ElemType &empty)
{
    ElemType tmp, t[100];
    int num = 0;

    stringstream input_T(str);
    while(input_T >> tmp)
    {
        t[num] = tmp;
        num++;
    }
    BinaryTreeNode<ElemType> *root;

    num = 0;
    root = T.CreateBinaryTree(t, empty, num);
    T.SetRoot(root);
}

//�����������Ĵ洢�ṹ (�ݹ鲿�֣���Ա������
template<class ElemType>
BinaryTreeNode<ElemType>* BinaryTree<ElemType>::CreateBinaryTree(ElemType x[], ElemType &empty, int &n)
{
    ElemType ch = x[n];
    n++;
    if (ch == empty)
    {
        return NULL;
    }
    else
    {
        BinaryTreeNode<ElemType> *Node = new BinaryTreeNode<ElemType>;
        Node->data = ch;
        Node->Lkid = CreateBinaryTree(x, empty, n);
        Node->Rkid = CreateBinaryTree(x, empty, n);
        return Node;
    }
}

template<class ElemType>
bool visit(BinaryTreeNode<ElemType> * root)
{

    if(!root) return false;
    else
    {
        cout<<root->data<<" ";
        return true;
    }
}
//ǰ���������ǲ��֣��û�������
template<class ElemType>
bool PreOrderTraverse(BinaryTree<ElemType> &T)
{
    T.PreOrderTraverse(T.GetRoot(),visit);
    return true;
}

//ǰ��������ݹ鲿�֣���Ա������
template<class ElemType>
bool BinaryTree<ElemType>::PreOrderTraverse(BinaryTreeNode<ElemType> *T, bool (*visit)(BinaryTreeNode<ElemType> *T)) const
{
    if(T)
    {
        cout<<T->data<<" ";
        PreOrderTraverse(T->Lkid,visit);
        PreOrderTraverse(T->Rkid,visit);
    }
    return true;
}

//�����������ǲ��֣��û�������
template<class ElemType>
bool InOrderTraverse(BinaryTree<ElemType> &T)
{
    T.InOrderTraverse(T.GetRoot(),visit);
    return true;
}

//����������ݹ鲿�֣���Ա������
template<class ElemType>
bool BinaryTree<ElemType>::InOrderTraverse(BinaryTreeNode<ElemType> *T, bool (*visit)(BinaryTreeNode<ElemType> *T)) const
{
    if(T)
    {
        InOrderTraverse(T->Lkid,visit);
        cout<<T->data<<" ";
        InOrderTraverse(T->Rkid,visit);
    }
    return true;
}

//�����������ǲ��֣��û�������
template<class ElemType>
bool PostOrderTraverse(BinaryTree<ElemType> &T)
{
    T.PostOrderTraverse(T.GetRoot(),visit);
    return true;
}

//����������ݹ鲿�֣���Ա������
template<class ElemType>
bool BinaryTree<ElemType>::PostOrderTraverse(BinaryTreeNode<ElemType> *T, bool (*visit)(BinaryTreeNode<ElemType> *T)) const
{
    if(T)
    {
        PostOrderTraverse(T->Lkid,visit);
        PostOrderTraverse(T->Rkid,visit);
        cout<<T->data<<" ";
    }
    return true;
}
//��α�������Ա����
template<class ElemType>
bool BinaryTree<ElemType>::LayerOrderTraverse(bool (*visit)(BinaryTreeNode<ElemType> *T)) const
{
    BinaryTreeNode<ElemType>*p=root;
    BinaryTreeLinkQueue<BinaryTreeNode<ElemType>*>Q;
    Q.EnQueue(p);
    while(!Q.QueueisEmpty())
    {
        Q.DeQueue(p);
        cout<<p->data<<" ";
        if(p->Lkid)
            Q.EnQueue(p->Lkid);
        if(p->Rkid)
            Q.EnQueue(p->Rkid);
    }
    return true;
}

//������(��ǲ��֣�public��
template<class ElemType>
bool BinaryTree<ElemType>::BinaryTreeDestroy()
{
    if(!root)
        return false;
    BinaryTreeDestroy_Cursive(root);
    return true;
}

//���������ݹ鲿�֡�private��
template<class ElemType>
void BinaryTree<ElemType>::BinaryTreeDestroy_Cursive(BinaryTreeNode<ElemType> *T)
{
    if(T->Lkid)
        BinaryTreeDestroy_Cursive(T->Lkid);
    if(T->Rkid)
        BinaryTreeDestroy_Cursive(T->Rkid);
    delete T;
    T=NULL;
}

//��ȡ����㣨��ǣ�
template<class ElemType>
BinaryTreeNode<ElemType> * GetParent(BinaryTree<ElemType> &T, ElemType &x)
{
    BinaryTreeNode<ElemType> *parent;
    if(T.GetRoot()==NULL||T.GetRootData()==x)//1�����գ�2������û��˫�׽��
    {
        return NULL;
    }
    T.GetParent_Cursive(T.GetRoot(),x,parent);
    return parent;
}

//��ȡ����㣨�ݹ飩
template<class ElemType>
void BinaryTree<ElemType>::GetParent_Cursive(BinaryTreeNode<ElemType> * parent,ElemType &x,BinaryTreeNode<ElemType> * &result) const
{
    if(parent==NULL)//�Ҿ�
        return;
    else if(((parent->Lkid)&&(parent->Lkid->data)==x)||((parent->Rkid)&&(parent->Rkid->data)==x))
        result=parent;//�ҵ�˫�׽��
    else
    {
        GetParent_Cursive(parent->Lkid,x,result);
        GetParent_Cursive(parent->Rkid,x,result);
    }
}

//���ҽ���λ�ã���ǲ��֣��û�������
template<class ElemType>
BinaryTreeNode<ElemType> * Location(BinaryTree<ElemType> &T, ElemType &x)
{
    BinaryTreeNode<ElemType> *location=NULL;//�ҵ������δ֪�ģ������������locationΪNULL
    T.Location_Cursive(T.GetRoot(),x,location);
    return location;
}

//���ҽ���λ�ã��ݹ鲿�֣���Ա������
template<class ElemType>  //ָ��locationΪ���ҽ��
void BinaryTree<ElemType>::Location_Cursive(BinaryTreeNode<ElemType> * root,const ElemType &x,BinaryTreeNode<ElemType> *&location)
{
    if(!root)
        return;
    else if(root->data==x)//����˫�׽��ʡ�����ˡ�����
        location=root;//�ҵ�������
    else
    {
        Location_Cursive(root->Lkid,x,location);
        Location_Cursive(root->Rkid,x,location);
    }
}

//������Ԫ��ֵxΪ�����ģ��ӣ��������ĸ߶ȣ���ǲ��֣��û�������
template<class ElemType>
int GetBinaryTreeHeight(BinaryTree<ElemType> &T,ElemType &x)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1�����գ�2������û�������㣬������Ϊ0
        return 0;
    else
        return T.GetBinaryTreeHeight_Cursive(Location(T,x),x);
}

//������Ԫ��ֵxΪ�����ģ��ӣ��������ĸ߶ȣ��ݹ鲿�֣���Ա������
template<class ElemType>
int BinaryTree<ElemType>::GetBinaryTreeHeight_Cursive(BinaryTreeNode<ElemType> *root,ElemType &x) const
{
    int l,r;
    if(root==NULL)
        return 0;
    l=GetBinaryTreeHeight_Cursive(root->GetLkid(),x);
    r=GetBinaryTreeHeight_Cursive(root->GetRkid(),x);
    //cout<<"left: "<<l<<" "<<"right: "<<r<<endl;
    if(l>r)
        return 1+l;
    else
        return 1+r;

}
//������Ԫ��ֵxΪ�����ĺ��ӽ�㣨��ǲ��֣��û�������
//������Ԫ��ֵxΪ�����ĺ��ӽ���ָ�루��ǣ�flag=0�����ӣ�flag=1���Һ��ӣ�
template<class ElemType>
BinaryTreeNode<ElemType> *LocationKid(BinaryTree<ElemType> &T,ElemType &x, int flag)
{
    BinaryTreeNode<ElemType> *location=NULL;//�ҵ������δ֪�ģ������������locationΪNULL
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1�����գ�2������û�������㣬�򷵻�NULL
    {
        return NULL;
    }
    T.Location_Kid(Location(T,x),x,flag,location);
    return location;
}

//������Ԫ��ֵxΪ�����ĺ��ӽ�㣨�ݹ鲿�֣���Ա������
//����ֵΪx�Ľ��ĺ��ӽ���ָ�루flag=0�����ӣ�flag=1���Һ��ӣ�
template<class ElemType>
void BinaryTree<ElemType>::Location_Kid(BinaryTreeNode<ElemType> *T,ElemType &x,int flag,BinaryTreeNode<ElemType> *&location) const
{
    if(flag)//flag=1,�Һ���
        location=T->GetRkid();
    else//flag=0,����
        location=T->GetLkid();
}

//ɾ����Ԫ��ֵxΪ�����ģ��ӣ�������ǲ��֣��û�������
//ɾ����Ԫ��ֵxΪ�����ģ��ӣ�����flag=0����������flag=1����������
template<class ElemType>
bool DeleteKid(BinaryTree<ElemType> &T, ElemType &x, int flag)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1�����գ�2������û�������㣬�򷵻�false
        return false;
    return T.KidTreeDestroy(Location(T,x),flag);
}

//ɾ����Ԫ��ֵxΪ�����ģ��ӣ������ݹ鲿�֣���Ա������
//ɾ����Ԫ��ֵxΪ�����ģ��ӣ�����flag=0����������flag=1����������
template<class ElemType>
bool BinaryTree<ElemType>::KidTreeDestroy(BinaryTreeNode<ElemType> *root, int flag)
{
    if((flag==0&&root->Lkid==NULL)||(flag==1&&root->Rkid==NULL))//û�������������false
        return false;
    else//���������
    {
        if(flag)//������
        {
            BinaryTreeDestroy_Cursive(root->Rkid);
            //delete root->Rkid;//�ͷ��������Ŀռ�
            root->Rkid=NULL;
        }
        else//������
        {
            BinaryTreeDestroy_Cursive(root->Lkid);
            //delete root->Lkid;//�ͷ��������Ŀռ�
            root->Lkid=NULL;
        }
        return true;
    }
}

template<class ElemType>
void PrintTree(BinaryTree<ElemType> &T)
{
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    cout<<endl;
    PostOrderTraverse(T);
}
//����Ԫ��ֵΪx�Ľ���λ�ò�����������ǲ��֣��û�������
//����Ԫ��ֵΪx�Ľ���λ�ò���������flag=0����������flag=1����������
template<class ElemType>
bool InsertKidTree(BinaryTree<ElemType> &T, BinaryTree<ElemType> &R, ElemType &x, int flag)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1�����գ�2������û�������㣬�򷵻�false
        return false;
    return T.Insert_KidTree(Location(T,x),R.GetRoot(),flag);
}

//����Ԫ��ֵΪx�Ľ���λ�ò����������ݹ鲿�֣���Ա������
//����Ԫ��ֵΪx�Ľ���λ�ò���������flag=0����������flag=1����������
template<class ElemType>
bool BinaryTree<ElemType>::Insert_KidTree(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *kid,int flag)
{
    BinaryTreeNode<ElemType> *p;
    if(flag)//����һ��������
    {
        p=parent->Rkid;
        parent->Rkid=kid;
        kid->Rkid=p;
        return true;
    }
    else//����һ��������
    {
        p=parent->Lkid;
        parent->Lkid=kid;
        kid->Rkid=p;
        return true;
    }
    return false;
}

//��Ԫ��ֵΪx�Ľ�����¸�ֵ����ǲ��֣��û�������
//��Ԫ��ֵΪx�Ľ�����¸�ֵ
template<class ElemType>
bool AssignNodeData(BinaryTree<ElemType> &T, ElemType &x, ElemType &value)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1�����գ�2������û�������㣬�򷵻�false
        return false;
    T.Assign_NodeData(Location(T,x),x,value);
    return true;
}

//��Ԫ��ֵΪx�Ľ�����¸�ֵ����Ա������
//��Ԫ��ֵΪx�Ľ�����¸�ֵ��flag=0����������flag=1����������
template<class ElemType>
void BinaryTree<ElemType>::Assign_NodeData(BinaryTreeNode<ElemType> *root,ElemType &x,ElemType &value)
{
    root->data=value;
}

//����ָ��ֵΪx�Ľ����ֵܽ���ָ�루��ǲ��֣��û�������
//����ָ��ֵΪx�Ľ����ֵܽ���ָ�루flag=0�����ֵܣ�flag=1�����ֵܣ�
template<class ElemType>
BinaryTreeNode<ElemType> *GetSibling(BinaryTree<ElemType> &T, ElemType &x, int flag)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL||Location(T,x)==T.GetRoot())//1������;2������û��������;3���������Ǹ���㣬�򷵻�NULL
        return NULL;
    BinaryTreeNode<ElemType> *parent;
    T.GetParent_Cursive(T.GetRoot(),x,parent);//Ҫ���ҵ�˫�׽������ҵ��ֵܽ��
    return T.Get_Sibling(parent,Location(T,x),flag);
}

//����ָ��ֵΪx�Ľ����ֵܽ���ָ�루��Ա������
//����ָ��ֵΪx�Ľ����ֵܽ���ָ�루flag=0�����ֵܣ�flag=1�����ֵܣ�
template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Get_Sibling(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *location,int flag)const
{
    if(flag==0&&parent->Rkid==location)//�����ֵܣ��ж����Լ��ǲ������ֵ�
        return parent->Lkid;
    else if(flag==1&&parent->Lkid==location)//ͬ�������ֵܣ��ж����Լ��ǲ������ֵ�
        return parent->Rkid;
    else
        return NULL;
}

//�ж��Ƿ�����ȫ������
template<class ElemType>
bool BinaryTree<ElemType>::IsCompleteTree() const
{
    bool f=false;
    if(!root)
        return true;
    BinaryTreeNode<ElemType>*p=root;
    BinaryTreeLinkQueue<BinaryTreeNode<ElemType>*>Q;
    Q.EnQueue(p);
    while(!Q.QueueisEmpty())
    {
        //p=Q.GetFront();
        Q.DeQueue(p);
        if(p)//��p��ΪNULL
        {
            if(f)
                return false;
            Q.EnQueue(p->Lkid);
            Q.EnQueue(p->Rkid);
        }
        else//��pΪNULL
            f=true;
    }
    return true;
}
//�����==���غ�������ǲ��֣���Ա������ʽ���أ�
template<class ElemType>
bool BinaryTree<ElemType>::operator ==(const BinaryTree<ElemType> &T)
{
    return checkEqual(root,T.GetRoot());
}

//�����==���غ������ݹ鲿�֣�˽�г�Ա������
template<class ElemType>
bool BinaryTree<ElemType>::checkEqual(const BinaryTreeNode<ElemType> *root1, const BinaryTreeNode<ElemType> *root2)
{
    bool f1,f2;
    if(!root1&&!root2)//������root1��root2��Ϊ�գ���������ͬ
        return true;
    else if(root1->data==root2->data)//���°�������ҵ�˳�򣬶�������һ��ȶ�
    {
        f1=checkEqual(root1->Lkid,root2->Lkid);
        f2=checkEqual(root1->Rkid,root2->Rkid);
    }
    else//(!root1&&root2)||(root1&&!root2)||(root1->data!=root2->data)
        return false;
    if(f1&&f2)
        return true;
    else
        return false;
}

//____________________________________________________________________________________________
//______________________________________<�����Ƕ�����ADT����>_________________________________
//____________________________________________________________________________________________


const int MAXLISTSIZE = 100;

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
SqStack<ElemType>::SqStack(int maxsize)//��ʼ��˳��ջ
{
    if(maxsize==0)
        maxsize=MAXLISTSIZE;
    base=new ElemType[maxsize];
    if(!base)//�����ڴ�ʧ�ܣ�exit��0��
        exit(0);
    top=base;
    maxSize=maxsize;//˳��ջ��������洢����
}

template<class ElemType>
bool SqStack<ElemType>::StackClear( )//��˳��ջ��Ϊ�ձ�
{
    if(!top)
        return false;
    top=base;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::StackFull() const//�ж�˳��ջ�Ƿ�Ϊ��ջ
{
    return top-base==maxSize;
}

template<class ElemType>
bool SqStack<ElemType>::GetTop(ElemType &e) const//��e����ջ��Ԫ��
{
    if(StackisEmpty())
        return false;
    e=*(top-1);
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::push(ElemType &e)//��ջ
{
    if(StackFull())
        return false;
    *top++=e;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::pop(ElemType &e)//��ջ
{
    if(StackisEmpty())
        return false;
    e=*--top;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::StackDestroy()//����˳��ջ
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
void SqStack<ElemType>::StackTraverse() const//����˳��ջ
{
    ElemType *now;
    now=base;
    while(top!=now)
        cout<<*now++;
    cout<<endl;
}

template<class ElemType>
bool SqStack<ElemType>::DoubleSpace()//ջ�ռ�ӱ�
{
    top=new ElemType[maxSize];
    if(!top)
        exit(0);
    return true;
}

//������ǰ������ķǵݹ��㷨
template<class ElemType>
void PreOrder(BinaryTree<ElemType> &T)
{
    SqStack<BinaryTreeNode<ElemType>*>S;
    BinaryTreeNode<ElemType> *p=T.GetRoot();
    S.push(p);
    while(!S.StackisEmpty())
    {
        S.pop(p);
        if(p)//���ջ��Ԫ�ز�ΪNULL
        {
            //��
            cout<<p->data<<" ";//�������ǰ����ֵ
            S.push(p->Rkid);//Ȼ������������ջ
            S.push(p->Lkid);//����������ջ
        }
    }
}

//��������������ķǵݹ��㷨
template<class ElemType>
void InOrder(BinaryTree<ElemType> &T)
{
    SqStack<BinaryTreeNode<ElemType>*>S;
    BinaryTreeNode<ElemType> *p=T.GetRoot();
    while(p||!S.StackisEmpty())
    {
        while(p)//p��Ϊ�վʹ���p������
        {
            S.push(p);
            p=p->Lkid;//һֱ�ҵ����µ�������
        }
        //�������������Ѿ�������ϣ����γ�ջ�����ջ��Ԫ�ص�ֵ
        if(!S.StackisEmpty())
        {
            S.pop(p);
            cout<<p->data<<" ";
            p=p->Rkid;
        }
    }
}

//��������������ķǵݹ��㷨
template<class ElemType>
void PostOrder(BinaryTree<ElemType> &T)
{
    SqStack<BinaryTreeNode<ElemType>*>S;
    BinaryTreeNode<ElemType> *p=T.GetRoot(),*top;
    S.push(p);
    p=NULL;
    while(!S.StackisEmpty())
    {
        S.GetTop(top);
        //1��ջ��Ԫ��û��������2��p��ջ��Ԫ�ص����������
        if((!top->Lkid&&!top->Rkid)||(p&&(p==top->Lkid||p==top->Rkid)))
        {
            cout<<top->data<<" ";
            p=top;//ջ��Ԫ�ظ���p�ȴ���һ���ж�
            S.pop(top);
        }
        else
        {
            if(top->Rkid)//����������ջ
                S.push(top->Rkid);
            if(top->Lkid)//����������ջ
                S.push(top->Lkid);
        }
    }
}

int main()
{
    BinaryTree<string> tree;
    string s,empty;
    getline(cin,empty);
    getline(cin,s);
    CreateTree(tree,s,empty);
    PostOrder(tree);
    return 0;
}

