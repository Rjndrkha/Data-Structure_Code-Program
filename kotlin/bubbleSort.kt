fun bubbleSort(inputList: MutableList<Int>): List<Int> {
    var swapped: Boolean = false
    for (i in 0 until inputList.count() - 1) {
        swapped = false
        for (j in 0 until inputList.count() - i - 1) {
            if (inputList[j] > inputList[j + 1]) {
                inputList[j] = inputList[j + 1].also { inputList[j + 1] = inputList[j] }
                swapped = true
            }
        }
        if (!swapped) {
            break
        }
    }
    return inputList
}

fun main() {
    val input = mutableListOf(5, 4, 3, 2, 1)
    val result = bubbleSort(input)
    result.forEach { value ->
        print("$value ")
    }
}