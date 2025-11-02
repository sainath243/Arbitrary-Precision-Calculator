# Arbitrary-Precision-Calculator
🎯 Arbitrary Precision Calculator (ACP) in C

This project is a terminal-based Arbitrary Precision Calculator (ACP) developed in the C programming language. It performs arithmetic operations on very large numbers that cannot be handled by standard C data types. The system demonstrates the use of doubly linked lists, modular programming, and dynamic memory management, making it a strong foundation for advanced applications in compiler design, cryptography, and scientific computing.

📌 Project Overview

->Standard data types (int, long, float) have limited range and lose accuracy when numbers exceed their limits. The ACP project overcomes this limitation by representing each number as a doubly linked list of digits, enabling operations on numbers of arbitrary size.

->The calculator supports Addition, Subtraction, Multiplication, Division, Modulo, and Power, ensuring accurate results for high-precision calculations. It is useful for educational purposes, understanding data structures, and exploring big number arithmetic in real-world systems.

⚙️ Components / Tools Used

->C Programming Language
->GCC Compiler
->Command-line Interface (CLI)
->Doubly Linked List (for storing big numbers)
->Modular Programming Techniques

📁 File Modules
main.c – Handles command-line input, sets up the double linked lists for the numbers, and manages the overall program flow for performing operations on the numbers.

comparelist.c – Contains functions to compare two double linked lists representing numbers, useful for validating or comparing magnitudes.

apc.h – Header file declaring structures, constants, and function prototypes shared across other source files.

addition.c – Performs addition operation on two double linked lists representing numbers.

subtraction.c – Performs subtraction operation on two double linked lists representing numbers.

multiplication.c – Performs multiplication operation on two double linked lists representing numbers.

division.c – Performs division operation on two double linked lists representing numbers.

function.c – Contains utility or helper functions used by multiple modules (general-purpose functions).

operations.c – Manages the dispatching and execution of various arithmetic operations on double linked lists.

🧠 Working Principle
->The system reads input numbers (from CLI or file), converts them into doubly linked lists, and applies arithmetic algorithms digit by digit.
->It processes operations as follows:
->Addition & Subtraction: Performed digit-wise with carry/borrow propagation
->Multiplication: Implemented using repeated addition or digit-shift method
->Division & Modulo: Performed via repeated subtraction and quotient tracking
->Power: Calculated using iterative multiplication
->This ensures correctness and precision regardless of the number size.

🔐 Input Validation & Error Handling
->Verifies that inputs are valid integers (ignores leading zeros).
->Handles division by zero with meaningful error messages.
->Rejects invalid tokens (e.g., letters in numeric input).
->Prevents memory leaks through proper allocation and deallocation.

💡 Features

✅ Handles very large numbers beyond built-in limits 
✅ Supports addition, subtraction, multiplication, division, modulo, and power 
✅ Uses doubly linked lists for digit-by-digit precision 
✅ Modular codebase for maintainability and extension 
✅ Provides error handling (division by zero, invalid input) 
✅ Demonstrates dynamic memory management and data structures in C 
✅ Can be extended for cryptography and scientific computing

📂 File Structure

arbitrary-precision-calculator/
├── main.c          # Program entry point, command-line processing
├── addition.c      # Big integer addition on doubly linked lists
├── subtraction.c   # Big integer subtraction on doubly linked lists
├── multiplication.c # Big integer multiplication on doubly linked lists
├── division.c      # Big integer division on doubly linked lists
├── operations.c    # Dispatch for arithmetic operations
├── comparelist.c   # Comparison functions for doubly linked list numbers
├── function.c      # General utility and helper functions
├── apc.h           # Global declarations, structs, and prototypes
├── README.md # Project documentation

📸 Project Media



<img width="404" height="285" alt="2" src="https://github.com/user-attachments/assets/4a1e728a-089c-4dcc-af7f-7e993657a8e8" />       <img width="309" height="262" alt="3" src="https://github.com/user-attachments/assets/94539836-a8ca-4aee-ae63-d0fc9bea6664" />

<img width="349" height="268" alt="4" src="https://github.com/user-attachments/assets/73b7eac7-f9d3-47b5-9f6d-7a0c4becec49" />      <img width="348" height="261" alt="5" src="https://github.com/user-attachments/assets/a06e1978-3db5-4c93-a09c-82c1690a37d6" />

<img width="375" height="259" alt="6" src="https://github.com/user-attachments/assets/b051908b-2f76-42d7-917d-95bed4e6d53b" />

📈 Future Improvements
->Support for floating-point arbitrary precision arithmetic
->Implementation of factorial, logarithm, and trigonometric functions
->Expression evaluation with operator precedence (similar to a scientific calculator)
->GUI version using GTK or Qt for enhanced visualization
->Export results in CSV or JSON formats for further analysis
->Optimized algorithms such as Karatsuba multiplication and divide-and-conquer division
->Library version for easy integration with other applications

👨‍💻 Developed By C.Sainath chennasainath2051@gmail.com

chenna Sainath Embedded Systems & Compiler Design Enthusiast 
📧 chennasainath2051@gmail.com
