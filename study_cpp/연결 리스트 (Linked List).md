## 연결 리스트

### insert 함수
1. 새로운 원소를 생성
2. 새 원소의 pre 값에 삽입할 위치에 주소를 대입
3. 새 원소의 nxt 값에 삽입할 위치의 nxt 값을 대입
4. 삽입할 위치의 nxt 값과 삽입할 위치의 다음 원소의 pre 값을 새 원소로 변경
5. unused 1 증가
```cpp
void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}
```

### erase 함수
1. 이전 위치의 nxt를 삭제할 위치의 nxt로 변경
2. 다음 위치의 pre를 삭제할 위치의 pre로 변경
```cpp
void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
```

## STL
```cpp
int main() {
    list<int> L = {1,2};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    L.insert(t, 6);
    t++;
    t = L.erase(t);

    cout << *t << '\n';
    for(auto i : L) cout << i << ' ';
    cout << '\n';
    for(list<int>::iterator it = L.begin(); it != L.end(); it++) 
        cout << *it << ' ';
}
```

## 참고
- [[실전 알고리즘] 0x04강 - 연결 리스트](https://blog.encrypted.gg/932?category=773649)

