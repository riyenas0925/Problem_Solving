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
```c++
to_string();
```

### 문자열 -> 숫자
```c++
stoll   // long long
strtol  // long
strtoul // unsigned long
strod() // double
```

### 문자열 슬라이싱
```c++
stl.substr(시작지점, 원하는 개수)를 통하여 슬라이싱
ex. str.substr(0,index); //0~index-1까지
ex. Str.substr(index+1, strl.length()); //index+1 부터 끝까지
```

### 문자 대소문자 변환
```c++
int toupper(int c)  // c가 소문자면 대문자로 변환
int tolower(int c)  // c가 대문자면 소문자로 변환
```

### 문자가 숫자인지
```c++
bool isdigit(char c) // 숫자면 true, 숫자가 아니면 false
```

### 숫자 -> 문자열 변환
```c++
string s = to_string(n);
```

### 문자열 -> int
```c++
int n1 = stoi("-1234"); // -1234
int n2 = stoi("+1234"); // 1234
int n3 = stoi("1234");  // 1234
```

### 문자열 -> long long
```c++
int n = stoll("1234");
```

### 문자열 찾기
```c++
int pos = find("문자열", 시작 위치); // 없으면 -1 있다면 시작 위치
```

### 문자열 일부 가져오기
```c++
// 세번쨰 문자에서 2개를 가져온다.
s.substr(3,2);
```