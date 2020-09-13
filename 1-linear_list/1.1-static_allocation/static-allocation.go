/**
 * @Author: lzw5399
 * @Date: 2020/9/13 15:14
 * @Desc: 数据结构: 线性表
 * @Desc: 对应的物理结构的实现: 顺序表
 * @Desc: 顺序表的具体实现: 静态分配
 */
package main

import "fmt"

func main() {
	var list LinearList // 定义一个顺序表
	InitList(&list)     // 对顺序表进行初始化

	fmt.Println(list)
}

const (
	MaxSize = 10
)

// 定义一个顺序表的结构
type LinearList struct {
	Data   [MaxSize]rune // 实际数据存储
	Length rune          // 当前长度
}

// 初始化顺序表
func InitList(list *LinearList) {
	for i := 0; i < MaxSize; i++ {
		list.Data[i] = 0
	}
	list.Length = 0
}
