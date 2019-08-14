#include "find_s.h"

using namespace find_s;

training_element::training_element(std::vector<std::string> & in, bool es) :
    instance(in), enjoy_sport(es) {}

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