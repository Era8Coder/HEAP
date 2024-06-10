#include<bits/stdc++.h>
using namespace std;
// HERE WE ARE IMPLEMENTING MIN HEAP <<--

class heap{
    private:
        vector<int> v;

    public:
        heap() : v{}{

        }

        int get_parent_idx(int i){
            return (i-1)/2;
        }

        int get_left_child(int i){
            return 2*i+1;
        }

        int get_right_child(int i){
            return 2*i;
        }

        void insert(int val){
            v.push_back(val);
            heapifyUp(v.size() - 1);
        }

        void heapifyUp(int index){
            if(index == 0){
                return;
            }
            
            int parent_idx = get_parent_idx(index);
            
            if(v[parent_idx] > v[index]){           // Creating a Min - Heap 
                swap(v[parent_idx],v[index]);
                heapifyUp(parent_idx);
            }
        }

        int get_size(){
            return v.size();
        }

        void heapifyDown(int idx){
            int left_child = get_left_child(idx);
            int right_child= get_right_child(idx);
            if(left_child >= v.size()){
                return;             // No CHildren Are Present
            }

            int min_idx = idx;

            if(v[min_idx] > v[left_child]){
                min_idx = left_child;
            }

            if(right_child < v.size() && v[min_idx] > v[right_child]){
                min_idx = right_child;
            }

            if(min_idx != idx){
                swap(v[min_idx], v[idx]);
                heapifyDown(min_idx);
            }
        }

        void delete_min(){
            if(v.size() == 0){
                cout << "Heap is Empty" << endl;
                return;
            }

            swap(v[0],v[v.size()-1]);
            v.pop_back();

            heapifyDown(0);
        }

        int get_min(){
            if(v.size() == 0){
                return -1;
            }
            return v[0];
        }
};

int main(){
    heap hp;
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        hp.insert(v[i]);
    }
    cout << hp.get_min() << endl;
    hp.delete_min();
    cout << hp.get_min() << endl;
    return 0;
}