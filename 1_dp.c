// Name - Anurag Sarva
// Roll No. - cs24mtech14003
// Subject - ADSA
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

// here i am creating the structure of a doubly linked list which will store character element.
struct input_str
{
    struct input_str *prev;
    char data;
    struct input_str *next;
};

int main()
{
    printf("Enter a valid input string (A to Z or a to z), to check the longest palindromic subsequence(enter characters continuously, without any enter): ");

    // here i am initialising the head of the linked list and one pointer to traverse the linked list.
    struct input_str *head = NULL;
    struct input_str *temp = NULL;
    char data;


    // here i ma taking the input from user and creating the doubly linked list
    while (1)
    {
        scanf("%c",&data);
        if(data == '\n') break;

         if (data == ' ') {
            continue; 
        }
        
        if (!((data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z'))) {
            printf("Invalid input. Please enter only letters which is from A to Z or a to z.\n");
            return 1;
        }

        struct input_str *new_node = (struct input_str *)malloc(sizeof(struct input_str));
        new_node->data = data;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            new_node->prev = NULL;
            temp = new_node;
        } else {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
        }
    }

    if (head == NULL)
    {
        printf("Empty string.\n");
        return 1;
    }

    // here i am calculating the length of the doubly linked list
    struct input_str *ptr = head;

    int len = 0;
    while (ptr->next)
    {
        len++;
        ptr = ptr->next;
    }
    len = len + 1;

    // here i am initializing the DP table, which will memorise the previous solved part.
    int **dp = (int **)malloc(len * sizeof(int *));
    for (int i = 0; i < len; i++)
    {
        dp[i] = (int *)calloc(len, sizeof(int));
    }

    int maxi = 0;

    // here i am filling the DP table for the longest palindromic subsequence
    for (int i = len - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        struct input_str *front = head;
        for (int k = 0; k < i; k++)
            front = front->next;

        struct input_str *bck = front;
        for (int j = i + 1; j < len; j++)
        {
            bck = bck->next;
            if (front->data == bck->data)
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
                if (maxi < dp[i][j])
                    maxi = dp[i][j];
            }
            else
            {
                if (dp[i + 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i + 1][j];
                    if (maxi < dp[i][j])
                        maxi = dp[i][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    if (maxi < dp[i][j])
                        maxi = dp[i][j];
                }
            }
        }
    }

    // here i am printing the length of the longest palindromic subsequence
    printf("The length of the longest palindromic subsequence is %d", maxi);

    // now finding the longest palindromic subsequence with the help of the DP table
    char *rslt = (char *)malloc((dp[0][len - 1] + 1) * sizeof(char));
    rslt[dp[0][len - 1]] = '\0';

    int i = 0;
    int j = len - 1;
    struct input_str *left = head;
    struct input_str *right = ptr;
    int frnt = 0;
    int lst = dp[0][len - 1] - 1;

    // here i am finding the longest palindrome subsequence
    while (i <= j)
    {
        if (left->data == right->data)
        {
            rslt[frnt++] = left->data;
            rslt[lst--] = right->data;
            left = left->next;
            right = right->prev;
            i++;
            j--;
        }
        else if (dp[i + 1][j] > dp[i][j - 1])
        {
            left = left->next;
            i++;
        }
        else
        {
            right = right->prev;
            j--;
        }
    }

    printf("\nLongest palindromic subsequence is: %s\n", rslt);

    // here i am free all the dynamically allocated memory.
    while (head)
    {
        struct input_str *remove = head;
        head = remove->next;
        free(remove);
    }

    return 0;
}