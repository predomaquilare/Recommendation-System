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
    PurchaseHistory(int num, char **file);
    ~PurchaseHistory();
  private:
    std::vector<std::string> all_clients;
    std::vector<std::string> all_products;
    std::vector<std::list<int>> purchase_history;
    std::vector<std::vector<std::string>> hash_vector;

    std::unordered_map<std::string, int> map_client;
    std::unordered_map<std::string, int> map_product;

    bool quit_flag;
    
    void vectorToMap(std::vector<std::string> &vetor, std::unordered_map<std::string, int> &mapping);
    void clean_vector(std::vector<std::string> &clean_vector);
    void load_csv(int num, char **file);

    std::list<int> get_items_from_client(std::vector<std::list<int>> client);
    std::string get_client_code_by_id(int client);
    std::string get_product_code_by_id(int product);
    void terminal_acess();
};
