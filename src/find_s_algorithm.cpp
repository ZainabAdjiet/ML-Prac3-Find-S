#include "find_s.h"

using namespace find_s;
using namespace std;

int main(int argc, char const *argv[]) {
    
    vector<string> in1 = { "Sunny", "Warm", "Normal", "Strong", "Warm", "Same" };
    vector<string> in2 = { "Sunny", "Warm", "High", "Strong", "Warm", "Same" };

    vector<training_element> training_set = {
        training_element(in1, true), training_element(in2, true)
    };

    vector<string> hypothesis = { "{}", "{}", "{}", "{}", "{}", "{}" };

    adjust_hypothesis(hypothesis, training_set);

    for (string s : hypothesis) {
        cout << s << " ";
    }

    return 0;
}
