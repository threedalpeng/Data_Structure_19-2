#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _threadedTree* threadedPointer;
typedef struct _threadedTree
{
    bool leftThread;
    threadedPointer leftChild;
    char data;
    threadedPointer rightChild;
    bool rightThread;
} threadedTree;

void treeInorder(threadedPointer tree)
/* traverse the threaded binary tree inorder */
{
    threadedPointer tmp = tree;
    for (;;)
    {
        tmp = inorderSuccessor(tmp);
        if (tmp == tree) break;
        printf("%3c", tmp->data);
    }
}

threadedPointer inorderSuccessor(threadedPointer tree)
{
    threadedPointer tmp;
    tmp = tree->rightChild;
    if (!tree->rightThread)
    {
        while(!tmp->leftThread)
            tmp = tmp->leftChild;
    }
    return tmp;
}

void insertRight(threadedPointer s, threadedPointer r)
/* insert r as the right child of s */
{
    threadedPointer tmp;
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;
    r->leftChild = s;
    r->leftThread = true;
    s->rightChild = r;
    s->rightThread = false;
    if (!r->rightThread)
    {
        tmp = inorderSuccessor(r);
        tmp->leftChild = r;
    }
}

int main(void)
{
    
}