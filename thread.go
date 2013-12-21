package main;

// #cgo LDFLAGS: -lpthread
// #include "thread.h"
import "C"
import "time"
import ."fmt"

func main() {
	C.StartThread()
	time.Sleep(time.Second * 2)
	if C.CancelThread() != 0 {
		Println("thread cancelled as expected")
	}
}
