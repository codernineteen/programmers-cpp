//Problem url : https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    int p1C = 0, p2C = 0, p3C = 0;
    
    
    for(int i=0; i < answers.size(); i++) {
        if(answers[i] == p1[i%5]) {
            p1C += 1;
        }
        
        if(answers[i] == p2[i%8]) {
            p2C += 1;
        }
        
        if(answers[i] == p3[i%10]) {
            p3C += 1;
        }
    }
    
    if(p1C == p2C && p2C == p3C) {
        answer = {1,2,3};
    } else if(p1C > p2C && p1C > p3C) {
        answer = {1};
    } else if(p1C < p3C && p2C < p3C) {
        answer = {3};
    } else if(p1C < p2C && p2C > p3C) {
        answer = {2};
    } else if(p1C == p2C && p2C > p3C) {
        answer = {1,2};
    } else if(p1C < p2C && p2C == p3C) {
        answer = {2,3};
    } else if(p1C > p2C && p1C == p3C) {
        answer = {1,3};
    }
    
    return answer;
}