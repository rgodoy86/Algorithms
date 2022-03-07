//
//  main.cpp
//  Algorithms
//
//  Created by Raphael Godoy on 07.03.22.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function to print vector values
template<typename T>
void printv(vector<T> &v){
    if(v.empty()) return;
    
    for(T &item : v){
        cout << item << " ";
    }
    cout << endl;
}


// Bubble Sort
template<typename T>
void sort_bubble(vector<T> &v){
    T value_tmp;
    
    if(v.empty()) return;
    
    unsigned long repeat = v.size()-1;
    unsigned long last_index = v.size()-1;
    
    while(repeat > 0){
        for(int i=0; i < last_index; ++i){
            if(v.at(i) > v.at(i+1)){
                value_tmp = v.at(i+1);
                v.at(i+1) = v.at(i);
                v.at(i) = value_tmp;
            }
        }
        --repeat;
        --last_index;
    }
}

// Merge Sort
// O(n logn) time
// O(n) space
template <typename T>
void merge(vector<T> &v, vector<T> &v_left, vector<T> &v_right){
    unsigned long  v_size = v.size();
    unsigned long  v_left_size = v_left.size();
    unsigned long  v_right_size = v_right.size();
    unsigned long  i_left=0, i_right=0, i_merged=0;
    
    // Compare the first indexes and see which one is the smalles one
    while(i_left < v_left_size && i_right < v_right_size){
        if(v_left.at(i_left) <= v_right.at(i_right)){
            v.at(i_merged) = v_left.at(i_left);
            ++i_left;
        }else{
            v.at(i_merged) = v_right.at(i_right);
            ++i_right;
        }
        ++i_merged;
    }
    
    // Fill the remaining left part
    while(i_left < v_left_size){
        v.at(i_merged) = v_left.at(i_left);
        ++i_left;
        ++i_merged;
    }
    
    // Or fill the remianing right part
    while(i_right < v_right_size){
        v.at(i_merged) = v_right.at(i_right);
        ++i_right;
        ++i_merged;
    }
}

template <typename T>
void sort_merge(vector<T> &v){
    unsigned long vector_size = v.size();
    
    if(vector_size < 2) return;
    
    unsigned long index_mid = vector_size / 2;
    
    vector<T> v_left(index_mid);
    vector<T> v_right(vector_size - index_mid);
    
    // Split into vector_left and vector_right
    for(int i = 0; i < vector_size; ++i){
        if (i < index_mid){
            v_left.at(i) = v.at(i);
        }else{
            v_right.at(i-index_mid) = v.at(i);
        }
    }
    
    // Split each vector
    sort_merge(v_left);
    sort_merge(v_right);
    
    merge(v, v_left, v_right);
}

int main() {
    // insert code here...
    vector<int> v1;
    
    // Create vector with random numbers
    srand((int)time(0));
    int i = 0;
    while(i++ < 10){
        v1.push_back(rand() % 100);
    }
    
    auto v2 = v1;
    
    cout << "Original Vector: ";
    printv(v1);
    
    cout << "Sort Bubble: ";
    sort_bubble(v1);
    printv(v1);
    
    cout << "Sort Merge:  ";
    sort_merge(v2);
    printv(v2);
    
    return 0;
}
