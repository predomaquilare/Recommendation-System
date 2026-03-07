#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <mutex>


class PurchaseHistory {

  public:
    PurchaseHistory();
    ~PurchaseHistory();


  private:
    std::vector<string> all_clients;
    std::vector<string> all_products
    std::vector<std::vector<string>> hash_vector;
    unsigned long long hash_function_client(std::string);
    unsigned long long hash_function_product(std::string);
    
    void load_csv(int num, std::string file);
    void fill_hash_vector();


};
