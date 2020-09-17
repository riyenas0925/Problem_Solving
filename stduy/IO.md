## Input & Output

### cin, cout 입출력 속도 빠르게 하기
* printf, scanf와 같이 사용하면 안된다.  
* 싱글 스레드 상황에서만 사용해야함

```c++
int main() {
    //fast
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "test" << "\n";

    //slow
    cout << "test" << endl;
}
```

### 입력 받기 1
* 빈 줄이 주어질 수도 있고
* 각 줄의 앞 뒤에 공백이 있을 수도 있다.
```
    Hello
Baekjoon     
   Online Judge
```

```c++
int main() {
    string str;

    for(int i = 0; i < 100; i++) {
        getline(cin, str);
        cout << str << endl;
    }
}
```

### 입력 받기 2
* 각 줄은 공백으로 시작하지 않고
* 공백으로 끝나지 않는다.

```
Hello
Baekjoon
Online Judge
```

```c++
int main() {
    while(true) {
        getline(cin, str);
        if(str=="") {
            break;
        }
        cout << str << endl;
    }
}
```

### 입력 받기 3
* A와 B는 콤마(,)로 구분되어 있다.
```
1,2
3,4
```

```c++
int main(){
    int a, b;
    char c;

    cin >> a >> c >> b;

    cout << a + b << endl;
}
```