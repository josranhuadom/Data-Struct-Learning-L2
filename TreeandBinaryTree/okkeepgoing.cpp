#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
struct BiTNode 
{
	char data;
	struct BiTNode *lchild, *rchild;
};

//����������
void CreateBiTree(BiTNode *&BiTree)
{
	char ch;
	cin >> ch;
		if (ch == '#')
		{
			BiTree = NULL;
			return;
		}
		else
		{
			BiTree = new BiTNode;
			BiTree->data = ch;
			cout << "���������" << endl;
			CreateBiTree(BiTree->lchild);
			cout << "���������" << endl;
			CreateBiTree(BiTree->rchild);
		}
}

//���������
int NodeCount(BiTNode *BiTree)
{
	if (BiTree == NULL)
		return 0;
	else
		return NodeCount(BiTree->lchild) + NodeCount(BiTree->rchild) + 1;
}

//������������
int Depth(BiTNode *BiTree)
{
	if (BiTree == NULL)                                  //���Ϊ���������Ϊ 0���ݹ����
		return 0;
	else
	{
		int m = Depth(BiTree->lchild);          //�ݹ��������������ȼ�Ϊ m
		int n = Depth(BiTree->rchild);           //�ݹ��������������ȼ�Ϊ n
		if (m > n)
			return (m + 1);
		else
			return (n + 1);
	}
}

//�������
void InOrderTraversal(BiTNode *BiTree)
{
	if (BiTree)
	{
		InOrderTraversal(BiTree->lchild);
		cout << BiTree->data;
		InOrderTraversal(BiTree->rchild);
	}
}

//�������
void PostOrderTraversal(BiTNode *BiTree)
{
	if (BiTree)
	{
		PostOrderTraversal(BiTree->lchild);
		PostOrderTraversal(BiTree->rchild);
		cout << BiTree->data;
	}
}

int main()
{
	BiTNode *BiTree = new BiTNode;
	cout << "�������ַ�" << "����ֱ�Ӹ���ճ����A B C # # D E # G # # F # # #��" << endl;
	CreateBiTree(BiTree);
	cout << "�������Ľڵ����Ϊ" << NodeCount(BiTree) << endl;
	cout << "�����������Ϊ" << Depth(BiTree) << endl;
	cout << "�������Ϊ��";
	InOrderTraversal(BiTree);
	cout << endl;
	cout << "�������Ϊ��";
	PostOrderTraversal(BiTree);
	cout << endl;
	system("pause");
}