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