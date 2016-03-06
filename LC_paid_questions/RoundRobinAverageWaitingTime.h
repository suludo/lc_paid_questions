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
#include <algorithm>

//http://www.tutorialspoint.com/operating_system/os_process_scheduling_algorithms.htm

using namespace std;

struct Proc{
    int arr;
    int exec;
    Proc(int a, int e):arr(a),exec(e){}
};

float RoundRobinAverageWaitingTime(vector<int>& arrival, vector<int>& run, int q){
    if(arrival.empty() || run.empty() || arrival.size()!=run.size()) return 0;
    
    queue<Proc> taskQueue;
    int i=0, N = arrival.size();
    taskQueue.push(Proc(arrival[i], run[i]));
    ++i;
    int cur_time = 0, wait_time = 0;
    while(!taskQueue.empty()){
        Proc curTask = taskQueue.front();
        taskQueue.pop();
        wait_time += (cur_time - curTask.arr);
        cur_time += min(curTask.exec, q);
        while(i<N && arrival[i]<=cur_time){
            taskQueue.push(Proc(arrival[i], run[i]));
            i++;
        }
        if(curTask.exec>q)
            taskQueue.push(Proc(cur_time, curTask.exec-q));
        
        if(taskQueue.empty() && i<N){
            taskQueue.push(Proc(arrival[i], run[i]));
            //this line is important
            cur_time = arrival[i];
            i++;
        }
    }
    return (float)wait_time/N;
}

void test(){
    vector<int> a = {0,1,2,3};//{0,1,4};
    vector<int> r = {5,3,8,6};//{5,2,3};
    int q = 3;
    
    cout<<"avr waiting time is: "<<RoundRobinAverageWaitingTime(a,r,q)<<endl;
}

#endif /* RoundRobinAverageWaitingTime_h */
