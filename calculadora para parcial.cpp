#include <iostream>
#include "libreria_calculadora.h"

using namespace std; 

int main (){
	float n1,n2,n3;
	char simbolo;
	cout<<"calculadora"<<endl;
	cout<<"ingrese el primer numero"<<endl;
	cin>>n1;
	cout<<"ingrese el segundo numero"<<endl;
	cin>>n2;
	cout<<"ingrese el simbolo de operacion (+,-,*,/,!)"<<endl;
	cin>>simbolo;
		
	if(simbolo=='+'){
		n3=sumar(n1,n2);
	}else if(simbolo=='-'){
		n3=restar(n1,n2);
	}else if(simbolo=='*'){
		n3=multiplicar(n1,n2);
	}else if(simbolo=='/'){
		n3=dividir(n1,n2);
	}else if(simbolo=='!'){
		n3=factorial(n1);
	}
	cout<<"el resultado es: "<<n3<<endl;
	
	system ("pause");
	return 0;
}

