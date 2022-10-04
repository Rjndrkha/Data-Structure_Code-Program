package Golang

import (
	"fmt"
	"math"
)

func merge(arr []string, start int, mid int, end int) {
	var mergedArray []string

	var i = start
	var j = mid + 1

	for i <= mid && j <= end {
		if len(arr[i])%2 == 0 && len(arr[j])%2 != 0 {
			mergedArray = append(mergedArray, arr[j])
			j++
		} else if len(arr[i])%2 != 0 && len(arr[j])%2 == 0 {
			mergedArray = append(mergedArray, arr[i])
			i++
		} else if len(arr[i])%2 == 0 && len(arr[j])%2 == 0 {
			if len(arr[i]) > len(arr[j]) {
				mergedArray = append(mergedArray, arr[i])
				i++
			} else if len(arr[i]) < len(arr[j]) {
				mergedArray = append(mergedArray, arr[j])
				j++
			} else {
				if arr[i] <= arr[j] {
					mergedArray = append(mergedArray, arr[i])
					i++
				} else {
					mergedArray = append(mergedArray, arr[j])
					j++
				}
			}
		} else if len(arr[i])%2 != 0 && len(arr[j])%2 != 0 {
			if len(arr[i]) < len(arr[j]) {
				mergedArray = append(mergedArray, arr[i])
				i++
			} else if len(arr[i]) > len(arr[j]) {
				mergedArray = append(mergedArray, arr[j])
				j++
			} else {
				if arr[i] <= arr[j] {
					mergedArray = append(mergedArray, arr[i])
					i++
				} else {
					mergedArray = append(mergedArray, arr[j])
					j++
				}
			}
		}
	}

	for i <= mid {
		mergedArray = append(mergedArray, arr[i])
		i++
	}

	for j <= end {
		mergedArray = append(mergedArray, arr[j])
		j++
	}

	j = 0

	for i = start; i <= end; i++ {
		arr[i] = mergedArray[j]
		j++
	}
}

func divide(arr []string, start int, end int) {
	if start < end {
		var mid = start + (int)(math.Floor(float64((end-start)/2)))

		divide(arr, start, mid)
		divide(arr, mid+1, end)
		merge(arr, start, mid, end)
	}
}

func customSorting(strArr []string) []string {
	if len(strArr) <= 1 {
		return strArr
	}

	divide(strArr, 0, len(strArr)-1)

	return strArr
}

func main() {
	var strArr = []string{"abc", "ab", "abcde", "a", "abcd"}
	var strArrTwo = []string{"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"}

	sortedArray := customSorting(strArr)
	sortedArrayTwo := customSorting(strArrTwo)

	fmt.Println(sortedArray)
	fmt.Println(sortedArrayTwo)
}