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
#include <algorithm>
#include <vector>
#include <functional>

/**
 * Returns the number of rows in the table
 * @return - number of rows
*/
int nwen::VectorDbTable::rows() const{
    return this->tableRows;
}

/**
 * Returns a pointer to the movie at the given row
 * @param row - the row number
 * @return - pointer to the movie at the given row
*/
nwen::movie *  nwen::VectorDbTable::get(int row) const{
    if(row >= this->tableRows || row < 0){
        return nullptr;
    }
    return const_cast<nwen::movie*>(&this->table.at(row));
}

/**
 * Adds a movie to the table
 * @param mv - the movie to add
 * @return - true if the movie was added, false if the movie already exists
*/
bool nwen::VectorDbTable::add(const nwen::movie& mv){
    for(auto& m : this->table){
        if(m.id == mv.id){
            return false;
        }
    }
      this->tableRows++;
      this->table.push_back(mv);
      return true;
}

/**
 * Removes a movie from the table
 * @param id - the id of the movie to remove
 * @return - true if the movie was removed, false if the movie does not exist
*/
bool nwen::VectorDbTable::remove(unsigned long id){
    for(auto it = this->table.begin(); it != this->table.end(); it++){
        if(it->id == id){
            this->table.erase(it);
            this->tableRows--;
            return true;
        }
    }    
    return false;
}/**
* Updates a movie in the table
* @param id - the id of the movie to update
* @param mv - the movie to update
* @return - true if the movie was updated, false if the movie does not exist/ id not found
*/
bool nwen::VectorDbTable::update(unsigned long id, movie& mv) {
    for(auto& m : this->table){
        if(m.id == id){
            m = mv;
            return true;
        }
    }
    return false;
}