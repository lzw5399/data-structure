# data structure

- 1-linear-list(线性表)
   - 1.1-static-allocation(线性表 -> 顺序表 -> 静态分配)
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
   - 1.2-dynamic-allocation(线性表 -> 顺序表 -> 动态分配)
   - 1.3-singly-linked-list(线性表 -> 链表 -> 单链表)
      ```cpp
     // 带头节点的 初始化
     bool InitList(LinkList &list);
     
     // 带头节点的 在位序i(从1开始)插入元素elem 
     bool ListInsert(LinkList &list, int i, ElemType elem);
     
     // 不带头节点的 初始化
     void InitListWithoutHeaderNode(LinkList &list);
     
     // 不带头节点的 在位序i(从1开始)插入元素elem
     bool ListInsertWithoutHeaderNode(LinkList &list, int i, ElemType elem);
      ```
   