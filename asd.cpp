#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main(int argc, char ** argv)
{
	int i=0;
	while(argv[0][i]!='\0')i++;
	i-=3;
	argv[0][i]  ='c';
	argv[0][i+1]='p';
	argv[0][i+2]='p';
	ifstream in(argv[0]);
	string a;
	while(getline(in,a))
	{
		cout<<a<<"\n";
	}
	return 0;
}
