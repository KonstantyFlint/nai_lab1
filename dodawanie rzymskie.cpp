#include <iostream>

using namespace std;

string 	r[]={"I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M","MM","MMM"};
int		d[]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,2000,3000};
int size=30;

int getDig(string fff)
{
	for(int i=0;i<size;i++)
	{
		if(fff==r[i])return d[i];
	}
	return 0;
}

int decode(string fff)
{
	if(fff.size()==0)return 0;
	int sum=0;
	string test="";
	int savecount=0;
	int savedig=0;
	for(int i=0;i<4;i++)
	{
		test+=fff[i];
		int d=getDig(test);
		if(d)
		{
			savecount=i;
			savedig=d;
		}
	}
	if (savedig==0)return -1;
	string rest="";
	for(int i=savecount+1;i<fff.size();i++)rest+=fff[i];
	return savedig+decode(rest);
}

string getcode(int x)
{
	for(int i=0;i<size;i++)
	{
		if(x==d[i])return r[i];
	}
	return "";
}

string encode(int num)
{
	if(num<=0 or num>3999)return "XD";
	int t;
	int s;
	int d;
	int j;
	t=(num/1000)*1000;
	num-=t;
	s=(num/100)*100;
	num-=s;
	d=(num/10)*10;
	num-=d;
	j=num;
	return getcode(t)+getcode(s)+getcode(d)+getcode(j);
}

int main(int argc, char ** argv)
{
	string a,b;
	cin>>a>>b;
	if(encode(decode(a))!=a){cout<<"XD";return 1;}
	if(encode(decode(b))!=b){cout<<"XD";return 1;}
	cout<<encode(decode(a)+decode(b));
}
