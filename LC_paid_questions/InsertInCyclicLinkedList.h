//
//  InsertInCyclicLinkedList.h
//  LC_paid_questions
//
//  Created by Xiaorui Zhao on 3/6/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef InsertInCyclicLinkedList_h
#define InsertInCyclicLinkedList_h


//http://articles.leetcode.com/insert-into-a-cyclic-sorted-list/

#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int v, Node* n=NULL):val(v),next(n){}
};

void print(Node* n){
    Node* prev = NULL;
    Node* p = n;
    while(p){
        cout<<p->val;
        
        if(prev && prev->next==n)
            break;
        else
            cout<<"->";
        
        prev = p;
        p=p->next;
    }
    if(!p) cout<<"  NOT A CYCLIC LINKED LIST!!";
    cout<<endl;
}

Node* InsertInCyclicLinkedList(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        newNode->next = newNode;
        head = newNode;
        return newNode;
    }
    Node* p = head;
    Node* prev = NULL;
    
    while(p->next){
        prev = p;
        p = p->next;
        
        if(p==head) break;
        if(prev->val > p->val) break;
        if(prev->val<=val && p->val>=val) break;
    }
    
    if(!p->next){
        cout<<"wrong!! non-cyclic"<<endl;
        return NULL;
    }
    prev->next = newNode;
    newNode->next = p;
    return newNode;
}

void test(){
    //regular, insert in the middle, 3
    Node* h1 = new Node(0);
    Node* n11 = new Node(1);
    Node* n12 = new Node(2);
    Node * n13 = new Node(4);
    h1->next = n11;
    n11->next = n12;
    n12->next = n13;
    n13->next = h1;
    
    // 5 && end, 6
    Node* h2 = new Node(5);
    Node* n21 = new Node(5);
    Node* n22 = new Node(5);
    h2->next = n21;
    n21->next = n22;
    n22->next = h2;
    
    // start, 6
    Node* h3 = new Node(7);
    Node* n31 = new Node(8);
    Node* n32 = new Node(9);
    Node * n33 = new Node(10);
    h3->next = n31; n31->next = n32; n32->next = n33; n33->next=h3;
    
    //non-cyclic linked list
    Node* h4 = new Node(-2);
    Node* n41 = new Node(-1);
    Node* n42 = new Node(0);
    h4->next = n41; n41->next = n42;
    
    
    
    Node* h = NULL;
    print(h);
    InsertInCyclicLinkedList(h, 0);
    print(h);
    
    InsertInCyclicLinkedList(h, 1);
    print(h);
    
    
    
    print(h1);
    InsertInCyclicLinkedList(h1, 3);
    print(h1);
    
    print(n21);
    InsertInCyclicLinkedList(n21, 5);
    print(n21);
    
    print(n32);
    InsertInCyclicLinkedList(n32, 6);
    print(n32);
    
    print(h4);
    InsertInCyclicLinkedList(h4, 0);
    print(h4);
    
    
}



#endif /* InsertInCyclicLinkedList_h */
