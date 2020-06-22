

#include <stdio.h>
#include <math.h>
int  getUserInput(int,int);
void calcResistance(int, int, int, int, int, int);

int main (){
	int bands,s1,s2,s3,s4,s5,s6;
	printf("Welcome to the Seneca College Resistor Calculator...\n");
	bands = getUserInput(4,6);
	if (bands == 4){
		printf("First Stripe\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s1);
		printf("\nSecond Stripe\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s2);
		printf("\nMultiplier Colour\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE, 10-GOLD, 11-SILVER\nEnter Value: ");
		scanf("%d",&s3);
		printf("\nTolerance Colour\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 10-GOLD, 11-SILVER\nEnter Value: ");
		scanf("%d",&s4);
		s5 = -1 ;
		s6 = -1 ;
		calcResistance(s1,s2,s3,s4,s5,s6);
	}
	else if (bands == 5){
		printf("First Stripe\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s1);
		printf("\nSecond Stripe\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s2);
		printf("\nThird Stripe\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s3);
		printf("\nMultiplier Colour\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE, 10-GOLD, 11-SILVER\nEnter Value: ");
		scanf("%d",&s4);
		printf("\nTolerance Colour\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 10-GOLD, 11-SILVER\nEnter Value: ");
		scanf("%d",&s5);
		s6 = -1;
		calcResistance(s1,s2,s3,s4,s5,s6);
	}
	else {
		printf("First Stripe\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s1);
		printf("\nSecond Stripe\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s2);
		printf("\nThird Stripe\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE\nEnter Value: ");
		scanf("%d",&s3);
		printf("\nMultiplier Colour\n0-BLACK, 1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 9-WHITE, 10-GOLD, 11-SILVER\nEnter Value: ");
		scanf("%d",&s4);
		printf("\nTolerance Colour\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW ,5-GREEN, 6-BLUE, 7-VIOLET, 8-GREY, 10-GOLD, 11-SILVER\nEnter Value: ");
		scanf("%d",&s5);
		printf("\nTemprature Coefficient\n1-BROWN, 2-RED, 3-ORANGE, 4-YELLOW, 6-BLUE, 7-VIOLET\nEnter Value: ");
		scanf("%d",&s6);
		calcResistance(s1,s2,s3,s4,s5,s6);
	}
	getchar();
	getchar();
	return 0;
}

int getUserInput(int low,int high) {
	int n; 
	do {
		printf("How many bands in your resistor? ");
		scanf("%d",&n);
		if (n > high || n < low){
			 printf("***error: %d is not valid, number must be between %d and %d, try again***\n",n,low,high);
		}
		else {
			printf("\n");
		}
	}while( n > high || n < low);
	return n;
}
void calcResistance(int v1, int v2, int v3, int v4, int v5, int v6){
	float tol,temp;
	double calc,multi;

	if (v5 == -1 && v6 == -1){
		if ( v3 >= 10 ){
			multi = pow(10.0,-(v3-10));
		}
		else {
			multi = pow(10.0,(v3+1));
		}
		calc = (v1 * multi) + (v2 *multi/10);
		if (v4 == 5){
			tol = 0.5 ;
		}
		else if (v4 == 6){
			tol = 0.25 ;
		}
		else if (v4 == 7){
			tol = 0.10 ;
		}
		else if (v4 == 8){
			tol = 0.05 ;
		}
		else if (v4 == 10){
			tol = 5 ;
		}
		else if (v4 == 11) { 
			tol = 10 ;
		}
		else {
			tol = v4;
		}
		printf("\nThank You!\nYour resistor has a value of: %.3lf +/- %.2f%%\n",calc,tol);
	}
	else if (v5 != -1 && v6 == -1){
		if ( v4 >= 10 ){
			multi = pow(10.0,-(v4-11));
		}
		else {
			multi = pow(10.0,v4+2);
		}
		calc = (v1*multi) + (v2*multi/10) + (v3*multi/100);
		if (v5 == 5){
			tol = 0.5 ;
		}
		else if (v5 == 6){
			tol = 0.25 ;
		}
		else if (v5 == 7){
			tol = 0.10 ;
		}
		else if (v5 == 8){
			tol = 0.05 ;
		}
		else if (v5 == 10){
			tol = 5 ;
		}
		else if (v5 == 11) { 
			tol = 10 ;
		}
		else {
			tol = v5;
		}
		printf("\nThank You!\nYour resistor has a value of: %.2lf +/- %.2f%%\n",calc,tol);
	}
	else {
		if ( v4 >= 10 ){
			multi = pow(10.0,-(v4-11));
		}
		else {
			multi = pow(10.0,v4+2);
		}
		calc = (v1*multi) + (v2*multi/10) + (v3*multi/100);
																							
		if (v5 == 5){
			tol = 0.5 ;
		}
		else if (v5 == 6){
			tol = 0.25 ;
		}
		else if (v5 == 7){
			tol = 0.10 ;
		}
		else if (v5 == 8){
			tol = 0.05 ;
		}
		else if (v5 == 10){
			tol = 5 ;
		}
		else if (v5 == 11) { 
			tol = 10 ;
		}
		else {
			tol = v5;
		}
		if (v6 == 1){
			temp = 100;
		}
		else if (v6 == 2){
			temp = 50;
		}
		else if (v6 == 3){
			temp = 15;
		}
		else if (v6 == 4){
			temp = 25;
		}
		else if (v6 == 6){
			temp = 10;
		}
		else {
			temp = 5;
		}
		printf("\nThank You!\nYour resistor has a value of: %.2lf +/- %.2f%% Temp. Co. %.0f\n",calc,tol,temp);
	}
}



