#include <iostream>
#include <algorithm>
using namespace std;
//Phone: Фамилия, Имя, Отчество, Адрес, Номер, Время внутри-городских разговоров,
//Время междугородних разговоров. Создать массив объектов. Вывести:
//а) сведения об абонентах, время внутригородских разговоров кото-рых превышает заданное;
//b) сведения об абонентах, воспользовавшихся междугородней свя-зью;
//c) сведения об абонентах, выведенные в алфавитном порядке.
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
	cout<<"Введите ФИО:";
	cin >> second_name;
	cin >> first_name;
	cin >> otch;
	cout<<"Введите адрес";
	cin >> adr.str >> adr.h;
	cout<<"Введите номер";
	cin >> number;
	cout<<"Введите время внутри-городских разговоров";
	cin >> time_in;
	cout<<"Введите Время междугородних разговоров";
	cin >> time_out;
}
void Phone::show()
{
	cout<<"ФИО: "<< second_name <<" "<< first_name <<" "<< otch<<endl;
	cout<<"Адрес: "<< adr.str <<" "<<adr.h<<endl;
	cout<<"Номер"<< number<<endl<<endl;
}
int Phone::in(){return time_in;}
int Phone::out(){return time_out;}
void spisk_a(Phone spisp[],int &n,int &k)
{
	cout<<"Список а"<<endl;
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
	cout<<"Список b"<<endl;
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
	cout<<"Список c"<<endl;
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
	cout<<"Предел времени внутригородских разговоров: ";
	cin>>n;
	cout<<endl;
	cout<<"Введите количество абонентов: ";
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