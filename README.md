# data structure

- 1-linear-list(线性表)
   - 1.1-static-allocation(线性表 -> 顺序表 -> 静态分配)
        <details>
        <summary>打开/折叠 实现了的方法</summary>
        
        ```cpp
        // 初始化顺序表
        void InitList(LinearList &list);
        
        // 在位序i(从1开始)插入元素elem
        bool ListInsert(LinearList &list, int i, DataType elem);
        
        // 在位序i(从1开始)删除元素elem
        bool ListDelete(LinearList &list, int i, DataType &elem);
        
        // 查找第i位元素，返回值(按位查找)
        DataType GetElem(LinearList list, int i);
        
        // 传入elem元素，查找顺序表里第一个值等于elem的元素，并返回位序
        int LocateElem(LinearList list, DataType elem);
        ```
        </details>
   - 1.2-dynamic-allocation(线性表 -> 顺序表 -> 动态分配)
   - 1.3-singly-linked-list(线性表 -> 链表 -> 单链表)
        <details>
        <summary>打开/折叠 实现了的方法</summary>
        
          ```cpp
         // 带头节点的 初始化
         bool InitList(LinkList &list);
         
         // 带头节点的 在位序i(从1开始)插入元素elem 
         bool ListInsert(LinkList &list, int i, ElemType elem);
         
         // 不带头节点的 初始化
         void InitListWithoutHeaderNode(LinkList &list);
         
         // 不带头节点的 在位序i(从1开始)插入元素elem
         bool ListInsertWithoutHeaderNode(LinkList &list, int i, ElemType elem);
         
         // 后插操作: 在previousNode之后插入元素elem
         bool InsertNextNode(LNode *previousNode, ElemType elem);
         
         // 前插操作: 在p之前插入元素elem
         bool InsertPriorNode(LNode *p, ElemType elem);
         
         // 删除指定位序的i(从1开始)的元素，并返回被删除的元素elem
         bool ListDelete(LinkList list, int i, ElemType &elem);
         
         // 删除单链表的当前节点node
         bool DeleteNode(LNode *node);
         
         // 按位查找: 找到第i位(从1开始)元素并返回
         LNode *GetElem(LinkList list, int i);
         
         // 按值查找: 找到第一个值为elem的节点
         LNode *LocateElem(LinkList list, ElemType elem);
         
         // 带头节点的 逆置单链表
         LinkList ReverseList(LinkList list);
         
         // 不带头结点的 逆置单链表
         LinkList ReverseListWithoutHeaderNode(LinkList list);
          ```
          
        </detail>
   - 1.4-double-linked-list(线性表 -> 链表 -> 双链表)
   - 1.5-circular-singly-linked-list(线性表 -> 链表 -> 循环单链表)
   - 1.6-circular-double-linked-list(线性表 -> 链表 -> 循环双链表)
   