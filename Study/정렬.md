## 정렬 STL
* default값은 오름차순

### 배열일 경우
```c++
int a[100];
// sort(배열의 포인터, 배열의 포인터 + 배열의 크기)
sort(a, a+100)
```

### vector일 경우
```c++
vector<int> a(100);
// sort(iterator의 begin(), iterator의 end())
sort(a.begin(), a.end());

sort(a.begin(), a.end(), greater<int>());   // 내림차순
sort(a.begin(), a.end(), less<int>());      // 오름차순 (default);
```

### 비교함수 이용
```c++
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
```

### 중복 제거
```c++
vector<int> a(100);
sort(a.begin(), b.begin());
a.erase(unique(a.begin(), a.end()), a.end());
```
```c++
unordered_set<int> s(nums.begin(), nums.end());
```

## 정렬 구현

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