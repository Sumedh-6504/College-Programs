// Calendar Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day
{
    char *name;
    int date, month, year;
    char *activity;
};

struct Day *Calendar[7];

// Creating the calendar according to the user's needs
void create()
{
    for (int i = 0; i < 7; i++)
    {
        Calendar[i] = (struct Day *)malloc(sizeof(struct Day));

        // Assuming 20 and 100 bytes of memory required for day name and activity on that day and allocating memory using malloc()
        Calendar[i]->name = (char *)malloc(20 * sizeof(char));
        Calendar[i]->activity = (char *)malloc(100 * (sizeof(char)));

        printf("Enter day name: ");
        scanf("%s", Calendar[i]->name);

        printf("Enter date, month and year: ");
        scanf("%d %d %d", &Calendar[i]->date, &Calendar[i]->month, &Calendar[i]->year);

        printf("Enter the activity on day %d : ", i + 1);
        scanf("%s", Calendar[i]->activity);

        printf("\n");
    }
}

// Reading the calendar by the OS
void read()
{
    for (int i = 0; i < 7; i++)
    {
        printf("Day %d ", i + 1);

        printf("Day name: %s \n", Calendar[i]->name);
        printf("Date, Month, Year: %d %d %d \n", Calendar[i]->date, Calendar[i]->month, Calendar[i]->year);
        printf("Activity: %s", Calendar[i]->activity);
        printf("\n");
    }
}

// Now lastly Displaying the Calendar
void display()
{
    printf("Daily Activity details");
    for (int i = 0; i < 7; i++)
    {
        printf("Day %d \n Day name: %s \n Date, Month, Year: %d %d %d \n Day activity: %s \n", i + 1, Calendar[i]->name, Calendar[i]->date, Calendar[i]->month, Calendar[i]->year, Calendar[i]->activity);
    }
}

// Parent function which runs all the above function
int main()
{
    printf("Creating a calendar... \n");
    create();

    printf("Wait, Reading the calendar... \n");
    read();

    printf("Displaying the calendar... \n");
    display();

    // freeing the memory allocated for each day in a week, name of the day and activity due to OS optimisation!
    for (int i = 0; i < 7; i++)
    {
        free(Calendar[i]->name);     // for the name allocation
        free(Calendar[i]->activity); // for the activity allocation
        free(Calendar[i]);           // for the struct Day* allocation
    }
}

/*
Ouput with no warnings, or error

1. Don't give a space in activity while you are giving an input in the terminal
2. while you are creating a struct use char* for the name and activity variables created.
*/
