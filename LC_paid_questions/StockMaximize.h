//
//  StockMaximize.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 3/6/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef StockMaximize_h
#define StockMaximize_h


#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int64_t maxProfit(vector<int> &prices){
    int N = prices.size();
    if(N<=1) return 0;
    stack<int> stk; //indices of the peak price of day slices
    stk.push(N-1); //last one
    int cur = prices.back();
    for(int i=N-2; i>=0; i--){
        while(i>=0 && prices[i]<=cur) i--;
        if(i>=0){
            cur = prices[i];
            stk.push(i);
        }
    }
    int64_t ret = 0;
    for(int i=0; i<N; i++){
        if(i<stk.top()){
            ret += (prices[stk.top()]-prices[i]);
        }
        else{
            stk.pop();
        }
    }
    return ret;
}

vector<vector<int>> parseTestCases(){
    int n=0;
    cout<<"Number of test cases: ";
    cin>>n;
    vector<vector<int>> ret(n);
    for(int i=0; i<n; i++){
        cout<<"Case "<<i+1<<" # prices: ";
        int np=0;
        cin>>np;
        int p=-1;
        for(int j=0; j<np; j++){
            cout<<"Case "<<i+1<<" Price "<<j+1<<" is: ";
            cin>>p;
            ret[i].push_back(p);
        }
    }
    return ret;
}

void test() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> testPack = parseTestCases();
    for(int i=0; i<testPack.size(); i++)
        cout<<"Case 1 result: "<<maxProfit(testPack[i])<<endl;
    //return 0;
}


#endif /* StockMaximize_h */
