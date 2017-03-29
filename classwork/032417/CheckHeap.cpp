bool isHeap(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (2*i+1 > size)
			break;

		if (arr[i] <= arr[2*i+1] || arr[i] <= arr[2*i+2])
			return false;
	}

	return true;
}

bool isHeapRec(int arr[], int index, int size)
{
	if (isLeaf(arr, index, size))
		return true;

	if (arr[i] > arr[2*i+1] && arr[i] > arr[2*i+2])
		if (isHeapRec(arr, index*2+1, size) && isHeapRec(arr, index*2+2, size))
			return true;

	return false;
}
