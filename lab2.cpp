#include <iostream>
#include <cmath>
using namespace std;
//3
class Vector {
		int n;
		double* members;
public:
		Vector();
		Vector(int k);
		Vector(int k, double* arr);
		Vector(const Vector& ob);
		~Vector();
		void Module();
		double Scalar(Vector& a,Vector& b);
		void CheckCollinearity(Vector& a, Vector& b);
		const Vector operator+(const Vector& ob);
		const Vector operator-(const Vector& ob);
		const Vector operator*(const int& i);
		const Vector operator=(const Vector& ob);
		double& operator[](int i);
		Vector& operator++();
		Vector& operator--();
		friend ostream& operator<<(ostream& mystream, Vector& ob);
		friend istream& operator>>(istream& mystream, Vector& ob);

};



Vector::Vector()
{
		n = rand() % 7 + 1;
		members = new double[n];
		for (int i = 0; i < n; ++i)
		{
				members[i] = rand() % 15 + 1;
		}
				
}

Vector::Vector(int k)
{
		n = k;
		members = new double[n];
		for (int i = 0; i < n; ++i)
		{
				members[i] = rand() % 15 + 1;
		}

}

Vector::Vector(int k, double* arr)
{
		n = k;
		members = new double[n];
		for (int i = 0; i < n; ++i)
		{
				members[i] = arr[i];
		}

}

Vector::Vector(const Vector& ob)
{
		n = ob.n;
		members = new double[n];
		for (int i = 0; i < n; ++i)
		{
				members[i] = ob.members[i];
		}
}

Vector::~Vector()
{
		delete[] members;
}



void Vector::Module()
{
		double sum = 0;
		for (int i = 0; i < this->n; ++i)
		{
				sum += (this->members[i])*(this->members[i]);
		}
		cout << "Module of vector is " << sqrt(sum) << endl;
}

double Vector::Scalar(Vector& a, Vector& b)
{
		double sum = 0;
		if (a.n != b.n)
		{
				cout << "Incorrect" << endl;
				return sum;
		}
		for (int i = 0; i < n; ++i)
		{
				sum += a.members[i] * b.members[i];
		}
		return sum;
}

void Vector::CheckCollinearity(Vector& a, Vector& b)
{
		if (a.n != b.n)
		{
				cout << "Incorrect" << endl;
				return;
		}
		if (!Scalar(a, b))
		{
				cout << "Vectors are orthogonal"<<endl;
				return;
		}
		for (int i = 0; i < a.n - 1; ++i)
		{
				if ( static_cast<double>(a.members[i] / b.members[i]) != static_cast<double>(a.members[i + 1] / b.members[i + 1]) )
				{
						cout << "Vectors are neither orthogonal nor collinear" << endl;
						return;
				}
		}
		cout << "Vectors are collinear"<<endl;
}


const Vector Vector::operator+(const Vector& ob)
{

		if (this->n != ob.n)
		{
				cout << "Incorrect" << endl;
				Vector temp1(1);
				temp1.members[0] = 0;
				return temp1;
		}
		Vector temp(n);

		for (int i = 0; i < n; ++i)
		{
				 temp.members[i]= this->members[i] +ob.members[i];
		}
		return temp;
}

const Vector Vector::operator-(const Vector& ob)
{
		
		if (this->n != ob.n)
		{
				cout << "Incorrect" << endl;
				Vector temp1(1);
				temp1.members[0] = 0;
				return temp1;
		}
		Vector temp(n);
		for (int i = 0; i < n; ++i)
		{
				temp.members[i] = this->members[i] - ob.members[i];
		}
		return temp;
}


const Vector Vector::operator*(const int& i)
{
		Vector temp(n);

		for (int k = 0; k < n; ++k)
		{
				 temp.members[k] = this->members[k]* i;
		}
		return temp;
}

const Vector Vector::operator=(const Vector& ob)
{
		delete[] this->members;
		this->n = ob.n;
		this->members = new double[ob.n];
		for (int i = 0; i < n; ++i)
		{
				this->members[i] = ob.members[i];
		}
		return *this;
}

double& Vector::operator[](int i)
{
		return(members[i]);
}

Vector& Vector::operator++()
{
		for(int i =0; i< this->n; ++i) ++(this->members[i]);
		return *this;
}
Vector& Vector::operator--()
{
		for (int i = 0; i < this->n; ++i) --(this->members[i]);
		return *this;
}

ostream& operator<<(ostream& mystream, Vector& ob)
{
		mystream << "Vector("; 
		for (int i = 0; i < ob.n; ++i)
		{
				mystream << ob.members[i];
				if (i != ob.n - 1) mystream << ", ";
		}
		mystream << ")"<<endl;
		return mystream;
}

istream& operator>>(istream& mystream, Vector& ob)
{
		cout << "Enter dimension:";
		mystream >> ob.n;
		delete[] ob.members;
		ob.members = new double[ob.n];
		cout << endl;
		for (int i = 0; i < ob.n; ++i)
		{
				cout << "Enter " << i + 1 << " member:";
				mystream >> ob.members[i];
		}
		return mystream;
}
int main()
{
		double arr1[] = {1, 2 , 7 ,3};
		double arr2[] = { 2, 4 , 14 ,6};
		Vector *p = new Vector[10];
		Vector v1(4, arr1);
		Vector v2(4, arr2);
		Vector v3(4);
		Vector v4(5);
		Vector v5;
		v1.Module();
		v1.CheckCollinearity(v1, v2);
		v1.CheckCollinearity(v2, v3);
		v1.CheckCollinearity(v3, v4);
		cout << v3;
		cout << v5;
		cout<<"Result of scalar product is: "<<v3.Scalar(v3,v2)<<endl;
		v5 = v3 + v2;
		cout << v5;
		v5 = v5 - v3;
		cout << v5;
		v5 = v5*5;
		cout << v5;
		cout << v5[2]<<endl;
		++v5;
		cout << v5;
		--v5;
		cout << v5;
		cin >> v5;
		cout << v5;
		cout << p[3];
		delete[] p;

		return 0;
}