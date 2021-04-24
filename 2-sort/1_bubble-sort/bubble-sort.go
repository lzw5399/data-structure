/**
 * @Author: lzw5399
 * @Date: 2021/4/24 14:15
 * @Desc: 冒泡排序
 */
package main

import "fmt"

func main() {
	s := []int{5, 8, 6, 3, 9, 2, 1, 7}

	// 冒泡排序
	bubbleSort(s)

	fmt.Println(s)
}

// 冒泡排序，使用双循环
func bubbleSort(s []int) {
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(s); j++ {
			if s[i] < s[j] {
				tmp := s[i]
				s[i] = s[j]
				s[j] = tmp
			}
		}
	}
}
