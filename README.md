
# Tetris Game On SFML(C++)

This is 2d game that is designed using SFMl library and the back end code all works on C/C++






## Installation/Running on Ubuntu/Linux

Install the SFMl libaray on linux to run the Project/Game

To install the lastest version 2.5.1 of SFMl to run the Game 
Open Terminal and run the command in your Terminal
```bash
    sudo apt-get install libsfml-dev
```
Make sure you already have compiler (GCC) and make if not then install it using
```bash
    sudo apt-get install build-essential
```
After running the following commnads SFMl will be download on your machine.

To run the Game on your Machine 

1. Open the folder in which all the files related to the game are kept (make sure that all the files are in a single file) 

2. Right click in the folder and Open with terminal

3. Then Run the following command on your Machine

```bash
    g++ -c ./main.cpp
    g++ main.cpp -o sfml-app -lsfml-app -lsfml-graphics -lsfml-audio -lsml-window -lsml-system
    ./sfml-app
```

## Installation/Running on window(VS-Code)

Before Installing SFML library make sure that you have already installed VS-Code in your windows 

If VS-Code is not already installed Download VS-Code from the following link

https://code.visualstudio.com/

After VS-Code is download and Installed on your machine open VS-Code and go to extension from the side bar on the left. Search install C/C++

you need to install G++ compile for C++ to run the project 

To install G++ Compiler you need to install Mingw-64 in your Machine

Install Mingw-64 from the following link 

https://sourceforge.net/projects/mingw/

After installing Mingw-64 you need to add the path of Mingw-64 to Enviornment Variables

1. For this open Directory in which mingw-64 is Installed

2. In Mingw-64 Directory open the folder named bin . 

3. Once you have opened bin folder copy the path of the bin folder.

4. Now go to Start Search Menu and search Enviornment Variables. 

5. Open Enviornment Variables and then in System Variables open path.

6. After you are in Path select new path 

7. Paste the copied path there and press OK/Apply

Your G++ Compiler is ready

Now you need to Install SFML 2.5.1 on your windows

1. For this open the Following link

https://www.sfml-dev.org/download/sfml/2.5.1/  
and download GCC 7.3.0 MinGW (DW2) - 32-bit

2.  After the file is Download. It should be in .Zip format. Extract the file and open the Extracted Folder

3. The Folder should contain SFML-2.5.1 folder in it copy the folder and Paste it in your Local Disk(C:)

4. Now open the SFMl-2.5.1 folder. In this folder you will find a folder named bin. Open bin folder copy bin folder path.

5. After then Bin folder path is copied again open Enviornment Variables . Go to path . Add new path and paste the path in it and press Ok/Apply.

6. Restart VS-Code and open it again and now you need to open the folder in which all the file regaring the Tetris game are kept.

7. Once the folder regarding the Game is opened VS-Code press 
Ctrl+Shift+p and from the menu bar open C/C++ configuration.

8. Now you will find out a new folder in the Explorer menu .vscode is created in the folder and open c_cpp_prperties.json

9. You will find a code is written in th file c_cpp_prperties.json . You simple need to write a path in incudePath section
For Example

```code
    "includePath": [
        "${default}",
        "C:\\SFML-2.5.1\\include"
    ]
```

Congratualtion! your SFMl Libaray is ready to run a game

Now, to run the open new terminal from the Terminal menu on the top bar.

After New Terminal is pressed you will find a terminal in the bottom of your screen 

Enter Following commands in the Terminal

```bash
    g++ -IC:\SFML-2.5.1\include -c main.cpp -o main.o
    g++ -LC:\SFML-2.5.1\lib .\main.o -o sfml-app -lmingw32 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lsfml-main -mwindows
    ./sfml-app.exe
```

Congratualtion! now your able to run the SFMl code in Windows














    