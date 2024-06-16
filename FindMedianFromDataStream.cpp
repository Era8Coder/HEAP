#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxheap;        // MaxHeap
    priority_queue<int,vector<int>,greater<int>> minheap;           // MinHeap

public:
    MedianFinder() {
        //   
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();

        // Balance the sizes of the heaps
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        int max = 0;
        int min = 0;
        if(maxheap.size() > 0){
            max = maxheap.top();
        }
        if(minheap.size() > 0){
            min = minheap.top();
        }

        if(maxheap.size() == minheap.size()){
            return (max + min)/(2.0);
        }else{
            return max;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){

    return 0;
}