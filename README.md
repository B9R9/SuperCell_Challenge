markdown
Copy code
# Platoform Survivor
 The idea was to mix Platform and survivor games. Coin falling from the sky, enemy try to surround you, you will have to collect coin to gain exp and obtain some evolution: Weapons, speed, health, ...
The scene is supposed to change every certain time. 

Probably too ambitious but if you miss the moon, you land on the stars!!!


## Getting Started

These instructions will help you understand how to use the provided Makefile to build, clean, and run your project.

### Prerequisites

- [CMake](https://cmake.org/) installed
- [SFML](https://www.sfml-dev.org/) library (optional, can be downloaded automatically)

### Usage

#### Build Project

To build the project, run the following command:

````make all````  
- This will clear the screen and initiate the build process.

#### Clean Project
To clean the project (remove executables and SFML libraries), run:  
```make clean```   

#### Build and Run
To build and run the project, use:  
````make buildrun````  
- This command will build the project and execute the resulting executable.

Other Targets  
make destroy: Remove the entire build directory.  
make clear: Clear the terminal screen.  
make re: Remove everything and rebuild.  
make XcodeProjet: Create an Xcode project.  
make delete_sfml: Remove the SFML directory.  
make download_sfml: Download SFML if not already present.  
make reset: Remove SFML, clean, remove the build directory, and rebuild.  

#### Additional Notes  
The color codes in the Makefile are for terminal output formatting.  
The generatex_xcode_project.sh script is used to create an Xcode project.  

#### Authors  
Baptiste  
