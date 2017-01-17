#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

//using std::vector;
using std::list;

bool in_list(std::list<int> list, int num){
    for (std::list<int>::const_iterator iterator = list.begin(), end = list.end(); iterator != end; ++iterator){
        if (*iterator == num) return 1;
    }
    
    return 0;
    
}


//Least recently used at one end of the data structure, most recently used at the other end

int main(int argc, char *argv[1]){
    
    int i;
    int j=0;
    int size = atoi(argv[1]);
    //list<int> used;
    
    int bfr;
    int temp;
    list<int> pagetable;
    
    
    std::list<int>::iterator iterator;
    
    int checkcount = 0;
    int faultcount = 0;
    
    
    
    
    while(!cin.eof()){
        
        cin>>bfr;
        //cout<<bfr<<' ';
        bool found = (std::find(pagetable.begin(), pagetable.end(), bfr) != pagetable.end());
        
        if(!found){
            if(pagetable.size() >= size){
                faultcount++;
                pagetable.pop_front();
                pagetable.push_back((int)bfr);
            }
            else if (pagetable.size() < size){
                faultcount++;
                pagetable.push_back((int)bfr);
                //cout<<pagetable.front();
            }
        }
        else if(found){
            for(iterator=pagetable.begin(); iterator!=pagetable.end(); ++iterator){
                //cout<<"Hi";
                if(*iterator == (int)bfr){
                    pagetable.remove(*iterator);
                    break;
                }
            }
            pagetable.push_back(*iterator);
            
        }
        //cout << "size:"<< pagetable.size()<<' ';
        
        checkcount++;
        
        
        
        
    }
    
    
    
    
    for (std::list<int>::const_iterator iterator = pagetable.begin(), end = pagetable.end(); iterator != end; ++iterator){
        cerr<<*iterator<<' ';
    }
    
    cout<<checkcount<<endl;
    cout<<faultcount<<endl;
    return 0;
    
    
    
}
