function shellSort(arr) {
	let n = arr.length;

	//Start with a really large gap, and then reduce the gap until there isn't any
	//With this, the gap starts as half of the array length, and then half of that every time
	for (let gap = Math.floor(n/2); gap > 0; gap = Math.floor(gap/2))
	{
		//Do a insertion sort for each of the section the gap ends up dividing
		for (let i = gap; i < n; i += 1)
		{
			//We store the current varible
			let temp = arr[i];
			
			//This is the insection sort to sort the section into order
			let j;
			for (j = i; j >= gap && arr[j-gap] > temp; j-=gap)
			{
				arr[j] = arr[j-gap];
			}

			arr[j] = temp;
		}
	}

	return arr;
}