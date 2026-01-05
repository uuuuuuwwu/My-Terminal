# Minimalist C++ CLI Shell Emulator (learning project)

A lightweight command-line interface (CLI) emulator written in C++ that simulates a terminal environment with user authentication, virtual paths, and administrative privilege escalation.

###  Features

- **User Sessions:** Basic login system that initializes a home directory and user environment.
- **Admin System:** Dynamic prompt change (from `[$]` to `[#]`) upon successful password verification.
- **Command Dispatcher:** Efficient command handling using a `std::map` of function pointers.
- **Environment Suite:** Includes the `ec` (Environment Control) set of commands for system metadata.

###  Available Commands

"help"        |      Displays general help information.
"ec"	        |      Shows the reference for the "ec" command class.
"ecVersion"	  |      Displays the current software version.
"ecName"	    |      Shows the name of the currently logged-in user.
"ecPath"	    |      Displays the virtual directory path.
"iWannaBeAnAdmin"  |   Prompts for a password to grant administrative rights.
"clear"	      |      Clears the terminal screen.
"exit"	      |      Closes the emulator.

##  How to Run

### Prerequisites
    A C++ compiler (GCC, Clang, or MSVC) supporting C++11 or higher.
    
### Compilation
Open your terminal and run:
```
g++ -o shell_emulator C\ plus\ plus\ program.cpp
```
### Execution
```
./shell_emulator
```
##  Usage Example
<img width="689" height="593" alt="Снимок экрана (33)" src="https://github.com/user-attachments/assets/179c906e-7bc7-46c0-ade8-56462297dc5e" />

License
This project is open-source and available under the MIT License.
