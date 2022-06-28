package main

import (
	_ "bufio"
	"fmt"
	_ "os"
	_ "strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	var data [100010]int
	data[0] = 0
	data[1] = 1

	for i := 0; i <= n; i++ {
		data[i] = i
	}

	for i := 1; i <= n; i++ {
		for j := 1; j*j <= i; j++ {
			data[i] = min(data[i], data[i-j*j]+1)
		}
	}
	fmt.Println(data[n])
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
