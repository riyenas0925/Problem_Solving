## Binary Search
* 오름차순으로 정렬된 리스트에서 특정 값의 위치를 찾는 알고리즘
* 모든 값을 순회해야 하는 일반적인 Search보다 더 빠르다는 장점이 있음
* 중앙값을 찾는 값에 비교
    * 중앙값 > 찾는값 : 중앙값 기준으로 왼쪽(작은 부분)을 탐색
    * 중앙값 < 찾는값 : 중앙값 기준으로 오른쪽(큰 부분)을 탐색

![binary-and-linear-search-animations](https://user-images.githubusercontent.com/32615702/104535663-f5bfd500-5659-11eb-924f-3a6a7e0427b1.gif)

## binary_search 구현 (non-recursion)
```c++
int binary_search(int *arr, int low, int high, int target) {
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] > target) {
            high = mid - 1;
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
}
```

## binary_search 구현 (recursion)
```c++
int binary_search(int *arr, int low, int high, int target) {

    if(high <= low) {
        return -1;
    }

    int mid = (low + high) / 2; // 중간값을 찾는다.

    if(arr[mid] > target) {
        binary_search_resursion(arr, low, mid - 1, target);
    } else if(arr[mid] < target) {
        binary_search_resursion(arr, mid + 1, high, target);
    } else {
        return mid;
    }
}

```

## binary_search STL
### binary_search
* 반환 값은 arr ~ arr + n에 있으면 1, 없으면 0
* 이진 탐색은 데이터가 정렬되어있어야 한다
```c++
sort(arr, arr + n); 
binary_search(arr, arr + n, val);
```

### upper_bound
```c++
upper_bound(arr, arr + n, val);
```

### lower_bound
```c++
lower_bound(arr, arr + n, val);
```