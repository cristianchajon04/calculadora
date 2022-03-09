#include <iostream>

using namespace std;

int main(){
	int n1,n2,menu,suma,resta,multi,divi;
	
	cout<<"Calculadora"<<endl;
	cout<<"ingrese el primer numero"<<endl;
	cin>>n1;
	cout<<"ingrese el segundo numero"<<endl;
	cin>>n2;
	cout<<"ingrese el numero de la operacion a realizar"<<endl;
	cout<<"1. suma"<<endl;
	cout<<"2. resta"<<endl;
	cout<<"3. multiplicacion"<<endl;
	cout<<"4. division"<<endl;
	cin>>menu;
	if(menu==1){
		suma=n1+n2;
		cout<<"el total es "<<suma<<endl;
	}else if(menu==2){
		resta=n1-n2;
		cout<<"la resta es "<<resta<<endl;
	}else if(menu==3){
		multi=n1*n2;
		cout<<"el producto es "<<multi<<endl;
	}else if(menu==4){
		divi=n1/n2;
		cout<<"la division es "<<divi<<endl;
	}else{
		cout<<"Ingrese un numero valido."<<endl;
	}
	system("pause");
	return 4;
}




