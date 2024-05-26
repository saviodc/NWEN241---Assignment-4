/**
 * abstractdb.hpp
 * C++ header file that should contain declaration for
 * - struct movie (given)
 * - AbstractDbTable abstract class
 * 
 * You need to modify this file to declare AbstractDbTable abstract class 
 * as specified in the hand-out (Task 1)
 */ 



#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

#include <string>

namespace nwen 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

    /**
     * AbstractDbTable abstract class - represents a database table
     * @method rows() - returns the number of rows in the table
     * @method get() - returns a pointer to the movie at the given row
     * @method add() - adds a movie to the table
     * @method update() - updates a movie in the table
     * @method remove() - removes a movie from the table
     * @method loadCSV() - loads the table from a CSV file
     * @method saveCSV() - saves the table to a CSV file
    */
    class AbstractDbTable {
        public:
            virtual int rows() const = 0;
            virtual movie * get(int) const = 0;
            virtual bool add(const movie&) = 0;
            virtual bool update(unsigned long, movie&) = 0;
            virtual bool remove(unsigned long) =0;
            bool loadCSV(const std::string&);
            bool saveCSV(const std::string &);
    };
}

#endif /* __ABSTRACT_DB_HPP__ */
