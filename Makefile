CC = g++
CFLAGS = -g -O3 -march=native -fopenmp -fopt-info-vec-optimized -Wall -Wextra -std=c++17

PURCHASE_MODULE_PATH = purchase\ history\ module/src
SIMILARITY_MODULE_PATH = similarity\ module/src

SRC = $(PURCHASE_MODULE_PATH)/purchase_history_modulelib.cpp \
			$(SIMILARITY_MODULE_PATH)/similarity_modulelib.cpp \
			main/main.cpp
			# $(SIMILARITY_MODULE_PATH)/similarity_module.cpp 
      # $(PURCHASE_MODULE_PATH)/purchase_history_module.cpp \


TARGET = RecommendationSystem

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
