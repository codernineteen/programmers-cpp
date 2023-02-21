#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < lost.size(); i++) {
        for(int j = 0; j < reserve.size(); j++) {
            if(lost[i] == reserve[j]) {
                lost[i] = -100;
                reserve[j] = -100;
                answer += 1;
                break;
            }
        }
    }
    
    
    for(int i = 0; i < lost.size(); i++) {
        if(lost[i] > 0)
        {
            for(int j = 0; j < reserve.size(); j++) {
                if(lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1) {
                    reserve[j] = -100;
                    answer += 1;
                    break;
                }
            }
        }
    }
        
    return answer;
}