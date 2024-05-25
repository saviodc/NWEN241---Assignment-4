/**
 * abstractdb.cpp
 * C++ source file that should contain implementation for member functions
 * - loadCSV()
 * - saveCSV()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Tasks 4 and 5)
 */ 
#include "vectordb.hpp"
#include "abstractdb.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

bool nwen::AbstractDbTable::saveCSV(std::string filename){
    std::ofstream file(filename, std::ios::trunc | std::ios::out);
    if(!file.is_open()){
        return false;
    }
    for(int i = 0; i < this->rows() && file.good(); i++){
        nwen::movie* mv = this->get(i);
        //file << mv->id << "," << mv->title << "," << mv->year << "," << mv->director << "\n";
        file << mv->id << ",\"" << mv->title << "\"," << mv->year << ",\"" << mv->director << "\"" << "\n";    

    }
    file.close(); 
    return true;
}

bool nwen::AbstractDbTable::loadCSV(std::string filename){
    return false;
}