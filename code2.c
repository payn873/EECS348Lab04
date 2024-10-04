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
