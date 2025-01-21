// Name - Anurag Savra
// Roll No. - cs24mtech14003
// Subject - ADSA
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

// this is the structure to represent a town by using a doubly linked list
struct towns_dll_node {
    struct towns_dll_node* prev;
    int loc_n;
    struct towns_dll_node* next;
};

int main() {
    struct towns_dll_node* head = NULL;
    struct towns_dll_node* temp_ptr = NULL;
    int n, d;

    // takeing input from user, number of town
    printf("Please enter the number of towns: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter the valid entry....\n");
        return 1;
    }
    int z = 0;
    int low = -1;

    // takeing the input from user for towns location
    printf("Please enter the valid location (i.e. in integer) of the towns in sorted order (i.e. low to high and enter the element one by one by clicking space button, other wise code will give you wrong output) : ");

    int k = 0;
    while(z < n) {
        int loc_n;
        scanf("%d", &loc_n);
        // if(low >= loc_n) {
        //     printf("invalid entry...\n");
        //     return 1;
        // }
        low = loc_n;

        struct towns_dll_node* new_ddl_node = (struct towns_dll_node*)malloc(sizeof(struct towns_dll_node));
        new_ddl_node->next = NULL;
        new_ddl_node->loc_n = loc_n;
        new_ddl_node->prev = NULL;

        // inserting the new node in-to the doubly linked list
        if (head == NULL) {
            head = new_ddl_node;
            temp_ptr = new_ddl_node;
        } else {
            temp_ptr->next = new_ddl_node;
            new_ddl_node->prev = temp_ptr;
            temp_ptr = temp_ptr->next;
        }
        z = z + 1;
    }

    if(n != z)
    {
        printf("Invalid, entry...");
        return 1;
    } 

    int cc = 0;
    struct towns_dll_node* ttmp = head;
    while(ttmp)
        {
            ttmp = ttmp->next;
            cc++;
        }

    if(cc != n) {
        printf("invalid input...\n");
        return 1;
    }
    d = temp_ptr->loc_n;
    temp_ptr = temp_ptr->prev;
    struct towns_dll_node* rem = temp_ptr->next;
    temp_ptr->next = NULL;
    free(rem);

    struct towns_dll_node* pp = head;
    while(pp->next)
    {
        if(pp->loc_n >= pp->next->loc_n)
            {
                printf("Invalid, input.....\n");
                return 1;
            }
        pp = pp->next;
    }

    // taking inputs from the user for maximum distance d
    // printf("Please enter the maximum value of distance d: ");
    // scanf("%d", &d);

    if (d <= 0) {
        printf("Please enter the valid entery for distance...\n");

        // here i am free all the dynamically allocated memory.
        struct towns_dll_node* temp;
        while (head) {
            temp = head;
            head = head->next;
            free(temp);
        }

        return 1;
    }

    // below i am finding the best station location.
    struct towns_dll_node* prsnt = head;
    printf("This is the optimal station loacatin between the towns : ");
    int cnt = 0;
    while (true) {
        if(prsnt){
        int station_loc_n = prsnt->loc_n + d;
        printf("%d ", station_loc_n);
        cnt = cnt + 1;
        // moving the prsnt pointer to the first town that the prsnt station will not cover
        while (true) {
            if(prsnt && prsnt->loc_n <= station_loc_n + d)
                prsnt = prsnt->next;
            else break;
        }}
        else break;
    }

    printf("\n");
    printf("Minimum number of %d station is required, to statisfy the condition.\n",cnt);

    // here i am free all the dynamically allocated memory.
    struct towns_dll_node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}