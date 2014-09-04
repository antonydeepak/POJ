#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<iomanip>
#include<locale>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

#define PI 3.14159265

void solve()
{
	long n;
	cin >> n;
	int height = 0;
	long n_two_prime_factorials = 2;
	while (!(n % n_two_prime_factorials)){
		n_two_prime_factorials *= 2;
		height++;
	}
	printf("%ld %ld\n", (n - (long)(pow(2, height) - 1)), (n + (long)(pow(2, height) - 1)));
	//cout << n - (pow(2, height) - 1) << " " << n + (pow(2, height) - 1) << endl;
}

int main(int argc, char *argv[]){
	long tc;
	cin >> tc;
	for (long i = 0; i < tc; i++)
	{
		solve();
	}
}

