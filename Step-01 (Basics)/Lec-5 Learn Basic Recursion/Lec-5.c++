// Intro to Recursion
//->5.1_Some Basic problem based on recursion

#include <bits/stdc++.h>
using namespace std;

// a. Print Name 5 Times using RECURSION.
void func1(int i, int n1){

    // BASE COndition.
    if(i>n1) return;
    cout<< "Dishant" <<endl;

    //call func to print till i increment
    func1(i+1, n1);
}


// b. Print Linearly from 1 to N.
void func2(int i, int n2){

    // BASE Condition
    if(i>n2) return;
    cout << i << endl;

//call the func to print i values incremently till n
    func2(i+1, n2);
}


//# c. Print from N to 1. imp
void func3(int i, int n3){
    // BASE Condition
    if(i < 1) return;
    cout << i << endl;

    //Call the func to print in reverse order
    func3(i - 1, n3);
}

// ANOTHER WAY 3.2
//void func3_2(int i, int n3_2){
    //BASE Condition
//    if(i>n3_2) return;
    //call func to print (i+1) integers.
//    func3_2(i+1, n3_2);
//    cout << i << endl;
}



// ### d. Print Linearly from 1 to N (by using BACKTRACKING)**Imp
void func4(int i, int n4) {
    //BASE Condition
    if(i < 1) return;

    // call the func for backtrack to print linearly 1 to n
    func4(i - 1, n4);
    cout << i << endl;
}


// e. Print from N to 1 (By Backtracking)
void func5(int i, int n5){
    //BASE Condition
    if(i == 0) return;
    cout << i << endl;
    i--;

    // call func to print n to 1
    func5(i , n5);

}


//-> 5.2_Sum of first N numbers
// 5.2_1. Parameterised Way
void func6(int i, int sum){
    if(i < 1){
        cout << "sum of first N numbers is " <<sum << endl;
        return;
    }
    func6(i-1, sum+i);
}


// 5.2_2. FUNCTIONAL Recursion Way
    int sum2(int n6_2){
        if(n6_2 == 0){
            return 0;
        }
        else{
            return n6_2 + sum2(n6_2 - 1);
        }
    }


//-> 5.3_Factorial of N numbers
// Recursive
    int facto(int n7){
        if(n7 == 0){
            return 1;
        }
        else {
            return n7 * facto(n7 - 1);
        }
    }


//-> 5.4_Reverse an Array
// 1. Recursive method
//Approach: The recursive method has an approach almost similar to the iterative one. The approach has been broken down into some steps for simplicity.
//   -> Create a function that takes an array, start index, and end index of the array as parameters.
//   -> Swap the elements present  at the start and end index,
//   -> The portion of the array left to be reversed is arr[start+1,end-1]. Make a recursive call to reverse the rest of the array. While calling recursion pass start +1  and ends - 1 as parameters for the shrunk array. Repeat step 2.
//   -> Continue recursion as long as the ‘start < end’ condition is satisfied. This is the base case for our recursion.

// Function to print array
void printArr(int arr[], int n8) {
    cout << "Reversed Array is " << endl;
    for(int i=0; i<n8; i++) {
        cout << arr[i]<< " ";
    }
}

// Function to Reverse Array using Recursion
void revArr(int arr[], int start, int end) {
    if(start < end) {
        swap(arr[start], arr[end]);
        revArr(arr, start+1, end-1);
    }
}



// ANOTHER Way to Reverse Array
// 2. Using single Pointer for Swapping element of array in Recursive Way

void revvArr(int i, int arry[], int n9) {
    if(i >= n9/2) {
        return;
    }
    else {
        swap(arry[i], arry[n9-i-1]);
        revvArr(i+1, arry, n9);
    }
}



//-> 5.5_Check if the given String is Palindrome or not

    bool palin(int i, string &s) {
        if(i >= s.size() / 2){
            return true;
        }
        if(s[i] != s[s.size() - i -1]){
            return false;
        }
        return palin(i+1, s);
    }


//-> 5.6_FIBONACCI Number
    int fibonacci(int n10){
        // BASE Condition
        if(n10 <= 1){
            return n10;
        }

        // problem broken down into 2 function calls & their result combined & returned
        int last = fibonacci(n10 - 1);
        int secondlast = fibonacci(n10 - 2);

        return last + secondlast;
    }


int main()
{

    // problem 1 soln
        int n1;
        cin >> n1;
        func1(1, n1);

    

    // problem 2 soln
        int n2;
        cin >> n2;
        func2(1, n2);
    

    // problem 3 soln
        int n3;
        cin >> n3;
        func3(n3, n3);

    // ANOTHER WAY 3_2
    //    int n3_2;
    //    cin >> n3_2;
    //    func3_2(1, n3_2);

    

    // problem 4 soln
        int n4;
        cin >> n4;
        func4(n4, n4);
    

    // problem 5 soln
        int n5, i;
        cin >> n5;
        i = n5;
        func5(i, n5);
    

    // problem Soln 5.2_1
    int n6;
    cin >> n6;
    func6(n6, 0);

    // Another way to sol 5.2_2
    int n6_2;
    cin >> n6_2;
    cout << sum2(n6_2);


    // problem Soln 5.3
    int n7;
    cin >> n7;
    cout << "factorial of " << n7 << " is " << facto(n7);


    // peoblem Soln 5.4
    int n8;
    cin >> n8 ;
    int arr[] = {11, 23, 39, 51, 72};
    revArr(arr, 0, n8-1);
    printArr(arr, n8);


    // Another Way to solve 5.4_2
    int n9;
    cin >> n9;
    int arry[n9];
    for(int i=0; i<n9; i++){
        cin >> arry[i];
    }
    revvArr(0, arry, n9);
    // print the reverse array
    for(int i=0; i<n9; i++){
        cout << arry[i] << " ";
    }


    // problem Soln 5.5
    string s;
    cin >> s;
    cout << palin(0, s);


    // problem 5.6
    int  n10;
    cin >> n10;
    cout << fibonacci(n10) << endl;


    return 0;
}
