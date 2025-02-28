// Complete C++ STL (Standard Template Library 4 DSA)
/* C++ STL has 3 major components:

#    Containers
#    Iterators
#    Algorithms

*/

#include<bits/stdc++.h>
using namespace std;


/*// PAIRS (it is a part of utility library)

void explainPair() {

    pair<int, int> p = {1, 2};

    cout << p.first << " " << p.second;

    pair<int, <int, int>> p = {3, {4, 5}};

    cout << p.first << " " << p.second.second << " " << p.second.first;

    pair<int, int> arr[] = { {1, 2}, {3, 4}, {5, 6} };

    cout << arr[1].second;
}
*/


 // VECTORS (It is container {learning 1st container})

void explainVector() {

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);// same as push_back

    vector<pai><int, int>vec;

    v.push_back({1, 2});
    v.emplace_back{1, 2};

    vector<int> v(5, 100); //creates 5 instance of 100 in vector container like-> [100,100,100,100,100]

    vector<int> v(5); // creates 5 instance of garbage values

    vector<int> v1(5, 20);
    vector<int> v2(v1); // creates copy v1 for v2 with another container

// how to access elements in vector

    vector<int>::iterator it = v.begin();// iterator points the elememt where it lies

    it++;
    cout<< *(it) << " ";// this * access the vector element inside it

    it = it + 2;
    cout << *(it) << " ";

// Some other Iterators in Vectors
    // r means reverse
    vector<int>::iterator it = v.end();//here end does not means last element in memory but last space after the assign container

    vector<int>::iterator it = v.rend();
//  rend & rbegin rarely 
    vector<int>::iterator it = v.rbegin();

    cout << v[0] << " " << v.at(0);

    cout << v.back() << " ";

*

/* Printing of VECTOR


// printing vector
    for (vector::iterator it = v.begin(); it != v.end(); i++) {// '!=' means does not
        cout << *(it) << " ";
    }

// Shortcut of above lenghty line code for vector iterator using "auto"

    for (auto it = v.begin(); it != v.end(); i++) {
        cout << *(it) << " ";
    }

// Another Shortcut is using "for each loop"

    for (auto it : v) {
        cout << it << " ";
    }

*/



/* // ERASE in Vector

// {10, 20, 22, 35} -> before
v.erase(v.begin()+1); // afetr erase {10, 22, 35}, +1 erases '20'

// {10, 20, 30, 40, 50}
v.erase(v.begin() + 2, v.begin() + 4); //after {10,20,50} [start, end)

*/



/* // INSERT Function

vector<int> v(2, 100); // {100, 100}
v.insert(v.begin(), 300);// {300, 100, 100}
v.insert(v.begin() +1, 2, 10); // {300, 10, 10, 100, 100}

*/



/* // COPY Function

vector<int> copy(2, 50); // before-> {50, 50}
v.inser(v.begin(), copy.begin(), copy.end()); // after-> {50, 50, 300, 10, 10, 100, 100}

// some other functions of vector

// {10, 20}
cout << v.size(); // how many elements in vector

// {10, 20}
v.pop_back(); // {10} delete last element in vector

// before swap v1-> {10, 20} , v2-> {30, 40}
v1.swap(v2); // after v1 -> {30, 40}, v2-> {10, 20}

// erase the entire vector
v.clear();

cout << v.empty(); // check for vector is empty or not

} // 4 expVect

*/



/*// LIST in Vector
// same as vector but gives 'front' operation as well
void explainList() {
    list<int> ls;

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5, 2, 4}

    ls.emplace_front(); // {2, 4}

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

}

*/



/*// DQ in Vector

void explainDeque() {

    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4); //{4, 1, 2}
    dq.emplace_front(3); // {3, 4, 1, 2}

    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4, 1}

    dq.back(); 

    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

}

*/



/*// STACK in Vector (LIFO)
// NOTE:- TC in stack for all operation(push, pop, etc) happens in O(1) i.e, constant time

void explainStack() {
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // prints 5

    st.pop(); // delete upper element from stack & looks like {3, 3, 2, 1}

    cout << st.top(); // 3

    cout << st.size(); // 4

    cout << st.empty(); // checks is stack empty or not?

    stack<int> st1, st2;
    st.swap(st2);

}

*/



/*// QUEUE in Vector (FIFO)
// TC for all operation in Q happens is O(1)

void explainQueue() {
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(4); // {1, 2, 4}


    // Before-> {1, 2, 4}
    q.back() += 5;// After-> {1, 2, (4+5)} ie, Q is {1, 2, 9}

    cout << q.back(); // prints 9

    cout << q.front(); // prints 1

    q.pop(); // delete 1st element from Q ie, {2, 9}

    cout << q.front(); // prints 2

    // size swap empty same as stack 

}

*/



/*// PRIORITY Queue
//****TC 4 PQ for Push & POP is O(logn) and for TOP is O(1)
// Largest Value stays at Top

void explainPQ() {
    priority_queue<int> pq;
// This Maximum HEAP (max heap)
    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // prints 10

    // size swzp empty functions same as others


    // ***Minimum HEAP (min heap) *** i.e mini elements at TOP
    priority_queue<int, vector<int>, greater<int>> pq;// datatype, vector,  greater Int
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // prints 2

}

*/



/*// SET in Vector
// Set **stores sorted order & uniue** elements in it.
// TC 4 all operations for SET is O(logn)

    void explainSet() {
        set<int>set1;
        set1.insert(1); // {1}
        set1.emplace(2); // {1, 2}
        set1.insert(2); // only unique no duplicates ie. {1, 2}
        set1.insert(4); // {1, 2, 4}
        set1.insert(3); // {1, 2, 3, 4}

    // Functionality of insert in vector
    // can be used also, that only increases eficiency

    // begin(), end(), rbegin(), rend(), size(), empty()
    // & swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = set1.find(3); // returns iterator which pts to 3

    // {1, 2, 3, 4, 5}
    auto it = set1.find(6); // 6 is not in set so after 5 it prints set1.end() 5 it.

    // before-> {1, 4, 5}
    set1.erase(5); // erases 5 & maintainece sorted order // logarithmic time


// COUNT in SET
    int cnt = set1.count(1);// if exits it have 1 occurance either 0


// ERASE in SET
    auto it = set1.find(3);
    set1.erase(it); // takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = set1.find(2);
    auto it2 = set1.find(4);
    set1.erase(it1, it2); // after erase {1, 4, 5} [first, last)


    // lower_bound() & upper_bound() function works in the same way as in vector it does.

    // This is the syntax
    auto it = set1.lower_bound(2);

    auto it = set2.upper_bound(3);

    }

*/



/*// MULTISET in Vector
    // Everything in same as SET & stores duplicates element 

void explainMultiSet() {

    multiset<int>mst;
    mst.insert(1); // {1}
    mst.insert(1); // {1, 1}
    mst.insert(1); // {1, 1, 1}

    mst.erase(1); // all 1's erased

    int cnt = mst.count(1);

    //only a single one erased
    mst.erase(mst.find(1));

    mst.erase(mst.find(1), mst.find(1)+2);
    // rest all functions are same as set

}

*/



/*// UNORDER SET in Vector
// TC for UnSet in most of the cases is O(1)

void explainUnorderSet() {
    unorder_set<int> ust;
    // lower_bound & upper_bound function does not work
    // rest all functions are same as above
    // does not stores in any particular order
    // has better complexity then set in most cases
    // except some when collision happens for worst case goes O(n) rarely occurs!

}

*/



/*// MAP in Vector
// TC of Map is O(logN)
void explainMap() {

    map<int, int> mpp;

    map<int, pair<int, int>> mpp;

    map< pair<int, int>, int> mpp;

    mpp[1] = 2;
    mpp.emplace({3, 2});

    mpp.insert({2, 4});

    mpp.[{2, 3}] = 10;

    for(auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5]; // if something not exit in map prints as null or 0

    auto it = mpp.find(3);
    cout << *(it).second;

    auto it = mpp.find(5); //if 5 is not here then pts to mpp.find() i.e, after the Map


    // this is the syntax 
    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // earse swap size empty are same as above

}

*/



/*// MULTI_MAP in Vector

void explainMultiMap() {
    // everything same as map
    // it can store multiple keys i.e duplicates keys-> {1, 2}, {1, 3}
    // only map[key] cannot be used here
}


void explainUnorderedMap() {
    // same as set & unordered_set difference.
    // uniques key but not sorted
    // almost all cases work in O(1) but in Worst ie rarely O(N)
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // if they are same

    if(p1.first > p2.first) return true;
    return false;
}

*/





/*// Mandatory ALGO for C++_STL

void explainExtra() {

    sort(a, a + n);
    sort(v.begin(), v.end());

    sort(a+2, a+4);

    // sort in descending order-> {1,3,5,2} before
    sort(a, a+n, greater<int>);// after-> {5,3,2,1} here greater is automatically comparetor

// Sorting in my way

    pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};

    // sort it acc. to 2nd element
    // if second element is same then sort
    // acc. to first element but in descending

    sort(a, a+n, comp); // comp is self written comparitor & it is boolean function in code line-446

    // {4,1}, {2,1}, {1,2}

*/


/*// BUILT_IN_POP_COUNT in C++ STL 

    int num = 7;
    int cnt = __builtin_popcount();

    long long num = 165786578687;
    int cnt = __builtin_popcountll();


    string s = "123";
    sort(s.begin(), s.end());

    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a, a+n);

}

*/

int main () {

    return 0;
}