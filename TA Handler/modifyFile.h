#ifndef FILTERING_TA_FILES_MODIFYFILE_H
#define FILTERING_TA_FILES_MODIFYFILE_H
#include <iostream>
#include <fstream>
class modifyFile {
public:
    void filter(std::vector<std::string>& tas);
    void addNewTas(std::vector<std::string>& tas);
    void changeOrder(std::vector<std::string>& tas);
private:
    std::vector<std::string> filterTA;
    std::string yearHired;
    std::string studentID;
    std::string age;
    std::string status;
    bool valid;
    std::vector<std::string> sortedTas;
    int position;
};


#endif //FILTERING_TA_FILES_MODIFYFILE_H
