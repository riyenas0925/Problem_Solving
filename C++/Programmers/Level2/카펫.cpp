#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width, height;
    for(int width = 3; width < brown; width++) {
        for(int height = 3; height <= width; height++) {
            if(width * height == brown + yellow && (height - 2)*(width - 2) == yellow) {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }   
    }
    return answer;
}