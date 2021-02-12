#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string word; cin >> word;
    int alp[26] = {0};
    int max = 0, maxIndex; 
    int cnt = 0;

    //소문자 변환
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    //word에 나온 알파벳 개수 계산
    for(int i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        alp[index] = alp[index] + 1;
    }

    //최대빈도 알파벳 계산과, 최대빈도 알파벳이 몇개인지 계산
    for(int i = 0; i < 26; i++){
        if(max < alp[i]){
            max = alp[i];
            maxIndex = i;
            cnt = 0;
        } else if(max == alp[i]){
            cnt++;
        }
    }

    if(cnt > 0){
        cout << "?" << endl;
    } else {
        cout << (char)(maxIndex + 'A') << endl;
    }

    return 0;
}