#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

string convertToString(int number);
void iSystem(string val);
void sleep(int number);
void takePictures(int numberOf, int sleepFor, string directory);
void takePicture(int picNumber, string directory, int sleepFor);
void takePicture(int picNumber, string directory);
void makeDirectory(string directory);
void takePictures(int sleepFor, string directory);
void uploadImage(string Directory, int picNumber);

int main (int argc, char *argv[]){
	takePictures(10, 0, "AnotherFolder");
}


//Takes an int and returns it as a string
string convertToString(int number){
	stringstream ss;
	ss << number;
	return ss.str();
}


//Takes a string input, converts it to a const char* and runs it in the terminal.
void iSystem(string val){
	const char* newConstChar;
	newConstChar = val.c_str();
	system(newConstChar);
}


//Creates and executes a sleep command,combining the iSystem and convertToString methods.
void sleep(int number){
	iSystem("sleep " + convertToString(number));
}


//Takes number of pictures equal to numberOf with a delay in seconds equal to sleepFor.
void takePictures(int numberOf, int sleepFor, string directory){
	makeDirectory(directory);
	for (int x = 0; x < numberOf; x++){
		takePicture(x, directory, sleepFor);
		uploadImage(directory, x);
	}
}

//Takes an infite number of pictures with a delay equal to sleepFor.
void takePictures(int sleepFor, string directory){
	makeDirectory(directory);
	int number = 0;
	while(1){
		takePicture(number, directory, sleepFor);
		uploadImage(directory, number);
		number++;
	}
}

//Waits a number of specified seconds and then calls a function
void takePicture(int picNumber, string directory, int sleepFor){
	sleep(sleepFor);
	takePicture(picNumber, directory);
}

//takes a picture and stores in a specified directory.
void takePicture(int picNumber, string directory){
	//Code for Laptop webcam
	//iSystem("cd " + directory + " && streamer -f jpeg -o image" + convertToString(picNumber) + ".jpeg");

	//Code for the Pi below.
	iSystem("raspistill -o image" + convertToString(picNumber) + ".jpg");
}

//makes a directory within at the same location as the executable
void makeDirectory(string directory){
	iSystem("sudo mkdir " + directory);
}

//Goes to a specified directory and uploads an image and then moves it to
//a specified directory
void uploadImage(string Directory, int picNumber){
	iSystem("./Dropbox-Uploader/dropbox_uploader.sh upload image" + convertToString(picNumber) + ".jpg");
	iSystem("mv image" + convertToString(picNumber) + ".jpg Directory);
}
