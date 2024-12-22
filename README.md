![Budget Management](https://github.com/ewel1991/BudgetApp/raw/main/budgetApp.jpg)

# Budget Application - README

## Overview

This C++ application is a simple budget management system that allows users to log in, register, track their income and expenses, and view their balance for the current and previous months. The application also offers functionalities for changing user passwords and logging out. It uses a text-based menu system and stores data in XML files.

## Files

- **`BudgetMainApp.h`**: Contains the declaration of the `BudgetMainApp` class, which provides functionality for managing users, incomes, expenses, and balance calculations.
- **`Menus.h`**: Contains methods to display different menus in the user interface.
- **`Utils.h`**: The Utils class provides a set of utility functions that are commonly used throughout the application to handle user input and perform basic string and data validation operations
- **`UserManager.h`**: The UserManager class is responsible for managing user authentication and user-related operations such as registration, login, and password changes. 
- **`BudgetManager.h`**: Declares the BudgetManager class responsible for managing the core operations related to income and expenses. It handles operations like adding income and expenses, calculating balances for custom periods, and listing items based on user-specified date ranges.
- **`CashMethods.h`**: Defines the CashMethods class responsible for handling cash-related operations. It provides methods to validate amounts, convert string representations of amounts to double, and check or calculate balances.
- **`DateMethods.h`**: Defines the DateMethods class that manages date-related functionality. It provides methods to validate and convert dates, as well as obtain current and previous month dates for balance calculations.
- **`Operation.h`**: The Operation structure defines a data model used to represent individual financial operations in the budget management system. 

- **`File.h`**: The File class handles file operations for reading and writing XML data.
- **`OperationFile.h`**:The OperationFile class extends the File class and is responsible for handling file operations specific to the financial operations, such as incomes and expenses.
- **`UserFile.h`**: The UserFile class extends the File class and is specifically responsible for handling file operations related to user data.
- **`users.xml`**: Stores user information such as usernames, passwords, and other personal details.
- **`incomes.xml`**: Stores records of user income entries.
- **`expenses.xml`**: Stores records of user expense entries.
  
## Key Features

- **User Authentication**:
  - Log in with an existing account.
  - Register a new user.
  - Log out functionality.

- **Budget Management**:
  - Add income and expenses.
  - View current month, previous month, and custom period balances.
  - Change user password.

- **Menu System**:
  - Home Menu (for login/registration actions).
  - Main Menu (for budget management tasks).

## How It Works

1. **User Interaction**:
    - When the program starts, it checks if the user is logged in.
    - If the user is not logged in, they are presented with the **Home Menu**, where they can choose to log in or register a new user.
    - If the user is logged in, they are presented with the **Main Menu**, where they can perform various actions related to their finances (e.g., adding income, viewing balances, changing password).

2. **Menu Choices**:
    - **Home Menu** options:
      - `1`: Log in an existing user.
      - `2`: Register a new user.
      - `9`: Exit the program.
    
    - **Main Menu** options:
      - `1`: Add income.
      - `2`: Add expense.
      - `3`: View current month balance.
      - `4`: View previous month balance.
      - `5`: View balance for a custom period.
      - `6`: Change user password.
      - `7`: Log out.
      
3. **Exit Mechanism**:
    - The program continues running until the user selects the exit option (`9`), which prints a farewell message and terminates the application.

4. **Data Storage**:
    - User, income, and expense data are stored in XML files (`users.xml`, `incomes.xml`, `expenses.xml`), which are read and written by the `BudgetMainApp` class.

## Dependencies

- **C++ Standard Library**: This program relies on standard input/output and file handling.
  
## Example Usage

### Home Menu

```text
HOME MENU
1. Log in
2. Register
9. Exit
```

- The user can select `1` to log in or `2` to register a new account.
- If the user logs in successfully, the program will switch to the **Main Menu**.

### Main Menu

```text
MAIN MENU
1. Add Income
2. Add Expense
3. Show Current Month Balance
4. Show Previous Month Balance
5. Show Custom Period Balance
6. Change Password
7. Log Out
```

- The user can select options to manage their budget or perform other tasks like changing their password or logging out.

### Exit

```text
See you next time
```

- When the user selects `9`, the program exits with a farewell message.

## Compilation and Running

1. **Compile the Program**:
   ```bash
   g++ -o budget_app main.cpp BudgetMainApp.cpp Menus.cpp Utils.cpp
   ```

2. **Run the Program**:
   ```bash
   ./budget_app
   ```

3. **Exit the Program**:
   - Select option `9` from the menu to exit the application.


## License

This project is open source. Feel free to fork, modify, or contribute!

## Contact

If you have any questions, feedback, or suggestions about this project, feel free to contact me:

    Email: ewelina.beben.programista@gmail.com

  
