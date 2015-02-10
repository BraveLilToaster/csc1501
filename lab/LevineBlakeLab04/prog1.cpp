/* Assignment 4 - Converting Binary and Decimal
CSC 1501 – Assignment 4

Converting Binary and Decimal

(Due: 2/10/15 at the End of Class)
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int convertToBin(int num1, int ans, int bina[]);
int convertToDec(int num1, int ans, int bina[]);
int addBin(int num1, int num2, int ans, int bina[]);

int main(){
    int num1, num2, ans = 0;
    int bina[10];

    num1 = 34;
    cout << num1 << " in binary is " << convertToBin(num1, ans, bina) << endl;

    num1 = 22;
    cout << num1 << " in binary is " << convertToBin(num1, ans, bina) << endl;

    num1 = 1001;
    cout << num1 << " in decimal is " << convertToBin(num1, ans, bina) << endl;

    num1 = 111011;
    cout << num1 << " in decimal is " << convertToBin(num1, ans, bina) << endl;

    num1 = 11;
    num2 = 1110;
    cout << num1 << " + " << num2 << " in Binary is " << convertToDec(addBin(num1, num2, ans, bina), ans, bina) << endl;

    num1 = 1010;
    num2 = 111;
    cout << num1 << " + " << num2 << " in Binary is " << addBin(num1, num2, ans, bina) << endl;
}


int convertToBin(int num1, int ans, int bina[]){
    for(int i = 10; i >= 0; i--){
        if(pow(2.0, static_cast<double>(i)) <= num1){
            num1 = num1 % static_cast<int>(pow(2.0, static_cast<double>(i)));
            bina[i] = 1;
        }
        else{
            bina[i] = 0;
        }
    }

    for(int i = 10; i >= 0; i--){
        ans = 10 * ans + bina[i];
    }

    return ans;
}
int convertToDec(int num1, int ans, int bina[]){
    string bin = to_string(num1);
    cout << bin;

    int factor = 1;
    for(int i = 0; i < bin.length(); i++){
	if(bin.at(i) == 1){
	    ans += factor;
	}	
	factor *= 2;
    }
    return ans;
}
int addBin(int num1, int num2, int ans, int bina[]){
   num1 = convertToDec(num1, ans, bina);
   num2 = convertToDec(num2, ans, bina);
   ans = num1 + num2; 
   return ans;
}
