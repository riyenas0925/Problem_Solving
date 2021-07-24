    #include <bits/stdc++.h>

    using namespace std;

    deque<int> parse(string str, deque<int>& dq) {
        istringstream ss(str.substr(1, str.length() - 2));
        string stringBuffer;
        while (getline(ss, stringBuffer, ',')) {
            dq.push_back(stoi(stringBuffer));
        }
        return dq;
    }

    int main() {
        int t; cin >> t;
        for(int i = 0; i < t; i++) {
            string com; cin >> com;
            int n; cin >> n;
            string arr; cin >> arr;
            deque<int> dq;
            parse(arr, dq);
            bool cur = true; // true 앞 false 뒤
            bool fault = false;

            for(int j = 0; j < com.length(); j++) {
                if(com[j] == 'R') {
                    cur = !cur;
                }
                if(com[j] == 'D') {
                    if(dq.empty()) {
                        fault = true;
                        break;
                    }
                    if(cur == true) dq.pop_front();
                    else dq.pop_back();
                }
            }

            if(fault == true) {
                cout << "error\n";
            } else if(cur == true) {
                int size = dq.size();
                cout << "[";
                for(int j = 0; j < size; j++) {
                    cout << dq.front();
                    if(dq.size() != 1) cout << ",";
                    dq.pop_front();
                }
                cout << "]\n";
            } else {
                int size = dq.size();
                cout << "[";
                for(int j = 0; j < size; j++) {
                        cout << dq.back();
                    if(dq.size() != 1) cout << ",";
                    dq.pop_back();
                }
                cout << "]\n";
            }
        }
    }