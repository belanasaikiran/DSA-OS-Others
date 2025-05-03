// Correlate data from 2 separate logs, parse and store them using hashmap of
// lists so you can look it up in O(1) time later.
//

#include <iostream>
#include <unordered_map>

// A.log -> a b c b a b
// B.log -> b a c a a c


void storeMap(int *fp1, int *fp2, unordered_map<int, char> cp){

    while(readof(fp1) == readof(fp2)){

       cp.insert((int) fp1, *fp1 );

    }

}



void retrieveMap(char* c, <u_mp> cp){
    if(cp.find(c) != mp.end()){
        return cp.value();
    }
}


int main(){

    unordered_map<int, char> cp;

    // Open the File 1
    int *fd1 = fopen('A.log', 'r');
    int *fd2 = fopen('B.log', 'r');

    storeMap(fd1, fd2, &cp);

}
