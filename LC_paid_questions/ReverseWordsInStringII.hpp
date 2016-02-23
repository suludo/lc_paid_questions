//
//  ReverseWordsInStringII.hpp
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 2/22/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef ReverseWordsInStringII_h
#define ReverseWordsInStringII_h

/*
http://www.cnblogs.com/EdwardLiu/p/4306561.html
 
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
 */

#include <algorithm>
#include <string>

using namespace std;

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    for (int i = 0, j = 0; i < s.size(); i = j + 1) {
        for (j = i; j < s.size() && !isblank(s[j]); ++j);
        reverse(s.begin()+i, s.begin()+j);
    }
}

#endif /* ReverseWordsInStringII_h */
