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