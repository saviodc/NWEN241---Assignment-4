/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 

#include "vectordb.hpp"

int nwen::vectorDbTable::rows() const{
    return this->rows;
}

nwen::movie *  get(int row) const{
    if(row > this.rows){
        return nullptr;
    }
    return & this->table.at(row);
}

bool add(const movie&){
     if (std::find_if(this->table.begin(), this->table.end(), [movie](m)->m.id = movie.id)) return false;
     this->rows++;
     this->table.push_back(movie);
     return true;
}

bool update(unsigned long, movie&){
    
}
