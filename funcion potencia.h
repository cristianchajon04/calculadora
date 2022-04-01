float potencia(float num1, float num2){
    float _num1 = num1;
    if (num2 < 0){
        float _num2 = -(num2);
        for (float i = 1.0; i < _num2; i++){
            num1 *= _num1;
        }
        return num1;
    }
    if (num2 == 0){
        return 1;
    }
    for (float i = 1.0; i < num2; i++){
        num1 *= _num1;
    }
    return num1;
}