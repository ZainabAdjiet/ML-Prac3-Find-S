/****************************************************************/
/* Includes
/****************************************************************/

#include "find_s.h"

using namespace find_s;

/****************************************************************/
/* training_element methods
/****************************************************************/

training_element::training_element(std::vector<std::string> & in, bool es) :
    instance(in), enjoy_sport(es) {}

/****************************************************************/
/* General findS methods
/****************************************************************/

// loads training set for findS from given file
void find_s::load_training_set(std::vector<training_element> & training_set, std::string filename) {
    std::ifstream training(filename);
    std::string line, val;

    if (training.is_open()) {
        getline(training, line); // discard header line

        while (getline(training, line)) {
            std::vector<std::string> instance(6, " ");
            bool enjoy_sport;

            std::istringstream temp(line);
            for (int i = 0; i < 6; ++i) {
                temp >> val;
                instance[i] = val;
            }

            temp >> val;
            if (val == "Yes")   enjoy_sport = true;
            else                enjoy_sport = false;
            
            training_set.push_back(training_element(instance, enjoy_sport));
        }
        training.close();
    }
}

// adjusts hypothesis by comparing its elements with given training instance
void find_s::adjust_hypothesis(std::vector<std::string> & hypothesis, const training_element & element) {
    // only use positive instances
    if (element.enjoy_sport) {
        for (int j = 0; j < hypothesis.size(); ++j) {
            // if there is a difference between elements
            if (element.instance[j] != hypothesis[j]) {
                if (hypothesis[j] == "{}")  // if element is null set, take on value in instance
                    hypothesis[j] = element.instance[j];
                else if (hypothesis[j] != "?")  // if element differs and is not most general, make most general
                    hypothesis[j] = "?";
            }
        }
    }
}

/****************************************************************/
/* Stream operators
/****************************************************************/

// displays training instance attributes and hypothesis as a vector between '<' and '>'
std::ostream & find_s::operator<<(std::ostream & os, const std::vector<std::string> & str_vect) {
    os << "< ";
    int i = 0;
    for (; i < str_vect.size() - 1; ++i) {
        os << str_vect[i] << ", ";
    }
    os << str_vect[i] << " >";
    return os;
}

// displays full training instance with EnjoySport value
std::ostream & find_s::operator<<(std::ostream & os, const training_element & element) {
    os << "< " << element.instance << ", " << element.enjoy_sport << " >";
    return os;
}