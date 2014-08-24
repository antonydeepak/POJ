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
#define INF 1000003

long not_primes[INF] = { 0 };

void generate_primes()
{
	int k;
	for (long i = 2; i <= (double)sqrt(INF-1); i++){
		if (!not_primes[i]){
			k = 1;
			for (long j = i*i; j <= INF-1; j = i*i + i*k){
				not_primes[j] = 1;
				k++;
			}
		}
	}
}

void solve(long n)
{
	for (long i = 3; i <= n / 2 + 1; i += 2)
	{
		if (!not_primes[i]){
			if (!not_primes[n - i]){
				printf("%ld = %ld + %ld\n", n, i, n - i);
				return;
			}
		}
	}
	cout << "Goldbach's conjecture is wrong." << endl;
}


int main(int argc, char *argv[]){
	generate_primes();
	long n;
	while (scanf("%ld",&n) && n!=0)
	{
		solve(n);
	}
}