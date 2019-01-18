#include<iostream>
#include<time.h>
#include<cstdlib>
#define CLOCKS_PER_SEC ((clock_t)1000)
using namespace std;
const int MAXLISTSIZE=100;
const int MAX=10000000;
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
    //if(pos<1||pos>listsize+1||length>=MAXLISTSIZE)
    if(pos<1||pos>listsize)
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
    //cout<<endl;
    return 1;
}

//��β������
template<class ElemType>
void BubbleSort(SqList<ElemType> &A)
{
    ElemType e1,e2;
    int spot=0;
    int i,left,right;
    int low=0,high=A.ListLength()-1;
    while(low<high)
    {
        spot=0;
        left=low+1;
        right=high-1;
        for(i=low; i<high; i++)
        {
            e1=A.GetElem(i);
            e2=A.GetElem(i+1);
            if(e1>e2)
            {
                spot=1;
                A.SetElem(i,e2);
                A.SetElem(i+1,e1);
                right=i;
            }
        }
        high=right;
        for(i=high; i>low; i--)
        {
            e1=A.GetElem(i);
            e2=A.GetElem(i-1);
            if(e1<e2)
            {
                spot=1;
                A.SetElem(i,e2);
                A.SetElem(i-1,e1);
                left=i;
            }
        }
        low=left;
        if(!spot)
            break;
    }

}

int main()
{
    SqList<int>A(MAX),B(MAX);
    int i,e;
    clock_t start,finish;
    srand((unsigned)time(NULL));
    start=clock();
    for(i=1; i<=MAX; i++)
    {
        e=(int)(MAX*rand()/(RAND_MAX+1.0));
        A.ListInsert(i,e);
    }
    finish=clock();
    cout<<"���Ա�A�ĳ���Ϊ "<<A.ListLength()<<"\t��ʱ"<<(double)(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"Ԫ��������ɵ����Ա������...��ʼ����ð������"<<endl;
    start=clock();
    BubbleSort(A);
    finish=clock();
    cout<<"ð���������"<<"\t��ʱ"<<(double)(finish-start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;

    start=clock();
    for(i=1; i<=MAX; i++)
    {
        B.ListInsert(i,i);
    }
    finish=clock();
    cout<<"���Ա�B�ĳ���Ϊ "<<B.ListLength()<<"\t��ʱ"<<(double)(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"Ԫ���Ѿ���������Ա������...��ʼ����ð������"<<endl;
    start=clock();
    BubbleSort(B);
    finish=clock();
    cout<<"ð���������"<<"\t��ʱ"<<(double)(finish-start)/CLOCKS_PER_SEC<<"s";
    return 0;
}
