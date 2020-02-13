#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _Node* NodePtr;
typedef struct _Node
{
    NodePtr left;
    element data;
    NodePtr right;
} Node;
typedef struct _BinaryTree
{
    Node root;
} BinaryTree;

NodePtr createNode();
int isEmpty(BinaryTree);
BinaryTree makeBinaryTree(NodePtr, element, NodePtr);
element getData(NodePtr);
NodePtr getLeftChild(BinaryTree);
BinaryTree getRightChild(BinaryTree);

int main()
{

}

NodePtr createNode()
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int isEmpty(BinaryTree bt)
{
    if (!(bt->left || bt->right)) return 1;
    else return 0;
}
BinaryTree makeBinaryTree(BinaryTree, element, BinaryTree);
element getData(BinaryTree);
BinaryTree getLeftChild(BinaryTree);
BinaryTree getRightChild(BinaryTree);