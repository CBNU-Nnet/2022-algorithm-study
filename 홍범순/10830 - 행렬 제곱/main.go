package main

import (
	"fmt"
)

var N, B int
var A, res [][]int

func main() {
	fmt.Scanf("%d %d", &N, &B)

	A = make([][]int, N)
	res = make([][]int, N)

	for i := 0; i < N; i++ {
		A[i] = make([]int, N)
		res[i] = make([]int, N)
		for j := 0; j < N; j++ {
			fmt.Scan(&A[i][j])
		}
		res[i][i] = 1
	}

	for B > 0 {
		if B%2 == 1 {
			res = matrixMulti(res, A)
		}
		A = matrixMulti(A, A)
		B /= 2
	}

	printMatrix()
}

func matrixMulti(A, B [][]int) [][]int {
	tmp := make([][]int, N)
	for i := 0; i < N; i++ {
		tmp[i] = make([]int, N)
		for j := 0; j < N; j++ {
			tmp[i][j] = 0
			for k := 0; k < N; k++ {
				tmp[i][j] += (A[i][k] * B[k][j])
			}
			tmp[i][j] = tmp[i][j] % 1000
		}
	}
	return tmp
}

func printMatrix() {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Printf("%d ", res[i][j])
		}
		fmt.Println()
	}
}
