/**
 * @Author: lzw5399
 * @Date: 2020/9/22 22:24
 * @Desc: 逻辑结构: 线性表
 * @Desc: 实现方式: 链式存储(链表)
 * @Desc: 物理结构: 循环双链表
 */

#include <iostream>

using namespace std;

#define ElemType int

// 双链表结构体
typedef struct DNode {
    ElemType Data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

// 初始化循环双链表
void InitList(DLinklist &list) {
    list = (DNode *) malloc(sizeof(DNode));

    // 循环双链表初始化时：头节点的"前指针"和"后指针"都指向"头节点本身"
    list->next = list;
    list->prior = list;
}

// 判断是否为空，直接判断头节点的指针指向的是不是自己
bool Empty(DLinklist list) {
    return list->next == list ? true : false;
}

int main() {
    DLinklist list;

    // 初始化双链表
    InitList(list);

    return 0;
}



