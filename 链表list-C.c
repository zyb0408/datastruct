#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//�����������ͣ����Ը�����Ҫ�����������͵Ķ���
typedef int ElementType;

//�����㶨��
typedef struct ListNode {
	ElementType Element;							//������
	struct ListNode* Next;									//ָ����һ������ָ��
}Node,*PNode;

//������������
PNode CreateList(void);								//��������
void TraverseList(PNode List);						//��������
void InsertList(PNode List,int pos,int val);		//��������
void DeleteTheList(PNode List);						//ɾ����������
void DeleteList(PNode List,int pos);				//ɾ��������ĳ��λ��Ԫ��
PNode FindList(PNode List);							//�����ѯ����


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

//����ʵ��
PNode CreateList(void){
	int len;										//����������
	int val;										//���ڴ�Ž����ֵ
	PNode PHead = (PNode)malloc(sizeof(Node));		//��������һ��ͷ����ڴ�ռ�
	if(PHead==NULL){
		printf("�ռ����ʧ��..\n");
		exit(-1);
	}
	PNode PTail =PHead;								//�����β��㣬��ʼ��ʹ��ָ��ͷ���
	printf("�������������\n");
	scanf("%d",&len);								//���ս�����
	for(int i = 0; i < len;i++){
		PNode PNew = (PNode)malloc(sizeof(Node));
		if(PNew == NULL){
			printf("�½ڵ�����ڴ�ʧ��...\n");
			exit(-1);
		}
		printf("�������%d���������ݣ�\n",i+1);
		scanf("%d",&val);
		PNew->Element = val;
		PTail->Next = PNew;
		PNew->Next=NULL;
		PTail = PNew;
	}
	printf("�������ɹ���\n");
	return PHead;
}

//���������������
void TraverseList(PNode List){
	PNode p = List->Next;							//�׽�㸳ֵ����ʱ���
	printf("���������ֵΪ��\n");
	if(p==NULL)
		printf("     ����Ϊ��");
	while(p!=NULL){
		printf("%d ",p->Element);
		p=p->Next;
	}
	printf("\n");
}

//���������ѯ����
PNode FindList(PNode List){
	PNode p = List->Next;							//������ʱָ��pָ���׽��ĵ�ַ
	int num = 0;									//���ڼ�¼�������λ��
	int val = 0;									//���ڴ����Ҫ��ѯ��ֵ
	printf("������Ҫ��ѯ�����֣�\n");
	scanf("%d",&val);								//������Ҫ��ѯ����
	while(p!=NULL && p->Element!=val){
		p=p->Next;
		++num;
	}
	if(p!=NULL)
		printf("�ҵ��Ľ��Ϊ��%d\n",num+1);
	else
		printf("Ϊ�ҵ���ֵ��\n");
	return p;
}


//����������뺯��
void InsertList(PNode List,int pos,int val){
	int position = 0;
	PNode p = List;									//������pָ��ͷ���
	//Ѱ��pos����ǰ�����
	while(p!=NULL && position<pos-1){
		p=p->Next;
		++position;
	}
	PNode Tmp = (PNode)malloc(sizeof(Node));		//������ʱ������ڴ洢��Ҫ���������
	if(Tmp==NULL){
		printf("�ڴ����ʧ�ܣ��޷���������\n");
		exit(-1);
	}
	//������
	Tmp->Element = val;
	Tmp->Next = p->Next;
	p->Next = Tmp;
}

//����ɾ����������
void DeleteTheList(PNode List){
	PNode p,Tmp;
	p=List->Next;									//����pָ������ĵ�һ�����
	List->Next = NULL;
	while(p!=NULL){
		Tmp = p->Next;								//Tmpָ��Ҫɾ���Ľ�����һ�����
		free(p);									//�ͷ�ָ��p��ָ��Ľ��
		p=Tmp;										//���¸�ֵ
	}
	printf("����ɾ���ɹ�\n");
}

//����ɾ������Ԫ�غ���
//ɾ�������е�pos���
void DeleteList(PNode List,int pos){
	int position=0;
	PNode p = List;
	while(p!=NULL && position<pos-1){
		p = p->Next;
		++position;
	}
	//ɾ�����
	PNode Tmp = p->Next;
	p->Next = Tmp->Next;
	free(Tmp);
	Tmp=NULL;
}
