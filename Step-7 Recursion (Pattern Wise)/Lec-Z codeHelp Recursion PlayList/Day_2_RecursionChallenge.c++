//Recusrion Day-2 Challenge | Understanding Recursion


#include<bits/stdc++.h>
using namespace std;


// Level-0 for understanding
void reachHome(int src, int dest) {
    // just 4 checking recursion
    cout << "source " << src << " destination " <<dest <<endl;

    //base Case
    if (src == dest) {
        cout << "Reached Home" <<endl;
        return;
    }

    // processing - ek step aage badhjao
    src++;

    //Recursuve Relation
    reachHome(src, dest);
}







int main() {

// Level-0
    int dest = 10, src = 1;
    cout << endl;
    reachHome(src, dest);


    return 0;
}





