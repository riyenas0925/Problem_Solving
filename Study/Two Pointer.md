## Two Pointer 알고리즘

### 시작점과 끝점이 동일
* 시작점과 끝점이 0에서 시작
* 현재 부분 합이 n보다 작으면 끝점을 1 증가
* 현재 부분 합이 n보다 크거나 같으면 시작점을 1 증가

```c++
while(start <= end && start < 10001) {
    if(sum < n) {
        sum += arr[end++];
    } else if(sum > n){
        sum -= arr[start++];
    } else {
        sum -= arr[start++];
        answer++;
    }
}
```

### 포인터 두개가 다름
