package main

import (
	"fmt"
	"math"

	"github.com/google/uuid"
)

type Vertex struct {
	X, Y float64
}

type User struct {
	ID    uuid.UUID
	Email string
}

func (v *Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
	fmt.Println("Hello, world.")
	v := &Vertex{1, 4}
	fmt.Println(v.Abs())
}
