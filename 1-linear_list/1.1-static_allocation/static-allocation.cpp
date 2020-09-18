/**
 * @Author: lzw5399
 * @Date: 2020/9/18 22:50
 * @Desc: 数据结构(逻辑结构): 线性表
 * @Desc: 具体实现方式: 顺序表
 * @Desc: 顺序表的具体[物理结构]实现: 静态分配
 */
#define MAXSIZE 10

// 定义顺序表静态分配的结构体
typedef struct {
    int Data[MAXSIZE];
    int Length;
} LinearList;

// 初始化
void InitList(LinearList &list) {
    for (int i = 0; i < MAXSIZE; i++) {
        list.Data[i] = 0;
    }
    list.Length = 0;
}

// index这里是位序(第几位元素，从1开始)
bool ListInsert(LinearList &list, int index, int elem) {
    // 0. 预检查输入合法性
    if (list.Length >= MAXSIZE) // 存储空间已满，不能插入
        return false;
    if (index < 1 || index > list.Length + 1) // 判断index范围是否有效
        return false;

    // 1. 把index往后的元素分别往后移
    for (int i = list.Length; i >= index; i--) {
        list.Data[i] = list.Data[i - 1];
    }
    // 2. 把第index个元素赋值给elem
    list.Data[index - 1] = elem;
    list.Length += 1;

    return true;
}

int main() {
    LinearList list;
    InitList(list);

    // 填充一些数据
    list.Data[0] = 22;
    list.Data[1] = 33;
    list.Data[2] = 44;
    list.Data[3] = 55;
    list.Data[4] = 66;
    list.Length = 5;

    // 调用插入
    ListInsert(list, 3, 66666);

    ListInsert(list, 7, 555);
    return 0;
}
