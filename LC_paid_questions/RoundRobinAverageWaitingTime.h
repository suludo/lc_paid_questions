//
//  RoundRobinAverageWaitingTime.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 3/6/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef RoundRobinAverageWaitingTime_h
#define RoundRobinAverageWaitingTime_h

#include <queue>
#include <vector>

using namespace std;

struct Proc{
    int arr;
    int exec;
    Proc(int a, int e):arr(a),exec(e){}
};

int RoundRobinAverageWaitingTime(vector<int>& arrival, vector<int>& run, int q){
    if(arrival.empty() || run.empty() || arrival.size()!=run.size()) return 0;
    
    queue<int> taskQueue;
    int i=0;
    taskQueue.push(Proc(arrival[i], run[i]));
    ++i;
    while(!taskQueue.empty()){
        
    }
    
}


#endif /* RoundRobinAverageWaitingTime_h */
