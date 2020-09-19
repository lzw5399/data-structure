/**
 * @Author: lzw5399
 * @Date: 2020/9/19 12:49
 * @Desc: 逻辑结构: 线性表
 * @Desc: 实现方式: 链式存储(链表)
 * @Desc: 物理结构: 单链表
 */

#include <iostream>

using namespace std;

#define DataType int

// 定义了单链表的节点类型
typedef struct LNode {
    DataType data; // 当前节点存放的数据
    struct LNode *next; // 指向下一个节点的指针
} LNode, *LinkList; // 这里声明两个别名,LNode* = LinkList。之后使用过程中LinkList强调这是一个单链表，LNode*强调这是一个节点

void InitList(LinkList &L) {
    L = NULL;
}

int main() {
    // 声明一个指向单链表的指针
    LinkList L;

    InitList(L);

    cout << ":::" << L->data << endl;
    return 0;
}