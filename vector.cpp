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
	Vektor operator* (const Vektor v);//перегрузка оператора *
	Vektor operator* (const int x);//перегрузка оператора * (векторний добуток)
	int& operator [] (int x);//перегрузка оператора индексирования
    bool operator== (const Vektor v);//перегрузка оператора сравнения
	Vektor operator= (const Vektor v);//перегрузка оператора =
	friend std:: ostream& operator<< (std:: ostream& s, const Vektor v);//метод вывода
private:
	int* vek;
	int length;
};
Vektor::Vektor(){//реализация конструктора "по умолчанию"
	length=10;
	vek = new int[length];
}
Vektor:: ~Vektor(){//реализация деструктора
	using namespace std;
	cout<<"Destructor";
	delete[] vek;
}
Vektor:: Vektor(int x){//реализация конструктора с заданным размером
	length=x;
	vek=new int[length];
}
Vektor:: Vektor(const Vektor& v){//реализация копируещего конструктора
	this->length=v.length;
    vek = new int[length];
}
Vektor Vektor:: operator +(const Vektor v){//реализация перегрузки оператора +
	using namespace std;
	Vektor result;
	result.length=this->length;
	for (int i=0; i<this->length; i++){
		result.vek[i]=this->vek[i];
	}
	if (!(this->length=v.length)){
		cout<<"Wrong operation";
		return 0;
	}
	else
	{
		for (int i=0; i<this->length; i++){
			result.vek[i]+=v.vek[i];
		}	
	return result;	
	}
}
Vektor Vektor:: operator -(const Vektor v){//реализация перегрузки оператора -
	using namespace std;
	Vektor result;
	if (!(this->length=v.length)){
		cout<<"Wrong operation";
		return 0;
	}
	else
	{
		for (int i=0; i<this->length; i++){
			result.vek[i]-=v.vek[i];
		}	
	return result;	
	}
}
Vektor Vektor:: operator* (const Vektor v){//реализация оператора *
	using namespace std;
	Vektor result;
	if (!(this->length=v.length)){
		cout<<"Wrong operation";
		return 0;
	}
	else
	{
		for (int i=0; i<this->length; i++){
			result.vek[i]*=v.vek[i];
		}	
	return result;	
	}
}
int& Vektor:: operator [] (int x)
{
	return this->vek[x];
}
Vektor Vektor:: operator* (const int x){//реализация оператора *
	Vektor result;
		for (int i=0; i<this->length; i++){
			result.vek[i]*=x;
	return result;	
	}
}
bool Vektor:: operator ==(const Vektor v){//реализация оператора сравнения
	bool tmp=true;
	if (!(this->length==v.length)) {
		tmp=false;
	}
	else {
		for (int i=0; i<this->length; i++){
			if (!(this->vek[i]==v.vek[i])){
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
	for (int i=0; i<this->length; i++){
			this->vek[i]*=x;
		}
	return *this;	

}
Vektor Vektor:: operator= (const Vektor v){//реализация оператора =
if (!(this==&v)){
	this->length=v.length;
	if (vek) delete[] vek;
	vek = new int[v.length];
	for (int i=0; i<this->length; i++){
		this->vek[i]=v.vek[i];	
	}}
	return *this;
	}
}
std:: ostream& operator<<(std:: ostream& s, const Vektor v)//реализация метода вывода
{
	s<<v.length<<"-length"<<std::endl;
	for (int i=0; i<v.length; i++){
		s<<v.vek[i]<<"-element of vektor number "<<i<<std::endl;
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
