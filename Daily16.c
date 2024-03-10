/*
 Program: <Length and Weight conversions>
 Author: <Mark Daoud>
 Date: <d11/08/23>
 Time spent: <2.5 hours>
 Sources of Help: <Class Examples>
 Purpose: The purpose of this program is to convert weights and lengths depending on what direction the user chooses from us to metric
 or metric to us and to demonstrate how to use pointers to allow a function to change the value of a integer or double that it does not own.
*/




#include <stdio.h>
#include <math.h>

//Pre Condition: None
//Post Condition: The keyboard buffer has been cleared 
void clear_keyboard_buffer(void);

enum direction { QUIT, LENGTHS, WEIGHTS };
typedef enum direction Direction;

enum length { LRETURN, L_TO_M, L_TO_U };
typedef enum length Length;

enum weights { WRETURN, W_TO_M, W_TO_U };
typedef enum weights Weights;

//Pre Condition: None
//Post Condition: The main menu of options is displayed to the user
void display_menu(void);

//Pre Condition: None
//Post Condition: The user has choosen to convert lengths 
void convert_lengths(void);

//Pre Condition: None
//Post Condition: The user has choosen to convert weights
void convert_weights(void);

//Pre Condition: None
//Post Condition: The user has indicated if they want to convert lengths,weights, or quit
Direction get_choice(void);

//Pre Condition: None
//Post Condition: The user has indicated if they want to convert lengths to us,metric, or return to main menu
Length get_direction_length(void);

// Pre Condition : None
//Post Condition: The user has indicated if they want to convert weights to us,metric, or return to main menu
Weights get_direction_weight(void); 

//Pre Condition : None
//Post Condition: The values the user has entered have been converted to metric 
void length_to_metric(void); 

//Pre Condition : None
//Post Condition: The values the user has entered have been converted to us
void length_to_us(void);

//Pre Condition: None
//Post Condition: The length menu of options is displayed to the user
void display_menu_length(void);

//Pre Condition : None
//Post Condition: The values the user has entered have been converted to metric
void weight_to_metric(void);

//Pre Condition : None
//Post Condition: The values the user has entered have been converted to us
void weight_to_us(void);

//Pre Condition: None
//Post Condition: The weight menu of options is displayed to the user
void display_menu_weight(void);

const double INCHES_TO_FEET = 1.0/12.0;
const double FEET_TO_METERS = 0.3048;
const double METERS_TO_CM = 100;
const double METERS_TO_FEET = 1.0 / 0.3048;
const double FEET_TO_INCHES = 12.0;
const double CM_TO_METERS = 1.0 / 100;

const double GRAMS_TO_KILOGRAMS = 1.0 / 1000;
const double KILOGRAMS_TO_POUNDS = 2.2046; 
const double KILOGRAMS_TO_GRAMS = 1000;
const double POUNDS_TO_KILOGRAMS = 1.0 / 2.2046; 
const double POUNDS_TO_OUNCES = 16.0;
const double OUNCES_TO_POUNDS = 1.0 / 16.0;

//Pre Condition: None
//Post condition: The user has enter the values for pfeet and pinches and they have been stored in the address of their int
void get_input_length_to_metric(int* pfeet, double* pinches);

//Pre Condition: User has entered the values for feet and inches 
//Post condition: The values the user has entered for feet and inches have been converted to meters and 
//cm and those values have been stored in the addresses of their int
void calculate_length_to_metric(int feet, double inches, int* pmeters, double* p_cm);

//Pre Condition: The values the user has entered for feet and inches have been converted to meters and cm
//Post Condition: The result of the conversion is displayed to the user 
void display_length_to_metric(int feet, double inches, int meters, double cm);

//Pre Condition: None
//Post condition: The user has enter the values for pmeters and p_cm and they have been stored in the address of their int
void get_input_length_to_us(int* pmeters, double* p_cm);

//Pre Condition: User has entered the values for meters and cm
//Post condition: The values the user has entered for meters and cm have been converted to feet and 
//inches and those values have been stored in the addresses of their int
void calculate_length_to_us(int meters, double cm, int* pfeet, double* pinches);

// Pre Condition : The values the user has entered for meters and cm have been converted to feet and inches
//Post Condition: The result of the conversion is displayed to the user  
void display_length_to_us(int meters, double cm, int feet, double inches); 

//Pre Condition: None
//Post Condition: The user has entered the values for ppounds and pounces and they have been stored in the address of their int
void get_input_weight_to_metric(int* ppounds, double* pounces);  

//Pre Condition: The user has entered the values for pounds and ounces 
//Post Condition: The values the user has entered for pounds and ounces have been converted to kilograms and 
//grams and those values have been stored in the addresses of their int 
void calculate_weight_to_metric(int pounds, double ounces, int* pkilograms, double* pgrams);

//Pre Condition: The values the user has entered for pounds and ounces have been converted to kilograms and grams 
//Post Conditio: The result of the conversion is displayed to the user 
void display_weight_to_metric(int pounds, double ounces, int kilograms, double grams);  

//Pre Condition: None
//Post Condition: The user has entered the values for pkilograms and pgrams and they have been stored in the address of their int
void get_input_weight_to_us(int* pkilograms, double* pgrams);

//Pre Condition: The user has entered the values for kilograms and grams
//Post Condition: The values the user has entered for kilograms and grams have been converted to pounds and 
//ounces and those values have been stored in the addresses of their int 
void calculate_weight_to_us(int kilograms, double grams, int* ppounds, double* pounces);

// Pre Condition : The values the user has entered for kilograms and grams have been converted to pounds and ounces
//Post Conditio: The result of the conversion is displayed to the user
void display_weight_to_us(int kilograms, double grams, int pounds, double ounces); 


int main(int argc, char* argv[])
{
	Direction direction;

	do
	{
		direction = get_choice();
		switch (direction)
		{
		case LENGTHS:
			convert_lengths();
			break;
		case WEIGHTS:
			convert_weights();
			break;
		case QUIT:
			break;
		}

	} while (direction != QUIT);

	return 0;
}

Direction get_choice(void)
{
	char choice;
	do
	{
		display_menu();
		scanf(" %c", &choice);
		clear_keyboard_buffer();
		if (choice != '1' && choice != '2' && choice != '0')
		{
			printf("I'm sorry I don't understand.\n");
		}

	} while (choice != '1' && choice != '2' && choice != '0');

	switch (choice)
	{
	case '1':
		return LENGTHS;
		break;
	case '2':
		return WEIGHTS;
		break;
	}
	return QUIT;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

void display_menu(void)
{
	printf("Please choose from the following options.\n");
	printf("1) Convert Lengths.\n");
	printf("2) Convert Weights.\n");
	printf("	0) QUIT\n");
	printf("	Your choice: ");
}

void convert_lengths(void)
{
	Length direction_length;

	do
	{
		direction_length = get_direction_length();
		switch (direction_length)
		{
		case L_TO_M:
			length_to_metric();
			break;
		case L_TO_U:
			length_to_us();
			break;
		case LRETURN:
			break;
		}

	} while (direction_length != LRETURN);  
}

void convert_weights(void)
{
	Weights direction_weight;
	do
	{
		direction_weight = get_direction_weight();
		switch (direction_weight)
		{
		case W_TO_M:
			weight_to_metric();
			break;
		case W_TO_U:
			weight_to_us();
			break;
		case WRETURN:
			break;
		}

	} while (direction_weight != WRETURN);
}

void length_to_metric(void)
{
	int feet;
	double inches;
	int meters;
	double cm;
	get_input_length_to_metric(&feet, &inches); 
	calculate_length_to_metric(feet, inches, &meters, &cm);
	display_length_to_metric(feet, inches, meters, cm); 
	
}


void length_to_us(void)
{
	int meters;
	double cm; 
	int feet;
	double inches;
	get_input_length_to_us(&meters, &cm); 
	calculate_length_to_us(meters, cm, &feet, &inches);
	display_length_to_us(meters, cm, feet, inches);
}

Length get_direction_length(void)
{
	char choice_length;
	do
	{
		display_menu_length();
		scanf(" %c", &choice_length);
		clear_keyboard_buffer();
		if (choice_length != '1' && choice_length != '2' && choice_length != '0')
		{
			printf("I'm sorry I don't understand.\n");
		}

	} while (choice_length != '1' && choice_length != '2' && choice_length != '0');

	switch (choice_length)
	{
	case '1':
		return L_TO_M;
		break;
	case '2':
		return L_TO_U;
		break;
	}
	return LRETURN;
}
void display_menu_length(void)
{
	printf("Please choose from the following options.\n");
	printf("1) Convert to Metric.\n");
	printf("2) Convert to US.\n");
	printf("	0) QUIT\n");
	printf("	Your choice: ");
}
Weights get_direction_weight(void)
{
	char choice_weight;
	do
	{
		display_menu_weight();
		scanf(" %c", &choice_weight);
		clear_keyboard_buffer();
		if (choice_weight != '1' && choice_weight != '2' && choice_weight != '0')
		{
			printf("I'm sorry I don't understand.\n");
		}

	} while (choice_weight != '1' && choice_weight != '2' && choice_weight != '0');

	switch (choice_weight)
	{
	case '1':
		return W_TO_M;
		break;
	case '2':
		return W_TO_U;
		break;
	}
	return WRETURN;
}
void weight_to_metric(void)
{
	int pounds;
	double ounces;
	int kilograms; 
	double grams;
	get_input_weight_to_metric(&pounds, &ounces);  
	calculate_weight_to_metric(pounds, ounces, &kilograms, &grams); 
	display_weight_to_metric(pounds, ounces, kilograms, grams); 

}

void weight_to_us(void)
{
	int kilograms;
	double grams;
	int pounds;
	double ounces;
	get_input_weight_to_us(&kilograms, &grams);
	calculate_weight_to_us(kilograms, grams, &pounds, &ounces);
	display_weight_to_us(kilograms, grams, pounds, ounces);

}

void display_menu_weight(void)
{
	printf("Please choose from the following options.\n");
	printf("1) Convert to Metric.\n");
	printf("2) Convert to US.\n");
	printf("	0) QUIT\n");
	printf("	Your choice: ");
}
void get_input_length_to_metric(int* pfeet, double* pinches)
{
	printf("Enter the amount of feet: ");
	scanf("%d", pfeet); 
	clear_keyboard_buffer();
	printf("Enter the amount of inches: ");
	scanf("%lf", pinches);
	clear_keyboard_buffer(); 
}
void calculate_length_to_metric(int feet, double inches, int* pmeters, double* p_cm)
{
	double total_feet;
	double total_meters;

	total_feet = feet + inches * INCHES_TO_FEET;  
	total_meters = total_feet * FEET_TO_METERS;
	*pmeters = floor(total_meters);
	*p_cm = (total_meters - *pmeters) * METERS_TO_CM; 

}
void display_length_to_metric(int feet, double inches, int meters, double cm)
{
	printf("%d feet and %lf inches are equal to: \n", feet, inches);
	printf("%d meters and %lf centimeters.\n", meters, cm);
}
void get_input_length_to_us(int* pmeters, double* p_cm)
{
	printf("Enter the amount of meters: ");
	scanf("%d", pmeters);
	printf("Enter the amount of centimeters: ");
	scanf("%lf", p_cm);
}
void calculate_length_to_us(int meters, double cm, int* pfeet, double* pinches)
{
	double total_meters;
	double total_feet;
	total_meters = meters + cm * CM_TO_METERS;
	total_feet = total_meters * METERS_TO_FEET; 
	*pfeet = floor(total_feet);
	*pinches = (total_feet - *pfeet) * FEET_TO_INCHES;
}
void display_length_to_us(int meters, double cm, int feet, double inches)
{
	printf("%d meters and %lf centimeters are equal to: \n", meters, cm);
	printf("%d feet and %lf inches.\n", feet, inches); 
}
void get_input_weight_to_metric(int* ppounds, double* pounces)
{
	printf("Enter the amount of pounds: ");
	scanf("%d", ppounds);
	clear_keyboard_buffer(); 
	printf("Enter the amount of ounces: ");
	scanf("%lf", pounces);
	clear_keyboard_buffer(); 
}
void calculate_weight_to_metric(int pounds, double ounces, int* pkilograms, double* pgrams)
{
	double total_pounds;
	double total_kilograms;

	total_pounds = pounds + ounces * OUNCES_TO_POUNDS;
	total_kilograms = total_pounds * POUNDS_TO_KILOGRAMS;  
	*pkilograms = floor(total_kilograms);
	*pgrams = (total_kilograms - *pkilograms) * KILOGRAMS_TO_GRAMS;
}
void display_weight_to_metric(int pounds, double ounces, int kilograms, double grams)
{
	printf("%d pounds and %lf ounces is equal to:\n", pounds, ounces);
	printf("%d kilograms and %lf grams.\n", kilograms,grams);
}
void get_input_weight_to_us(int* pkilograms, double* pgrams)
{
	printf("Enter the amount of kilograms: ");
	scanf("%d", pkilograms);
	printf("Enter the amount of grams: ");
	scanf("%lf", pgrams);
}
void calculate_weight_to_us(int kilograms, double grams, int* ppounds, double* pounces)
{
	double total_kilograms;
	double total_pounds;

	total_kilograms = kilograms + grams * GRAMS_TO_KILOGRAMS;
	total_pounds = total_kilograms * KILOGRAMS_TO_POUNDS;
	*ppounds = floor(total_pounds);
	*pounces = (total_pounds - *ppounds) * POUNDS_TO_OUNCES;
}
void display_weight_to_us(int kilograms, double grams, int pounds, double ounces)
{
	printf("%d kilograms and %lf grams is equal to \n",kilograms,grams);
	printf("%d pounds and %lf ounces.\n",pounds, ounces);
}