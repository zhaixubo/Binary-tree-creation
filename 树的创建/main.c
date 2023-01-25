#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;
 
//中序后序建立二叉树
BiTNode *Creat(int lenth, char *mid, char *later) {
    if (lenth == 0)//长度为0，返回错误
    {
        return NULL;
    }
    //创建根节点
    BiTNode *P;
    P = (BiTree)malloc(sizeof(struct BiTNode));
    //由后续遍历二叉树得，后序的第一个元素即为根节点
    P->data = later[lenth - 1];
    int i;
    for (i = 0; i < lenth; i++)
    if (later[lenth - 1] == mid[i])
        break;
    //for循环找出中序的根节点在数组中的位置
    //构造左子树
    P->lchild = Creat(i, mid, later);//通过递归找左子树的根节点，结束后i的值为左子树中节点的个数
    //构造右子树
    P->rchild = Creat(lenth - i - 1, mid + i + 1, later + i);//通过递归找右子树的根节点
    //zhong+i为根节点的地址值
    return P;
}
 
//访问根节点
void visite(char ch) {
    printf("%c", ch);
}
 
//非递归先序遍历
void NRPreOrder(BiTree T) {
    BiTree stack[100], p;
    int top;
    if (T == NULL) {
        return;
    }
    top = 0;
    p = T;
    while (!(p == NULL && top == 0))
    {
        while (p != NULL)
        {
            visite(p->data);
            if (top<100 - 1)
            {
                stack[top] = p;
                top++;
            }
            else
            {
                printf("栈溢出");
                return;
            }
            p = p->lchild;
        }
        if (top <= 0)return;
        else
        {
            top--;
            p = stack[top];
            p = p->rchild;
        }
    }
}
 
int main()
{
    char mid[100], later[100];
    int len;
    printf("中序二叉树：\n");
    scanf("%s", mid);
    printf("\n");
    printf("后序二叉树：\n");
    scanf("%s", later);
    BiTNode *M = NULL;
    len = strlen(mid);
    M = Creat(len, mid, later);
    printf("先序遍历：\n");
    NRPreOrder(M);
    return 0;
}
