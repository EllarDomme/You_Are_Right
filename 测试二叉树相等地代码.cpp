#include<stdio.h>
#include <stdlib.h> 

// 构造二叉树链表节点结构体 
typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode;

// 构造生成二叉树节点函数
BiTreeNode *creatTree(int data) {
    BiTreeNode *newNode = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// 构造显示函数
void showTree(BiTreeNode *tree1) {
    if (tree1) {
        printf("数据为：%d ", tree1->data);
        showTree(tree1->lchild);
        showTree(tree1->rchild);
    }
}

// 构造交换孩子函数 
void exchangeChild(BiTreeNode *tree1) { 
    if (tree1!= NULL) {
        BiTreeNode *temp = tree1->lchild;
        tree1->lchild = tree1->rchild;
        tree1->rchild = temp;
        exchangeChild(tree1->rchild);
        exchangeChild(tree1->lchild);
    }
}

// 测试算法的可行性
int main() {
    BiTreeNode *tree1 = creatTree(1);
    tree1->lchild = creatTree(2);
    tree1->rchild = creatTree(5);

    exchangeChild(tree1);
    showTree(tree1);
    return 0;
}
