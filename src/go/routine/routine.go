package routine

import (
	"fmt"
	"time"
)

func f(from string) {
	for i := 0; i < 3; i++ {
		fmt.Println(from, ":", i)
	}
}
func Routines() {
	// 假设我们有一个函数叫做 f(s)。我们使用一般的方式调并同时运行。
	f("direct")
	// 使用 go f(s) 在一个 Go 协程中调用这个函数。这个新的 Go 协程将会并行的执行这个函数调用。
	go f("goroutine")

	// 匿名函数启动一个 Go协程
	go func(msg string) {
		fmt.Println(msg)
	}("going")

	time.Sleep(3)
	fmt.Println("done")
}

func Channel() {
	messages := make(chan string)
	// channel <- 语法 发送 一个新的值到通道中
	go func() { messages <- "ping" }()

	// <-channel 语法从通道中接收一个值
	msg := <-messages
	fmt.Println(msg)
}
