# Name - Anurag Sarva
# Roll no. - cs24mtech14003
# Subject - ADSA

> README

>> Assignment 2 Overview
This assignment includes two C programs dsa problems:
1. 1_dp.c: This code helps me to  calculate the longest palindrom subsequence, inside a string and by using the dynamic programming approach.
2. 2_greedy.c: This code helps me to determine the optimal place for the stations, so that it cover all the towns along with a line, and with a minimum number of station, which is based on a given maximum distance `d` for which the station gets covered.

>> Here is the Instruction and Command to Run my Code which is in C language.
This below section will provide you a step-by-step guide line on how to compile and execute each code file, by also including the specific commands that helps to run this code files.

>>> This is the Requirements in your system to run the code.
To compile and run the C code files, for that you must have:
- A C compiler, such as `gcc`, installed on your PC.
- A terminal to execute commands.

>>> Compilation Steps
1. Open Terminal in you PC:
   - Include the directory where 1_dp.c and 2_greedy.c code file are saved.

2. Compile Each Program in your PC:
   - Run the following given commands to compile each code file into an executable:
   - For 1_dp.c (Longest Palindrom Subsequence): bash gcc -o longest_palindrome 1_dp.c
   - For 2_greedy.c (Optimal Station Placement): bash gcc -o optimal_station 2_greedy.c
   After done with the compilation process, two different executable file like- "longest_palindrome" and "optimal_station", will be created in your PC's directory.

>>> Process to running each of the programs
Once compiled the file, then run the programs by executing the follosing command.
1. Run "longest_palindrome" Longest Palindrom Subsequence program:
   - Command: bash ./longest_palindrome
   - Instructions:
     - After running the executable file, the program will ask you, to enter the string. This string must contain only the alphabetic characters from A to Z or a to z ,e.g. "ABCADEDCBA".
     - Then the program will calculates and displaying the length and the content of the longest palindrom subsequence in the string provided by user by input.

2. Run "optimal_station" Optimal Station Placement Program:
   - Command: bash ./optimal_station
   - Instructions:
     - While executing the executable file, you will have to be enter input based on the prompt:
       1. Please enter the number of towns in integer and make sure it is valid.
       2. Please enter the locations for each of the town as a series of integers in sorted order, e.g. 1, 4, 8, 12, 15.
       3. Please enter the maximum distance 'd' that the each station can cover.
     - This program will helps me to determine the minimum number of stations required to cover each of the towns with in the distance given by the user and displaying the stations locations and also taking the of total stations.

>>> Example Usage of the code
1. For "longest_palindrome":
   - Input: "ABCADEDCBA"
   - Output will be: Length of the longest palindrom subsequence and also the subsequence itself, e.g. Length: 7, Subsequence: "ABBA".

2. For "optimal_station":
   - Input: 5 (number of towns) & 1, 4, 8, 12, 1 (location of a towns and last one is destance).
   - Output will be: Location of a Station and the minimum number of stations required.

>>> Notes:-
- For Memory Management: In both the program, it automatically free up all dynamically allocated memory space after completing all the tasks.
- For Input Requirements: My code will make ensures that the inputs follows the prompt instruction for the valid program execution.
