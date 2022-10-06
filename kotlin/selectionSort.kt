fun selectionSort(inputList : MutableList<Int>) : List<Int>{
    for(i in 0 until inputList.size - 1){
        var currentMinIndex = i
        for (j in inputList.size - 1 downTo i){
            if(inputList[j] < inputList[currentMinIndex]){
                currentMinIndex = j
            }
        }
        if (i != currentMinIndex){
            val temp = inputList[i]
            inputList[i] = inputList[currentMinIndex]
            inputList[currentMinIndex] = temp
        }
    }
    return inputList
}


fun main() {
    val input = mutableListOf(5, 4, 3, 2, 1)
    val result = selectionSort(input)
    result.forEach { value ->
        print("$value ")
    }
}