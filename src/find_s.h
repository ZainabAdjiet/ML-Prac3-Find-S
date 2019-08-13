#ifndef FIND_S_H
#define FIND_S_H

/****************************************************************/
/* Includes														*/
/****************************************************************/

#include <iostream>
#include <string>
#include <vector>

/****************************************************************/
/* Functions												    */
/****************************************************************/

namespace find_s {
    
    struct training_element {
        std::vector<std::string> instance;
        bool enjoy_sport;
    };

    void adjust_hypothesis(std::vector<std::string> hypothesis, std::vector<training_element> training_set);
}

#endif
