#include<unordered_map>
#include<iostream>

using namespace std;

int main() {
    unordered_map<string, int> um;

    // insert
    um["kim"] = 20;
    um.insert(pair<string, int>("kang", 19));
    um.insert(make_pair("kwon", 29));
    
    // iterator
    cout << "### iterator ###" << endl;
    unordered_map<string, int>::iterator it;
    for(it = um.begin(); it != um.end(); it++) 
        cout << it->first << " - " << it->second << endl; 

    // iterator(auto)
    cout << "### iterator(auto) ###" << endl;
    for(auto i : um)
        cout << i.first << " - " << i.second << endl;

    // find
    cout << "### find ###" << endl;
    cout << um.find("kang")->first << " - " << um.find("kang")->second << endl;
    cout << "kang - " << um["kang"] << endl;


    // find exception
    cout << "### find exception ###" << endl;
    if(um.find("null") != um.end()) {
        cout << um.find("null")->second << endl;
    } else {
        cout << "없는 id 입니다." << endl;
    }

    // erase
    cout << "### erase ###" << endl;
    um.erase("kang");
    //um.erase(um.find("kang")); -> kang이라는 키가 없으면 오류 발생!!!

    for (pair<string, int> i : um)
        cout << i.first << " - " << i.second << endl;

    cout << "### size ###" << endl;
    cout << um.size() << endl;

    cout << "### empty ###" << endl;
    cout << um.empty() << endl;
}