#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int data;
	TreeNode * pLeft;
	TreeNode * pRight;
};


// ����Ĺ������Ƚڵ㣨��ͨ������ / ������������
// �����������ཻ
TreeNode * GetLeastFather(TreeNode * Root ,TreeNode * Node1, TreeNode * Node2) {
	stack<TreeNode*>T1, T2;
	GetNodePath(Root, Node1, T1);
	GetNodePath(Root, Node2, T2);
	while (!T1.empty() && !T2.empty()) {
		int Num = T1.size() > T1.size() ? T1.size() - T2.size() : T2.size() - T1.size();
		while (Num) {
			(T1.size() > T1.size() ? T1 : T2).pop();
			Num--;
		}

	}
}

// ���������
int Depth(TreeNode * Root) {
	if (Root == nullptr)
		return 0;
	int Left = Depth(Root->pLeft);
	int Right = Depth(Root->pRight);
	return Left > Right ? Left + 1 : Right + 1;
}
// �������ڵ����

// ��ȡ�ڵ�·��
bool GetNodePath(TreeNode * Root, TreeNode * Node, stack<TreeNode*>&Path) {
	if (Root == nullptr || Node == nullptr)
		return false;
	Path.push(Root);
	if (Root != Node) {
		if (GetNodePath(Root->pLeft, Node, Path))
			return true;
		if (GetNodePath(Root->pRight, Node, Path))
			return true;
		Path.pop();
		return false;
	}
	else
		return true; 
}


