//Problem source: https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=cpp
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool isPrime(int num) {
    if(num < 2) {
        return false; 
    }
    
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}

void helper(string str, string res, int& answer, map<int, int>& memo) { 
    for(int i=0; i < str.length(); i++) {
        res += str[i];
        int num = stoi(res);
        auto data = memo.find(num);
        if(data == memo.end()) {
            cout << num << endl;
            if(isPrime(num)) answer += 1;
            memo.insert({num, 1});
        }
        string copy = str;
        copy.erase(copy.begin() + i);
        helper(copy, res, answer, memo);
        res.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    map<int, int> memo;
    
    helper(numbers, "", answer, memo);
    
    return answer;
}