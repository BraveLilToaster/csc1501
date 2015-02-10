/*
 * Assignment: Create a program which is capable of assembling and displaying various sets I will provide you with. The program must correctly display the result of operators on sets (such as Union and Intersection), and in addition it must do the following two things: First, it must NOT repeat any values that might appear more than once. So if you Union two sets together that each have the number ‘5’ somewhere in them, then ‘5’ should only appear ONCE in the resulting set. Second, if the resulting thread is empty, your program must indicate the empty thread in some recognizable manner, such as displaying “Empty Thread” or “E” or something similar. Below are the threads you will use. Also assume that the A group comprises ‘reality’ so to speak, the numbers 1-10 being all elements possible, such that the INVERSE of A, is the empty thread. Thus if you were asked to compute the INVERSE of B, it would be equivalent to saying “Set A minus Set B”. For this exercise, we will represent inverse with the ! symbol. (100pts total: 60 for program, 5 per problem)

A = {1,2,3,4,5,6,7,8,9,10}

B = {2,4,6,8,10}

C = {1,3,5,7,9}

D = {1,2,3,5,7}

Problem 1.)  A n D

Problem 2.) ( B U C ) n  A

Problem 3.) (!C U  C) n  A

Problem 4.) A – D

Problem 5.) N(!A U ( C U  D))

Problem 6.) B n C

Problem 7.) N(B n  C)

Problem 8.) A U  B U  C U  D

A reminder, N() indicates the SIZE of the resulting set. So if you have a set such as A = {1,3,7,10} then N(A) = 4. For problems asking for N(), your result should be a single number indicating the resulting set’s size. Finally, a basic hint to help with this assignment: You may find arrays to be useful.

 */
#include <iostream>
using namespace std;

void uni(int a1[], int a2[], int o[]);
void intert(int a1[], int a2[], int o[]);
void notx(int a1[], int o[]);
void printans(int o[]);

//the Omega array
int o[10];
int temp1[10];
int temp2[10];
//the other arrays
int a[11] = {1,2,3,4,5,6,7,8,9,10,-1};
int b[6] = {2,4,6,8,10,-1};
int c[6] = {1,3,5,7,9,-1};
int d[6] = {1,2,3,5,7,-1};

int main(){

    //Problem 1.)  A n D
    cout << "Problem 1: ";
    intert(a, d, o);
    printans(o);

    //Problem 2.) ( B U C ) n  A
    cout << "Problem 2: ";
    uni(b, c, temp);
    intert(temp1, a, o);
    printans(o);
        
    //Problem 3.) (!C U  C) n  A
    cout << "Problem 3: ";
    notx(c, temp1);
    uni(temp1, c, temp2); 
    intert(temp2, a, o);
    printans(o);
        
    //Problem 4.) A – D
    cout << "Problem 4: ";
    intert(a, d, o);
    printans(o);
        
    //Problem 5.) N(!A U ( C U  D))
    cout << "Problem 5: ";
    intert(a, d, o);
    printans(o);
        
    //Problem 6.) B n C
    cout << "Problem 6: ";
    intert(a, d, o);
    printans(o);
        
    //Problem 7.) N(B n  C)
    cout << "Problem 7: ";
    intert(a, d, o);
    printans(o);
    
    //Problem 8.) A U  B U  C U  D
    cout << "Problem 8: ";
    intert(a, d, o);
    printans(o);
}

//union function
void uni(int a1[], int a2[], int o[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < 10){
        if(a1[i] > a2[j]){
            if(a1[i] == -1) continue;
            o[k] = a1[i];
            i++;
            k++;
        }
        else if(a1[i] < a2[j]) {
            o[k] = a2[j];
            j++;
            k++;
        }
        else {
            o[j] = a2[j];
            i++;
            k++;
        }
    }
}

//print, then clear the omega array and temp array
void printans(int o[]) {
    for(int i=0; i<10; i++){
        if(o[i] == -1) break;
        else if(o[i] != 0) {
            cout << o[i] << ", ";
        }
    } 
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
        o[i] = 0;
        temp[i] = 0;
    }
}

//intersect function
void intert(int a1[], int a2[], int o[]){
    for(int j = 0; j < 10; j++){
        if(a1[j] == -1) break;
        for(int i = 0; i < 10; i ++){
            if(a2[i] == -1) break;
            else if(a1[j] == a2[i]){
                o[j] = a1[j];
            }
        }
    }        
}

//not function
void notx(int a1[], int o[]){
    for(int j = 0; j < 10; j++){
        if(a1[j] == -1) break;
        else if(o[j] == a1[j]){
            o[j] = 0;
        }
    }        
}
