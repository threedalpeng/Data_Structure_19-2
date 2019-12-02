#include <stdio.h>
#include <stdlib.h>

int max_count;

typedef struct _Node
{
	struct _Node* left;
	int data;
	struct _Node* right;
} TreeNode;

int IsEnd(TreeNode* t)
{
	if (!t->left && !t->right)
		return 1;
	else
		return 0;
}

TreeNode* MakeTree(int data)
{
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}

void InsertTree(TreeNode* rt, TreeNode* ch)
{
	TreeNode* tmp;
	int count = 0;
	while (1)
	{
		if (rt->data > ch->data) tmp = rt->left;
		else tmp = rt->right;
		
		if (tmp) rt = tmp, ++count;
		else 
		{
			tmp = ch;
			break;
		}
	}
	if (count > max_count) max_count = count;
}


int main() 
{
	int N, i, data;
	TreeNode* root = NULL;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &data);
		if (!root) 
		{
			root = MakeTree(data);
			continue;
		}
		InsertTree(root, MakeTree(data));
	}
	printf("%d", max_count);
}
