/**
 * @Author: lzw5399
 * @Date: 2020/9/13 15:14
 * @Desc: 数据结构: 线性表
 * @Desc: 对应的物理结构的实现: 顺序表
 * @Desc: 顺序表的具体实现: 动态分配
 */
package main

import "fmt"

type LinearList struct {
	Data    []int // 实际数据存储，是一个切片
	MaxSize int   // 顺序表的最大容量
	Length  int   // 顺序表的当前长度
}

const InitSize = 10

// 初始化顺序表
func InitList(list *LinearList) {
	list.Data = make([]int, InitSize)
	list.Length = 0
	list.MaxSize = InitSize
}

// 增加动态数组的长度 increaseLen是增量
func IncreaseSize(list *LinearList, increaseLen int) {
	// 申请新的空间
	temp := make([]int, list.MaxSize+increaseLen)
	// 将数据复制到新区域 (ps: 时间消耗大)
	for i := 0; i < len(list.Data); i++ {
		temp[i] = list.Data[i]
	}
	list.Data = temp
	list.MaxSize += increaseLen
}

func main() {
	var list LinearList
	InitList(&list)

	fmt.Println("initial max size: ", list.MaxSize)

	IncreaseSize(&list, 5)

	fmt.Println("new max size: ", list.MaxSize)
}
