#include <stdio.h>
#include <malloc.h>

typedef struct BitNode
{
    int data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode, *BitTree;

// 查找二叉排序树
/**
    描述：遍历此树，与每个节点比较大小，如果发现相同，返回当前节点，
         如果比节点数值小，查找左子树，如果大查找右子树
**/
bool SearchBST(BitTree T, int key, BitTree pre, BitTree &n)
{
    if(!T)
    {
        n = pre;    // 如果此树为空，则把前一个元素的指针pre负责给n
        return false;
    }
    else if(key == T->data)
    {
        n = T;
        return true;
    }
    if(key < T->data)
    {
        SearchBST(T->lchild, key, T, n);
    }
    else
    {
        SearchBST(T->rchild, key, T, n);
    }
}

/**
    描述：先搜索所增加的key，在不在此树里
         如果没有找到，则申请空间，把key加入里面，返回true，否则返回false
**/
bool InsertBST(BitTree &T, int k)
{
    BitNode *p;
    if(SearchBST(T,k, NULL, p))
    {
       return false;
    }

    BitNode *temp = new BitNode;
    temp->data = k;
    if(!p) // 只有树为空时，此次p才为NULL
    {
        T = temp;
    }
    else
    {
        if(k < p->data) // 如果不为空则与要加入的key值比较，小于就是左孩子，大于就是右孩子
        {
            p->lchild = temp;
        }
        else
        {
            p->rchild = temp;
        }
    }
    return true;
}

bool DeleteElement(BitTree T, int key)
{
    if(!T)
    {
        return false; // 空树，返回假
    }
    if(T->data == key)
    {
        BitNode *s, *p;
        if(T->rchild == NULL) // 只有右子树
        {
            s = T;
            T = T->lchild;
            free(s);
        }
        else if(T->lchild == NULL) // 只有左子树
        {
            s = T;
            T = T->rchild;
            free(s);
        }
        else  // 左右子树都有
        {
            p = T;
            s = T->rchild;
            while(s->lchild) //找到要删除的节点，就是他的右子树的最左子节点
            {
                p = s;
                s = s->lchild;
            }
            T->data = s->data;
            if(p != T) // 判断所删除的节点是前面节点的右子树还是左子树，只有最初的情况为右节点
            {
                p->lchild = NULL;
            }
            else
            {
                p->rchild = NULL;
            }
            free(s);
        }
        return true;
    }
    else if(key < T->data)
    {
        DeleteElement(T->lchild, key);
    }
    else
    {
        DeleteElement(T->rchild, key);
    }
}

// 中序遍历输出
void InorderReverse(BitTree T)
{
    if(T)
    {
        InorderReverse(T->lchild);
        printf("%d\t",T->data);
        InorderReverse(T->rchild);
    }
}