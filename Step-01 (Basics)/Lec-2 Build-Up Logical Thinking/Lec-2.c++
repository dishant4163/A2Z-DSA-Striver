// Pattern Question | 22 Patterns__Striver-A2Z DSA

/*   4 Rules for Pattern

1)  for the outer loop, count the no. of lines(row)

2)  for the inner loop, focus on the columns & convert them somehow to the rows

3)  Print them inside the inner 'for loop'

4)  Obsereve symmetry (optional)

*/

#include <bits/stdc++.h>
using namespace std;

/*// Pattern-1
void print1(int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "*";
        }
        cout << endl;
    }
}
*/

/*// Patern-2
void print2(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
*/

/*// Pattern-3
void print3(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++){
            cout << j <<" ";
        }
        cout << endl;
    }
}
*/

/*// Pattern-4
void print4(int n) {
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
*/

/*// # Pattern-5
void print5(int n) {
    for(int row=1; row<=n; row++) {
        for(int col=1; col<=n-row+1; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}
*/

/*// # Pattern-6
void print6(int n) {
    for(int row=1; row<=n; row++) {
        for(int col=1; col<=n-row+1; col++) {
            cout << col << " ";
        }
        cout << endl;
    }
}
*/

/*// ### Pattern-7
void print7(int n) {
    for(int i=0; i<n; i++){
        // SPACE
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        // STAR
        for(int j=0; j< 2*i+1; j++) {
            cout << "*";
        }
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
*/

/*// ### Pattern-8
void print8(int n) {
    for(int i=0; i<n; i++) {
        // SPACE
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        // STAR
        for(int j=0; j<2*n-(2*i+1); j++){
            cout << "*";
        }
        // SPACE
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
*/

/*// ### Pattern-9
void print9(int n){
    // UPPER Diamond
    for(int i=0; i<n; i++){
        // SPACE
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        // STAR
        for(int j=0; j< 2*i+1; j++) {
            cout << "*";
        }
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        cout << endl;
    }

    // LOWER Diamond
    for(int i=0; i<n; i++) {
        // SPACE
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        // STAR
        for(int j=0; j<2*n-(2*i+1); j++){
            cout << "*";
        }
        // SPACE
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        cout << endl;
    }

}
*/

/*// ###imp-> Pattern-10
void print10(int n) {
    for (int row=1; row<=2*n-1; row++) {
        int stars = row;
        if(row > n){
            stars = 2*n - row;
        }
        for(int col=1; col<=stars; col++) {
            cout << "*";
        }
        cout << endl;
    }
}
*/

/*// ###imp-> Pattern-11
void print11(int n) {
    int start = 1;
    for(int i=0; i<n; i++) {
        if(i%2 == 0) { // check if even row start with 1
            start = 1;
        }
        else {
            start = 0;
        }
        for(int j=0; j<=i; j++) {
            cout << start << " ";
            start = 1 - start; // 4 flip 0 to 1 vice-versa
        }
        cout << endl;
    }
}
*/

/*// ###imp Pattern-12
void print12(int n) {
    int space = 2* (n-1);
    for(int i=1; i<=n; i++){
        // numbers in original order 4 1st triangle
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        // space
        for(int j=1; j<=space; j++) {
            cout << " ";
        }

        // numbers but in reverse order 4 other triangle
        for(int j = i; j >= 1; j--) { // decrement order
            cout << j << " ";
        }
        cout << endl;
        space -= 2;
    }
}
*/

/*// Pattern-13
void print13(int n) {
    int num = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << num << " " ;
            num ++;
        }
        cout << endl;
    }
}
*/

/*// ### Pattern-14 (char)
void print14(int n){
    for(int i=0; i<n; i++) {
        for(char ch='A'; ch<='A'+i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
*/

/*// ### Pattern-15(reverse of 14)
void print15(int n) {
    for(int i=0; i<n; i++){
        for(char ch='A'; ch<= 'A' + (n - i - 1); ch++) {
            cout << ch <<" ";
        }
        cout << endl;
    }
}
*/

/* ### // Pattern-16
void print16(int n) {
    for(int i=0; i<n; i++) {
        char ch = 'A'+i;
        for(int j=0; j<=i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
*/

/*// ###Vimp Pattern-17
void print17(int n) {
    for(int i=0; i<n; i++) {
        // SPACE
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }

        // CHARACTERS
        char ch = 'A';
        int breakpoint = (2*i + 1) / 2;
        for(int j=1; j<=2*i+1; j++) {
            cout << ch << " ";
            if(j <= breakpoint){
                ch++;
            }
            else {
                ch--;
            }
        }


        // SPACE
        for(int j=0; j<n-i-1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
*/

/* ### // Pattern-18
// n=5
// E
// D E
// C D E
// B C D E
// A B C D E
void print18(int n) {
    for(int i=0; i<n; i++) {
        for(char ch='E'-i; ch <= 'E'; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
*/

/*// ### Vimp Pattern-18.2
// n=3 (https://www.naukri.com/code360/problems/alpha-triangle_6581429?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems)
// C
// C B
// C B A

void print18_2(int n) {
    for(int i=0; i<n; i++) {
        for(char ch = 'A'+n-1; ch>= 'A'+n-i-1; ch--) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
*/

/*// ##### Vimp Pattern-19
void print19(int n) {

    // UPPER PArt
    int initSpace = 0;// initial space 4 upper part
    for(int i=0; i<n; i++) {
        // STARS
        for(int j=1; j<=n-i; j++) {
            cout << "* ";
        }

        // SPACES
        for(int j=0; j < initSpace; j++){
            cout << " ";
        }

        // STARS
        for(int j=1; j<=n-i; j++) {
            cout << "* ";
        }
        initSpace += 2;
        cout << endl;
    }

    // LOWER Part
    initSpace = 2*n - 2;
    for(int i=1; i<=n; i++) {
        // STARS
        for(int j=1; j<=i; j++) {
            cout << "* ";
        }

        // SPACES
        for(int j=0; j<initSpace; j++) {
            cout << " ";
        }

        // STARS
        for(int j=1; j<=i; j++) {
            cout << "* ";
        }
        initSpace -= 2;
        cout << endl;
    }
}
*/

/*// ##### Vimp Pattern-20
void print20(int n) {
    int spaces = 2*n - 2; // no. of spaces
    for(int i=1; i<=2*n-1; i++) { // 2*n-1 is no. of row
        int stars = i; // no. of stars
        if(i > n) stars = 2*n - i;
        // STARS
        for(int j=1; j<=stars; j++) {
            cout << "*";
        }
        // SPACES
        for(int j = 1; j<= spaces; j++) {
            cout << " ";
        }
        // STARS
        for(int j=1; j<=stars; j++) {
            cout << "*";
        }
        cout << endl;
        if(i < n) {
            spaces -= 2;
        }
        else {
            spaces += 2;
        }
    }
}
*/

/*// ### Pattern-21
    void print21(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (i == 0 || j == 0 || i == n-1 || j == n-1){
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
*/

// Dabbang-1_Pattern-22
void print22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << (n - min(min(top, down), min(left, right)));
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;

    /*// Pattern 1
        print1(n);
    */

    /*// Pattern 2
        print2(n);
    */

    /*// Pattern 3
        print3(n);
    */

    /*// Pattern 4
        print4(n);
    */

    /*// Pattern 5
        print5(n);
    */

    /*// Pattern 6
        print6(n);
    */

    /*// Pattern 7
        print7(n);
    */

    /*// Pattern 8
        print8(n);
    */

    /*// Pattern 9
        print9(n);
    */

    /*// Pattern 10
        print10(n);
    */

    /*// Pattern 11
        print11(n);
    */

    /*// Pattern 12
        print12(n);
    */

    /*// Pattern 13
        print13(n);
    */

    /*// Pattern 14
        print14(n);
    */

    /*// Pattern 15
        print15(n);
    */

    /*// Pattern 16
        print16(n);
    */

    /*// Pattern 17
        print17(n);
    */

    /*// Pattern 18
        print18(n);
    */

    /*// Pattern 18.2
        print18_2(n);
    */

    /*// Pattern 19
        print19(n);
    */

    /*// Pattern 20
    print20(n);
*/

    /*// Pattern 21
    print21(n);
*/

    // Pattern 22
    print22(n);

    return 0;
}