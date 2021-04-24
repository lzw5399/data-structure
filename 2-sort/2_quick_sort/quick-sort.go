/**
 * @Author: lzw5399
 * @Date: 2021/4/24 15:15
 * @Desc:
 */
package main

import "fmt"

func main() {
	arr := []int{4, 4, 6, 5, 3, 2, 8, 1}
	quickSort(arr, 0, len(arr)-1)
	fmt.Println(arr)
}

// 快速排序
func quickSort(arr []int, startIndex, endIndex int) {
	if startIndex >= endIndex {
		return
	}

	pivotIndex := partition(arr, startIndex, endIndex)

	quickSort(arr, startIndex, pivotIndex-1)
	quickSort(arr, pivotIndex+1, endIndex)
}

// 获取基准元素，并相应的元素根据基准元素分治
func partition(arr []int, startIndex, endIndex int) int {
	// 基准元素
	pivot := arr[startIndex]
	// 标记小于基准元素的区域边界
	mark := startIndex

	for i := startIndex; i <= endIndex; i++ {
		// 小于基准元素要做两件事
		// 1. 将mark右移一位(因为小于基准元素的边界增大了)
		// 2. 将【mark当前所在的元素】和【当前遍历所在的元素】值互换
		if arr[i] < pivot {
			mark++
			temp := arr[mark]
			arr[mark] = arr[i]
			arr[i] = temp
		}
	}

	// 将pivot元素和【mark所指向的元素】互换
	arr[startIndex] = arr[mark]
	arr[mark] = pivot

	// 返回基准元素的索引
	return mark
}
