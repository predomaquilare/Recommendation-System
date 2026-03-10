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
#include <unistd.h>


class PurchaseHistory {

  public:
    PurchaseHistory(int num, char **file, bool terminal);
    ~PurchaseHistory();
    std::string get_client_code_by_id(int client);
    std::string get_product_code_by_id(int product);
    int get_id_by_client_code(std::string client);
    int get_id_by_product_code(std::string product);
    std::unordered_map<int,int> get_items_from_client(int client_id); 

  private:
    std::vector<std::string> all_clients;
    std::vector<std::string> all_products;
    std::vector<std::list<int>> purchase_history;
    std::vector<std::vector<std::string>> hash_vector;
    std::unordered_map<std::string, int> map_client_to_id;
    std::unordered_map<std::string, int> map_product_to_id;
    std::unordered_map<int, std::string> map_id_to_client;
    std::unordered_map<int, std::string> map_id_to_product;
    bool quit_flag;

    void vectorToMap(std::vector<std::string> &vetor, std::unordered_map<std::string, int> &mapping_to_id, std::unordered_map<int, std::string> &id_to_mapping); 
    void clean_vector(std::vector<std::string> &clean_vector);
    void load_csv(int num, char **file);
    void terminal_acess();
};
