## #include<algorithm>

### 벡터에서 특정 문자열 검색
```c++
int pos=find(seoul.begin(),seoul.end(),"Kim") - seoul.begin();
```

### 벡터에서 특정 문자열 개수 세기
```c++
int bn = count(B.begin(), B.end(), "Kim");
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