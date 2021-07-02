## 순열
* 순열은 서로 다른 n개중 r개를 골라 순서를 고려해 나열한 경우의 수를 의미
* nPr = n!/(n-r)!

### 구현
```cpp
void Permutation(vector<bool> visited, vector<int> vec, vector<int> res, int depth)
{
    if (depth == res.size())
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < vec.size(); i++) 
    {
        if(visited[i] == true) continue;
        visited[i] = true;
        res[depth] = vec[i];   
        Permutation(visited, vec, res, depth + 1); 
        visited[i] = false;
    }
}
```

## 조합 (Combination)
* 조합은 서로 다른 n개중에 r개를 선택하는 경우의 수를 의미
* nCr = n!/(n-r)!r!

### 구현
```cpp
void Combination(vector<char> vec, vector<char> res, int index, int depth) {
    if (depth == res.size()) {
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        
        return;
    }
    else {
        for(int i = index; i < vec.size(); i++) {
            res[depth] = vec[i];
            Combination(vec, res, i + 1, depth + 1);
        }
    }
}
```

## 중복 순열

## 중복 조합