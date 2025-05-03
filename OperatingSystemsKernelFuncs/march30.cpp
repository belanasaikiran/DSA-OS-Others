// Write a function that scans a given C++ source code file and identifies
// potential buffer overflows


#include <cstdio>


bool ScanBufOVerflow(FILE *fp){
    // fp is A.cpp
    vector<vector<typechar>> arrayStorage;

    while(!fp.empty()){

        if(line.datatype == array){
            arrayStorage.push_back(line);
        }

        if(element is accessing array){
            if(array exists in arrayStorage){
                if(value > arrayStorage[line].size()){
                fclose(fp);
                    return false;
                }
            }
        }

    }

    // int buffer[10];
    // buffer[11] = 2;


    fclose(fp);
    return true;
}

int main(){

    FILE *fp = fopen('A.cpp', 'r');

    bool didItWork  = ScanBufOVerflow(fp);
    if(!didItWork){
        cout << "There is an issue with the code";
    } else {
        cout << "No issues";
    }

    return 0;
}
