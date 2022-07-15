package main

import (
	"fmt"
)

var ARR_SIZE int = 1000010
var prime [1000010]bool
var primesum [1000010]int
var squaresum [1000010]int

func main() {
	Init()
	getPrimes()
	//debugprint()

	for i := 3; i < ARR_SIZE; i++ {
		if prime[i] == true {
			primesum[i] = primesum[i-1] + 1
		} else {
			primesum[i] = primesum[i-1]
		}

		if prime[i] == true && (i%4) == 1 {
			squaresum[i] = squaresum[i-1] + 1
		} else {
			squaresum[i] = squaresum[i-1]
		}
	}

	for {
		var L, U int
		fmt.Scan(&L, &U)

		x, y := 0, 0

		if L == -1 && U == -1 {
			return
		}

		if L >= 1 {
			x = primesum[U] - primesum[L-1]
			y = squaresum[U] - squaresum[L-1]
		} else if L < 1 && U >= 0 {
			x = primesum[U]
			y = squaresum[U]
		} else {
			x = 0
			y = 0
		}

		fmt.Printf("%d %d %d %d\n", L, U, x, y)
	}

}

func Init() {
	for i := 2; i < ARR_SIZE; i++ {
		prime[i] = true
		primesum[i] = 0
		squaresum[i] = 0
	}
	primesum[2] = 1
	squaresum[2] = 1
}

func getPrimes() {
	prime[1] = false
	for i := 2; i*i < ARR_SIZE; i++ {
		if prime[i] == true {
			for j := i * i; j < ARR_SIZE; j += i {
				prime[j] = false
			}
		}
	}
}

func debugprint() {
	for i := 0; i < 50; i++ {
		fmt.Printf("%d %d \n", i, prime[i])
	}
}
