#include <iostream>
#include <deque>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct page{
    int val;
    int freq;
};


int main(int argc, char*argv[]){
    
    int size = atoi(argv[1]);
    deque<page> pagetable(size);
    deque<page>::iterator it;
    
    int faultcount = 0;
    int checkcount = 0;
    
    page temp;
    
    for(it = pagetable.begin(); it!=pagetable.end();it++){
        it->val = 0;
        it->freq = 0;
    }
    
    int bfr;
    bool found;
    
    while (!cin.eof()){
        cin>>bfr;
        found = 0;
        //Find and move if found
        for(it = pagetable.begin(); it!= pagetable.end(); it++){
            if(it->val ==  bfr){
                found = 1;
                
                temp.val = bfr;
                temp.freq = it->freq+1;
                
                pagetable.erase(it);
                pagetable.push_front(temp);
                break;
            }
        }
        
        if (!found){
            while (pagetable.size() == size){
                deque<page>::iterator min;
                min = pagetable.begin();
                for(it = pagetable.begin(); it!= pagetable.end(); it++){
                    if(it->freq <= min->freq){
                        min = it;
                    }
                }
                pagetable.erase(min);
            }
            
            temp.val = bfr;
            temp.freq = 1;
            
            pagetable.push_front(temp);
            faultcount++;
            
        }
        
        checkcount++;
        
        
        
    }
    
    cout<<"Faultcount: "<<faultcount<<' ';
    cout<<"Checkcount: "<<checkcount<<endl;
    
    
    
    
}