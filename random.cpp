#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

using std::vector;

bool in_table(vector<int> table, int num){
    int i;
    for(i = 0; i<table.size();i++){
        if(table[i] == num) return 1;
    }
    return 0;
    
}


int main(int argc, char *argv[1]){
    int size = atoi(argv[1]);
    int bfr;
    vector<int> pagetable;
    
    int index;
    int checkcount = 0;
    int faultcount = 0;
    
    int seed = time(NULL);
    srand(seed);
    
    
    while (!cin.eof()){
        cin>>bfr;
        
        if(!in_table(pagetable, bfr)){
            if(pagetable.size()>=size){
                index = rand()%size;
                pagetable[index] = bfr;
            }
            else if(pagetable.size()<size){
                pagetable.push_back((int)bfr);
            }
            faultcount++;
        }
        
        checkcount++;
        
        
        
    }
    cout<<"Requests:"<<checkcount<<' ';
    cout<<"Faults:"<<faultcount<< '\n';
    return 0;

    
    
}