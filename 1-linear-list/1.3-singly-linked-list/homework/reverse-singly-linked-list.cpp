/**
 * @Author: lzw5399
 * @Date: 2020/9/20 17:31
 * @Desc: 作业: 逆置单链表
 */

#include <iostream>

using namespace std;

#define ElemType int

// 定义了单链表的节点类型
typedef struct LNode {
    ElemType data; // 当前节点存放的数据
    struct LNode *next; // 指向下一个节点的指针
} LNode, *LinkList; // 这里声明两个别名,LNode* = LinkList。之后使用过程中LinkList强调这是一个单链表，LNode*强调这是一个节点

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

// 带头节点的逆置
LinkList ReverseList(LinkList list) {
    if (list == NULL)
        return NULL;

    // 初始化一个新的单链表
    LinkList newList = (LNode *) malloc(sizeof(LNode));
    newList->next = NULL;

    LNode *node = list->next;

    while (node != NULL) {
        LNode *temp = node->next; // node原来的next存起来
        node->next = newList->next; // newList的下一个赋值给当前node的下一个
        newList->next = node; // 然后把node赋值给newList的下一个

        node = temp; // 继续遍历
    }

    return newList;
}

// 不带头结点的逆置
LinkList ReverseListWithoutHeaderNode(LinkList list) {
    if (list == NULL || list->next == NULL)
        return NULL;

    LinkList newList;

    LNode *currentNode = list->next; // 这里跳过list的头节点
    int index = 0;
    while (currentNode != NULL) {
        LNode *tempNext = currentNode->next;
        if (index == 0) {
            newList = currentNode;
            newList->next = NULL;
        } else {
            currentNode->next = newList;
            newList = currentNode;
        }

        currentNode = tempNext;
        index++;
    }

    return newList;
}

int main() {
    // 1. 准备一个原始的单链表
    LinkList originList;
    InitList(originList);
    for (int i = 1; i <= 10; i++) {
        ListInsert(originList, i, i);
    }

    // 2. 采用头插法 逆置带头节点的单链表
    LinkList newList = ReverseList(originList);

    // 3. 头插法 逆置出不带头节点的单链表
    LinkList newListWithoutHeaderNode = ReverseListWithoutHeaderNode(newList);

    return 0;
}

