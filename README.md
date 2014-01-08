Taking-pictures-with-a-Pi
=========================

The main idea behind this script is to run on a raspberry pi to take pictures and store them in a specific directory. 

Although the goal of just taking pictures was met with very little problems I decided to take it further so it could be used for more then one application.

Note: As of right now the user had to edit the code inorder for it to work by changing the values in the function call within main().

This will only run on Linux sytems and Arm Linux systems such as operating systems for the raspberry pi. Please compile the code with the correct compiler for your system.

To run, download main.cpp file and compile it using the g++ command in the terminal. This will compile it to work with arm processors, please not that you must comiple if on your Raspberry Pi for this reason. After comipling simply run the programm. In order for the dropbox functionality to work please have Dropbox uploader installed and set up, if it isn't set up you will be requried to when you first run this program.
