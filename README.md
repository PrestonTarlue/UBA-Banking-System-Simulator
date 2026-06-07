UBA Banking System Simulator

This is a core-level command-line banking simulator designed for the HELIOS OS environment. It demonstrates how to manage persistent state, handle user input, and implement basic financial logic in C++.
How It Works

The system operates as a state-based simulator:

    Memory Management: The system uses a std::map as an in-memory database to store account names and their corresponding balances.

    Transaction Loop: A continuous while(true) loop manages the user interface, routing inputs to specific logic functions (Deposit, Withdraw, Balance Check).

    Persistence: Whenever a transaction occurs, the system triggers the SaveData() function. This function iterates through the memory map and synchronizes the current state to a local accounts.txt file, ensuring the bank's data is recorded.

    Input Handling: The system utilizes std::getline combined with std::cin.ignore() to safely handle name strings and prevent buffer overflows or input skipping.

Educational Value: What You Will Learn

By studying and modifying this code, you will understand:

    Data Structures: How to use std::map to associate unique keys (names) with values (balances) efficiently.

    File I/O: The mechanics of std::ofstream for writing persistent data to disk.

    Control Flow: How to use switch statements and infinite loops to build a responsive command-line interface.

    Memory State vs. Disk State: The difference between volatile memory (the RAM where the map lives) and non-volatile storage (the text file).

    Buffer Management: How to manage the input stream properly using cin.ignore() to ensure the terminal reads names correctly.
