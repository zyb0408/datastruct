#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXLISTSIZE=100;
template<class ElemType>
class SqList
{
private:
    ElemType *elem;   // 存储空间基址
    int length;               // 当前长度
    int listsize;        // 允许的最大存储容量(以sizeof(ElemType)为单位
public:

    SqList(int ms = 20);//初始化顺序表
    ~SqList()
    {
        delete [] elem;   //删除顺序表
    }
    void ListClear( )
    {
        length = 0;   //将顺序表置为空表
    }
    int ListLength() const
    {
        return length;   //返回顺序表的长度
    }
    bool SetListLength(int len);   //设置顺序表的长度
    bool ListEmpty() const;   //判断顺序表是否为空表
    bool ListFull() const; //判断顺序表是否为满表
    ElemType GetElem(int i) const; //用e返回顺序表的第i个元素
    bool SetElem(int i, ElemType e);  //用e设置顺序表的第i个元素
    bool ListInsert(int pos,ElemType e); //在顺序表的第pos个位置之前插入e元素
    bool ListDelete(int pos, ElemType &e); //删除顺序表的第pos个位置的元素
    bool compare(ElemType a, ElemType *b); //compare函数，用来判断a和b是否相等
    int LocateElem(ElemType e);//按指定条件查找
    void Invert(int, int);  //逆置顺序表
    bool PriorElem(ElemType cur_e, ElemType &pri_e);  //返回线性表给定数据元素的前驱数据元素的值
    bool NextElem(ElemType cur_e, ElemType &nex_e);   //返回线性表给定数据元素的后继数据元素的值
    void ListDestroy();  //销毁线性表
    int ListTraverse() const;//遍历顺序表
};
template<class ElemType>
SqList<ElemType>::SqList(int maxsize)//初始化顺序表
{
    if(maxsize==0)
        maxsize=MAXLISTSIZE;
    elem=new ElemType[maxsize];
    if(!elem)//分配内存失败，exit（0）
        exit(0);
    length=0;//顺序表的初始长度为0
    listsize=maxsize;//顺序表允许的最大存储容量
}

template<class ElemType>
bool SqList<ElemType>::ListEmpty() const//判断顺序表是否为空
{
    if(length==0)
        return true;//当前元素个数为0，则代表此顺序表为空表
    else
        return false;//反之，则代表此顺序表不为空表
}

template<class ElemType>
bool SqList<ElemType>::ListFull() const//判断线性表是否为满
{
    if(length==MAXLISTSIZE)
        return true;//当前元素个数与最大存储容量相等，则代表此顺序表为满表
    else
        return false;//反之，则代表此顺序表不为满表
}

template<class ElemType>
bool SqList<ElemType>::SetListLength(int len)//判断设置的长度的合法性
{
    if(len<0||len>MAXLISTSIZE)
        return false;//（1）设置的长度小于0（2）设置的长度大于约定值MAXLISTSIZE
    //这两种情况是不合理的，换言之，设置的顺序表长度不合理
    length=len;
    return true;//反之，设置的长度合理时，length=len
}

template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const//用e返回顺序表的第i个元素
{
    if(i<0||i>listsize)
        exit(0);//先判断传入的i值是否在顺序表的合法长度范围内
    return *(elem+i);//当i合法时，可正常返回顺序表的第i个元素
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int i,ElemType e)//用e设置顺序表的第i个元素
{
    if(i<0||i>listsize)
        return false;//先判断传入的i值是否在顺序表的合法长度范围内
    *(elem+i)=e;//将e的值传给*（elem+i)
    return true;//当i合法时，可正常设置顺序表的第i个元素。
}

template<class ElemType>
bool SqList<ElemType>::ListInsert(int pos,ElemType e)//在顺序表的第pos个位置之前插入e元素
{
    if(pos<1||pos>listsize+1||pos>=MAXLISTSIZE)
        return false;//先判断传入的i值是否在顺序表的合法长度范围内
    else
    {
        for(int i=length-1; i>=pos-1; i--)//pos-1为插入e的位置所在
            elem[i+1]=elem[i];//从顺序表尾部往前，依次将各元素位置后移一个单位长度
        elem[pos-1]=e;//在顺序表的第pos个位置之前插入e
        length++;//插入e元素后顺序表整体增加1个单位长度
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::ListDelete(int pos,ElemType &e)//删除顺序表的第pos个位置的元素
{
    if(pos<1||pos>length)
        return false;//先判断传入的i值是否在顺序表的合法长度范围内
    else
    {
        e=elem[pos-1];//将被删除的第pos个位置的元素的值交给e带离此处
        //去往何处不知道，反正按要求是要用到ElemType &e，不这样用的话都不知道要在哪里用它了
        for(int i=pos; i<=length; i++) //pos为删除e的位置后移一个单位长度的位置
            elem[i-1]=elem[i];//从顺序表pos位置开始往后，依次将各元素位置前移一个单位长度
        length--;//删除e元素后顺序表整体减少1个单位长度
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::compare(ElemType a,ElemType *b)//用于判断a和b是否相等
{
    //好像没什么技巧，直接比较一下就行了
    if(a==*b)
        return true;
    return false;
}

template<class ElemType>
int SqList<ElemType>::LocateElem(ElemType e)//按指定条件查找
{
    int i;
    for(i=0; i<length; i++)
    {
        if(compare(e,elem+i)==false)
            continue;//继续查找下一位
        else
            break;//找到则直接break到下一步
    }
    if(i==length)//i=length时已对顺序表搜索完毕
        return 0;//i=length说明为找到e，即e非顺序表中的元素
    else
        return 1;//i!=length说明已找到e所在位置
}

template<class ElemType>
void SqList<ElemType>::Invert(int s,int t)//逆置顺序表
{
    ElemType store;//设一个中专站，作暂时存储作用
    for(int i=s; i<=(s+t)/2; i++)
    {
        store=elem[i];
        elem[i]=elem[s+t-i];
        elem[s+t-i]=store;
    }
}

template<class ElemType>
bool SqList<ElemType>::PriorElem(ElemType cur_e,ElemType &pre_e)//返回线性表给定数据元素的前驱数据元素的值
{
    if(elem)
    {
        //已知元素的值，现需寻找该元素在其所属顺序表中的下标位置
        //先用LocateElem（）函数对某一元素进行定位
        if(LocateELem(cur_e)&&LocateElem(cur_e)!=0)
            //若cur_e对应的下标为0，那它就没有前驱元素了，所以这里要排除掉cur_e下标为0的情况
        {
            pre_e=*(elem+LocateElem(cur_e)-1);
            //*(elem+LocateElem(cur_e)-1)和*(elem+i)是一个类型的意思，都是取表中某一个位置的元素的值
            //以后回头检查代码检查到这里的时候别懵逼
            return true;
        }
        else
            return false;
    }
    return false;
}

template<class ElemType>
bool SqList<ElemType>::NextElem(ElemType cur_e,ElemType &nex_e)//返回线性表给定数据元素的后继数据元素的值
{
    if(elem)
    {
        //已知元素的值，现需寻找该元素在其所属顺序表中的下标位置
        //先用LocateElem（）函数对某一元素进行定位
        if(LocateELem(cur_e)&&LocateElem(cur_e)!=length-1)
            //若cur_e对应的下标为length-1，那它就没有后驱元素了，所以这里要排除掉cur_e下标为length-1的情况
        {
            nex_e=*(elem+LocateElem(cur_e)+1);
            //*(elem+LocateElem(cur_e)+1)和*(elem+i)是一个类型的意思，都是取表中某一个位置的元素的值
            return true;
        }
        else
            return false;
    }
    return false;//这个函数和上面那个找前驱元素的函数同理
}

template<class ElemType>
void SqList<ElemType>::ListDestroy()//销毁顺序表
{
    delete elem;
    listsize=0;
    length=0;//空空如也
}

template<class ElemType>
int SqList<ElemType>::ListTraverse() const//遍历顺序表
{
    for(int i=0; i<length; i++)
        cout<<*(elem+i)<<" ";
    cout<<endl;
    return 1;
}

//一趟归并排序算法: (两路有序并为一路)
template<class ElemType>
void Merge(SqList<ElemType> &A, int low,int mid,int high)//low为第1有序区的第1个元素，mid为第1有序区的最后1个元素
{
    int i,j,k=0;
    ElemType *s=new ElemType[high+1-low];
    for(i=low,j=mid+1; i<=mid&&j<=high; k++)
    {
        if(A.GetElem(i)<=A.GetElem(j))
            s[k]=A.GetElem(i++);
        else
            s[k]=A.GetElem(j++);
    }
    for(;i<=mid;++i,++k)
        s[k]=A.GetElem(i);
    for(;j<=high;++j,++k)
        s[k]=A.GetElem(j);
    for(i=low,k=0; i<=high; i++,k++)
        A.SetElem(i,s[k]);
    delete s;

}

//非递归形式的两路归并排序算法
template<class ElemType>
void MergeSort(SqList<ElemType> &A)
{
    int i,n,low,mid,high,k=1;
    ElemType e;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>e;
        A.ListInsert(i,e);
    }

    for(;k<=A.ListLength()-1;k*=2)
    {
        low=0;
        while(low+k<=A.ListLength()-1)
        {
            mid=low+k-1;
            high=mid+k;
            if(high>A.ListLength()-1)
                high=A.ListLength()-1;
            Merge(A,low,mid,high);
            low=high+1;
        }
        A.ListTraverse();
    }
}

void Judge(int kind)
{
    if(kind==0)
    {
        SqList <int> A;
        MergeSort(A);
    }
    else if(kind==1)
    {
        SqList <double> A;
        MergeSort(A);
    }
    else if(kind==2)
    {
        SqList <char> A;
        MergeSort(A);
    }
    else if(kind==3)
    {
        SqList <string> A;
        MergeSort(A);
    }
    else
        cout<<"err"<<endl;
}

int main()
{
    int kind;
    cin>>kind;
    Judge(kind);
    //A.ListTraverse();

    return 0;
}
