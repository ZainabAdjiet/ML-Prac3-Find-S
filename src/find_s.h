#ifndef FIND_S_H
#define FIND_S_H

/****************************************************************/
/* Includes														*/
/****************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>

/****************************************************************/
/* Functions												    */
/****************************************************************/

namespace find_s {
    
    struct training_element {
        std::vector<std::string> instance;
        bool enjoy_sport;
        training_element(std::vector<std::string> & instance, bool enjoy_sport);
    };

    void read_training_set(std::vector<training_element> & training_set, std::string filename);
    void adjust_hypothesis(std::vector<std::string> & hypothesis, const std::vector<training_element> & training_set);
    std::ostream & operator<<(std::ostream & os, const std::vector<std::string> & str_vect);
    std::ostream & operator<<(std::ostream & os, const training_element & element);
}

#endif
