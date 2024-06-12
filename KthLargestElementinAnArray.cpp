#include<bits/stdc++.h>
using namespace std;

// K'th Smallest => Use MAX Heap
int k_smallest(vector<int> &v, int k){
    priority_queue<int> pq;             // By default it's MAX Heap
    int n = v.size();
    for(int i=0; i<n; i++){
        pq.push(v[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

// K'th Largest => Use MIN Heap
int k_largest(vector<int> &v, int k){
    priority_queue<int, vector<int>, greater<int>> pq;      // Creating MIN Heap
    int n = v.size();
    for(int i=0; i<n; i++){
        pq.push(v[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int n;  cin>>n;
    int k;  cin>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << "Kth Smallest Element : " << endl;
    cout << k_smallest(v, k) << endl;
    cout << "Kth Largest Element : " << endl;
    cout << k_largest(v, k) << endl;
    return 0;
}