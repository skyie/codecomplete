package basic

import (
	"fmt"
)

// 常量定义
const HELLO = "hello"
const (
	RED   = "red"
	BLACK = "black"
)

// 变量定义
func Var() {
	var a int          // 变量声明
	var str1 = "hello" // 变量声明同时初始化
	str2 := "str2"     // := 方式省去写关键字var,更简单
	a = 10

	print("a: %d, str1: %s, str2: %s", a, str1, str2)
}

/*
	go数据类型包括：
	1. bool型： true or false
	2. 数字类型：uint8, uint16, uint32, uint64, int8, int16, int32, int64
      浮点：float32, float64,
      其他数字类型：byte(等价于uint8)
	3. 字符串型：
	4. 派生类型：

*/
func DataType() {
	// 第一种 声明数据类型
	var a0 bool
	var a1 uint8
	var a2 float32
	var a3 error             // error错误类型
	var a4 []int             // 数组
	var a5 map[string]string // map
	var a6 chan int          // 通道
	var a7 *int              // 指针

	fmt.Printf("%v\n%v\n%v\n%v\n%v\n%v\n%v\n", a0, a1, a2, a3, a4, a5, a6, a7)

	// 第二种：根据值自动判断类型
	var b1 = 20
	var b2 = "hello"
	fmt.Printf("%v\n%v\n", b1, b2)

	// 第三种：省略var关键字
	c1 := 10
	c2 := "test"
	fmt.Printf("%v\n%v\n", c1, c2)

	// 空白标识符
	_, d1 := 1, 2
	fmt.Printf("%v\n", d1)
}

func Slice() {
	var a1 []int             // 未定义长度切片
	var a2 = make([]int, 10) // 定义长度为10的切片

	a3 := []int{1, 2, 3}
	a4 := a3[0:]
	a5 := a3[1:2]

	fmt.Printf("%v\n%v\n%v\n%v\n%v\n", a1, a2, a3, a4, a5)
}

/**
 *  go语言没有类，只有结构体
 *  1. 成员名大写表示外部可以访问，小写表示私有，外部不可访问
 *
 */
type Student struct {
	Name string
	Age  int
	From string
}

func Struct() {
	s1 := Student{} // 空结构体定义
	s2 := Student{  // 定义同时初始化
		Name: "Tom",
		Age:  10,
		From: "China",
	}
	name := s2.Name // 访问结构体成员
	s2.Age = 11
	print("s1: %v, s2: %v, name: %s", s1, s2, name)

}
