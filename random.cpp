#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long unsigned int rd(long long unsigned int min, long long unsigned int max)
{
	return rand()%(max-min+1)+min;
}

int main()
{
	srand(time(NULL));
	int sum[21]={};
	for(int i=0;i<1000000;i++)sum[rd(9876543210,9876543230)-9876543210]++;
	for(int i=0;i<21;i++)cout<<sum[i]<<endl;
	int SSUUMM=0;
	for(int i=0;i<21;i++)SSUUMM+=sum[i];
	return 0;
}
