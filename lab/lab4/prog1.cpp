#include <iostream>
#include <array>
using namespace std;

void isPrime(int testNumber[]);

int main() {
    int testNumber[10] = {5,8,21,23,77,101,103,107,299,1001};

    isPrime(testNumber);
}

void isPrime(int testNumber[]) {
    for(int i=0; i<10; i ++) {
        int primecheck = 0;
        if((testNumber[i] % 2) == 0) {
            cout << testNumber[i] << " is NOT prime." << endl;   
        }
        else {
            for(int j=3; j<testNumber[i]; j++) {
                if((testNumber[i] % j) == 0) {
                    primecheck++;
                }
            }
            if(primecheck == 0) {
                cout << testNumber[i] << " is in fact prime." << endl;   
            }
            else {
                cout << testNumber[i] << " is NOT prime." << endl;   

            }
        }
    }

}
