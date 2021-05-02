## String

### "", '' 차이
* ""는 문자열
* ''는 문자

### reverse
```c++
string s;
reverse(s.begin(), s.end());
```

### 숫자 -> 문자열
```
to_string();
```

### 문자열 -> 숫자
```
stoll   // long long
strtol  // long
strtoul // unsigned long
strod() // double
```

### 문자열 슬라이싱
```
stl.substr(시작지점, 원하는 개수)를 통하여 슬라이싱
ex. str.substr(0,index); //0~index-1까지
ex. Str.substr(index+1, strl.length()); //index+1 부터 끝까지
```