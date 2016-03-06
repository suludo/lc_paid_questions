//
//  RadixSort.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 2/28/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef RadixSort_h
#define RadixSort_h

#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h> //rand
#include <time.h>
using namespace std;

void countSort(vector<int>& nums, int base){
    vector<int> count(10); //10 buckets for 0~9
    for(auto n:nums)
        count[(n/base)%10]++;
    for(int i=1; i<10; i++)
        count[i]+=count[i-1];
    vector<int> it = count;
    for(int i=0; i<nums.size(); i++){
        int index = (nums[i]/base)%10;
        int cnt = count[index]-1;
        
        //TODO: YOU CANNOT ELIMINATE THE SAPCE USAGE OF THE NEW ARRAY
        //THAT STORES THE RE-ORDERED ORIG ARRAY
        //B/C COUNT SORT SPACE COMPLEXITY O(N+K)
        //http://www.geeksforgeeks.org/counting-sort/
    }
}

void radixSort(vector<int>&nums, int m){
    int base = 1;
    while(base<=m){
        countSort(nums, base);
        base*=10;
    }
}
void test(){
    vector<int> nums = {5,4,3,2,1};
    /* initialize random seed: */
    srand (time(NULL));
    for(int i=0; i<10; i++){
        nums.push_back(rand()%10+1);
    }
    
    radixSort(nums, 10);
    for(auto a: nums)
        cout<<a<<" ";
}
void radixSort(vector<int> &nums){

}


#endif /* RadixSort_h */
