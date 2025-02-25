#include<stdio.h>
#include <stdlib.h> 

// �������������ڵ�ṹ�� 
typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode;

// �������ɶ������ڵ㺯��
BiTreeNode *creatTree(int data) {
    BiTreeNode *newNode = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// ������ʾ����
void showTree(BiTreeNode *tree1) {
    if (tree1) {
        printf("����Ϊ��%d ", tree1->data);
        showTree(tree1->lchild);
        showTree(tree1->rchild);
    }
}

// ���콻�����Ӻ��� 
void exchangeChild(BiTreeNode *tree1) { 
    if (tree1!= NULL) {
        BiTreeNode *temp = tree1->lchild;
        tree1->lchild = tree1->rchild;
        tree1->rchild = temp;
        exchangeChild(tree1->rchild);
        exchangeChild(tree1->lchild);
    }
}

// �����㷨�Ŀ�����
int main() {
    BiTreeNode *tree1 = creatTree(1);
    tree1->lchild = creatTree(2);
    tree1->rchild = creatTree(5);

    exchangeChild(tree1);
    showTree(tree1);
    return 0;
}
