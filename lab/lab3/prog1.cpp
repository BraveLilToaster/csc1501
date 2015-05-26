/*

A = {1,2,3,4,5,6,7,8,9,10}

B = {2,4,6,8,10}

C = {1,3,5,7,9}

D = {1,2,3,5,7}

 */
#include <iostream>
#include <array>
using namespace std;

void intert(int a1[], int a2[], int master[], int temp1[]);
void uni(int a1[], int a2[], int master[], int temp1[]);
void notx(int a1[], int temp[]);
void subtract(int a1[], int a2[], int master[], int temp1[]);
void printans(int temp[]);
void printanslength(int temp[]);

//the Omega array
int master[10] = {1,2,3,4,5,6,7,8,9,10};
int temp1[10];
int temp2[10];
//the other arrays
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int b[10] = {0,2,0,4,0,6,0,8,0,10};
int c[10] = {1,0,3,0,5,0,7,0,9,0};
int d[10] = {1,2,3,0,5,0,7,0,0,0};

int main(){

    //Problem 1.)  A n D
    cout << "Problem 1.)  A n D " << endl;
    intert(a, d, master, temp1);
    printans(temp1);

    //Problem 2.) ( B U C ) n  A
    cout << "Problem 2.) ( B U C ) n  A " << endl;
    uni(b, c, master, temp1);
    intert(temp1, a, master, temp1);
    printans(temp1);
        
    //Problem 3.) (!C U  C) n  A
    cout << "Problem 3.) (!C U  C) n  A " << endl;
    notx(c, temp1);
    uni(temp1, c, master, temp1); 
    intert(temp1, a, master, temp1);
    printans(temp1);
        
    //Problem 4.) A – D
    cout << "Problem 4.) A – D " << endl;
    subtract(a, d, master, temp1);
    printans(temp1);
        
    //Problem 5.) N(!A U ( C U  D))
    cout << "Problem 5.) N(!A U ( C U  D)) " << endl;
    uni(c, d, master, temp1);
    notx(a, temp2);
    uni(temp2, temp1, master, temp1);
    printanslength(temp1);
        
    //Problem 6.) B n C
    cout << "Problem 6.) B n C " << endl;
    intert(b, c, master, temp1);
    printans(temp1);
        
    //Problem 7.) N(B n  C)
    cout << "Problem 7.) N(B n  C) " << endl;
    intert(b, c, master, temp1);
    printanslength(temp1);
    
    //Problem 8.) A U  B U  C U  D
    cout << "Problem 8.) A U  B U  C U  D " << endl;
    uni(a, b, master, temp1);
    uni(temp1, c, master, temp1);
    uni(temp1, d, master, temp1);
    printans(temp1);
}

//intersect function
void intert(int a1[], int a2[], int master[], int temp1[]){
	for(int i = 0; i < 10; i ++) {
		if (a1[i] != 0 && a2[i] != 0) {
			temp1[i] = master[i];
		}
	}
}

//union function
void uni(int a1[], int a2[], int master[], int temp1[]){
	for(int i = 0; i < 10; i ++) {
		if (a1[i] != 0 || a2[i] != 0) {
			temp1[i] = master[i];
		}
	}
}

//not function
void notx(int a1[], int temp[]){
    for(int j = 0; j < 10; j++){
        if(a1[j] != 0){
		temp[j] = 0;
        }
	else {
		temp[j] = 1;
	}
    }        
}

//subtract function
void subtract(int a1[], int a2[], int master[], int temp1[]) {
	for(int i = 0; i < 10; i ++) {
		if (a1[i] != 0 && a2[i] != 0) {
			temp1[i] = 0;
		}
		else {
			temp1[i] = master[i];
		}
	}
	
}

//print, then clear the omega array and temp array
void printans(int temp[]) {
    for(int i=0; i<10; i++){
	if (temp[i] != 0) {
		cout << temp[i] << " ";
	}
        temp1[i] = 0;
        temp2[i] = 0;
    } 
    cout << endl << endl;
}

//Print length
void printanslength(int temp[]) {
	int count = 0;
	for(int i = 0; i < 10; i++){
		if (temp[i] != 0) {
			count++;
		}
        temp1[i] = 0;
        temp2[i] = 0;
	}
	cout << "N = " << count << endl << endl;
}


