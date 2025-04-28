# Todo_list_with_timmer_realtime
Task Manager Console Application

Overview

This is a console-based Task Manager application written in C++ for Windows. It allows users to
Add tasks to a to-do list, which are saved in a text file (sample121.txt).
Set a countdown timer for tasks, stored in a separate text file (Time121.txt).
View the list of tasks, a countdown timer (if set), and the current system time in a formatted console display.
Navigate through a menu-driven interface to perform these actions.
The program uses Windows-specific console cursor positioning (gotoxy) to create an organized display layout and provides a simple way to manage daily tasks with time tracking.

Features-----------------------------------------
Task Input: Add multiple tasks, which are appended to sample121.txt.
Timer Setting: Set a countdown timer (hours, minutes, seconds) for tasks, saved in Time121.txt.
Display: View tasks, countdown timer, and real-time clock in a structured console layout.
Real-Time Clock: Displays the current system time, updated every second.
Menu-Driven Interface: Choose options to input tasks, view tasks, or exit the program.
Visual Feedback: Includes animations (e.g., loading dots) for task storage and program exit

Requirements-------------------------------------------
Operating System: Windows (due to use of windows.h for console cursor positioning).
Compiler: A C++ compiler supporting C++11 or later (e.g., MinGW, MSVC).
Libraries: Standard C++ libraries (iostream, string, fstream, time.h) and Windows API (windows.h).

Installation----------------------------------------------
Clone or Download: Obtain the source code (main.cpp).
Compile the Program:
Using MinGW:
g++ main.cpp -o task_manager.exe
Using MSVC (Visual Studio):
Create a new project, add main.cpp, and build the solution.
Run the Program:
./task_manager.exe
Ensure the executable is in a directory where it can create and access sample121.txt and Time121.txt.

Usage-----------------------------------------------------------
Run the Program:
Launch task_manager.exe in a Windows command prompt or terminal.
Main Menu:
Option 1: Input Tasks/Timer
Choose 1 to add tasks or set a timer.
For tasks, enter the number of tasks and input each task description.
For timer, enter hours, minutes, and seconds for the countdown.
Option 2: View Lists
Displays tasks from sample121.txt, the countdown timer (if set), and the real-time clock.
Tasks are listed with a dash (-) prefix, timer at (50, 4), and clock at (50, 2) in the console.
Option 3: Exit
Exits the program with a brief animation and farewell messages
Example Interaction:-------------------------------------------------------------------------


Welcome to our service
____________________________________
        Press 1 for input tasks
        Press 2 for view lists
        Press 3 to exit
        Enter your choice: 1
______________________________
Enter 1 for saving tasks
Enter 2 for adding timmer in task
Enter the choice: 1
Enter no of tasks: 2
ENTER TASKS
1: Finish homework
ENTER TASKS
2: Buy groceries
Storing Tasks...
your tasks are stored

Then, select option 2 to view:

========Todays Tasks=======
Todays Tasks
  -Finish homework
  -Buy groceries
THE REMAINING TIME LEFT 00:05:00
                      14:23:10

File Structure

main.cpp: The main source code file containing the program logic.
sample121.txt: Stores tasks entered by the user (created automatically on first task input).
Time121.txt: Stores timer settings (hours, minutes, seconds) entered by the user.
task_manager.exe: The compiled executable (generated after compilation).

Notes--------------------------------------------------------------------------


Limitations:---------------------------------------------------------------------
The program is Windows-specific due to the use of windows.h for gotoxy. For cross-platform support, consider using libraries like ncurses.
The real-time clock and countdown timer use separate loops, causing only one to display at a time (noted in the code comments). To display both simultaneously, consider using multithreading or a single loop to update both.
No task deletion or editing functionality is implemented.
Timer settings are appended to Time121.txt without validation or loading previous timers.
The real-time clock loop runs indefinitely when viewing tasks, requiring the user to terminate the program manually (e.g., Ctrl+C).

Potential Improvements:----------------------------------------------------------------
Add task deletion or completion marking.
Load and resume timers from Time121.txt.
Implement a keypress check (e.g., using <conio.h>) to exit the display view back to the main menu.
Validate timer inputs to prevent crashes (e.g., non-numeric input in stoi).
Use a single loop to update both real-time clock and countdown timer for simultaneous display.

Known Issues:---------------------------------------------------------------------------------
The Real_time function contains a recursive call, causing stack overflow. This should be replaced with a loop or removed if the timer is prioritized.
The countdown timer logic in set_timmer has a minor bug where min_in = 60 should be min_in = 59.

Troubleshooting----------------------------------------------------------------------------------
"Invalid opening the file" Error: Ensure the program has write permissions in the directory where sample121.txt and Time121.txt are created.
Timer Not Displaying: If the real-time clock is active, it may prevent the timer from showing due to loop conflicts. Comment out the Real_time() call in Display() to test the timer.
Console Output Overlaps: Adjust gotoxy coordinates in Real_time, show_time_left, or Display to avoid overlapping sections.
