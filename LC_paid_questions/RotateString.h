//
//  RotateString.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 3/5/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef RotateString_h
#define RotateString_h

#include <string>

using namespace std;

// e.g. "abcd" "cdab"
int isRotateString(string a, string b){

    if(a.empty() && b.empty()) return 1;
    if(a.empty() || b.empty() || a.size()!=b.size()) return -1;
    
    string ss = a+a;
    return ((ss.find(b) != std::string::npos) ? 1:-1);
    //return 0;
}

void test(){
    string ta = "abcd";
    string tb = "cdab";
    cout<<std::string::npos<<endl;
    cout<<isRotateString(ta, tb)<<endl;
    cout<<isRotateString("aaaa", "bbbb")<<endl;
    cout<<isRotateString("abcd", "acbd")<<endl;
}
#endif /* RotateString_h */
