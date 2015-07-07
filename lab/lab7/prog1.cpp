#include<iostream>
#include <cmath>

using namespace std;

void getHamm(int hammBin);
void intToArr(int hamm, int hammArr[]);
int binToDec(int bin);

int main(){
    int hammBin = 0;
    getHamm(1101010);
    getHamm(10111);
    getHamm(1010101);
    getHamm(1001001);
    getHamm(110011);

}

void intToArr(int hamm, int hammArr[]) {
    for (int i=6; i>=0; i--) {
        hammArr[i] = hamm % 10; 
        hamm = hamm/10;
    }
}

int binToDec(int bin){
    int dec = 0, i = 0;
    while(bin > 0) {
        dec += ((bin%10)*pow(2.0, static_cast<double>(i)));
        bin = bin/10;
        i++;
    }
    return dec;
}

void getHamm(int hammBin) {
    int hammDec = 0, errBit=0, errLoc=0;
    int hammArr[7];


    //convert the binary number into an array of ints
    intToArr(hammBin, hammArr);

    //Print the Original Code
    cout << "The original code is " ;
    for(int i=0; i<7; i++) {
        cout << hammArr[i];
    }
    cout << endl;

    //look for the error bit in the hamming code and store it in errBit
    errLoc += ((hammArr[0] + hammArr[2] + hammArr[4] + hammArr[6]) % 2) * 100;
    errLoc += ((hammArr[1] + hammArr[2] + hammArr[5] + hammArr[6]) % 2) * 10;
    errLoc +=  (hammArr[3] + hammArr[4] + hammArr[5] + hammArr[6]) % 2;
    errLoc = binToDec(errLoc);
    if(errLoc == 0){
        cout << "There is no error. Yay!" << endl << "The original code is correct." << endl;

    }
    else{
        cout << "The error is at place " << errLoc << endl;

        //swap the error
        if(hammArr[errLoc-1] == 0) {
            hammArr[errLoc-1] = 1;
        }
        else {
            hammArr[errLoc-1] = 0;
        }

        //Print the correct code
        hammBin = 0;
        cout << "The correct code is " ;
        for(int i=0; i<7; i++) {
            cout << hammArr[i];
        }
        cout << endl;
    }

    //print the message
    hammDec = (hammArr[2] * 1000) + (hammArr[4] * 100) + (hammArr[5] * 10) + hammArr[6] ;
    cout << "The message is " << binToDec(hammDec) << endl << endl;

}
