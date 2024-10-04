#include <stdio.h>

int main(){
	/*Takes an NFL score and prints out all possible plays to get that score*/
	//NFL score
	int score = -1;
	//Goes until user inputs 1 or 0
	while (score != 1 && score != 0){
		//Takes integer input from the user and sets it to the NFL score
		printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d", &score);
		//Prints all possible plays to get inputed score
		printScores(score);
	}
	return 0;
}

int printScores(int givenScore){
	/*Calculates and prints all possible plays that can get a given score*/
	//Goes through all possible accquired safety points
	for(int i = 0; i <= (1 + (givenScore/2)); i++){
		int safety = 2*i;
		//Goes through all possible accquired field goal points
		for(int j = 0; j <= (1 + (givenScore/3)); j++){
			int fieldGoal = 3*j;
			//Goes through all possible accquired touchdown points
			for(int k = 0; k <= (1 + (givenScore/6)); k++){
				int touchDown = 6*k;
				//Goes through all possible accquired touchdown points with a field goal
				for(int l = 0; l <= (1 + (givenScore/7)); l++){
					int touchDownFieldGoal = 7*l;
					//Goes throguh all possible accquired touchdown points with a two point conversion
					for(int m = 0; m <= (1 + (givenScore/8)); m++){
						int touchDownConversion = 8*m;
						//If the play matchup gives the given score, prints out the play matchup
						if((safety + fieldGoal + touchDown + touchDownFieldGoal + touchDownConversion) == givenScore){
							printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d 3pt FG, %d Safety\n", m, l, k, j, i);
						}
					}
				}
			}
		}
	}
	return 0;
}
