#include<iostream>
#include<stack>

using namespace std;

int main(){
    int k, sum = 0;

    stack<int> st;

    cin >> k;
    
    for(int i = 0; i < k; i++){
        int num; cin >> num;

        if (num == 0){
            st.pop();
        } else {
            st.push(num);
        }
    }

    int stackSize = st.size();

    for(int i = 0; i < stackSize; i++){
        sum = sum + st.top();
        st.pop();
    }

    cout << sum << endl;

    return 0;
}