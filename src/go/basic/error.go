package basic

import (
	"errors"
	"fmt"
)

func Sqrt(f float64) (float64, error) {
	if f < 0 {
		return 0, errors.New("math: square root of negative number")
	}
	return 0, nil
}

func UseSqrt() {
	_, err := Sqrt(0)
	if err != nil {
		fmt.Printf("Sqrt fail, err: %s", err.Error())
	}
}
