package main

import (
	"fmt"
)

var N int

func main() {
	fmt.Scan(&N)

	var arr []int = make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}
	var B [1000010]bool
	ans := 1

	for i := 0; i < 1000010; i++ {
		B[i] = false
	}

	for i := 0; i < N; i++ {
		if B[arr[i]] == false {
			mx := 1
			cnt := 1

			newArr := popNumberFromArray(arr, arr[i])

			for j := 1; j < len(newArr); j++ {
				if newArr[j] == newArr[j-1] {
					cnt += 1
				} else {
					mx = max(cnt, mx)
					cnt = 1
				}
			}
			mx = max(cnt, mx)

			B[arr[i]] = true
			ans = max(ans, mx)
		}
	}

	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func popNumberFromArray(arr []int, num int) []int {
	var newArr []int
	for i := 0; i < len(arr); i++ {
		if arr[i] != num {
			newArr = append(newArr, arr[i])
		}
	}

	return newArr
}
