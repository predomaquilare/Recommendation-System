#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "../include/purchase_history_modulelib.hpp"

int main (int argc, char **argv) {
  PurchaseHistory module;
  module.load_csv(argc, argv);
  return 0;
}

