#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXLISTSIZE=100;
template<class ElemType>
class SqList
{
private:
    ElemType *elem;   // �洢�ռ��ַ
    int length;               // ��ǰ����
    int listsize;        // ��������洢����(��sizeof(ElemType)Ϊ��λ
public:

    SqList(int ms = 20);//��ʼ��˳���
    ~SqList()
    {
        delete [] elem;   //ɾ��˳���
    }
    void ListClear( )
    {
        length = 0;   //��˳�����Ϊ�ձ�
    }
    int ListLength() const
    {
        return length;   //����˳���ĳ���
    }
    bool SetListLength(int len);   //����˳���ĳ���
    bool ListEmpty() const;   //�ж�˳����Ƿ�Ϊ�ձ�
    bool ListFull() const; //�ж�˳����Ƿ�Ϊ����
    ElemType GetElem(int i) const; //��e����˳���ĵ�i��Ԫ��
    bool SetElem(int i, ElemType e);  //��e����˳���ĵ�i��Ԫ��
    bool ListInsert(int pos,ElemType e); //��˳���ĵ�pos��λ��֮ǰ����eԪ��
    bool ListDelete(int pos, ElemType &e); //ɾ��˳���ĵ�pos��λ�õ�Ԫ��
    bool compare(ElemType a, ElemType *b); //compare�����������ж�a��b�Ƿ����
    int LocateElem(ElemType e);//��ָ����������
    void Invert(int, int);  //����˳���
    bool PriorElem(ElemType cur_e, ElemType &pri_e);  //�������Ա��������Ԫ�ص�ǰ������Ԫ�ص�ֵ
    bool NextElem(ElemType cur_e, ElemType &nex_e);   //�������Ա��������Ԫ�صĺ������Ԫ�ص�ֵ
    void ListDestroy();  //�������Ա�
    int ListTraverse() const;//����˳���
};
template<class ElemType>
SqList<ElemType>::SqList(int maxsize)//��ʼ��˳���
{
    if(maxsize==0)
        maxsize=MAXLISTSIZE;
    elem=new ElemType[maxsize];
    if(!elem)//�����ڴ�ʧ�ܣ�exit��0��
        exit(0);
    length=0;//˳���ĳ�ʼ����Ϊ0
    listsize=maxsize;//˳�����������洢����
}

template<class ElemType>
bool SqList<ElemType>::ListEmpty() const//�ж�˳����Ƿ�Ϊ��
{
    if(length==0)
        return true;//��ǰԪ�ظ���Ϊ0��������˳���Ϊ�ձ�
    else
        return false;//��֮��������˳���Ϊ�ձ�
}

template<class ElemType>
bool SqList<ElemType>::ListFull() const//�ж����Ա��Ƿ�Ϊ��
{
    if(length==MAXLISTSIZE)
        return true;//��ǰԪ�ظ��������洢������ȣ�������˳���Ϊ����
    else
        return false;//��֮��������˳���Ϊ����
}

template<class ElemType>
bool SqList<ElemType>::SetListLength(int len)//�ж����õĳ��ȵĺϷ���
{
    if(len<0||len>MAXLISTSIZE)
        return false;//��1�����õĳ���С��0��2�����õĳ��ȴ���Լ��ֵMAXLISTSIZE
    //����������ǲ�����ģ�����֮�����õ�˳����Ȳ�����
    length=len;
    return true;//��֮�����õĳ��Ⱥ���ʱ��length=len
}

template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const//��e����˳���ĵ�i��Ԫ��
{
    if(i<0||i>listsize)
        exit(0);//���жϴ����iֵ�Ƿ���˳���ĺϷ����ȷ�Χ��
    return *(elem+i);//��i�Ϸ�ʱ������������˳���ĵ�i��Ԫ��
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int i,ElemType e)//��e����˳���ĵ�i��Ԫ��
{
    if(i<0||i>listsize)
        return false;//���жϴ����iֵ�Ƿ���˳���ĺϷ����ȷ�Χ��
    *(elem+i)=e;//��e��ֵ����*��elem+i)
    return true;//��i�Ϸ�ʱ������������˳���ĵ�i��Ԫ�ء�
}

template<class ElemType>
bool SqList<ElemType>::ListInsert(int pos,ElemType e)//��˳���ĵ�pos��λ��֮ǰ����eԪ��
{
    if(pos<1||pos>listsize+1||pos>=MAXLISTSIZE)
        return false;//���жϴ����iֵ�Ƿ���˳���ĺϷ����ȷ�Χ��
    else
    {
        for(int i=length-1; i>=pos-1; i--)//pos-1Ϊ����e��λ������
            elem[i+1]=elem[i];//��˳���β����ǰ�����ν���Ԫ��λ�ú���һ����λ����
        elem[pos-1]=e;//��˳���ĵ�pos��λ��֮ǰ����e
        length++;//����eԪ�غ�˳�����������1����λ����
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::ListDelete(int pos,ElemType &e)//ɾ��˳���ĵ�pos��λ�õ�Ԫ��
{
    if(pos<1||pos>length)
        return false;//���жϴ����iֵ�Ƿ���˳���ĺϷ����ȷ�Χ��
    else
    {
        e=elem[pos-1];//����ɾ���ĵ�pos��λ�õ�Ԫ�ص�ֵ����e����˴�
        //ȥ���δ���֪����������Ҫ����Ҫ�õ�ElemType &e���������õĻ�����֪��Ҫ������������
        for(int i=pos; i<=length; i++) //posΪɾ��e��λ�ú���һ����λ���ȵ�λ��
            elem[i-1]=elem[i];//��˳���posλ�ÿ�ʼ�������ν���Ԫ��λ��ǰ��һ����λ����
        length--;//ɾ��eԪ�غ�˳����������1����λ����
        return true;
    }
}

template<class ElemType>
bool SqList<ElemType>::compare(ElemType a,ElemType *b)//�����ж�a��b�Ƿ����
{
    //����ûʲô���ɣ�ֱ�ӱȽ�һ�¾�����
    if(a==*b)
        return true;
    return false;
}

template<class ElemType>
int SqList<ElemType>::LocateElem(ElemType e)//��ָ����������
{
    int i;
    for(i=0; i<length; i++)
    {
        if(compare(e,elem+i)==false)
            continue;//����������һλ
        else
            break;//�ҵ���ֱ��break����һ��
    }
    if(i==length)//i=lengthʱ�Ѷ�˳����������
        return 0;//i=length˵��Ϊ�ҵ�e����e��˳����е�Ԫ��
    else
        return 1;//i!=length˵�����ҵ�e����λ��
}

template<class ElemType>
void SqList<ElemType>::Invert(int s,int t)//����˳���
{
    ElemType store;//��һ����רվ������ʱ�洢����
    for(int i=s; i<=(s+t)/2; i++)
    {
        store=elem[i];
        elem[i]=elem[s+t-i];
        elem[s+t-i]=store;
    }
}

template<class ElemType>
bool SqList<ElemType>::PriorElem(ElemType cur_e,ElemType &pre_e)//�������Ա��������Ԫ�ص�ǰ������Ԫ�ص�ֵ
{
    if(elem)
    {
        //��֪Ԫ�ص�ֵ������Ѱ�Ҹ�Ԫ����������˳����е��±�λ��
        //����LocateElem����������ĳһԪ�ؽ��ж�λ
        if(LocateELem(cur_e)&&LocateElem(cur_e)!=0)
            //��cur_e��Ӧ���±�Ϊ0��������û��ǰ��Ԫ���ˣ���������Ҫ�ų���cur_e�±�Ϊ0�����
        {
            pre_e=*(elem+LocateElem(cur_e)-1);
            //*(elem+LocateElem(cur_e)-1)��*(elem+i)��һ�����͵���˼������ȡ����ĳһ��λ�õ�Ԫ�ص�ֵ
            //�Ժ��ͷ�������鵽�����ʱ����±�
            return true;
        }
        else
            return false;
    }
    return false;
}

template<class ElemType>
bool SqList<ElemType>::NextElem(ElemType cur_e,ElemType &nex_e)//�������Ա��������Ԫ�صĺ������Ԫ�ص�ֵ
{
    if(elem)
    {
        //��֪Ԫ�ص�ֵ������Ѱ�Ҹ�Ԫ����������˳����е��±�λ��
        //����LocateElem����������ĳһԪ�ؽ��ж�λ
        if(LocateELem(cur_e)&&LocateElem(cur_e)!=length-1)
            //��cur_e��Ӧ���±�Ϊlength-1��������û�к���Ԫ���ˣ���������Ҫ�ų���cur_e�±�Ϊlength-1�����
        {
            nex_e=*(elem+LocateElem(cur_e)+1);
            //*(elem+LocateElem(cur_e)+1)��*(elem+i)��һ�����͵���˼������ȡ����ĳһ��λ�õ�Ԫ�ص�ֵ
            return true;
        }
        else
            return false;
    }
    return false;//��������������Ǹ���ǰ��Ԫ�صĺ���ͬ��
}

template<class ElemType>
void SqList<ElemType>::ListDestroy()//����˳���
{
    delete elem;
    listsize=0;
    length=0;//�տ���Ҳ
}

template<class ElemType>
int SqList<ElemType>::ListTraverse() const//����˳���
{
    for(int i=0; i<length; i++)
        cout<<*(elem+i)<<" ";
    cout<<endl;
    return 1;
}

//һ�˹鲢�����㷨: (��·����Ϊһ·)
template<class ElemType>
void Merge(SqList<ElemType> &A, int low,int mid,int high)//lowΪ��1�������ĵ�1��Ԫ�أ�midΪ��1�����������1��Ԫ��
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

//�ǵݹ���ʽ����·�鲢�����㷨
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
