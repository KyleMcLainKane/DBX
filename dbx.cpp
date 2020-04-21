//
//  Kyle McLain Kane (cssc1950)
//  Assignment #1, 2/17/2020, CS530
//  This is a program designed to convert regular files into binary to hex
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>
#include <iomanip>

using namespace std;

// This function is print hex
// format should be address, <B0B1>, human readable form
void printH(const vector<string> &convertedH, int l, string arr){
    int k = 1;
    int j = 0;
    for(int i = 0; i < l; i++){   
        //ADDRESS PRINTING
        if(i % 16 == 0){  
            cout << &convertedH[i] << ": ";
        }

        cout<< convertedH[i];                               //Prints out the data

        if(k % 2 == 0){                                     //Prints out the spacing
            cout << " ";
        }

        if(k % 16 == 0){         
            while(j < k){                                   //Prints out most text
                cout << arr[j];
                j++;
            }
            cout << "\n";            
        }
       
        //Equation used to calculate the offset spaces
        int temp = (l-j);                                   //Length - j
        int temp1 = temp;                                   //Setting temp1 to remainder of subtraction
        temp = 2*temp;
        temp1 = temp1/2;
        int spacesU = temp + temp1;
        int x = 41 - spacesU;

        if(i == l - 1){
            cout << setw(x);                                //Offsetting the blank space
            while(j < l){                                   //Prints out the remainder of the text
                cout << arr[j];
                j++;
            }
        }

        k++;
    }
    
    cout << "\n"; //TEMP
    
}

//Printing out the binary format
void printB(const vector<string> &convertedB, int l, string arr){
    int k = 0;
    for(int i = 0; i < l; i++){                             //For loop to print out contents
        if(i % 6 == 0 && i != 0) {                          //Checks after each 6th element to print the readable file
            while(k < i) {                                  //Prints some readable values
                cout << arr[k];
                k++;
            }
            cout << "\n";                                   //Next line after each 6th element and text
        }

        if(i % 6 == 0)                                      //Prints the address of every first new line
            cout<<&convertedB[i]<<": ";

        cout << convertedB[i] << " ";                       //Printing out the contents

        if(i == l-1){                                       //Prints out the remainder of readable values

            //Calculation for the offset
            int temp = (l-k);       
            int num = temp;
            temp = 8*temp;        
            int spacesU = temp + num;
            int x = 55 - spacesU;

            cout << setw(x);                                //Printing out the necessary spaces

            while(k < l){                                   //Printing out the remaining contents
                cout << arr[k];
                k++;
            }
        }
    }
    cout << "\n";
}

//Converting char to hexadecimal
void hexC(int length, string arr){
    vector <string> buff;                                   //Creating a vector to store converted values
    for(int i = 0; i < length; i++){        
        ostringstream s;
        s << hex<< (int)arr[i];                              //Using hex to convert into hex
        buff.push_back(s.str());                            //Pushing converted hex onto buffer      
    }
    printH(buff, length, arr);                              //Calling print hexadecimal
}

//Converting char to decimal
void bC(int length, string arr){
    vector <string> buff;                                   //Creating a vector to store converted values
    for(int i = 0; i < length; i++){
        ostringstream s;
        s << bitset<8>(arr[i]);                             //Using bitset to convert into binary
        buff.push_back(s.str());                            //Pushing converted binary onto buffer
    }
    printB(buff, length, arr);                              //Calling the print binary
}

//Returns the element where the name of the file is
int type(int argc){
    if(argc > 2) {                                          //Returns a 2 for a binary conversion
        return 2;
    }else{
        return 1;                                           //Returns a 1 for a hex conversion
    }
}

//Main of the program where filename is read
int main(int argc, char** argv) {    
    string STRING;                                           //String from input file
    int temp = type(argc);
    string file = argv[temp];                                //Setting the name of the file
    ifstream myfile(file.c_str());

    //Checks to see if a filename has been provided
    if (argc == 1) {
        cout << "Please enter filename" << endl;       
        return 0;
    }

    //Checking to see if the file is openable
    if (!myfile) {
        cout << "Error opening the file. \n";
        return 0;
    }

    //Reading the file into STRING
    while (!myfile.eof())
        getline(myfile, STRING);
    myfile.close();                                          //Closing the file that we are reading from

    //Setting up an array with an individual char in each cell
    int len = STRING.length();                               //Gets the length of the string
    char arr[len];                                           //Each element will consist of a specific character

    //Checking for unreadable/printable char from ASCII 32-126
    for(int i = 0; i < len; i++){                            //Placing char by char into the new array 
        if((int)STRING[i] > 126 || (int)STRING[i] < 32){     //Checking to make sure they are printable characters
            arr[i] = '.';                                    //If not printable, replace with a .
        }else{
            arr[i] = STRING[i];
        }
    }

    //Process for checking if the user wants binary
    string tp;                                               //Temporary string to make sure the aguement listed is -b
    if (temp == 2) {
        tp = argv[1];
        if (tp.compare("-b") == 0) {
            bC(len, arr);                                    //Calling binary conversion
        }
    }

    //Process for calling hex conversion
    if (temp == 1)
        hexC(len, arr);                                     //Calling hexadecimal conversion

    return 0;
}