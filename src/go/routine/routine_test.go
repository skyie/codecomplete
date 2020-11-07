package routine

import "testing"

// 运行go test方法是 go test basic_test.go basic.go
func TestVar(t *testing.T) {
	Routines()
}

func TestChannel(t *testing.T) {
	Channel()
}
