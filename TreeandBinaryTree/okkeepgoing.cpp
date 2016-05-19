#include<iostream>
using namespace std;

struct BiTNode 
{
	char data;
	struct BiTNode *lchild, *rchild;
};
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
			cout << "请继续输入" << endl;
			CreateBiTree(BiTree->lchild);
			cout << "请继续输入" << endl;
			CreateBiTree(BiTree->rchild);
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
	BiTNode *BiTree = new BiTNode;
	cout << "请输入字符" << "（可直接复制粘贴：A B C # # D E # G # # F # # #）" << endl;
	CreateBiTree(BiTree);
	cout << "二叉树的节点个数为" << NodeCount(BiTree) << endl;
	cout << "二叉树的深度为" << Depth(BiTree) << endl;
	cout << "中序遍历为：";
	InOrderTraversal(BiTree);
	cout << endl;
	cout << "后序遍历为：";
	PostOrderTraversal(BiTree);
	cout << endl;
	system("pause");
}