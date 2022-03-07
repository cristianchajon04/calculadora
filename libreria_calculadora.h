float sumar(float x,float y){
	return x+y;
}
float restar(float x, float y){
	return x-y;
}
float multiplicar(float x, float y){
	return x*y;
}

float dividir(float x, float y){
	return x/y;
}


int factorial(int x){
	
	if(x<0){
		return 0;
	}else if(x>1){
		return x*factorial(x-1);
	}
}
