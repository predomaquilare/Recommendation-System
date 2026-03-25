CC = g++
CFLAGS = -g -O3 -march=native -fopenmp -fopt-info-vec-optimized -Wall -Wextra -std=c++17

PURCHASE_MODULE_PATH = purchase\ history\ module/src
SIMILARITY_MODULE_PATH = similarity\ module/src
RECOMMENDATION_MODULE_PATH = recommendation\ module/src

SRC = $(PURCHASE_MODULE_PATH)/purchase_history_modulelib.cpp \
			$(SIMILARITY_MODULE_PATH)/similarity_modulelib.cpp \
			$(RECOMMENDATION_MODULE_PATH)/recommendation_modulelib.cpp\
			main/main.cpp

TARGET = RecommendationSystem

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
