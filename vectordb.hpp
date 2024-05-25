/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 
#include "abstractdb.hpp"
#include <algorithm>
#include <vector>
namespace nwen{
    class VectorDbTable : public AbstractDbTable{
        private:
        int tableRows;
        std::vector<movie> table;
        public:
            int rows() const ;
            movie * get(int) ;
            bool add(const movie&) ;
            bool update(unsigned long, movie&) ;
            bool remove(unsigned long) ;
            //default constructer 
            VectorDbTable(): tableRows(0) {}
            ~VectorDbTable() {
                table.clear();
            }
    };
}
