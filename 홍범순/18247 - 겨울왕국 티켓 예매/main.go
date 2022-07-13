package main

import (
	"fmt"
)

func main() {
	var T int
	fmt.Scan(&T)

	for ; T > 0; T-- {
		var N, M int
		fmt.Scan(&N, &M)

		//L : 12

		if N < 12 || M < 4 {
			fmt.Print("-1\n")
		} else {
			fmt.Printf("%d\n", 11*M+4)
		}
	}
}
