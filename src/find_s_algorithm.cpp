#include "find_s.h"

using namespace find_s;
using namespace std;

int main(int argc, char const *argv[]) {
    vector<training_element> training_set;

    if (argc > 1) {
        string filename = string(argv[1]);
        read_training_set(training_set, filename);

        for (training_element el : training_set) {
            cout << el << endl;
        }

        // using '{}' as notation for empty set
        vector<string> hypothesis = { "{}", "{}", "{}", "{}", "{}", "{}" };

        adjust_hypothesis(hypothesis, training_set);

        cout << hypothesis << endl;

        return 0;
    }
    else {
        cout << "no file name specified" << endl;
        return 1;
    }
    
}
