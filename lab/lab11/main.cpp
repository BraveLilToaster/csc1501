#include<iostream>
#include<stdlib.h>
using namespace std;

int rando();

int main() {
    int password[4];
    int guess[4];
    int ignore[4];
    int correct = 0, location = 0, guess1;
    bool ans = false;
    srand(time(NULL));
    for(int i=0; i<4; i++) {
        password[i] = rando();
    }
    cout << endl;
    
    cout << "Try and guess my 4 digit password. I'll only use the numbers 1-6." << endl;

    do {
        //reset ignore array, correct and location counters
        for (int g=0; g<4; g++) {
            ignore[g] = password[g];   
            cout << password[g];
        }
        cout <<endl;
        correct = 0;
        location = 0;

        //input guess
        for(int y=0; y<4; y++) {
            cin >>guess[y];
        }

        //check results
        for(int j=0; j<4; j++) {

            //check for # of correct
            if(password[j] == guess[j]) {
                ignore[j] = 0;
                correct++;   
            }

            //check for # of wrong location 
            else {
                for(int k=0; k<4; k++) {
                    if(ignore[k] == guess[j]) {
                        ignore[j] = 0;
                        location++; 
                    }
                }
            }
        }

        //check answer and respond
        if (correct < 4) {
            cout << endl << correct << " correct." << endl;
            cout << location << " in wrong location." << endl;
            cout << "Thats not right. Try again" << endl;
        }
        else {
            ans = true;
        }
    }
    while (!ans);

    cout << "You have bested me. NOOOOOOOOOO!!!" << endl;

}

int rando(){
    return (rand() % 6 + 1)  ;
}
