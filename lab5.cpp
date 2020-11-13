#include <iostream>
#include<string>
using namespace std;
//var 6
class instruments
{
public:
	instruments()
	{
		Name="";
	}
	~instruments(){}
	virtual void set(string name)
	{
		Name=name;
	}
	virtual string getname()
	{return Name;}
	virtual void show()
	{
		cout<<"name of the instrument: ";
		cout<<Name<<endl;
	}
protected:
	string Name;
};
class Stringed:public instruments
{
public:
	Stringed()
	{
		Name="";
		kol=0;
	}
	Stringed(string name, int kl)
	{
		Name=name;
		kol=kl;
	}
	~Stringed(){}
	void set(string name, int kl)
	{
		Name=name;
		kol=kl;
	}
	int getkol()
	{return kol;}
	void show()
	{
		cout<<"name of the instrument: ";
		cout<<Name<<endl;
		cout<<"number of string: ";
		cout<<kol<<endl;
	}
private:
	int kol;

};
class percussion :public instruments
{
public:
	percussion ()
	{
		Name="";
		type_inst="";
	}
	percussion(string name,  string type_in)
	{
		Name=name;
		type_inst=type_in;
	}
	~percussion (){}
	void set(string name,  string type_in )
	{
		Name=name;
		type_inst=type_in;
	}
	string gettype_inst()
	{return type_inst;}
	void show()
	{
		cout<<"name of the instrument: ";
		cout<<Name<<endl;
		cout<<"Type of percussion instrument: ";
		cout<<type_inst<<endl;
	}
private:
	string type_inst;

};
class wind :public instruments
{
public:
	wind ()
	{
		Name="";
		material="";
	}
	wind(string name,  string mrial)
	{
		Name=name;
		material=mrial;
	}
	~wind (){}	
	void set(string name,  string mrial )
	{
		Name=name;
		material=mrial;
	}
	string gettype_inst()
	{return material;}
	void show()
	{
		cout<<"name of the instrument: ";
		cout<<Name<<endl;
		cout<<"material of wind instrument: ";
		cout<<material<<endl;
	}
private:
	string material;

};

int main()
{
	instruments** orkestor= new instruments*[5];
	Stringed* strng;
	percussion* bam;
	wind* woo;
	
	for (int i = 0; i <5 ; i++)
	{
		int n;
	cout<<"What number of instruments to add"<<endl<<"1) Stringed"<<endl<<"2) percussion"<<endl<<"3) wind"<<endl;
	cin>>n;
	string Name;
	int kol=0;
	string material;
	string type_inst;
	switch (n)
	{ 
	case 1:
		cin>>Name;
		cin>>kol;
		strng=new Stringed(Name,kol);
		orkestor[i]=strng;
		break;
	case 2:
		cin>>Name;
		cin>>type_inst;
		bam=new percussion(Name,type_inst);
		orkestor[i]=bam;
		break;
	case 3:cin>>Name;
		cin>>material;
		woo=new wind(Name,material);
		orkestor[i]=woo;
		break;
	default:cout<<"You dont know music instruments";
		break;
	}
	}
	for (int i = 0; i < 5; i++)
	{
		orkestor[i]->show;
		cout<<endl;
	}
	return 0;
}
