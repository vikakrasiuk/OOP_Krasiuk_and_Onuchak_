#include <iostream>
#include <stdio.h>
	using namespace std;
class Vektor {
public:
	Vektor();//конструктор "по умолчанию"
	~Vektor();//деструктор
	Vektor(int x);//конструктор "по размеру вектора"
	Vektor(const Vektor& v);//копирующий конструктор
	Vektor operator+ (const Vektor v);//перегрузка оператора +
	Vektor operator- (const Vektor v);//перегрузка оператора -
	Vektor operator* (const Vektor v);//перегрузка оператора *(векторный добуток)
	Vektor operator* (const int x);//перегрузка оператора * (вектор на число)
	double abs()//модуль вектора
	Vektor operator% (const Vektor v);//перегрузка оператора *
	int& operator [] (int x);//перегрузка оператора индексирования
    bool operator== (const Vektor v);//перегрузка оператора сравнения
	Vektor operator= (const Vektor v);//перегрузка оператора =
	friend std:: ostream& operator<< (std:: ostream& s, const Vektor v);//метод вывода
private:
       double * coordinaty;
       double rozmirnist; 
      } ;
Vektor::Vektor(){//реализация конструктора "по умолчанию"
        rozmirnist=10;
	coordinaty = new int[rozmirnist];
}
Vektor:: ~Vektor(){//реализация деструктора
	using namespace std;
	cout<<"Destructor";
	delete[] coordinaty;
}
Vektor:: Vektor(int x){//реализация конструктора с заданным размером
	rozmirnist=x;
        coordinaty=new int[rozmirnist];
}
Vektor:: Vektor(const Vektor& v){//реализация копируещего конструктора
	this->rozmirnist=v.rozmirnist;
    coordinaty = new int[rozmirnist];
}
Vektor Vektor:: operator +(const Vektor v){//реализация перегрузки оператора +
	using namespace std;
	Vektor result;
	result.rozmirnist=this->rozmirnist;
	for (int i=0; i<this->rozmirnist; i++){
		result.coordinaty[i]=this->coordinaty[i];
	}
	if (!(this->rozmirnist=v.rozmirnist)){
		cout<<"Wrong operation";
		return 0;
	}
	else
	{
		for (int i=0; i<this->rozmirnist; i++){
			result.coordinaty[i]+=v.coordinaty[i];
		}	
	return result;	
	}
}
Vektor Vektor:: operator -(const Vektor v){//реализация перегрузки оператора -
	using namespace std;
	Vektor result;
	if (!(this->rozmirnist=v.rozmirnist)){
		cout<<"Wrong operation";
		return 0;
	}
	else
	{
		for (int i=0; i<this->rozmirnist; i++){
			result.coordinaty[i]-=v.coordinaty[i];
		}	
	return result;	
	}
}
Vektor Vektor:: operator* (const Vektor v){//реализация оператора *
	using namespace std;
	Vektor result;
	if (!(this->rozmirnist=v.rozmirnist)){
		cout<<"Wrong operation";
		return 0;
	}
	else
	{
		for (int i=0; i<this->rozmirnist; i++){
			result.coordinaty[i]*=v.coordinaty[i];
		}	
	return result;	
	}
}
int& Vektor:: operator [] (int x)
{
	return this->coordinaty[x];
}
Vektor Vektor:: operator* (const int x){//реализация оператора *
	Vektor result;
		for (int i=0; i<this->rozmirnist; i++){
			result.coordinaty[i]*=x;
	return result;	
	}
}
double Vektor::abs()// реализация модуля
{
	double(modul,s);
	s=0
	for(int i=0;i<rozmirnist;i++)
{s=s+coordinaty[i]*coordinaty[i]
}
return s
}
bool Vektor:: operator ==(const Vektor v){//реализация оператора сравнения
	bool tmp=true;
	if (!(this->rozmirnist==v.rozmirnist)) {
		tmp=false;
	}
	else {
		for (int i=0; i<this->rozmirnist; i++){
			if (!(this->coordinaty[i]==v.coordinaty[i])){
				tmp=false;
			}
		}
	}
	if (tmp=false) {
		return false;
	}
	else{return true;}
}

Vektor Vektor:: operator*= (int x){//реализация оператора *
	for (int i=0; i<this->rozmirnist; i++){
			this->coordinaty[i]*=x;
		}
	return *this;	

}
Vektor Vektor:: operator= (const Vektor v){//реализация оператора =
if (!(this==&v)){
	this->rozmirnist=v.rozmirnist;
	if (coordinaty) delete[] coordinaty;
	coordinaty = new int[v.rozmirnist];
	for (int i=0; i<this->rozmirnist; i++){
		this->coordinaty[i]=v.coordinaty[i];	
	}}
	return *this;
	}
}
std:: ostream& operator<<(std:: ostream& s, const Vektor v)//реализация метода вывода
{
	s<<v.rozmirnist<<"-rozmirnist"<<std::endl;
	for (int i=0; i<v.rozmirnist; i++){
		s<<v.coordinaty[i]<<"-element of vektor number "<<i<<std::endl;
	}
	return s;
}
int main() 
{
	Vector a;
	Vector b(2);
	Vector c(3);

	for (int i = 0; i < 2; i++)
		b[i] = i;

	b *= 2;
	b = a = b + b; 

	if (a != b) cout << "Something wrong\n"; 
	else cout << "As expected\n";

	b += c;   // эта строчка работать не должна, потому что векторы
		  // разной размерности складывать нельзя.         

	cout << a << endl
	     << c << endl
	     << b << endl;

	return 0;
}
