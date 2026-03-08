CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -Ipurchase_history_module/include

PURCHASE_MODULE_PATH = purchase\ history\ module/src

SRC = $(PURCHASE_MODULE_PATH)/purchase_history_module.cpp \
      $(PURCHASE_MODULE_PATH)/purchase_history_modulelib.cpp

TARGET = PurchaseHistoryModule

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
