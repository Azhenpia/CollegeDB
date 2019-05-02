#include "function.h"

void check_cmd(int k)
{
    if (k != 3)
    {
        printf("wrong number of arguments! Sorry!\n");
        exit(0);
    }
}

void check_file(FILE *in)
{
    if (in == NULL)
    {
        printf("Invalid input file! Sorry!\n");
        exit(0);
    }
}


void check_school_data_correctness(School *sch[])
{
    for(int i = 0; i < 100; ++i)
    {
        //printf("the %d data set:\n",i);
        printf("Uname = %s\n", sch[i]->Uname);
        fflush(stdout);
        printf("SAbb = %s\n", sch[i]->SAbb);
        fflush(stdout);
        printf("gpa = %f\n",sch[i]->gpa);
        fflush(stdout);
        printf("SAT_M = %d\n",sch[i]->SAT_M);
        fflush(stdout);
        printf("SAT_R = %d\n",sch[i]->SAT_R);
        fflush(stdout);
        printf("Pub_Pri = %d\n",sch[i]->Pub_Pri);
        fflush(stdout);
        printf("Tui_out = %d\n",sch[i]->Tui_out);
        fflush(stdout);
        printf("Tui_in = %d\n",sch[i]->Tui_in);
        fflush(stdout);
    }
}

void check_state_data_correctness(State state[])
{
    for(int i = 0; i < 51; ++i)
    {
        //printf("the %d data set:\n",i);
        printf("full = %s\n", state[i].full);
        fflush(stdout);
        printf("abbre = %s\n", state[i].abbre);
        fflush(stdout);
    }
}

void input_schools(FILE *in, School *sch[], int k)
{
    static int i, j;
    static int backStart = 0;
    static int itemIdentifier = 1;
    char str[100];
    char *temp = "";

    for(i = 0; i < k; ++i)
    {
        fgets(str,100,in);
        backStart = 0;
        itemIdentifier = 1;
        sch[i] = (School *)malloc(sizeof(School));
                //allocate dynamic memory for each School object

        for(j = 1; j <= strlen(str); ++j)
        {
            if(str[j] == ',' || str[j] == '\0')
            {
                switch(itemIdentifier)
                {
                case 1:
                    //allocate dynamic memory for each attribute of School object
                    sch[i]->Uname = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(sch[i]->Uname,str + backStart,j-backStart);
                    sch[i]->Uname[j-backStart] = '\0';
                    break;

                case 2:
                    sch[i]->SAbb = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(sch[i]->SAbb,str + backStart,j-backStart);
                    sch[i]->SAbb[j-backStart] = '\0';
                    break;

                case 3:
                    temp = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(temp,(char*)str + backStart,j-backStart);
                    temp[j-backStart] = '\0';
                    sch[i]->gpa = atof(temp);
                    break;

                case 4:
                    temp = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(temp,(char*)str + backStart,j-backStart);
                    temp[j-backStart] = '\0';
                    sch[i]->SAT_M = atoi(temp);
                    break;

                case 5:
                    temp = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(temp,(char*)str + backStart,j-backStart);
                    temp[j-backStart] = '\0';
                    sch[i]->SAT_R = atoi(temp);
                    break;

                case 6:
                    temp = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(temp,(char*)str + backStart,j-backStart);
                    temp[j-backStart] = '\0';
                    sch[i]->Pub_Pri = atoi(temp);
                    break;

                case 7:
                    temp = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(temp,(char*)str + backStart,j-backStart);
                    temp[j-backStart] = '\0';
                    sch[i]->Tui_out = atoi(temp);
                    break;

                case 8:
                    temp = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(temp,(char*)str + backStart,j-backStart);
                    temp[j-backStart] = '\0';
                    sch[i]->Tui_in = atoi(temp);
                    break;
                default:
                    ; //do nothing
                }
                backStart = j + 2;
                j += 1;
                itemIdentifier++;
            }
        }
        //Private colleges have the same tuition fees for both inside and outside the state
        if(sch[i]->Pub_Pri == 1)
            sch[i]->Tui_in = sch[i]->Tui_out;
    }
    //check_school_data_correctness(sch);
}

void input_states(FILE *in, State state[], int k)
{
    static int i, j;
    static int backStart = 0;
    static int itemIdentifier = 1;
    char str[100];

    for(i = 0; i < k; ++i)
    {
        fgets(str,100,in);
        backStart = 0;
        itemIdentifier = 1;

        for(j = 1; j <= strlen(str); ++j)
        {
            if(str[j] == '-' || str[j] == '\0')
            {
                switch(itemIdentifier)
                {
                case 1:
                    //allocate dynamic memory for each attribute of State object
                    state[i].full = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(state[i].full,str + backStart,j-backStart);
                    state[i].full[j-backStart-1] = '\0';
                    break;

                case 2:
                    state[i].abbre = (char *) malloc( (j-backStart+1) * sizeof(char) );
                    strncpy(state[i].abbre,str + backStart,j-backStart);
                    state[i].abbre[j-backStart-1] = '\0';
                    break;

                default:
                    ; //do nothing
                }
                backStart = j + 2;
                j += 1;
                itemIdentifier++;
            }
        }
    }
    //check_state_data_correctness(state);
}

void main_menu()
{
    printf("Welcome to the admission checker!\n");
    printf("Here is a database of the nation's top 100 universities.\n\n");
    printf("1: Access Data\n");
    printf("2: Data Implementation\n");
    printf("0: Exit\n");
}

void access(School *sch[], State state[])
{
    while(1)
    {
        int choice;
        setjmp(ebuf1);
        printf("\n1: ALL INFORMATION\n");
        printf("2: GPA\n");
        printf("3: SAT_MATH\n");
        printf("4: SAT_READING\n");
        printf("5: TUITION\n");
        printf("6: LAST_STEP\n");
        printf("0: EXIT\n");

        do
        {
            printf("Your choice: ");
            scanf("%d",&choice);
        }
        while(choice < 0 || choice > 6);
        switch(choice)
        {
        case 1:
            displayInfo(sch,state,1);
            break;
        case 2:
            displayInfo(sch,state,2);
            break;
        case 3:
            displayInfo(sch,state,3);
            break;
        case 4:
            displayInfo(sch,state,4);
            break;
        case 5:
            displayInfo(sch,state,5);
            break;
        case 6:
            printf("\n");
            longjmp(ebuf, 3);
        case 0:
            printf("The program is terminated, goodbye!\n");
            exit(0);
        default:
            ; //do nothing
        }
    }

}

void displayInfo(School *sch[], State state[], int infoCode)
{
    while(1)
    {
        static int choice;
        setjmp(ebuf2);
        printf("\n1: All Schools\n");
        printf("2: Specific group\n");
        printf("3: Specific school\n");
        printf("4: Last Step\n");
        printf("0: EXIT\n");

        do
        {
            printf("Your choice: ");
            scanf("%d",&choice);
            getchar(); //discard the \n in the buffer
        }
        while(choice < 0 || choice > 4);

        while(1)
        {
            static int groupCategory = -1;
            char stateAbbr[3];
            if(choice == 2)
            {
                printf("\nChoose specific group:\n");
                printf("1: State\n");
                printf("2: Public School\n");
                printf("3: Private School\n");
                printf("4: Last Step\n");
                printf("5: EXIT\n");
                printf("Your choice: ");

                scanf("%d",&groupCategory);
                getchar();

                if(groupCategory == 1)
                {
                    char state_name[30 * sizeof(char)];

                    do
                    {
                        printf("Please input the state name, either full name or abbreviation:\n");
                        fgets(state_name,30,stdin);
                        state_name[strlen(state_name)-1] = '\0';
                        matchingState(state_name,state);
                        strcpy(stateAbbr,state_name);
                        stateAbbr[2] = '\0';
                    }
                    while(stateAbbr[0] == '\0');

                }
            }

            static int item = -1;
            if(choice == 3)
            {
                char sch_name[60 * sizeof(char)];
                do
                {
                    printf("\nPlease input the full school name. -- is needed before the sub-campus. ");
                    printf("Or press 1 to last step\n");
                    fgets(sch_name,60,stdin);
                    if(strcmp(sch_name,"1\n") != 0)
                        item = matchingName(sch_name,sch);
                    else
                        item = -2;
                    if(item == -1)
                        printf("This university name is invalid. Please try again!");
                }
                while(item == -1);
            }

            static int p;
            for(p = 0; p < school_size; ++p)
            {
                switch (choice)
                {
                case 1:
                    break;
                case 2:
                    if(groupCategory == 1)
                    {
                        if(strcmp(sch[p]->SAbb,stateAbbr)!=0)
                            continue;
                        else
                            break;
                    }
                    if(groupCategory == 2)
                    {
                        if(sch[p]->Pub_Pri == 1)
                            continue;
                        else
                            break;
                    }
                    if(groupCategory == 3)
                    {
                        if(sch[p]->Pub_Pri == 0)
                            continue;
                        else
                            break;
                    }
                    if(groupCategory == 4)
                    {
                        longjmp(ebuf2, 3);
                    }
                    if(groupCategory == 5)
                    {
                        printf("The program is terminated, goodbye!\n");
                        exit(0);
                    }
                    break;
                case 3:
                {
                    if(item == -2)
                        longjmp(ebuf2, 3);
                    if(p != item)
                            continue;
                    else{
                        printf("\n");
                        break;
                    }
                    break;
                }
                case 4:
                    longjmp(ebuf1, 3);
                case 0:
                    printf("The program is terminated, goodbye!\n");
                    exit(0);
                }
                switch (infoCode)
                {
                case 1:
                    printf("%3d: %-60s%-2s    %0.2f    %d    %d    %-5d    %-5d\r\n", p+1,sch[p]->Uname,sch[p]->SAbb,
                           sch[p]->gpa,sch[p]->SAT_M,sch[p]->SAT_R,sch[p]->Tui_out,sch[p]->Tui_in);
                    break;
                case 2:
                    printf("%3d: %-60s%-2s    %0.2f\r\n", p+1,sch[p]->Uname,sch[p]->SAbb,sch[p]->gpa);
                    break;
                case 3:
                    printf("%3d: %-60s%-2s    %d\r\n", p+1,sch[p]->Uname,sch[p]->SAbb,sch[p]->SAT_M);
                    break;
                case 4:
                    printf("%3d: %-60s%-2s    %d\r\n", p+1,sch[p]->Uname,sch[p]->SAbb,sch[p]->SAT_R);
                    break;
                case 5:
                    printf("%3d: %-60s%-2s    %-5d  %-5d\r\n", p+1,sch[p]->Uname,sch[p]->SAbb,
                           sch[p]->Tui_out,sch[p]->Tui_in);
                    break;
                }
            }
            if(choice == 3 || choice == 1)
                longjmp(ebuf2, 3);
        }
    }
}

void matchingState(char *state_name, State state[])
{
    int i;
    toUpperStr(state_name);
    if(strlen(state_name) == 2)
    {
        fflush(stdout);
        for(i = 0; i < state_size; ++i)
        {
            if(strcmp(state_name,state[i].abbre))
                return;
        }
    }
    else
    {
        for(i = 0; i < state_size; ++i)
        {
            char *a = (char *)malloc(strlen(state[i].full)*sizeof(char));
            strcpy(a,state[i].full);
            toUpperStr(a);
            if(strcmp(a, state_name)==0)
            {
                strcpy(state_name,state[i].abbre);
                state_name[2] = '\0';
                return;
            }
        }
    }
    state_name[0] = '\0';
}

int matchingName(char *sch_name, School* sch[])
{
    int i;
    //data washing
    //data = strupr(sch_name);
    sch_name[strlen(sch_name)-1] = '\0';
    toUpperStr(sch_name);
    if(strstr(sch_name,"UNIVERSITY")==sch_name)
        sch_name = sch_name + 14; //case of "UNIVERSITY OF"
    else if(strstr(sch_name,"UNIVERSITY")!= NULL)
        *strstr(sch_name,"UNIVERSITY") = '\0';
    for(i = 0; i < school_size; ++i)
    {
        char *a = (char *)malloc(strlen(sch[i]->Uname)*sizeof(char));
        strcpy(a,sch[i]->Uname);
        toUpperStr(a);
        if(strstr(a,sch_name)!=NULL)
        {
            free(a);
            return i;
        }
    }
    return -1;
}

void toUpperStr(char* str)
{
    int i;
    for(i = 0; i < strlen(str); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

void implementation(School *sch[], State state[])
{
    while(1)
    {
        int choice;
        setjmp(ebuf3);
        printf("\n1: SORTING\n");
        printf("2: AVERAGE\n");
        printf("3: LAST STEP\n");
        printf("0: EXIT\n");
        do
        {
            printf("Your choice: ");
            scanf("%d",&choice);
        }
        while(choice < 0 || choice > 4);

        switch(choice)
        {
        case 1:
            sort(sch,state);
            break;
        case 2:
            average(sch,state);
            break;
        case 3:
            longjmp(ebuf, 3);
        case 0:
            printf("The program is terminated, goodbye!\n");
            exit(0);
        default:
            ; // do nothing
        }
    }
}

void sort(School *sch[], State state[])
{
    while(1)
    {
        printf("\nChoose one criterion:\n");
        printf("1: RANKING\n");
        printf("2: GPA\n");
        printf("3: SAT_MATH\n");
        printf("4: SAT_READING\n");
        printf("5: TUITION(OUT_STATE)\n");
        printf("6: LAST STEP\n");
        printf("0: EXIT\n");

        int criterion = -1;

        do
        {
            printf("Your criterion: ");
            scanf("%d",&criterion);
        }
        while(criterion < 0 || criterion > 6);
        switch(criterion)
        {
        case 1:
            displaySortedInfo(sch,state,1);
            break;
        case 2:
            displaySortedInfo(sch,state,2);
            break;
        case 3:
            displaySortedInfo(sch,state,3);
            break;
        case 4:
            displaySortedInfo(sch,state,4);
            break;
        case 5:
            displaySortedInfo(sch,state,5);
            break;
        case 6:
            longjmp(ebuf3, 3);
        case 0:
            printf("The program is terminated, goodbye!\n");
            exit(0);
        default:
            ; //do nothing
        }
    }
}

void displaySortedInfo(School *sch[], State state[], int criterion)
{
    SchElement order[school_size];
    int i, p;
    // store the data for sort
    switch(criterion)
    {
    case 2:
        for(i = 0; i < school_size; ++i)
        {
            order[i].index = i+1;
            order[i].value = sch[i]->gpa;
        }
        break;
    case 3:
        for( i = 0; i < school_size; ++i)
        {
            order[i].index = i+1;
            order[i].value = sch[i]->SAT_M;
        }
        break;
    case 4:
        for( i = 0; i < school_size; ++i)
        {
            order[i].index = i+1;
            order[i].value = sch[i]->SAT_R;
        }
        break;
    case 5:
        for( i = 0; i < school_size; ++i)
        {
            order[i].index = i+1;
            order[i].value = sch[i]->Tui_out;
        }
        break;
    default:
        ; //do nothing
    }

    qsort(order,school_size,sizeof(order[0]),cmp);

    for( i = 0; i < school_size; ++i)
    {
        p = order[i].index-1;
        printf("%3d    ",i+1);
        if (criterion == 1)
            printf("%3d: %-60s%-2s    %0.2f    %d    %d    %-5d    %-5d\r\n", i+1,sch[i]->Uname,sch[i]->SAbb,
                   sch[i]->gpa,sch[i]->SAT_M,sch[i]->SAT_R,sch[i]->Tui_out,sch[i]->Tui_in);
        else
            printf("%3d: %-60s%-2s    %0.2f    %d    %d    %-5d    %-5d\r\n", p+1,sch[p]->Uname,sch[p]->SAbb,
                   sch[p]->gpa,sch[p]->SAT_M,sch[p]->SAT_R,sch[p]->Tui_out,sch[p]->Tui_in);
    }
}

int cmp(const void* a,const void* b)
{
    return ((SchElement*)a)->value > ((SchElement*)b)->value? 1 :-1;
}

void average(School *sch[], State state[])
{
    while(1)
    {
        int choice;
        printf("\n1: GPA\n");
        printf("2: SAT_MATH\n");
        printf("3: SAT_READING\n");
        printf("4: TUITION(OUT_STATE)\n");
        printf("5: LAST STEP\n");
        printf("0: EXIT\n");

        do
        {
            printf("Your choice: ");
            scanf("%d",&choice);
        }
        while(choice < 0 || choice > 5);
        switch(choice)
        {
        case 1:
            displayAverageInfo(sch,state,1);
            break;
        case 2:
            displayAverageInfo(sch,state,2);
            break;
        case 3:
            displayAverageInfo(sch,state,3);
            break;
        case 4:
            displayAverageInfo(sch,state,4);
            break;
        case 5:
            longjmp(ebuf3, 3);
        case 0:
            printf("The program is terminated, goodbye!\n");
            exit(0);
        default:
            ; //do nothing
        }
    }
}

void displayAverageInfo(School *sch[], State state[], int criterion)
{
    char* cri;
    int i;
    double summation1 = 0;

    // calculate the summation of row data
    switch(criterion)
    {
    case 1:
        cri = "GPA";
        for(i = 0; i < school_size; ++i)
            summation1 = summation1 + sch[i]->gpa;
        break;
    case 2:
        cri = "SAT MATH\0";
        for( i = 0; i < school_size; ++i)
            summation1 = summation1 + sch[i]->SAT_M;
        break;
    case 3:
        cri = "SAT READING\0";
        for( i = 0; i < school_size; ++i)
            summation1 = summation1 + sch[i]->SAT_R;
        break;
    case 4:
        cri = "TUITION FEE ONT STATE\0";
        for( i = 0; i < school_size; ++i)
            summation1 = summation1 + sch[i]->Tui_out;
        break;
    default:
        ; //do nothing
    }
    if(criterion == 1)
        printf("The average %s of admitted students in the top 100 national universities is %0.2f.\n",cri,summation1/school_size);
    else
        printf("The average %s of admitted students in the top 100 national universities is %d.\n",cri,(int)summation1/school_size);

}
