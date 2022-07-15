package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var arr [10010]int

func main() {
	in := bufio.NewReader(os.Stdin)

	n := 0
	for {
		data, _ := in.ReadString('\n')
		data = strings.TrimSpace(data)
		if data == "" {
			break
		}
		arr[n], _ = strconv.Atoi(data)
		n++
	}

	searcher(0, n)

}

func searcher(start, end int) {
	if start >= end {
		return
	}

	var i int = start

	for ; i < end; i++ {
		if arr[start] < arr[i] {
			break
		}
	}

	searcher(start+1, i)
	searcher(i, end)

	fmt.Println(arr[start])
}
