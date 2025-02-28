// Knowing Basic Maths 4 DSA

#include <bits/stdc++.h>
using namespace std;

int main()
{

	// DIGITS Concept
	// (Number of digits)  https://www.naukri.com/code360/problems/number-of-digits_9173?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/* // Soln of Num of digits
	int countDigits(int n){
		// Write your code here.
			int count = 0;
			while(n > 0){
				count = count + 1;
				n = n/10;
			}
			return count;
	}
	*/

	// Reverse of a number
	// https://www.naukri.com/code360/problems/reverse-of-a-number_624652?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/* // Soln of Rev of a Num

	int n;
		cin >> n;
		int revNum = 0;
		while(n > 0){
			int lastdigit = n%10;
			revNum = (revNum*10) + lastdigit;
			n = n/10;
		}
		cout << revNum;
	*/

	// Palindrome Num
	// https://www.naukri.com/code360/problems/palindrome-number_624662?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/*
	bool palindrome(int n)
	{
		// Write your code here
		int dup = n;
		int revNum = 0;
		while(n>0){
			int ld = n%10;
			revNum = (revNum * 10) + ld;
			n=n/10;
		}
		if(dup == revNum) {
			return true;
		}
		else {
			return false;
		}
	}
	*/

	// Armstrong Number
	// https://www.naukri.com/code360/problems/check-armstrong_589?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/*
	bool checkArmstrong(int n){
		//Write your code here
		int dup=n;
		int sum = 0;
		int digits = log10(n) + 1;
		while(n>0) {
			int ld = n%10;
			sum = sum + pow(ld, digits);
			n=n/10;
		}
		if(sum == dup){
			return true;
		} else {
			return false;
		}
	}
	*/

	// PRINT ALL DIVISIONS
    // https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/*
	BETTER APPROACH:
	In this approach, we will check till square root of n

	Watch the video from here:
	https://youtu.be/1xNbjMdbjug?si=kvRb4gHxxG8aje2C&t=1812

	So suppose the number is 16

	1 x 16
	2 x 8
	4 x 4   # After this numbers repeat
	8 x 2
	16 x 1

	So there are 2 sections, so instead of looping from 1 to n
	We can loop from 1 to sqrt of n


	So we loop till sqrt of n because after that the divisors repeat

	The divisors will be i and n/i
	For example, if i = 2, then n/i = 16/2 = 8

	CASE:
	There can be case where 6x6=36
	So the divisor can repeat here, so we will have to check this

	*/

	/*

	int* printDivisors(int n, int &size){
	// Write your code here
		int *listt = new int[n];
		size = 0;

		for(int i=1; i <= sqrt(n); i++) { // or v can use i*i <=n; bcz sqrt is function & it call every time & inc memory & runtime i.e it is better 2 use
			if(n%i == 0){
				listt[size] = i;
				size++;

				// add n/i to the list only if i NOT EQUAL to n/i
				if(i != n/i){
					listt[size] = n/i;
					size++;
				}
			}
		}
// sort function is used 4 sorting the list elements
		sort(listt, listt+size);
		return listt;

	*/

	// CHECK PRIME
	// https://www.naukri.com/code360/problems/check-prime_624674?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/*
	// Write your code here
		int n;
		cin >> n;
		int cnt = 0;
		for(int i=1; i*i <= n; i++) {
			if(n%i==0) {
				cnt++;
				if((n/i) != i) cnt++;
			}
		}
		if(cnt == 2) cout << "true";
		else cout << "false";
	*/

	// GCD or HCF(Euclidean Algo)
	// https://www.naukri.com/code360/problems/gcd_6557?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

	/*

		int gcd(int a,int b) // TC of gcd = O(log phi min(a,b))
	{
		//Write your code here
		while(a > 0 && b > 0) {
			if(a > b){
				a = a%b;
			}
			else {
				b = b%a;
			}
		}

		if(a == 0) {
			return b;
		}
		else {
			return a;
		}

	}

	*/

	return 0;
}
