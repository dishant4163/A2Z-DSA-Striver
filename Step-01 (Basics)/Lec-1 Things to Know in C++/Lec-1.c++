// Things to Know in any Programming Language



#include <bits/stdc++.h>
using namespace std;

int main() {

// Basic I/O
int x, y;
cin >> x >> y;
cout << "Value of x: " << x << " & y: " << y;


// Data Types****

// **int
int a = 10;
// long (4 wider range)
long b = 15;
cin >> a;
long long c = 150000000;

// **float, double (4 decimal value)

float d = 5.66;
float e = 5;
double f = 6;
cout << "value of e: " << e;

// string & getline
// NOTE: in string value should initialize in double quotes "" i.e 4 cin values
string s1, s2;
cin >> s1 >> s2;
cout << s1 << " " << s2;
// **another way to get all things from the entire string
string str;
getline(cin, str);
cout << str;

// char
char ch, ch2 = 't';
cin >> ch;
cout << ch << " & value of ch2 is " << ch2;


/*If else Statement */
// 1. Wap that takes an input of age & prints if u are adult or not?

int age;
cin >> age;
if (age>=18) {
    cout << "you are an adult!";
}
else {   // or v can write 'else if(age<18)'
    cout << "you are not an adult!";
}


//2. School has follwing rules for grade system.
// a. Below 25 - F
// b. 25 to 44 - E
// c. 45 to 49 - D
// d. 50 to 59 - C
// e. 60 to 79 - B
// f. 80 to 100 - A
// Ask user to enter marks & print the corresponding grade.


int marks;
cin >> marks;
if(marks < 25){
    cout << "Your grade is F";
}
else if(marks <= 44){
    cout << "Your grade is E";
}
else if(marks <= 49){
    cout << "Your grade is D";
}
else if(marks <= 59){
    cout << "Your grade is C";
}
else if(marks <= 79){
    cout << "Your grade is B";
}
else if(marks <= 100){
    cout << "Your grade is A";
}



//3. Take the age from user & then decide acc.
//1. If age < 18
//    print-> not eliglible for job
//2. If age >= 18 and age <= 54
//    print-> eliglible for job.
//3. If age >= 55 and age <= 57
//    print-> eliglible for job, but retriement soon.
//4. If age > 57
//    print-> retriement time.


int age;
cin >> age;
if(age < 18) {
    cout << "not eliglible for job.";
}
else if(age <= 54){
    cout << "eliglible for job.";
}

else if(age <= 57){
    cout << "eliglible for job, but retriement soon.";
}
// or i.e NESTED if else-if
else if(age <= 57){
    cout << "eliglible for job";
    if(age >= 55) {
        cout << ", but retriement soon.";
   }

}
else {
    cout << "retriement time.";
}


/* SWITCH Statement */
//1. Take the day no & print thr corresponding day for
//1 print Monday, for 2 print Tuesday and so on for 7 print Sunday


    int day;
    cin >> day;

    switch (day){
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
            default:
                cout << "Invalid Case";
    }
    cout << " Check";


// Arrays__(Basic)
// 1D-Array
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    cout << arr[2] << endl;
    // addition in arr[1]
    arr[1] += 6;
    cout << arr[1] << endl;
    // updation in array
    arr[3] = 20 ;
    cout << arr[3] <<endl;
    double ar[3]; // any datatype can be used in array
    cin >> ar[3] ;
    cout << ar[3] << endl;


// 2D-Array
    int arry[3][5];

    arry[1][3] = 99;
    cout << arry[1][3] << endl;
    cout << arry[2][5] << endl; // prt any garbage value


// String
//NOTE:- String store Characters like a,b,c,...z &  A,B,...Z
    string s = "Dishant";
    cout << s << endl;
    // how find size of string
    int len = s.size();
    cout << len << endl;
    // how to find specific charater location using indexing as starts from 0 base in string
    cout << s[0] << " " << s[2] << " " << s[len-1] << endl; // s[len-1] OR s[6] for last character
    // how to update string charaters init.
    s[0] = 'I';//4 updation use single quotes 4 character
    cout << s <<endl;


// FOR Loop
// for loop with statement inside to be in loop
    for(int i=1; i<=5; i++){
        cout <<"Dishant Pal aka Code Hashira!" << endl;
    }

// NOTE:- for printing 'i' value initilize out of scope of for loop i.e given below, i as j with decrement order

    int j;
    for(j=5; j>0; j--){
        cout <<"Dishant Pal aka Code Hashira! " << j << endl;
    }


// WHILE Loop

    int i=1;
    while(i<=5){
        cout << "Hashira " << i << endl;
        i++;
    }

    // do While (it runs code mini 1 time without checking while condition for e.g.,)
    int j = 2;
    do {
        cout <<"Code Hashira " << j << endl;
        j++;
    } while(j<=1);
    cout << j << endl;


/* FUNCTIONS */

// **Pts to Ponder**
// Functions are set of code which performs something for u
// Functions are used to modularies code
// Functions are used to increase readability
// Functions are used to use same code multiple times
// Types of functions:-
// 1) void-> does not return anything
// 2) return
// 3) parameterised
// 4) non parameterised

// Void & Parameterised function
// below e.g., of void & parameterisedfunction
void printName(string name){ //passing parameters in function
    cout << "Hi " << name << endl;
}

int main() {
    string name;
    cin >> name;
    printName(name);

    string name2;
    cin >> name2;
    printName(name2);


// E.g-02 Take 2 nos & print its sum for multiple times
// Return Function

int sum(int num1, int num2){ // Return Function
    int num3 = num1 + num2;
    return num3;
}


int main(){
    int num1, num2;
    cin >> num1 >> num2;
    int result = sum(num1, num2);
    cout << result;


// ANOTHER Way by Void-Return Function(but it cause function overloading)

    void sum(int num1, int num2){
        int num3 = num1 + num2;
        cout << num3;
    }

    int main() {
        int num1, num2;
        cin >> num1 >> num2;
        sum(num1, num2);


/* Pass by Value & Reference */

// Pass by Value (a copy goes go but not original no go it it is in memory )

//eg-1
void doSomething(int num) {
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

int main() {

    int num = 10;
    doSomething(num);
    cout << num << endl;


// eg-2
void doSomething(string s) {
    s[0] = 't';
    cout << s << endl;
}

int main() {
    string s = "raj";
    doSomething(s);
    cout << s << endl;


// Pass by Reference (its takes the original and the address "&" send it)
// eg-1
void doSomething(string &s) { // & get it from the address and pass the original
    s[0] = 't';
    cout << s << endl;
}

int main() {
    string s = "raj";
    doSomething(s);
    cout << s << endl;


// eg-2
void doSomething(int &num){ // pass the reference using '&'
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

int main() {
    int num = 10;
    doSomething(num);
    cout << num << endl;


// Things to Kept in Mind 4 using reference in ARRAYS
// 1. Array always go with pass by REFERENCE


void doSomething(int arr[], int n) {
    arr[0] += 100;
    cout << "Value inside function: " << arr[0] << endl;
}

int main(){
    int n = 5;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    doSomething(arr, n);
    cout << "Value inside int main: " << arr[0] << endl;




    return 0;
}
