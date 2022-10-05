fun merge(leftList: List<Int>, rightRight: List<Int>): List<Int> {
    var indexLeft = 0
    var indexRight = 0
    var newList: MutableList<Int> = mutableListOf()

    while (indexLeft < leftList.count() && indexRight < rightRight.count()) {
        if (leftList[indexLeft] <= rightRight[indexRight]) {
            newList.add(leftList[indexLeft])
            indexLeft++
        } else {
            newList.add(rightRight[indexRight])
            indexRight++
        }
    }

    while (indexLeft < leftList.size) {
        newList.add(leftList[indexLeft])
        indexLeft++
    }

    while (indexRight < rightRight.size) {
        newList.add(rightRight[indexRight])
        indexRight++
    }

    return newList;
}

fun mergeSort(inputList: List<Int>): List<Int> {
    if (inputList.size <= 1) {
        return inputList
    }

    val middle = inputList.size / 2
    var left = inputList.subList(0, middle)
    var right = inputList.subList(middle, inputList.size)

    return merge(mergeSort(left), mergeSort(right))
}


fun main() {
    val input = mutableListOf(5, 4, 3, 2, 1)
    val result = mergeSort(input)
    result.forEach { value ->
        print("$value ")
    }
}

