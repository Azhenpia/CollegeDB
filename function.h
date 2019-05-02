#ifndef linkHead
#define linkHead

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

jmp_buf ebuf;
jmp_buf ebuf1;
jmp_buf ebuf2;
jmp_buf ebuf3;
#define state_size 51 //including DC
#define school_size 100

/* Defined Struct */
typedef struct school_{
	char *Uname;
	char *SAbb;
	float gpa;
	int SAT_M;
	int SAT_R;
	int Pub_Pri;
	int Tui_out;
	int Tui_in;
}School;

typedef struct state_{
	char* full;
	char* abbre;
}State;

//Use to store the school information to sort
// index - the original ranking of Top100 university
//          the index in the database
// value - selected variable sorted
typedef struct node{
    int index;
    double value;
}SchElement;

void check_cmd(int );
// check whether the correct number of command line argument is used.
// If not, give user an error message and then terminate the entire
// program execution.

void check_file(FILE *);
// check whether the give file has been opened properly. If not, give user
// an error message and then terminate the entire program execution.

void input_schools(FILE *, School *[], int k);
// read in the first k lines in the input file about school information and
// store these information in the pointer array of schools.

void input_states(FILE *, State [], int k);
// read in the first k lines in the input file about state information and
// store the full name and abbreviation of each state in the array of states.

void main_menu();
// print out the main menu

void access(School *[], State []);
// implementation of choice 1 at the first level.
// note that this continues running until user enters EXIT
// it may happen that at some time, the user goes to the "data implementation"
// mode. you can consider to do that by calling function implementation()

void implementation(School *[], State []);
// implementation of choice 2 at the first level.
// note that this contiues running until user enters EXIT
// it may happen that at some time, the user goes to the "access data"
// mode. you can consider to do that by calling function access()

void check_school_data_correctness(School *[]);
//[test function] use for test the correctness of input

void check_state_data_correctness(State []);
//[test function] use for test the correctness of input

void displayInfo(School *[],State [], int );
// call by access(), and display selected Top100 University data. This will decide the
// row/ entity display. Last parameter with integer data type - the information identifier
// passed by access(). It mainly decides the column of output.
// If "specific group" is chosen, one more menu pop up
// this function will do pretreatment to the user input to improve fault tolerance
// one main level + one small sub-level

void matchingState(char *, State []);
// First parameter - user inputed row data to request for data about the specific state
// This function matching the state name and store the standard one [in database] in the
// location at the memory of first parameter
// Compatible with full name, abbreviation, capitalization

int matchingName(char *, School* []);
// First parameter - user inputed row data to request for data about the specific university
// This function matching the school name and return the index of specific university within
// database.
// Compatible with full name, capitalization.

void toUpperStr(char*);
// Convert all letters in the input string to uppercase

void sort(School *[], State []);
// mainly get user choice of sorting criterion
// and call the displaySortedInfo() to display result

void average(School *[], State []);
// mainly get user choice of average criterion
// and call the displayAverageInfo() to display result

void displaySortedInfo(School *[], State [], int);
// Extract the data to be sorted from the DB and store it in an array with data type SchElement
// Use quick sort to this array and display information in order

void displayAverageInfo(School *[], State [], int);
// calculate the summation of specific attribute and display average number in format

int cmp(const void* ,const void* );
// Custom comparison criteria for struct SchElement

#endif // linkHead#define linkHead
