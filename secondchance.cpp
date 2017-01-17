#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

using std::vector;

bool in_array(int arr[],int size, int num){
    int i;
    for (i=0;i<size;i++){
        if(arr[i] == num) return 1;
    }
    return 0;
    
}


int main(int argc, char *argv[]){
    
    int i;
    int j=0;
    //char bfr[100];
    //string bfr="hi";
    int bfr;
    int temp;
    int size = atoi(argv[1]);
    int pagetable[size];
    int reference[size];
    int checkcount=0;
    int faultcount=0;
    int tablesize = 0;
    
    /*initialize reference bits*/
    for(j=0;j<size;j++){
        reference[j] = 0;
    }
    
    for(j=0;j<size;j++){
        pagetable[j] = -1;
    }
    
    bool inserts;
    int firstIndex = 0;
    
    while(!cin.eof()){
        
        inserts = false;
        cin>>bfr;
        
        
        if(!in_array(pagetable, size, bfr) && tablesize>=size){
            faultcount++;
            cout<<bfr<<endl;
            while (inserts == false){
                
                   if(reference[firstIndex]==0){
                       pagetable[firstIndex] = bfr;
                       reference[firstIndex] = 1;
                       inserts = true;
                       firstIndex=(firstIndex+1)%size;
                   }
                   else{
                       reference[firstIndex] = 0;
                       
                       firstIndex=(firstIndex+1)%size;
                
                   } /* end if-else */
                
            } /* end while */
            
        }/* end if check for in array */
        
        else if(tablesize<size && !in_array(pagetable,size,bfr)){
            pagetable[firstIndex] = bfr;
            reference[firstIndex] = 1;
            firstIndex=(firstIndex+1)%size;
            faultcount++;
            tablesize++;
            
        }
        
        if(in_array(pagetable, size, bfr)){
            for(i = 0; i<tablesize;i++){
                if(pagetable[i] == bfr){
                    reference[i] = 1;
                }
            }
        }
        
        
        checkcount++;
        
        
        
    }



/*
    for(j=0;j<size;j++){
        cerr<<pagetable[j]<<' ';
    } */
    
    cout<<checkcount<<endl;
    cout<<faultcount<<endl;
    
    
    return 0;
    

    
}
