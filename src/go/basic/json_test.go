package basic

import (
	"encoding/json"
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// json传输map
type TestMap struct {
	ParamMap map[string]string `json:"param_map"`
}

func TestJsonMap(t *testing.T) {
	var testMap TestMap
	myMap := make(map[string]string)
	myMap["read_only"] = "ON"
	myMap["super_read_only"] = "ON"

	testMap.ParamMap = myMap
	result, err := json.Marshal(testMap)
	assert.Nil(t, err)

	var resultMap TestMap
	err = json.Unmarshal(result, &resultMap)
	assert.Nil(t, err)
	fmt.Printf("resultMap: %#v", resultMap)
}
