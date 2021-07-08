# 수학

## 최대값
### *max_element
```cpp
int arr[10] = {1, 2, 3, 4, 5};
int mx = *max_element(arr, arr+10);
```
```cpp
vector<int> V = {1, 2, 3, 4, 5};
int mx = *max_element(V.begin(), V.end());
```

### max;
```cpp
int a, b, c;
int mx = max({a, b, c});
```

## 최소값
### *min_element
```cpp
int arr[10] = {1, 2, 3, 4, 5};
int mn = *min_element(arr, arr+10);
```
```cpp
vector<int> V = {1, 2, 3, 4, 5};
int mn = *min_element(V.begin(), V.end());
```

### min
```cpp
int a = 1, b = 2, c = 3;
int mn = min({a, b, c});
```

## 최대값, 최소값
```cpp
int a = 1, b = 2, c = 3;
pair<int, int> min_max = minmax({a, b, c});
int mn = min_max.first;     // 최소값
int mx = min_max.second;    // 최대값
```

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

## 최대공약수, 최소공배수

### 최대공약수
```c++
int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y); 
}
```

### 최소공배수
```c++
int lcm(int x, int y) {
    return x * y / gcd(x, y); 
}
```

## 진법 변환
```
string notation(int n, int num) {
    string str = "";
    if(num == 0) return "0";
    vector<char> alp = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(num > 0) {
        str.push_back(alp[num % n]);
        num = num / n;
    }
    reverse(str.begin(), str.end());
    return str;
}
```