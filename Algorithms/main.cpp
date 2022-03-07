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


// Sort vector using Bubble technique
template<typename T>
vector<T> sort_bubble(vector<T> &v){
    T value_tmp;
    
    if(v.empty()) return v;
    
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
    
    return v;
    
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
    
    printv(v1);
    
    sort_bubble(v1);
    
    printv(v1);
    
    
    
    
    return 0;
}
