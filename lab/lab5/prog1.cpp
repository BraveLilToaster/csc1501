#include <iostream>
using namespace std;

void bruteForce(int& x);
void formula(int& x);

int main() {
    int x;
    cout << "All numbers between one and x will be added. Enter x: ";
    cin >> x;
    bruteForce(x);
    formula(x);
}

void bruteForce(int& x) {
    int count = 0, sum=0;
    for(int i=0; i<x; i++){
        sum += (i+1);
        count = count + i;
    }
    cout << "Brute Force:\n" << "The sum is " << sum << " and the number of operations is " << count << endl;
}

void formula(int& x) {
    int count=3, sum;
    sum = (x*(x+1))/2;
    
    cout << "Formula:\n" << "The sum is " << sum << " and the number of operations is " << count <<  endl;
}
