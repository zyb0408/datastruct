#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<sstream>

using namespace std;

/* 链队列的结点定义 */
template<class ElemType>
struct BinaryTreeLinkQueueNode
{
    ElemType data;
    BinaryTreeLinkQueueNode<ElemType> *next;
    BinaryTreeLinkQueueNode(BinaryTreeLinkQueueNode<ElemType> *ptr = NULL)
    {
        next = ptr;   //构造函数1，用于构造头结点
    }
    BinaryTreeLinkQueueNode(const ElemType &item, BinaryTreeLinkQueueNode<ElemType> *ptr = NULL) //构造函数2，用于构造其他结点
    //函数参数表中的形参允许有默认值，但是带默认值的参数需要放后面
    {
        next = ptr;
        data = item;
    }
    ElemType getData()
    {
        return data;   //取得结点中的数据
    }
    void SetLink(BinaryTreeLinkQueueNode<ElemType> *link)
    {
        next = link;    //修改结点的next域
    }
    void SetData(ElemType value)
    {
        data = value;    //修改结点的data域
    }
};
//带头结点的链队列
template<class ElemType>
class BinaryTreeLinkQueue
{
private:
    BinaryTreeLinkQueueNode<ElemType> *front;   // 队头指针
    BinaryTreeLinkQueueNode<ElemType> *rear;   // 队尾指针
    int length;   //队列当前元素个数
public:
    //无参数的构造函数
    BinaryTreeLinkQueue();
    //销毁链队列
    bool LinkQueueDestroy();
    //清空链表
    bool LinkQueueClear();
    //返回链队列的长度
    int QueueLength() const
    {
        return length;
    }
    //判断链队列是否为空队列
    bool QueueisEmpty() const;
    //入队
    bool EnQueue(ElemType &e);
    //出队
    bool DeQueue(ElemType &e);
    //获取链队列头结点指针
    BinaryTreeLinkQueueNode<ElemType>* GetFront()
    {
        return front;
    }
    //获取队头元素
    ElemType GetFrontData()
    {
        return front->data;
    }
    //获取链队列队尾指针
    BinaryTreeLinkQueueNode<ElemType>* GetRear()
    {
        return rear;
    }
    //遍历链队列
    bool QueueTraverse() const;
};
template<class ElemType>
BinaryTreeLinkQueue<ElemType>::BinaryTreeLinkQueue()//无参数的构造函数
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
bool BinaryTreeLinkQueue<ElemType>::LinkQueueDestroy()//销毁链队列
{
    BinaryTreeLinkQueueNode<ElemType> *p;
    if(!front)
        return false;
    while(front->next)  //便利链队列，释放链队列的所有结点
    {
        p=front->next;
        front->next=p->next;
        delete(p);
    }
    //free(front); //释放链队列的头结点
    front=rear=NULL;
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::LinkQueueClear()//清空链队列
{
    if(!front)
        return false;
    front=rear;
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::QueueisEmpty() const//判断链队列是否为空队列
{
    return rear==front;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::EnQueue(ElemType &e)  //入队
{
    BinaryTreeLinkQueueNode<ElemType> *p=new BinaryTreeLinkQueueNode<ElemType>();
    if(!p)
        return false;
    p->data=e;
    p->next=NULL;
    rear->next=p; //修改尾结点的指针
    rear=p;  //移动队尾指针
    length++;
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::DeQueue(ElemType &e)  //出队
{
    if(QueueisEmpty())
    {
        return false;
    }
    BinaryTreeLinkQueueNode<ElemType> *p=front->next;
    e=p->data;  //用e保存出队的数据
    front->next=p->next;  //修改头结点的指针
    if(rear==p)
        rear=front;
    length--;
    free(p);
    return true;
}

template<class ElemType>
bool BinaryTreeLinkQueue<ElemType>::QueueTraverse() const  //遍历链队列
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


/* 二叉表的结点定义 */
template<class ElemType>
struct BinaryTreeNode
{
    ElemType data;
    BinaryTreeNode<ElemType> *Lkid, *Rkid;
    BinaryTreeNode() : Lkid(NULL), Rkid(NULL) {} //构造函数1，用于构造根结点
    BinaryTreeNode(const ElemType &item, BinaryTreeNode<ElemType> *Lptr = NULL, BinaryTreeNode<ElemType> *Rptr = NULL) //构造函数2，用于构造其他结点
    //函数参数表中的形参允许有默认值，但是带默认值的参数需要放后面
    {
        Lkid = Lptr;
        Rkid = Rptr;
        data = item;
    }

    ElemType getData()
    {
        return data;   //取得结点中的数据
    }
    void SetLkid( BinaryTreeNode<ElemType> *link )
    {
        Lkid = link;    //修改结点的左孩子域
    }
    void SetRkid( BinaryTreeNode<ElemType> *link )
    {
        Rkid = link;    //修改结点的右孩子域
    }
    void SetData( ElemType value )
    {
        data = value;    //修改结点的data域
    }
    BinaryTreeNode<ElemType> * GetLkid() const
    {
        return Lkid;   //获取左孩子结点
    }
    BinaryTreeNode<ElemType> * GetRkid() const
    {
        return Rkid;   //获取左孩子结点
    }
};
//二叉树
template<class ElemType>
class BinaryTree
{
private:
    BinaryTreeNode<ElemType> *root;   // 头指针

    void BinaryTreeDestroy_Cursive(BinaryTreeNode<ElemType> *T); //销毁树（递归准备，private）
    bool checkEqual(const BinaryTreeNode<ElemType> *root1, const BinaryTreeNode<ElemType> *root2);//运算符==重载函数（递归部分，私有成员函数）

public:
    //无参数的构造函数
    BinaryTree():root(NULL) {}
    //带参数的构造函数
    BinaryTree(const ElemType &item)
    {
        root = new BinaryTreeNode<ElemType>(item);
    }
    //生成树
    void makeBinaryTree( const ElemType &item, BinaryTree &left, BinaryTree &right);
    //析构函数
    //~BinaryTree(){BinaryTreeDestroy();}
    //销毁树
    bool BinaryTreeDestroy();
    //销毁子树
    bool KidTreeDestroy(BinaryTreeNode<ElemType> * root, int flag);
    //返回以元素值x为根结点的（子）二叉树的高度（递归）
    int GetBinaryTreeHeight_Cursive( BinaryTreeNode<ElemType> *T, ElemType &x ) const;
    //统计结点个数
    int BinaryTreeSize( BinaryTreeNode<ElemType> *T ) const;
    //统计度为2的结点个数
    int CountDegreeTwo( BinaryTreeNode<ElemType> *T ) const;
    //判断二叉树是否为空
    bool BinaryTreeisEmpty() const
    {
        return root == NULL;
    }
    //获取根结点元素值
    ElemType GetRootData() const
    {
        return root->data;
    }
    //给元素值为x的结点重新赋值
    void Assign_NodeData( BinaryTreeNode<ElemType> *root,ElemType &x,ElemType &value);
    //查找值为x的结点的位置（递归）
    void Location_Cursive( BinaryTreeNode<ElemType> *root,const ElemType &x,BinaryTreeNode<ElemType> * &location);
    //查找值为x的结点的孩子结点的指针（flag=0，左孩子；flag=1，右孩子）
    BinaryTreeNode<ElemType> *Location_Kid(BinaryTreeNode<ElemType> * parent, int flag) const;
    //在以元素值x为根结点的位置插入子树（外壳，flag=0，左子树；flag=1，右子树）
    bool Insert_KidTree(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *kid,int flag);
    //设置根结点
    void SetRoot(BinaryTreeNode<ElemType> * p)
    {
        root = p;
    }
    //获取根结点
    BinaryTreeNode<ElemType> * GetRoot() const
    {
        return root;
    }
    //获取父结点
    void GetParent_Cursive(BinaryTreeNode<ElemType> * parent, ElemType &x, BinaryTreeNode<ElemType> * &result) const;
    //前序遍历
    bool PreOrderTraverse(BinaryTreeNode<ElemType> *T,bool(*visit)(BinaryTreeNode<ElemType> *T)) const;  //前序遍历（递归）
    //中序遍历
    bool InOrderTraverse(BinaryTreeNode<ElemType> *T,bool(*visit)(BinaryTreeNode<ElemType> *T)) const;  //中序遍历（递归）
    //后序遍历
    bool PostOrderTraverse(BinaryTreeNode<ElemType> *T,bool(*visit)(BinaryTreeNode<ElemType> *T)) const;  //后序遍历（递归）
    //按树状打印出二叉树的形状（递归};
    void Print_BinaryTree(BinaryTreeNode<ElemType> *root, int i); //按树状打印出二叉树的形状（递归）
    //建立二叉树的存储结构
    BinaryTreeNode<ElemType>* CreateBinaryTree(ElemType x[], ElemType &empty, int &n);
    //层次遍历，成员函数
    bool LayerOrderTraverse(bool (*visit)(BinaryTreeNode<ElemType> *T)) const;
    //查找值为x的结点的孩子结点的指针（flag=0，左孩子；flag=1，右孩子）
    void Location_Kid(BinaryTreeNode<ElemType> *T,ElemType &x,int flag,BinaryTreeNode<ElemType> *&location) const;
    //返回指向值为x的结点的兄弟结点的指针（flag=0，左兄弟；flag=1，右兄弟）
    BinaryTreeNode<ElemType> *Get_Sibling(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *location,int flag)const;
    //判断是否是完全二叉树
    bool IsCompleteTree() const;
    //运算符==重载函数
    bool operator ==(const BinaryTree<ElemType> &T);
};


template<class ElemType>
void PreOrderTraverse(BinaryTreeNode<ElemType> *T)//前序遍历
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
void InOrderTraverse(BinaryTreeNode<ElemType> *T)//中序遍历
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
void PostOrderTraverse(BinaryTreeNode<ElemType> *T)//后序遍历
{
    if(T)
    {
        PostOrderTraverse(T->Lkid);
        PostOrderTraverse(T->Rkid);
        cout<<T->data<<" ";
    }
    //return true;
}

//建立二叉树的存储结构 （外壳部分，用户函数）
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

//建立二叉树的存储结构 (递归部分，成员函数）
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
//前序遍历（外壳部分，用户函数）
template<class ElemType>
bool PreOrderTraverse(BinaryTree<ElemType> &T)
{
    T.PreOrderTraverse(T.GetRoot(),visit);
    return true;
}

//前序遍历（递归部分，成员函数）
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

//中序遍历（外壳部分，用户函数）
template<class ElemType>
bool InOrderTraverse(BinaryTree<ElemType> &T)
{
    T.InOrderTraverse(T.GetRoot(),visit);
    return true;
}

//中序遍历（递归部分，成员函数）
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

//后序遍历（外壳部分，用户函数）
template<class ElemType>
bool PostOrderTraverse(BinaryTree<ElemType> &T)
{
    T.PostOrderTraverse(T.GetRoot(),visit);
    return true;
}

//后序遍历（递归部分，成员函数）
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
//层次遍历，成员函数
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

//销毁树(外壳部分，public）
template<class ElemType>
bool BinaryTree<ElemType>::BinaryTreeDestroy()
{
    if(!root)
        return false;
    BinaryTreeDestroy_Cursive(root);
    return true;
}

//销毁树（递归部分。private）
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

//获取父结点（外壳）
template<class ElemType>
BinaryTreeNode<ElemType> * GetParent(BinaryTree<ElemType> &T, ElemType &x)
{
    BinaryTreeNode<ElemType> *parent;
    if(T.GetRoot()==NULL||T.GetRootData()==x)//1、树空；2、树根没有双亲结点
    {
        return NULL;
    }
    T.GetParent_Cursive(T.GetRoot(),x,parent);
    return parent;
}

//获取父结点（递归）
template<class ElemType>
void BinaryTree<ElemType>::GetParent_Cursive(BinaryTreeNode<ElemType> * parent,ElemType &x,BinaryTreeNode<ElemType> * &result) const
{
    if(parent==NULL)//找尽
        return;
    else if(((parent->Lkid)&&(parent->Lkid->data)==x)||((parent->Rkid)&&(parent->Rkid->data)==x))
        result=parent;//找到双亲结点
    else
    {
        GetParent_Cursive(parent->Lkid,x,result);
        GetParent_Cursive(parent->Rkid,x,result);
    }
}

//查找结点的位置（外壳部分，用户函数）
template<class ElemType>
BinaryTreeNode<ElemType> * Location(BinaryTree<ElemType> &T, ElemType &x)
{
    BinaryTreeNode<ElemType> *location=NULL;//找到与否是未知的，方便起见先设location为NULL
    T.Location_Cursive(T.GetRoot(),x,location);
    return location;
}

//查找结点的位置（递归部分，成员函数）
template<class ElemType>  //指针location为查找结果
void BinaryTree<ElemType>::Location_Cursive(BinaryTreeNode<ElemType> * root,const ElemType &x,BinaryTreeNode<ElemType> *&location)
{
    if(!root)
        return;
    else if(root->data==x)//比找双亲结点省力多了。。。
        location=root;//找到这个结点
    else
    {
        Location_Cursive(root->Lkid,x,location);
        Location_Cursive(root->Rkid,x,location);
    }
}

//计算以元素值x为根结点的（子）二叉树的高度（外壳部分，用户函数）
template<class ElemType>
int GetBinaryTreeHeight(BinaryTree<ElemType> &T,ElemType &x)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1、树空；2、树中没有这个结点，则树高为0
        return 0;
    else
        return T.GetBinaryTreeHeight_Cursive(Location(T,x),x);
}

//计算以元素值x为根结点的（子）二叉树的高度（递归部分，成员函数）
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
//查找以元素值x为父结点的孩子结点（外壳部分，用户函数）
//返回以元素值x为父结点的孩子结点的指针（外壳，flag=0，左孩子；flag=1，右孩子）
template<class ElemType>
BinaryTreeNode<ElemType> *LocationKid(BinaryTree<ElemType> &T,ElemType &x, int flag)
{
    BinaryTreeNode<ElemType> *location=NULL;//找到与否是未知的，方便起见先设location为NULL
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1、树空；2、树中没有这个结点，则返回NULL
    {
        return NULL;
    }
    T.Location_Kid(Location(T,x),x,flag,location);
    return location;
}

//查找以元素值x为父结点的孩子结点（递归部分，成员函数）
//查找值为x的结点的孩子结点的指针（flag=0，左孩子；flag=1，右孩子）
template<class ElemType>
void BinaryTree<ElemType>::Location_Kid(BinaryTreeNode<ElemType> *T,ElemType &x,int flag,BinaryTreeNode<ElemType> *&location) const
{
    if(flag)//flag=1,右孩子
        location=T->GetRkid();
    else//flag=0,左孩子
        location=T->GetLkid();
}

//删除以元素值x为根结点的（子）树（外壳部分，用户函数）
//删除以元素值x为根结点的（子）树（flag=0，左子树；flag=1，右子树）
template<class ElemType>
bool DeleteKid(BinaryTree<ElemType> &T, ElemType &x, int flag)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1、树空；2、树中没有这个结点，则返回false
        return false;
    return T.KidTreeDestroy(Location(T,x),flag);
}

//删除以元素值x为根结点的（子）树（递归部分，成员函数）
//删除以元素值x为根结点的（子）树（flag=0，左子树；flag=1，右子树）
template<class ElemType>
bool BinaryTree<ElemType>::KidTreeDestroy(BinaryTreeNode<ElemType> *root, int flag)
{
    if((flag==0&&root->Lkid==NULL)||(flag==1&&root->Rkid==NULL))//没这棵子树，返回false
        return false;
    else//有这棵子树
    {
        if(flag)//柚子树
        {
            BinaryTreeDestroy_Cursive(root->Rkid);
            //delete root->Rkid;//释放柚子树的空间
            root->Rkid=NULL;
        }
        else//左子树
        {
            BinaryTreeDestroy_Cursive(root->Lkid);
            //delete root->Lkid;//释放左子树的空间
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
//在以元素值为x的结点的位置插入子树（外壳部分，用户函数）
//在以元素值为x的结点的位置插入子树（flag=0，左子树；flag=1，右子树）
template<class ElemType>
bool InsertKidTree(BinaryTree<ElemType> &T, BinaryTree<ElemType> &R, ElemType &x, int flag)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1、树空；2、树中没有这个结点，则返回false
        return false;
    return T.Insert_KidTree(Location(T,x),R.GetRoot(),flag);
}

//在以元素值为x的结点的位置插入子树（递归部分，成员函数）
//在以元素值为x的结点的位置插入子树（flag=0，左子树；flag=1，右子树）
template<class ElemType>
bool BinaryTree<ElemType>::Insert_KidTree(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *kid,int flag)
{
    BinaryTreeNode<ElemType> *p;
    if(flag)//插入一棵柚子树
    {
        p=parent->Rkid;
        parent->Rkid=kid;
        kid->Rkid=p;
        return true;
    }
    else//插入一棵左子树
    {
        p=parent->Lkid;
        parent->Lkid=kid;
        kid->Rkid=p;
        return true;
    }
    return false;
}

//给元素值为x的结点重新赋值（外壳部分，用户函数）
//给元素值为x的结点重新赋值
template<class ElemType>
bool AssignNodeData(BinaryTree<ElemType> &T, ElemType &x, ElemType &value)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL)//1、树空；2、树中没有这个结点，则返回false
        return false;
    T.Assign_NodeData(Location(T,x),x,value);
    return true;
}

//给元素值为x的结点重新赋值（成员函数）
//给元素值为x的结点重新赋值（flag=0，左子树；flag=1，右子树）
template<class ElemType>
void BinaryTree<ElemType>::Assign_NodeData(BinaryTreeNode<ElemType> *root,ElemType &x,ElemType &value)
{
    root->data=value;
}

//返回指向值为x的结点的兄弟结点的指针（外壳部分，用户函数）
//返回指向值为x的结点的兄弟结点的指针（flag=0，左兄弟；flag=1，右兄弟）
template<class ElemType>
BinaryTreeNode<ElemType> *GetSibling(BinaryTree<ElemType> &T, ElemType &x, int flag)
{
    if(T.GetRoot()==NULL||Location(T,x)==NULL||Location(T,x)==T.GetRoot())//1、树空;2、树中没有这个结点;3、这个结点是根结点，则返回NULL
        return NULL;
    BinaryTreeNode<ElemType> *parent;
    T.GetParent_Cursive(T.GetRoot(),x,parent);//要先找到双亲结点才能找到兄弟结点
    return T.Get_Sibling(parent,Location(T,x),flag);
}

//返回指向值为x的结点的兄弟结点的指针（成员函数）
//返回指向值为x的结点的兄弟结点的指针（flag=0，左兄弟；flag=1，右兄弟）
template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Get_Sibling(BinaryTreeNode<ElemType> *parent,BinaryTreeNode<ElemType> *location,int flag)const
{
    if(flag==0&&parent->Rkid==location)//找左兄弟，判断它自己是不是右兄弟
        return parent->Lkid;
    else if(flag==1&&parent->Lkid==location)//同理，找右兄弟，判断它自己是不是左兄弟
        return parent->Rkid;
    else
        return NULL;
}

//判断是否是完全二叉树
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
        if(p)//当p不为NULL
        {
            if(f)
                return false;
            Q.EnQueue(p->Lkid);
            Q.EnQueue(p->Rkid);
        }
        else//当p为NULL
            f=true;
    }
    return true;
}
//运算符==重载函数（外壳部分，成员函数形式重载）
template<class ElemType>
bool BinaryTree<ElemType>::operator ==(const BinaryTree<ElemType> &T)
{
    return checkEqual(root,T.GetRoot());
}

//运算符==重载函数（递归部分，私有成员函数）
template<class ElemType>
bool BinaryTree<ElemType>::checkEqual(const BinaryTreeNode<ElemType> *root1, const BinaryTreeNode<ElemType> *root2)
{
    bool f1,f2;
    if(!root1&&!root2)//遍历到root1和root2都为空，则两树相同
        return true;
    else if(root1->data==root2->data)//往下按先左后右的顺序，对子树逐一相比对
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
//______________________________________<以上是二叉树ADT部分>_________________________________
//____________________________________________________________________________________________


const int MAXLISTSIZE = 100;

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
SqStack<ElemType>::SqStack(int maxsize)//初始化顺序栈
{
    if(maxsize==0)
        maxsize=MAXLISTSIZE;
    base=new ElemType[maxsize];
    if(!base)//分配内存失败，exit（0）
        exit(0);
    top=base;
    maxSize=maxsize;//顺序栈允许的最大存储容量
}

template<class ElemType>
bool SqStack<ElemType>::StackClear( )//将顺序栈置为空表
{
    if(!top)
        return false;
    top=base;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::StackFull() const//判断顺序栈是否为满栈
{
    return top-base==maxSize;
}

template<class ElemType>
bool SqStack<ElemType>::GetTop(ElemType &e) const//用e返回栈顶元素
{
    if(StackisEmpty())
        return false;
    e=*(top-1);
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::push(ElemType &e)//入栈
{
    if(StackFull())
        return false;
    *top++=e;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::pop(ElemType &e)//出栈
{
    if(StackisEmpty())
        return false;
    e=*--top;
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::StackDestroy()//销毁顺序栈
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
void SqStack<ElemType>::StackTraverse() const//遍历顺序栈
{
    ElemType *now;
    now=base;
    while(top!=now)
        cout<<*now++;
    cout<<endl;
}

template<class ElemType>
bool SqStack<ElemType>::DoubleSpace()//栈空间加倍
{
    top=new ElemType[maxSize];
    if(!top)
        exit(0);
    return true;
}

//二叉树前序遍历的非递归算法
template<class ElemType>
void PreOrder(BinaryTree<ElemType> &T)
{
    SqStack<BinaryTreeNode<ElemType>*>S;
    BinaryTreeNode<ElemType> *p=T.GetRoot();
    S.push(p);
    while(!S.StackisEmpty())
    {
        S.pop(p);
        if(p)//如果栈顶元素不为NULL
        {
            //则
            cout<<p->data<<" ";//先输出当前结点的值
            S.push(p->Rkid);//然后柚子树先入栈
            S.push(p->Lkid);//左子树再入栈
        }
    }
}

//二叉树中序遍历的非递归算法
template<class ElemType>
void InOrder(BinaryTree<ElemType> &T)
{
    SqStack<BinaryTreeNode<ElemType>*>S;
    BinaryTreeNode<ElemType> *p=T.GetRoot();
    while(p||!S.StackisEmpty())
    {
        while(p)//p不为空就代表p有子树
        {
            S.push(p);
            p=p->Lkid;//一直找到最下的左子树
        }
        //到这里左子树已经遍历完毕，依次出栈，输出栈顶元素的值
        if(!S.StackisEmpty())
        {
            S.pop(p);
            cout<<p->data<<" ";
            p=p->Rkid;
        }
    }
}

//二叉树后序遍历的非递归算法
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
        //1、栈顶元素没有子树；2、p是栈顶元素的左或柚子树
        if((!top->Lkid&&!top->Rkid)||(p&&(p==top->Lkid||p==top->Rkid)))
        {
            cout<<top->data<<" ";
            p=top;//栈顶元素赋给p等待下一次判断
            S.pop(top);
        }
        else
        {
            if(top->Rkid)//柚子树先入栈
                S.push(top->Rkid);
            if(top->Lkid)//左子树再入栈
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

