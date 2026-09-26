*This project has been created as part of the 42 curriculum by ndahouk and palkhour.*

# Minishell

## Description

**Minishell** is a simple shell project from the 42 curriculum  written in C language.

The goal of this project is to deeply understand the Bash behaviors and recreate them using processes, files descriptors, signals.

This project focuses on:
- Process creation (fork,execve).
- File descriptor management (dup2,dup, pipes).
- Signal handling (SIGINT, SIGDFL,SIGIGN).
- Parsing.
- Environment variable expansion.
- Built-in command implementation.

This project interprets the user input, executes commands, handles pipes and redirections, then manages environment variables.

---

## Instructions

### Compilation 
```bash
 make 
```
### Run
```bash
./minishell
```
Now welcome to our shell.

Example of few command you can run:  
```bash
 ls
```
```bash
export hi
```
 ```bash
unset hi
```
```bash
cat file.txt | grep 42
```
```bash
cat < file.txt
```
```bash
echo hello world!
```
```bash
cat > file.txt
```
Then to exit our shell you must write :  
exit or use ctrl D

### To remove all generated files:
```bash
make fclean
```

### To recompile:
```bash
make re
```

## Resources

GNU Bash Manual
- man bash
- man execve
- man fork
- man pipe
- man dup2
- man signal

AI Usage  
We used ai tools like ChatGPT to be able to understand the usage of the allowed functions given in the subject
so we know the right place to use them.
To help us debug some issues we faced along the way.

Other peers minishells  
we used some minishells to have a better understanding of what should be handled.


## Author
- **palkhour**
- **ndahouk**