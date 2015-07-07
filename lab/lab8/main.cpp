#include<iostream>
#include <cmath>

using namespace std;

void getHamm(int hammArr[]);
void sendHamm(int hammDec, int hammErr);
void intToArr(int hamm, int hammArr[]);
int binToDec(int bin);
int decToBin(int dec);



int main(){
    //corrected hamming code
    //print decimal num
    int hammDec[5] = {15, 7, 12, 2, 6};
    int hammErr[5] = {4,1,0,6,2};

    for (int i=0; i<5; i++){
        cout << i+1 << ")" << "\nOriginal number: ";
        sendHamm(hammDec[i], hammErr[i]);
    }
}

void sendHamm(int hammDec, int hammErr) {
    int hammArr[7];
    int bin[3];
    int error[2];
    //print decimal num
    cout << hammDec << endl;

    //correct hamming code
    hammDec = decToBin(hammDec);
    for (int i=6; i>=0; i--) {
        if(i == 0 || i == 1 || i==3) {
           hammArr[i] = 0; 
        }
        else {
            hammArr[i] = hammDec % 10; 
            hammDec = hammDec/10;
        }
    }
    cout << "Correct Hamming Code: ";
    for(int j=0; j<7; j++) {
        cout << hammArr[j];
    }
    cout << endl;

    //put error in hamming code
    hammErr = decToBin(hammErr);
    cout << hammErr << endl;
    for (int i=6; i>=0; i--) {
        if(i == 0 || i == 1 || i==3) {
            hammArr[i] = hammErr % 10; 
            hammErr = hammErr/10;
        }
    }


    getHamm(hammArr);
    
}

void getHamm(int hammArr[]) {
    int hammDec = 0, errBit=0, errLoc=0;

    //Print the Original Code
    cout << "The Received Hamming Code:" ;
    for(int i=0; i<7; i++) {
        cout << hammArr[i];
    }
    cout << endl;

    //look for the error bit in the hamming code and store it in errBit
    errLoc += ((hammArr[0] + hammArr[2] + hammArr[4] + hammArr[6]) % 2) * 100;
    cout << errLoc << endl;
    errLoc += ((hammArr[1] + hammArr[2] + hammArr[5] + hammArr[6]) % 2) * 10;
    cout << errLoc << endl;
    errLoc +=  (hammArr[3] + hammArr[4] + hammArr[5] + hammArr[6]) % 2;
    cout << errLoc << endl;
    errLoc = binToDec(errLoc);
    cout << errLoc << endl;
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

int decToBin(int dec){
    int bin = 0, i=0;
        
    while(dec > 0) {
        if(dec%2 == 0){
            bin += 0;
            i++;
        }
        else{
            bin += 1 * pow(10, static_cast<double>(i));
            i++;
        }
        dec = dec/2;
    }
    return bin;
}

