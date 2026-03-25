#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <unistd.h>
#include <unordered_map>

class PurchaseHistory {

  public:
    PurchaseHistory(int num_of_files, char **files, bool terminal);
    ~PurchaseHistory();
    std::string get_client_code_by_id(int client);
    std::string get_product_code_by_id(int product);
    int get_client_id_by_client_code(std::string client);
    int get_product_id_by_product_code(std::string product);
    std::string get_product_name_by_id(int product_id) const;
    std::unordered_map<int,int> get_purchased_items_from_client(int client_id); 
    std::vector<std::list<int>> get_client_purchase_history();
    int get_products_size();

  private:
    std::vector<std::string> all_clients_codes;
    std::vector<std::string> all_products_codes;
    std::vector<std::string> all_products_names;
    std::vector<std::list<int>> purchase_history;
    std::unordered_map<std::string, int> map_client_code_to_id;
    std::unordered_map<std::string, int> map_product_code_to_id;
    std::unordered_map<int, std::string> map_client_id_to_client_code;
    std::unordered_map<int, std::string> map_product_id_to_product;
    std::unordered_map<int, std::string> map_product_id_to_product_name;
    bool quit_flag;

    void load_csv(int num, char **file);
    void terminal_access();
};
