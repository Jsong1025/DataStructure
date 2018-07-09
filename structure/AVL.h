#include <stdio.h>
#include <malloc.h>

##define EH 0;
##define LH 1;
##define RH -1;

typedef struct BitNode
{
    int data;
    int bf;
    struct BitNode *lchild;
    struct BitNode *rchild;
} BitNode, *BitTree;

// 右旋操作
void R_Rotate(BitTree &T)
{
    BitTree p;
    p = T->lchild;
    T->lchild = p->rchild;
    p->rchild = T;
    T = p;
}

// 左旋操作
void L_Rotate(BitTree &T)
{
    BitTree p;
    p = T->rchild;
    T->rchild = p->lchild;
    p->lchild = T;
    T = p;
}

void RightBalance(BitTree &T)
{
    BitTree R;
    BitTree rl;
    R = T->rchild;
    switch(R->bf)
    {
        case RH:
            T->bf = R->bf = EH;
            L_Rotate(T);
            break;

        case EH:
            T->bf = RH;
            R->bf = LH;
            L_Rotate();
            break;

        case LH:
        // TODO
    }
}