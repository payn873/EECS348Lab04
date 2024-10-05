#include <stdio.h>

int main(){
	/*Converts a temperature of farenheit, celsius, or kelvin to farenheit, celsius or kelvin and 
	 * provides a weather advisory
	 */
	//Variables and functions being initialized
	char type;
	float temp;
	char scale;
	float celsius_to_farenheit(float);
	float farenheit_to_celsius(float);
	float kelvin_to_celsius(float);
	float celsius_to_kelvin(float);
	float farenheit_to_kelvin(float);
	float kelvin_to_farenheit(float);
	void categorize_temperature(float);
	//Entering in type of temperature being inputed
	printf("Enter what temperature type you are inputing (e.x. f, c, k): ");
	scanf(" %c", &type);
	//Checking for proper input and asking for a change in input if original is invalid
	while(type != 'f' && type != 'c' && type != 'k'){
		printf("You entered an invalid temperature type. Please enter f for farenheit, c for celsius, or k for kelvin :) : ");
		scanf(" %c", &type);
	}
	//Entering in value of temperature to be converted
	printf("Enter the temperature value (float): ");
	scanf("%f", &temp);
	//Checking for proper input and askng for a change in input if original is invalid
	//For farenheit temperatures
	if(type == 'f'){
		while(farenheit_to_kelvin(temp) < 0){
			printf("You enterd an invalid temperature, please try again: ");
			scanf("%f", &temp);
		}
	}
	//For celsius temperatures
	else if(type == 'c'){
		while(celsius_to_kelvin(temp) < 0){
			printf("You entered an invalid temperature, please try again: ");
			scanf("%f", &temp);
		}
	}
	//For kelvin temperatures
	else{
		while(temp < 0){
			printf("You entered an invalid temperature, please try again: ");
			scanf("%f", &temp);
		}
	}
	//Entering in type of temperature to convert to
	printf("Enter what temperature type you wish to conver to (e.x. f, c, k): ");
	scanf(" %c", &scale);
	//Checking for proper input and asking for a change if original is invalid
	while((scale != 'f' && scale != 'c' && scale != 'k') || scale == type){
		printf("You entered an invalid temperature type. Pleae enter f for farenheit, c for celsius, or k for kelvin, and remember to make sure this type is different from the previously entered type: ");
		scanf(" %c", &scale);
	}
	//Prints out farenheit conversion...
	if(type == 'f'){
		//...to celsius
		if(scale == 'c'){
			printf("Converted Temperature: %f Degrees Celsius\n", farenheit_to_celsius(temp));
			categorize_temperature(farenheit_to_celsius(temp));
		}
		//...to kelvin
		else{
			printf("Converted Temperature: %f Kelvin\n", farenheit_to_kelvin(temp));
			categorize_temperature(farenheit_to_celsius(temp));
		}
	}
	//Prints out celsius conversion...
	else if(type == 'c'){
		//...to kelvin
		if(scale == 'k'){
			printf("Converted Temperature: %f Kelvin\n", celsius_to_kelvin(temp));
			categorize_temperature(temp);
		}
		//...to farenheit
		else{
			printf("Converted Temperature: %f Degrees Farenheit\n", celsius_to_farenheit(temp));
			categorize_temperature(temp);
		}
	}
	//Prints out kelvin conversion...
	else{
		//...to farenheit
		if(scale == 'f'){
			printf("Converted Temperature: %f Degrees Farenheit\n", kelvin_to_farenheit(temp));
			categorize_temperature(kelvin_to_celsius(temp));
		}
		//...to celsius
		else{
			printf("Converted Temperature: %f Degrees Celsius\n", kelvin_to_celsius(temp));
			categorize_temperature(kelvin_to_celsius(temp));
		}
	}
}

float celsius_to_farenheit(float celsius){
	//Converts celsius temperature to farenheit
	float farenheit = (9.0/5.0)*celsius + 32.0;
	return farenheit;
}

float farenheit_to_celsius(float farenheit){
	//Converts farenheit temperature to celsius
	float celsius = (5.0/9.0)*(farenheit-32.0);
	return celsius;
}

float celsius_to_kelvin(float celsius){
	//Converts celsius temperature to kelvin
	float kelvin =  celsius + 273.15;
	return kelvin;
}

float kelvin_to_celsius(float kelvin){
	//Converts kelvin temperature to celsius
	float celsius =  kelvin - 273.15;
	return celsius;
}

float kelvin_to_farenheit(float kelvin){
	//Converts kelvin temperature to farenheit
	float celsius = kelvin_to_celsius(kelvin);
	float farenheit = celsius_to_farenheit(celsius);
	return farenheit;
}

float farenheit_to_kelvin(float farenheit){
	//Converts farenheit temperature to kelvin
	float celsius = farenheit_to_celsius(farenheit);
	float kelvin = celsius_to_kelvin(celsius);
	return kelvin;
}

void categorize_temperature(float celsius){
	/*Analyzes temperature in celsius and gives a temperature category and advisory for the category*/
	//Extreme heat
	if(celsius > 35.0){
		printf("Temperature Category: Extreme Heat\nWeather Advisory: Stay inside or go out with the polar bears.\n");
	}
	//Hot
	else if(celsius <= 35.0 && celsius > 25.0){
		printf("Temperature Category: Hot\nWeather Advisory: Wear cool clothing and stay hydrated.\n");
	}
	//Comftorable
	else if(celsius <= 25.0 && celsius > 10.0){
		printf("Temperature Category: Comftorable\nWeather Advisory: You should feel comftorable if you go outside now instead of playing on this computer all day.\n");
	}
	//Cold
	else if(celsius <= 10.0 && celsius >= 0.0){
		printf("Temperature Category: Cold\nWeather Advisory: Wear a jacket if the you want to go outside rather than grade beginner C code.\n");
	}
	//Freezing
	else{
		printf("Temperature Category: Freezing\nWeather Advisory: Stay indoors--unless you want to be cool like polar bears and hang out in the freezing cold.\n");
	}
}
