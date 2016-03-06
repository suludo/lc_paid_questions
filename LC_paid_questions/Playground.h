//
//  Playground.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 2/27/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef Playground_h
#define Playground_h

#include <iostream>
#include <utility>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

#define A(i) i*2
#define B(i) i*3
#define str(x) #x
#define str2(x,y) y##x

void test1(){
    cout<<A(1)<<" "<<B(1)<<endl;
    int i = 3;
    cout<<str(i)<<endl;
    int a = 1, b=2;
    str2(out,c)<<" aa"<<endl;
}



void test2(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    
    std::move(dq.front());
    cout<<dq.size()<<" "<<dq.front()<<endl;
    
}
//test priority queue comparator
struct Point{
    int x;
    int y;
    Point(int _x, int _y):x(_x),y(_y){}
};
class comp{
public:
    bool operator()(const Point&a, const Point& b) const{
        return a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y;
    }
};
void test(){
    priority_queue<Point, vector<Point>, comp> q;
    Point p1(1,1);
    Point p2(2,2);
    Point p3(3,3);
    Point p4(-4,-4);
    q.push(p1);
    q.push(p3);
    q.push(p2);
    q.push(p4);
    while(q.empty()==false){
        cout<<q.top().x<<" "<<q.top().y<<endl;
        q.pop();
    }

}

#endif /* Playground_h */
