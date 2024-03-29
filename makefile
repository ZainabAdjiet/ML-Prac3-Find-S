CC = g++
FLAGS = -std=c++11
INCLUDE =

SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(OBJ_DIR) find_s_algorithm

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

find_s_algorithm: $(OBJ_FILES)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c -o $@ $<

run:
	./find_s_algorithm training_set.txt
	
clean:
	rm -rf $(OBJ_DIR)/* find_s_algorithm
