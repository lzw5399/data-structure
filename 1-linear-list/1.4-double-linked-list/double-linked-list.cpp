/**
 * @Author: lzw5399
 * @Date: 2020/9/22 19:01
 * @Desc: 逻辑结构: 线性表
 * @Desc: 实现方式: 链式存储(链表)
 * @Desc: 物理结构: 双链表
 */

#include <iostream>

using namespace std;

#define ElemType int

// 双链表结构体
typedef struct DNode {
    ElemType Data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

void InitList(DLinklist &list) {
    list = (DNode *) malloc(sizeof(DNode));
    list->next = NULL;
    list->prior = NULL;
}

int main() {
    DLinklist list;

    // 初始化双链表
    InitList(list);

    return 0;
}

