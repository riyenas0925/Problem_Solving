#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
    string name;
    int kor;
    int eng;
    int math;
}student;

bool cmp(student a, student b) {
    if(a.kor == b.kor) {
        if(a.eng == b.eng) {
            if(a.math == b.math) {
                return a.name < b.name;
            } else {
                return a.math > b.math;
            }
        } else {
            return a.eng < b.eng;
            
        }
    } else {
        return a.kor > b.kor;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<student> v;
    
    for(int i = 0; i < n; i++) {
        int eng, kor, math; string name;
        cin >> name >> kor >> eng >> math;
        v.push_back({name, kor, eng, math});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << v[i].name << "\n";
    }
}
