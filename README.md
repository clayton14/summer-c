# C Programing at UML

Here is my repo that I am using to track my c learning progress.

## Dependances 

I prefer to work on UNIX / LINUX based machines therefore you can use your package manager to install these dependencies. If you are on windows you can also [use WLS](https://learn.microsoft.com/en-us/windows/wsl/install) to interface with a Linux environment. 

```bash
$ sudo apt install make cmake git
```

## Project Structure

I prefer to work on UNIX / LINUX based machines therefore you can use your package manager to install these dependencies. If you are on windows you can also use WLS to interface with a Linux environment. 

Class is structured by each week that goes by so I have set up a c project using cmake in each `week<week number>` folder. Week 1 will serve as a template for each week.

Here is what the folder strcture of week 1.  

```
week1
├── CMakeLists.txt      // simple CMakeLists.txt
├── build               // Where cmake build files go
├── include             // header files
├── lib                 // external libraries 
└── src                 // source code 
    └── main.c
```

## Compiling and Running Code

Select the week you want to compile and run:

```bash
$ cd <week/build>
$ cmake ..
$ make
```

to run the code, in the build directory:

```bash
$ ./week-1
```