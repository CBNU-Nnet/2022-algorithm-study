package main

import (
	"fmt"
)

func main() {
	var A, B string
	fmt.Scanf("%s %s", &A, &B)

	count := 0

	for i := 0; i < len(A); i++ {
		for j := 0; j < len(B); j++ {
			count += int(A[i]-'0') * int(B[j]-'0')
		}
	}

	fmt.Println(count)
}
