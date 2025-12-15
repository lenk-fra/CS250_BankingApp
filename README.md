# CS250_BankingApp
This is the repository for Module Eight. It shows 5-3 Project Two (Banking App)

# Project Summary
This project is a banking application that calculates how an investment grows over time using compound interest. The user enters an initial investment amount, a monthly deposit, an annual interest rate, and the number of years. The program then displays two reports: one showing growth without monthly deposits and one showing growth with monthly deposits. The goal of the project is to show how interest and regular deposits affect savings over time.

# What I Did Well
I did a good job separating the program into different parts. The BankingApp class handles all the calculations, while main.cpp handles user input and program flow. I also added input validation in the setter functions to prevent negative values and invalid data. This helps keep the program reliable and easier to debug.

# Areas for Improvement
The code could be improved by adding better input checks when reading user input, such as handling non-numeric values. The output could also be formatted better to show currency with two decimal places. These improvements would make the program more user-friendly and reduce the chance of errors.

# Most Challenging Parts
The most challenging part was calculating compound interest correctly, especially when monthly deposits were included. I solved this by breaking the calculations into monthly steps and using a helper function to calculate monthly interest. Testing the logic step by step helped ensure the results were correct.

# Transferable Skills
This project helped me improve my skills in object-oriented programming, using classes, functions, and vectors. I also practiced input validation, exception handling, and organizing code across multiple files. These skills will be useful in future projects and coursework.

# Maintainability and Readability
I made the program easy to read and maintain by using clear variable names, comments, and consistent formatting. Separating the header and implementation files also makes the code easier to update or expand in the future.
