

A.txt - shared file

T1, T2, T3 - A.txt


// T1 executes openfile
//

bool opened;

void openfile(char &inputfile){
    // create mutex lock - hold this resource - A.txt
    //
    // if(!opened){
    // opened = true;
    // open the file A.txt.
    //
    // end -> openend = false;
    // }

}

// if T2 executes openfile -> crash
//
// wait() or spinlock()
//
//
// If more variable exist than availble register, what does compiler do ? - register spilling ?



// --- ReAttempt
