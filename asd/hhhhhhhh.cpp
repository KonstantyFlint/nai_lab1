#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

char worksSoFar(int begin, string soFar, string target)
{
	int m=soFar.size();
	int n=target.size();
	if(m>n)return 0;				//dlugosc jest wieksza niz target
	
	bool good=1;
	for(int i=begin;i<m;i++)
	{
		if(soFar[i]!=target[i])
		{
			good=0;
			break;
		}
	}
	if(!good)return 0;				//stringi sie roznia
	else
	if(m==n)return 100;				//dokladnie takie same, taka sama dlugosc
	else	return 1;				//takie same poczatki, target jest dluzszy
}

bool test(string dict[],int dSize,string soFar,string target)
{
	for(int i=0;i<dSize;i++)
	{
		string newTry=soFar+dict[i];
		char out=worksSoFar(soFar.size()+1,newTry,target);
		if(out==0)continue;			//nie brnie dalej, bo juz sie rozni od targetu
		else
		if(out==100)				//znalazl target, koniec programu
		{
			return true;	
		}
		
		else//out=1
		{
			return test(dict,dSize,newTry,target);	//jak na razie dziala, wiec sprawdza o 1 poziom glebiej
		}
	}
	return 0;	//przeszedl przez wszystkie mozliwe koncowki i zadna nie pasuje
}

bool test(string target,string dict[],int dSize)
{
	return test(dict,dSize,"",target);
}

int main()
{
	string A;
	string B[10];
	int wCount=20;
	int c=0;
	
	ifstream fA;fA.open("A.txt");
	ifstream fB;fB.open("B.txt");
	
	//getline(fA,A);cout<<A<<endl;
	for(int i=0;i<wCount;i++){getline(fB,B[i]);}
	while(1)
	{
		cin>>A;
		cout<<test(B,10,"",A)<<endl;
	}
}
