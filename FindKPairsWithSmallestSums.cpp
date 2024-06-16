// I had seen the solution I don't have idea It's very good and tough problem :P

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;    // Result Vector to Store The Pairs
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // Priority Queue to store pairs with smallest Sums <<--; Sorted By Sum :)

        // Pushing the Initial Pairs into the priority Queue
        for(auto x : nums1){
            pq.push({x+nums2[0], 0});   // The sum and the index of the second element in nums2
        }

        // Pop the k smallest pairs from the priority queue
        while(k-- && !pq.empty()){
            int sum = pq.top().first;       // get the samllest sum
            int pos = pq.top().second;      // Get the index of the second element in nums

            res.push_back({sum-nums2[pos], nums2[pos]});    // Add the pair to result vector
            pq.pop();       // Remove the pair from priority queue

            // if there are more elements in nums2, push the next pair into the priority queue
            if(pos + 1 < nums2.size()){
                pq.push({sum - nums2[pos] + nums2[pos+1], pos+1});
            }
        }

        return res;         // Returning the K smallest pairs
    }
};

int main(){
    return 0;
}