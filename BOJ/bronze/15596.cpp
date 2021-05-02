#include<vector>

long long sum(std::vector<int> &a){
    long long total = 0;
    for(int i = 0; i < a.size(); i++){
        total = total + a[i];
    }
    return total;
}