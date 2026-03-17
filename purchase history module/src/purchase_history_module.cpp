#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "../include/purchase_history_modulelib.hpp"

int main (int argc, char **argv) {
  if (argc < 2){
    std::cerr << "You need to pass at least 1 additional arg to use this program" << std::endl;
    return 1;
  }
  PurchaseHistory module((argc-1), argv, false);
  std::vector<std::string> clients = {"99EJYS01","9O09ND01","67701201"};
  std::cout << std::endl;
  
  for(size_t i = 0; i < clients.size(); i++) {
    auto items = module.get_items_from_client(module.get_id_by_client_code(clients[i]));
    std::cout << "Client: " << clients[i] << std::endl;
    for(auto &p : items) std::cout << module.get_product_code_by_id(p.first) << " -> " << p.second << std::endl;
    std::cout << std::endl;
  }
  return 0;
}

