#include <iostream>
#include <algorithm>
using namespace std;
//Phone: �������, ���, ��������, �����, �����, ����� ������-��������� ����������,
//����� ������������� ����������. ������� ������ ��������. �������:
//�) �������� �� ���������, ����� ��������������� ���������� ����-��� ��������� ��������;
//b) �������� �� ���������, ����������������� ������������� ���-���;
//c) �������� �� ���������, ���������� � ���������� �������.
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
	cout<<"������� ���:";
	cin >> second_name;
	cin >> first_name;
	cin >> otch;
	cout<<"������� �����";
	cin >> adr.str >> adr.h;
	cout<<"������� �����";
	cin >> number;
	cout<<"������� ����� ������-��������� ����������";
	cin >> time_in;
	cout<<"������� ����� ������������� ����������";
	cin >> time_out;
}
void Phone::show()
{
	cout<<"���: "<< second_name <<" "<< first_name <<" "<< otch<<endl;
	cout<<"�����: "<< adr.str <<" "<<adr.h<<endl;
	cout<<"�����"<< number<<endl<<endl;
}
int Phone::in(){return time_in;}
int Phone::out(){return time_out;}
void spisk_a(Phone spisp[],int &n,int &k)
{
	cout<<"������ �"<<endl;
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
	cout<<"������ b"<<endl;
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
	cout<<"������ c"<<endl;
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
	cout<<"������ ������� ��������������� ����������: ";
	cin>>n;
	cout<<endl;
	cout<<"������� ���������� ���������: ";
	cin>>k;
	spisp=new Phone[k];
	spisk_a(spisp,n,k);
	spisk_b(spisp,k);
	spisk_c(spisp,k);
	delete [] spisp;
	cout<<endl;
	setlocale(LC_ALL, "Russian");
	system("Pause");
	return 0;
}