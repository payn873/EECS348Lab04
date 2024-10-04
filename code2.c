#include <stdio.h>

int main(){
	char type;
	float temp;
	char scale;
	float celsius_to_farenheit(float);
	float farenheit_to_celsius(float);
	float kelvin_to_celsius(float);
	float celsius_to_kelvin(float);
	float farenheit_to_kelvin(float);
	float kelvin_to_farenheit(float);
	printf("Enter what temperature type you are inputing (e.x. f, c, k): ");
	scanf(" %c", &type);
	while(type != 'f' && type != 'c' && type != 'k'){
		printf("You entered an invalid temperature type. Please enter f for farenheit, c for celsius, or k for kelvin :) : ");
		scanf(" %c", &type);
	}
	printf("Enter the temperature value (float): ");
	scanf("%f", &temp);
	printf("Enter what temperature type you wish to conver to (e.x. f, c, k): ");
	scanf(" %c", &scale);
	while((scale != 'f' && scale != 'c' && scale != 'k') || scale == type){
		printf("You entered an invalid temperature type. Pleae enter f for farenheit, c for celsius, or k for kelvin, and remember to make sure this type is different from the previously entered type: ");
		scanf(" %c", &scale);
	}
	if(type == 'f'){
		if(scale == 'c'){
			printf("%f\n", farenheit_to_celsius(temp));
		}
		else{
			printf("%f\n", farenheit_to_kelvin(temp));
		}
	}
	else if(type == 'c'){
		if(scale == 'k'){
			printf("%f\n", celsius_to_kelvin(temp));
		}
		else{
			printf("%f\n", celsius_to_farenheit(temp));
		}
	}
	else{
		if(scale == 'f'){
			printf("%f\n", kelvin_to_farenheit(temp));
		}
		else{
			printf("%f\n", kelvin_to_celsius(temp));
		}
	}
}

float celsius_to_farenheit(float celsius){
	float farenheit = (9.0/5.0)*celsius + 32.0;
	return farenheit;
}

float farenheit_to_celsius(float farenheit){
	float celsius = (5.0/9.0)*(farenheit-32.0);
	return celsius;
}

float celsius_to_kelvin(float celsius){
	float kelvin =  celsius + 273.15;
	return kelvin;
}

float kelvin_to_celsius(float kelvin){
	float celsius =  kelvin - 273.15;
	return celsius;
}

float kelvin_to_farenheit(float kelvin){
	float celsius = kelvin_to_celsius(kelvin);
	float farenheit = celsius_to_farenheit(celsius);
	return farenheit;
}

float farenheit_to_kelvin(float farenheit){
	float celsius = farenheit_to_celsius(farenheit);
	float kelvin = celsius_to_kelvin(celsius);
	return kelvin;
}
