## 소수 판별
### 1 ~ n -> O(N)
```c++
int answer = 0;

for(int i = 3; i <= n; i++) {
    int cnt = 0;
    
    for(int j = 2; j < i; j++) {
        if(i % j == 0) {
            cnt++;
        }
    }
    
    if(cnt == 0) {
        answer++;
    }
}
```

### 1 ~ sqrt(n) -> O(sqrt(N))
```c++
int cnt = 0;

for(int j = 2; j <= sqrt(i); j++) {
    if(i % j == 0) {
        cnt++;
        break;
    }
}

if(cnt == 0) {
    answer++;
}
```

### 에라토스테네스의 체 -> O(NloglogN)
```c++
vector<bool> arr(n+1, true);
int answer = 0;

for(int i = 2; i <= n; i++) {
    if(arr[i] == false) continue;

    for(int j = 2 * i; j <= n; j = j + i) {
        arr[j] = false;
    }
}

for(int i = 2; i <= n; i++) {
    if(arr[i]) {
        answer++;
    }
}
```