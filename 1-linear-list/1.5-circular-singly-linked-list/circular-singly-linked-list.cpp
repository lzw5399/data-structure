/**
 * @Author: lzw5399
 * @Date: 2020/9/22 22:12
 * @Desc: 逻辑结构: 线性表
 * @Desc: 实现方式: 链式存储(链表)
 * @Desc: 物理结构: 循环单链表
 */

#include <iostream>

using namespace std;

#define ElemType int

// 单链表结构体
typedef struct LNode {
    ElemType Data;
    struct LNode *next;
} LNode, *Linklist;

// 初始化循环单链表
bool InitList(Linklist &list) {
    list = (LNode *) malloc(sizeof(LNode));
    if (list == NULL)
        return false;

    // 循环单链表就是最后一个节点的指针指向头节点
    list->next = list;

    return true;
}

// 判断是否为空，直接判断头节点的指针指向的是不是自己
bool Empty(Linklist list) {
    return list->next == list ? true : false;
}

int main() {
    Linklist list;

    // 初始化循环单链表
    InitList(list);

    return 0;
}

