#include <iostream>
#include <cmath>
using namespace std;

/*
Convert 34 to Binary

Convert 22 to Binary

Convert 1001 to Decimal

Convert 111011 to Decimal

Add 11 and 1110 in Binary, Return the Answer in Binary

Add 1010 and 111 in Binary, then Convert the Answer to Decimal
*/

int decToBin(int dec);
int binToDec(int bin);
int addBin(int bin1, int bin2);

int main(){
    cout << "34 in binary is " << decToBin(34) << endl;
    cout << "22 in binary is " << decToBin(22) << endl;
    cout << "1001 in decimal is " << binToDec(1001) << endl;
    cout << "1111011 in decimal is " << binToDec(1111011) << endl;
    cout << "11 + 1110 = " << addBin(11, 1110) << endl;
    cout << "1010 + 111 in decimal = " << binToDec(addBin(1010, 111)) << endl;
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

int binToDec(int bin){
    int dec = 0, i = 0;
    while(bin > 0) {
        dec += ((bin%10)*pow(2.0, static_cast<double>(i)));
        bin = bin/10;
        i++;
    }
    return dec;
}

int addBin(int bin1, int bin2){
    int bin = 0, rem=0;
    double  i=0.0;
    while(bin1%10 !=0 || bin2&10 !=0) {
        if(bin1%10 == 1 && bin2%10 == 1) {
            if(rem == 0) {
                bin += 0 * pow(10.0, i);
                rem = 1;
                
            }
            else {
                bin += 1 * pow(10.0, i);
                rem = 1;
            }
        }
        else if(bin1%10 == 0 && bin2%10 == 0) {
            bin += (0 + rem) * pow(10.0, i);
            rem = 0;
        }
        else {
            if(rem == 0) {
                bin += 1 * pow(10.0, i);
                rem = 0;
            }
            else {
                bin += 0 * pow(10.0, i);
                rem = 1;
            }
        }
        bin2 = bin2/10;
        bin1 = bin1/10;
        i++;
    }
    bin += (rem) * pow(10.0, i);
/*
    while(bin1%10 !=0 || bin2&10 !=0) {
        bin += ((bin1%10 + bin2%10 + rem ) % 2) * (pow(10.0, static_cast<double>(i)));
        rem = (((bin1%10)*pow(2.0, static_cast<double>(i))) + ((bin2%10)*pow(2.0, static_cast<double>(i))) + rem ) / 2;
        
        bin2 = bin2/10;
        bin1 = bin1/10;
        i++;
    }
    */

    return bin;
}

