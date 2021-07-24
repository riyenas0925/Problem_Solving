#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
    int age;
    int seq;
    string name;
}member;

bool cmp(member a, member b) {
    if(a.age == b.age) {
        return a.seq < b.seq;
    } else {
        return a.age < b.age;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<member> v;
    
    for(int i = 0; i < n; i++) {
        int age; string name;
        cin >> age >> name;
        v.push_back({age, i, name});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << v[i].age << " " << v[i].name << "\n";
    }
}
