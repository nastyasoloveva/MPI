#include <iostream>
#include <algorithm>
using namespace std;
//var14
struct adres
{
	char str[50];
	int h;
};
class Phone
{
private:
	char second_name[30];
	
	char otch[30];
	int number;	
	adres adr;
	
public:
	char first_name[30];
	Phone();
	int in();
	int out();
	void show();
	int time_in,time_out;
};
Phone::Phone()
{
	cout<<"Input SFO:";
	cin >> second_name;
	cin >> first_name;
	cin >> otch;
	cout<<"Input address:";
	cin >> adr.str >> adr.h;
	cout<<"Input number:";
	cin >> number;
	cout<<"Input time of intra-city calls:";
	cin >> time_in;
	cout<<"Input time of long distance calls:";
	cin >> time_out;
}
void Phone::show()
{
	cout<<"SFO: "<< second_name <<" "<< first_name <<" "<< otch<<endl;
	cout<<"address: "<< adr.str <<" "<<adr.h<<endl;
	cout<<"Number: "<< number<<endl<<endl;
}
int Phone::in(){return time_in;}
int Phone::out(){return time_out;}
void spisk_a(Phone spisp[],int &n,int &k)
{
	cout<<"List a"<<endl;
	for (int i = 0; i < k; i++)
	{
		if (spisp[i].in > n)
		{
			spisp[i].show();
		}
	}

}
void spisk_b(Phone spisp[],int &k)
{
	cout<<"List b"<<endl;
	for (int i = 0; i < k; i++)
	{
		if (spisp[i].out > 0)
		{
			spisp[i].show();
		}
	}

}
void spisk_c(Phone spisp[],int &k)
{
	Phone remember;
	int n;
	cout<<"List c"<<endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < (k-1); j++)
		{
			if(spisp[j].first_name>spisp[j+1].first_name)
			{
				remember=spisp[j+1];
				spisp[j+1]=spisp[j];
				spisp[j]=remember;
				n++;
			}		
		}
		if(n==0)break;
			n=0;
	}
	for (int i = 0; i < k; i++)
	{
		spisp[i].show();
	}

}
int main()
{ 
	Phone *spisp;
	int n,k;
	cout<<"Time limit for intracity calls: ";
	cin>>n;
	cout<<endl;
	cout<<"Input number of subscribers: ";
	cin>>k;
	spisp=new Phone[k];
	spisk_a(spisp,n,k);
	spisk_b(spisp,k);
	spisk_c(spisp,k);
	delete [] spisp;
	cout<<endl;

	system("Pause");
	return 0;
}