//
//  FirstRepeatingLetterInString.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 3/6/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef FirstRepeatingLetterInString_h
#define FirstRepeatingLetterInString_h

#include <string>
#include <iostream>

using namespace std;

void FirstRepeatingLetterInString(string s){
    int n = s.size();
    if(n<=1) return;
    int dup[256] = {};
    int leftPos = 0;
    
    for(int i=0; i<s.size(); i++){
        if(dup[s[i]]==0) dup[s[i]] = i+1;
        else if(leftPos==0 || leftPos>dup[s[i]]) leftPos=dup[s[i]];
    }
    
    cout<<"first letter repeated is "<<leftPos-1<<" : "<<s[leftPos-1]<<endl;
}

void test(){
    FirstRepeatingLetterInString("abcbc");
}

#endif /* FirstRepeatingLetterInString_h */
