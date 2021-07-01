## String

### "", '' 차이
* ""는 문자열
* ''는 문자

### 문자열 뒤집기 (reverse)
```c++
string s;
reverse(s.begin(), s.end());
```

### 문자열 슬라이싱
```c++
stl.substr(시작지점, 원하는 개수)를 통하여 슬라이싱
ex. str.substr(0,index); //0~index-1까지
ex. Str.substr(index+1, strl.length()); //index+1 부터 끝까지
```

### 문자가 숫자인지
```c++
bool isdigit(char c) // 숫자면 true, 숫자가 아니면 false
```

### 문자가 알파벳인지
```c++
bool isalpha(char c) // 알파벳이면 true, 알파벳이 아니면 false;
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

### 문자열 -> 숫자 (ll, l , ul, d)
```c++
stoll("1234")       // long long
strtol("1234")      // long
strtoul("1234")     // unsigned long
strod("1234.123")   // double
```

### 문자열 찾기
```c++
int pos = find("문자열", 시작 위치); // 없으면 -1 있다면 시작 위치
```

### 문자열 대소문자로 변환
```c++
transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
```

### 문자 대소문자 변환
```c++
int toupper(int c)  // c가 소문자면 대문자로 변환
int tolower(int c)  // c가 대문자면 소문자로 변환
```