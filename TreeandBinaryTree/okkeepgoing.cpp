#include<iostream>
using namespace std;

struct BiTNode 
{
	char data;
	struct BiTNode *lchild, *rchild;
};
void CreateBiTree(BiTNode *&BiTree, char ch)
{
	while (ch != '@')
	{
		if (ch == '#')
			BiTree = NULL;
		else
		{
			
			BiTree->data = ch;
			CreateBiTree(BiTree->lchild, ch);
			CreateBiTree(BiTree->rchild, ch);
		}
		cout << "请继续输入" << endl;
		cin >> ch;
	}
}

int NodeCount(BiTNode *BiTree)
{
	if (BiTree == NULL)
		return 0;
	else
		return NodeCount(BiTree->lchild) + NodeCount(BiTree->rchild) + 1;
}

int Depth(BiTNode *BiTree)
{
	if (BiTree == NULL)
		return 0;
	else
	{
		int m = Depth(BiTree->lchild);
		int n = Depth(BiTree->rchild);
		if (m > n)
			return (m + 1);
		else
			return (n + 1);
	}
}

void InOrderTraversal(BiTNode *BiTree)
{
	if (BiTree)
	{
		InOrderTraversal(BiTree->lchild);
		cout << BiTree->data;
		InOrderTraversal(BiTree->rchild);
	}
}

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
	BiTNode *BiTree = NULL;
	char ch;
	cin >> ch;
	CreateBiTree(BiTree, ch);
	cout << "二叉树的节点个数为" << NodeCount(BiTree) << endl;
	cout << "二叉树的深度为" << Depth << endl;
	InOrderTraversal(BiTree);
	PostOrderTraversal(BiTree);

	system("pause");
}