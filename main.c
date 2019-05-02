#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char *argv[]){

    /* variables */
    FILE *school_info, *state_info;
    int choice;
    School *TOP100[school_size];
            //array of 100 pointers, each one points to one school
    State State_list[state_size];
            // array of the 50 states and DC

    check_cmd(argc);

    school_info = fopen(argv[1],"r");
    check_file(school_info);
    input_schools(school_info,TOP100,school_size);
    fclose(school_info);

    state_info = fopen(argv[2],"r");
    check_file(state_info);
    input_states(state_info, State_list, state_size);
    fclose(state_info);

    setjmp(ebuf);
    main_menu();

    do
    {
        printf("Your choice: ");
        scanf("%d",&choice);
    }while(choice < 0 || choice > 2);

    if (choice == 1)
        access(TOP100, State_list);
    if (choice == 2)
        implementation(TOP100, State_list);
    if (choice == 0)
        printf("The program is terminated, goodbye!\n");

    //release the dynamic memory allocation
    int i;
    for(i = 0; i < school_size; ++i){
        free(TOP100[i]);
    }
    for(i = 0; i < state_size; ++i){
        free(State_list[i].full);
        free(State_list[i].abbre);
    }
    return 0;
}

