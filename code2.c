#include <stdio.h>

int main(){
	char type;
	float temp;
	char scale;
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
}

float celsius_to_farenheit(float celsius){
	return (9.0/5.0)*celsius + 32.0;
}

float farenheit_to_celsius(float farenheit){
	return (5.0/9.0)*(farenheit-32.0);
}

float celsius_to_kelvin(float celsius){
	return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
	return kelvin - 273.15;
}

float kelvin_to_farenheit(float kelvin){
	return celsius_to_farenheit(kelvin_to_celsius(kelvin));
}

float farenheit_to_kelvin(float farenheit){
	return celsius_to_kelvin(farenheit_to_celsius(farenheit));
}
