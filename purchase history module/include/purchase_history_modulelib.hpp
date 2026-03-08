#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <mutex>


class PurchaseHistory {

  public:
    PurchaseHistory();
    ~PurchaseHistory();
    void load_csv(int num, char **file);


  private:
    std::vector<std::string> all_clients;
    std::vector<std::string> all_products;
    std::vector<std::list<std::string>> purchase_history;
    std::vector<std::vector<std::string>> hash_vector;

    std::map<std::string, int> map_client;
    std::map<std::string, int> map_product;

    unsigned long long hash_function_client(std::string);
    unsigned long long hash_function_product(std::string);
    
    void fill_hash_vector();
    void clean_vector();


};
