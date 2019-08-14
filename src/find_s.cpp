#include "find_s.h"

using namespace find_s;

training_element::training_element(std::vector<std::string> & in, bool es) :
    instance(in), enjoy_sport(es) {}

void find_s::read_training_set(std::vector<training_element> & training_set, std::string filename) {
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

void find_s::adjust_hypothesis(std::vector<std::string> & hypothesis, const std::vector<training_element> & training_set) {
    for (int i = 0; i < training_set.size(); ++i) {

        training_element element = training_set[i];
        
        if (element.enjoy_sport) {
            assert(element.instance.size() == hypothesis.size());

            for (int j = 0; j < hypothesis.size(); ++j) {
                if (element.instance[j] != hypothesis[j]) {
                    if (hypothesis[j] == "{}")
                        hypothesis[j] = element.instance[j];
                    else if (hypothesis[j] != "?")
                        hypothesis[j] = "?";
                }
            }
        }
    }
}

std::ostream & find_s::operator<<(std::ostream & os, const std::vector<std::string> & str_vect) {
    os << "< ";
    int i = 0;
    for (; i < str_vect.size() - 1; ++i) {
        os << str_vect[i] << ", ";
    }
    os << str_vect[i] << " >";
    return os;
}