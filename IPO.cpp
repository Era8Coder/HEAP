#include<bits/stdc++.h>
using namespace std;

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vp;
        int n = profits.size();
        for(int i=0; i<n; ++i){
            vp.push_back(make_pair(capital[i],profits[i]));
        }        
        // Sorting the projects on the basis of capital requirement
        sort(vp.begin(), vp.end());

        priority_queue<int> maxheap;
        int i = 0;

        while(k>0){
            // Adding all the projects that can be added to the current capital {Affordable Ones}
            while(i<n && vp[i].first <= w){
                maxheap.push(vp[i].second);
                ++i;
            }

            if(maxheap.empty()){            // If we can't extract any element
                // If no project can be undertaken -->> Break Out the loop 
                break;
            }

            w += maxheap.top();         // Now in the range of affordable ones Therefore we will take all the projects with the maximum profit ones :)
            maxheap.pop();
            --k;
        }

        return w;
    }

int main(){
    int n;  cin>>n;
    int k;  cin>>k;
    int w;  cin>>w;
    vector<int> profits(n);
    vector<int> capital(n);
    for(int i=0; i<n; i++){
        cin >> profits[i];
    }
    for(int j=0; j<n; j++){
        cin >> capital[j];
    }
    cout << findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}
