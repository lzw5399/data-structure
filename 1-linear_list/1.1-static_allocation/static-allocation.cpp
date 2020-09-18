/**
 * @Author: lzw5399
 * @Date: 2020/9/18 22:50
 * @Desc: 数据结构(逻辑结构): 线性表
 * @Desc: 具体实现方式: 顺序表
 * @Desc: 顺序表的具体[物理结构]实现: 静态分配
 */

#include <iostream>

using namespace std;

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

// i这里是位序(第几位元素，从1开始)
// 方法时间复杂度解析：
// 最好的是当i = list.Length + 1，正好在最后一位空的，为O(1)
// 最坏的是当i = 1，在表头，剩余的所有元素都要后移一位，为O(n)
// 平均复杂度为O(n)
bool ListInsert(LinearList &list, int i, int elem) {
    // 0. 预检查输入合法性
    if (list.Length >= MAXSIZE) // 存储空间已满，不能插入
        return false;
    if (i < 1 || i > list.Length + 1) // 判断index范围是否有效
        return false;

    // 1. 把index往后的元素分别往后移
    for (int j = list.Length; j >= i; j--) {
        list.Data[j] = list.Data[j - 1];
    }
    // 2. 把第index个元素赋值给elem
    list.Data[i - 1] = elem;
    list.Length += 1;

    return true;
}

// i这里是位序(第几位元素，从1开始)
// 方法最终会返回删除掉的元素的值，即&elem
// 算法时间复杂度解析：
// 最好的是当i = list.Length，正好删除最后一位元素，为O(1)
// 最坏的是当i = 1，删除表头元素，剩余所有元素都要前移一位，为O(n)
// 平均复杂度为O(n)
bool ListDelete(LinearList &list, int i, int &elem) {
    // 0. 输入参数预检
    if (i < 1 || i > list.Length)
        return false;

    // 1. 将即将被删除的数据赋值给elem
    elem = list.Data[i - 1];

    // 2. 将i后面的元素往前移一位，并将之前的最后一位置为0
    for (int j = i; j <= list.Length; j++) {
        if (j != list.Length)
            list.Data[j - 1] = list.Data[j];
        else
            list.Data[j - 1] = 0;
    }

    // 3. 长度减一
    list.Length -= 1;

    return true;
}

// i这里是位序(第几位元素，从1开始)
// 按位查找
// 时间复杂度: O(1)
int GetElem(LinearList list, int i) {
    return list.Data[i - 1];
}

// 传入elem元素，查找顺序表里第一个值等于elem的元素，并返回位序
// 按值查找
// 算法时间复杂度解析：
// 最好的是目标在表头，为O(1)
// 最坏的是目标在表尾，为O(n)
// 平均复杂度为O(n)
int LocateElem(LinearList list, int elem) {
    for (int i = 0; i < list.Length; i++) {
        if (list.Data[i] == elem)
            return i + 1;
    }

    return 0;
}

int main() {
    LinearList list;
    InitList(list);

    // 模拟填充一些数据
    list.Data[0] = 22;
    list.Data[1] = 33;
    list.Data[2] = 44;
    list.Data[3] = 55;
    list.Data[4] = 66;
    list.Length = 5;

    // 调用插入
    if (ListInsert(list, 3, 66666)) {
        cout << "插入成功" << endl;
    } else {
        cout << "输入不合法，插入失败" << endl;
    }

    // 调用删除
    int refBack;
    if (ListDelete(list, 2, refBack)) {
        cout << "删除成功，被删除掉的元素的值为：" << refBack << endl;
    } else {
        cout << "位序i非法，删除失败" << endl;
    }

    // 按位查找
    int elem = GetElem(list, 4);
    cout << "顺序表第四位元素: " << elem << endl;

    // 按值查找
    int i = LocateElem(list, 66);
    if (i != 0) {
        cout << "66在顺序表中的位序为: " << i << endl;
    } else {
        cout << "顺序表中查不到值为66的元素" << endl;
    }

    return 0;
}
