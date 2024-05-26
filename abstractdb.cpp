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
#include <algorithm>
#include <cstring>

/**
 * Saves the table to a CSV file
 * @param filename - the name of the file to save to
 * @return - true if the file was saved, false if the file could not be saved
*/
bool nwen::AbstractDbTable::saveCSV(const std::string& filename){
    std::ofstream file(filename, std::ios::trunc | std::ios::out);
    if(!file.is_open()){
        return false;
    }
    for(int i = 0; i < this->rows(); i++){
        nwen::movie* mv = this->get(i);
        file << mv->id << ",\"" << mv->title << "\"," << mv->year << ",\"" << mv->director << "\"" << "\n"; 
        if(file.fail()){
            file.close();
            return false;
        }
    }
    file.close(); 
    return true;
}

/**
 * Loads the table from a CSV file
 * @param filename - the name of the file to load from
 * @return - true if the file was loaded, false if the file could not be loaded
*/
bool nwen::AbstractDbTable::loadCSV(const std::string& filename ){
     std::ifstream file(filename);
    if(!file.is_open()){
        return false;
    }
    while(!file.eof()){
        if(file.fail()){
            file.close();
            return false;
        }
        
        try {
            nwen::movie mv;
            std::string val;
            std::getline(file, val,',');
            if(file.eof()){
                break;
            }
            mv.id = val.empty() ? throw std::invalid_argument("Empty") : std::stoul(val);
            std::getline(file, val, ',');
            val.erase(std::remove(val.begin(), val.end(), '\"'), val.end());
            std::strcpy(mv.title, val.c_str());
            std::getline(file, val, ',');
            mv.year = val.empty() ? throw std::invalid_argument("Empty") : std::stoi(val);
            std::getline(file, val, '\n');
            val.erase(std::remove(val.begin(), val.end(), '\"'), val.end());
            std::strcpy(mv.director, val.c_str());
            add(mv);
        } catch (const std::invalid_argument& e) {
            file.close();
            return false;
        }
        
    }
    file.close();
    return true;

}