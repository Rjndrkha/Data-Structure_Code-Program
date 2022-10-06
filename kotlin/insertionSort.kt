fun insertionSort(inputList: MutableList<Int>) : List<Int>{
    for (j in 1 until inputList.size) {
        val key = inputList[j]
        var i = j - 1
        while (i >= 0 && inputList[i] > key) {
            inputList[i + 1] = inputList[i]
            i--
        }
        inputList[i + 1] = key
    }
    return inputList
}

fun main() {
    val input = mutableListOf(5, 4, 3, 2, 1)
    val result = insertionSort(input)
    result.forEach { value ->
        print("$value ")
    }
}