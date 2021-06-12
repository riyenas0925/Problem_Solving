### 버블 정렬 (0(n^2))
```
void BubbleSort(int arr[], int n) {
    int i, j;
    int temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < (n - i) - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

### 선택 정렬 (O(n^2))
```
void SelSort(int arr[], int n) {
    int i, j;
    int maxIdx;
    int temp;

    for(i = 0; i < n - 1; i++) {
        maxIdx = i;

        for(j = j + 1; j < n; j++) {
            if(arr[j] < arr[maxIdx]) {
                maxIdx = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}
```

### 삽입정렬 (O(n^2))
```
void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];
			else
				break;
		}

		arr[j+1] = insData;
	}
}

```