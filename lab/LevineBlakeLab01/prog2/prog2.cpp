#include<iostream>
#include<string>
using namespace std;

/**
 * Prompts user to input a string
 * Takes in one string vairable 
 * echo that string
 */
int main(){
    string takeIn;

    cout << "Please input a single word: " ;
    cin >> takeIn;
    cout << endl << "You entered: " << takeIn << endl;

}
