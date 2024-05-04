#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "modifyFile.h"
//the text file is in the debugger folder
int main() {
    using namespace std;
    vector<string> ta;

    fstream myFile;
    myFile.open("TAs.txt", ios::in);

    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            ta.push_back(line);} //retrieve the file in the ta vector
    }
    myFile.close();
    modifyFile file;
    file.filter(ta); //remove the incorrect lines
    std::string option;
do {std::cout<<"1. Add Tas"<<std::endl;
std::cout<<"2. Reorder the file"<<std::endl;
std::cout<<"Choose what you want to do: ";
cin>>option;}
while ((option != "1") && (option != "2"));
std::cout << std::endl;
    if (option == "1"){
   file.addNewTas(ta); //function adds a new Ta
    }
    else {
       file.changeOrder(ta); //function asks you what parameter do you want to sort and sorts it
   }
 int total = ta.size();
   ofstream myFile2("TAs.txt"); //send the corrected text back to the txt file.
   if (myFile2.is_open()) {
       myFile2 << total << endl;
       for (const string& line : ta) {
           myFile2 << line << endl;} //restore ta in txt file.
       myFile2.close();}
    return 0;
}

