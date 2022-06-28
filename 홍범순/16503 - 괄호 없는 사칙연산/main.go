package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	data, _ := in.ReadString('\n')
	data = strings.TrimSpace(data)

	split := strings.Split(data, " ")

	Kstr := []string{split[0], split[2], split[4]}
	K := []int{}
	O := []string{split[1], split[3]}

	for _, v := range Kstr {
		j, _ := strconv.Atoi(v)
		K = append(K, j)
	}

	calc1 := calc(calc(K[0], K[1], O[0]), K[2], O[1])
	calc2 := calc(K[0], calc(K[1], K[2], O[1]), O[0])

	if calc1 <= calc2 {
		fmt.Println(calc1)
		fmt.Println(calc2)

	} else {
		fmt.Println(calc2)
		fmt.Println(calc1)
	}
}

func calc(a, b int, op string) int {

	switch op {
	case "+":
		return a + b
	case "-":
		return a - b
	case "*":
		return a * b
	case "/":
		return a / b
	}
	return 0
}
