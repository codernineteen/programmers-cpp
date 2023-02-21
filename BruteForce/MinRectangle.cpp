//Problem url: https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxW = 0;
    int maxH = 0;
    
    for(auto& size: sizes) {
        if(size[0] > size[1]) {
            if(maxW < size[0]) {
                maxW = size[0];
            }
            
            if(maxH < size[1]) {
                maxH = size[1];
            }
        } else {
            if(maxW < size[1]) {
                maxW = size[1];
            }
            
            if(maxH < size[0]) {
                maxH = size[0];
            }
        }
    }
    answer = maxW * maxH;
    
    return answer;
}