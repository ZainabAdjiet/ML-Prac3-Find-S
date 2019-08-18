# Find-S Algorithm

## How it works:
* Reads training instances from file specified
* Uses '{}' as null set for starting, most specific hypothesis
* Iterates over training set to find target concept
* Displays, in output file, how hypothesis changes as training set instances are processed
* Also writes how many additional training instances, compared to the example set, were needed to learn target concept

## How to run:
1. Run 'make'
2. Run 'make run' to run:
    './find_s_algorithm training_set.txt'