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

void format_output(int i,string answer)
{
	cout << answer << endl;
}

string solve()
{
	long N;
	cin >> N;
	long factor_5 = 5;
	long zeros = 0;
	while (factor_5 <= N){
		zeros += N / factor_5;
		factor_5 *= 5;
	}
	std::ostringstream convert_stream;
	convert_stream << zeros;
	return convert_stream.str();
}

void format_output(int i,string answer);
string solve();
int main(int argc, char *argv[]){
	long tc;
	cin >> tc;
	for (long i = 0; i < tc; i++)
	{
		format_output(i,solve());
	}
}

