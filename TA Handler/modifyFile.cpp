#include "modifyFile.h"
#include <fstream>
void modifyFile::filter(std::vector<std::string>& tas) {
    int lineCount = 0;

    for (const std::string& line : tas) {
        if (lineCount == 0) {  // the first line is removed because it contains the total number
            lineCount++;
            continue;}
        if (line.find("Alum") == -1) { //lines with the string Alum are removed
            filterTA.push_back(line);}}
    tas = filterTA;}

void modifyFile::addNewTas(std::vector<std::string>& tas) {
    valid = true;
    int validityYearHired;
    while (valid) { //loops if any of the conditions are true
        valid = false;
        try {
            std::cout << "Year Hired: ";
            std::cin >> yearHired;
            validityYearHired = std::stoi(yearHired); //converts year to integer to check issues
        } catch (const std::invalid_argument &a) {
            std::cerr << "Error" << a.what();
            valid = true;
        }
        catch (const std::out_of_range &a) {
            std::cerr << "Error" << a.what();
            valid = true;
        }
        if (validityYearHired < 2011 || validityYearHired > 2024) { //checks year range
            valid = true;
            std::cout << "The year is not in between 2010 and 2024"<<std::endl;
        }
    }
    valid = true;
    int validityID;
    while (valid) {//loops if any of the conditions are true
        valid = false;
        try {
            std::cout << "Enter a 7 digit Student ID: ";
            std::cin >> studentID;
            for (const std::string &line: tas) {
                if (line.find(studentID) == -1) {}
                else {
                    valid = true; //loops if studentID is already used
                    std::cout << "The student ID entered is already used";
                }
            }
            validityID = std::stoi(studentID); //converts ID integer to check issues
        } catch (const std::invalid_argument &a) {
            std::cerr << "Error" << a.what();
            valid = true;
        }
        catch (const std::out_of_range &a) {
            std::cerr << "Error" << a.what();
            valid = true;
        }
        if (validityID < 1000000 || validityID > 9999999) { //makes sure the ID is 7 digits
            valid = true;
            std::cout << "The number entered is not 7 digits";
        }
    }

    valid = true;
    int validityAge;
    while (valid) { //loops if any of the conditions are true
        valid = false;
        try {
            std::cout << "Age: ";
            std::cin >> age;
            validityAge = std::stoi(age); //converts age integer to check issues
        } catch (const std::invalid_argument &a) {
            std::cerr << "Error" << a.what();
            valid = true;
        }
        catch (const std::out_of_range &a) {
            std::cerr << "Error" << a.what();
            valid = true;
        }
        if (validityAge < 15 || validityAge > 49) { //checks for a correct age range
            valid = true;
            std::cout << "The age is not in between 14 and 50";
        }
    }


    do {
        std::cout << "Status(Grad or UGrad): ";
        std::cin >> status;
    } while ((status != "Grad") && (status != "UGrad")); // Loops as long as the status is not Grad or UGrad

    std::vector<std::string> addTa = {yearHired,studentID,age,status};
    tas.push_back(addTa[0] + " " + addTa[1] + " " + addTa[2] + " " + addTa[3]); //inserts the new line in the Ta vector
    }


void modifyFile::changeOrder(std::vector<std::string>& tas) {
    std::string choice1, choice2;
    do {
        std::cout << "Choose by what setting do you want to order the Tas" << std::endl; //menu
        std::cout << "1. Year Hired" << std::endl;
        std::cout << "2. Student ID" << std::endl;
        std::cout << "3. Age" << std::endl;
        std::cout << "4. status" << std::endl;
        std::cout << "Choose an option from 1 to 4: ";
        std::cin >> choice1;
    } while ((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4")); //menu
    do {
        std::cout << "1. Ascending order" << std::endl;
        std::cout << "2. Descending order" << std::endl;
        std::cout << "Choose 1 or 2: ";
        std::cin >> choice2;
    } while ((choice2 != "1") && (choice2 != "2"));
    int i = 0;
    int total = tas.size();
    std::vector<int> numbersToSort(total); //to sort the numbers
    std::vector<std::string> stringsToSort(total); //to sort the strings and re-insert the information in tas
    int infoNumber;
    if (choice1 == "1") { position = 0;} // position of year hired
    else if (choice1 == "2") {position = 5;} // position of student number
    else if (choice1 == "3") {position = 13;} // position of age
    else{}
            if (choice1 == "1" || choice1 == "2" || choice1 == "3") {
                for (const std::string &line: tas) {
                    studentID = line.substr(position, line.find(" ", position) - position); //extract the element desired based on the position
                    infoNumber = std::stoi(studentID); //convert the string to number
                    numbersToSort[i] = infoNumber;
                    i++;
                }
            }
            else{}
        if (choice1 == "4"){
        position = 16;
        for (const std::string &line: tas) {
            // store the status, no need to convert this one in number
                status = line.substr(16, line.find(" ", 16) - 16);
                stringsToSort[i] = status;
                i++;
            }
        }

    std::cout<<std::endl;
    if (choice1 == "1" || choice1 == "2" || choice1 == "3"){ //Sort the parameters that are numbers
        if(choice2 == "1"){ //ascending order
            std::sort(numbersToSort.begin(),numbersToSort.end(),[](int first,int second){
                return first<second;
            });}
        else{ //descending order
            std::sort(numbersToSort.begin(),numbersToSort.end(),[](int first,int second){
                return first>second;
            });}
               for(int i = 0;i<total;i++){
                stringsToSort[i] = std::to_string(numbersToSort[i]);}  // convert the numbers to strings
                                                                          // to put them back in the ta vector in order
    }
    else{   //Sort the status
        if(choice2 == "1"){ //ascending order
            std::sort(stringsToSort.begin(),stringsToSort.end(),[](std::string first,std::string second){
                return first<second;
            });}
        else{ //descending order
            std::sort(stringsToSort.begin(),stringsToSort.end(),[](std::string first,std::string second){
                return first>second;
            });}
    }
    i = 0;
    filterTA.clear();
    std::string removeLine;
    std::string marker;
    for (int j=0; j<total;j++) { //loop is equal to the number of Tas to store every line one at a time
        for (const std::string &line: tas) {
            marker = line.substr(position, line.find(" ", position) - position); //finds the position of the element to compare
            if (stringsToSort[i] != marker) {
            } // strings to sort has the elements in order
              // if it doesn't find the first element, it loops until it finds it
            else {
                sortedTas.push_back(line); //when it finds it, it stores the line
                removeLine = line.substr(5, line.find(" ", 5) - 5); //store the unique student id
                break; // breaks out of the loop because the element has been found
            }
        }
        for (const std::string& line : tas){ // necessary loop to avoid duplicates
            if (line.find(removeLine ) == -1){ //makes sure to remove the line with the tagged student id
                filterTA.push_back(line);
            }
    }
        tas = filterTA; //stores the new Ta vector without the already stored line
        filterTA.clear();
    i++;} // goes to the next element
   tas = sortedTas;

}