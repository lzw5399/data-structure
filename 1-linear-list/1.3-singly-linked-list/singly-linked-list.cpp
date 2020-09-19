/**
 * @Author: lzw5399
 * @Date: 2020/9/19 12:49
 * @Desc: 逻辑结构: 线性表
 * @Desc: 实现方式: 链式存储(链表)
 * @Desc: 物理结构: 单链表
 */

#include <iostream>

using namespace std;

#define ElemType int

// 定义了单链表的节点类型
typedef struct LNode {
    ElemType data; // 当前节点存放的数据
    struct LNode *next; // 指向下一个节点的指针
} LNode, *LinkList; // 这里声明两个别名,LNode* = LinkList。之后使用过程中LinkList强调这是一个单链表，LNode*强调这是一个节点

// 不带头节点的初始化方式
void InitListWithoutHeaderNode(LinkList &list) {
    list = NULL;
}

// 带头节点的初始化方式
bool InitList(LinkList &list) {
    list = (LNode *) malloc(sizeof(LNode));

    if (list == NULL) return false;

    list->next = NULL;
    return true;
}

// i这里是位序(第几位元素，从1开始)
// 【带头节点】的插入实现方式
// 平均时间复杂度: O(n)
bool ListInsert(LinkList &list, int i, ElemType elem) {
    // 1. 参数预检查
    if (i < 1)
        return false;

    // 2. 循环得到第i-1个元素
    LNode *previousNode;
    previousNode = list;
    int j = 0;

    while (previousNode != NULL && j < i - 1) {
        previousNode = previousNode->next;
        j++;
    }

    if (previousNode == NULL) // 防止i不合法，大于链表本身的长度
        return false;

    // 3. malloc为新节点申请内存空间,
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = previousNode->next;
    previousNode->next = newNode;

    return true;
}

// i这里是位序(第几位元素，从1开始)
// 【不带头节点】的插入实现方式
// 平均时间复杂度: O(n)
bool ListInsertWithoutHeaderNode(LinkList &list, int i, ElemType elem) {
    // 1. 参数预检查
    if (i < 1)
        return false;

    // 由于不带头节点，针对位序i=1的需要特殊处理
    if (i == 1) {
        LNode *headerNode = (LNode *) malloc(sizeof(LNode));
        headerNode->data = elem;
        headerNode->next = NULL;
        list = headerNode;

        return true;
    }

    // 2. 循环得到第i-1个元素
    LNode *previousNode;
    previousNode = list;
    int j = 0;

    while (previousNode != NULL && j < i - 1) {
        previousNode = previousNode->next;
        j++;
    }

    if (previousNode == NULL) // 防止i不合法，大于链表本身的长度
        return false;

    // 3. malloc为新节点申请内存空间,
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = previousNode->next;
    previousNode->next = newNode;

    return true;
}

// 后插操作: 在previousNode之后插入元素elem
// 时间复杂度: O(1)
bool InsertNextNode(LNode *previousNode, ElemType elem) {
    if (previousNode == NULL)
        return false;

    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = elem;
    newNode->next = NULL;
    previousNode->next = newNode;

    return true;
}

// 前插操作: 在p之前插入元素elem
// 由于单链表只能往后遍历，所有操作是 【...->p->p+1】变成了 【...->p->newNode->p+1】但是之后的p存的是elem即新值，newNode节点存的是原先的p里面的值
// 时间复杂度: O(1)
bool InsertPriorNode(LNode *p, ElemType elem) {
    if (p == NULL)
        return false;

    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->next = p->next;
    newNode->data = p->data;
    p->data = elem;
    p->next = newNode;

    return true;
}

int main() {
    // 声明一个指向单链表的指针
    LinkList list;

    InitList(list);

    ListInsert(list, 1, 233);
    ListInsert(list, 2, 555);
    ListInsert(list, 2, 666);
    ListInsert(list, 2, 777);
    ListInsert(list, 9, 999);

    return 0;
}