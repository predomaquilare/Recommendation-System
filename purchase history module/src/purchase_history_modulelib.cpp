#include "../include/purchase_history_modulelib.hpp"



PurchaseHistory::PurchaseHistory() {


}


PurchaseHistory::~PurchaseHistory(){}


void PurchaseHistory::load_csv(int num, char **file) {
  for(int i = 0; i < num-1; i++) { 
    std::string path = "../sales_data/" + std::string(file[i+1]) + ".csv";
    std::ifstream arquivo(path);
    std::string linha;

    if (!arquivo.is_open()) {
      std::cerr << "Erro ao abrir arquivo: " << path << std::endl;
      continue;
    }

    while (std::getline(arquivo, linha)) {
      std::stringstream ss(linha);
      std::string data, cliente, produto, nome;
      std::getline(ss, data, ',');
      std::getline(ss, cliente, ',');
      std::getline(ss, produto, ',');
      std::getline(ss, nome);
      all_clients.push_back(cliente);
      all_products.push_back(nome);
    }
  }

  purchase_history = std::vector<std::list<std::string>>(all_clients.size());
}

void PurchaseHistory::fill_hash_vector() {



}

void PurchaseHistory::clean_vector() {
  std::sort(all_clients.begin(), all_clients.end());
  all_clients.erase(std::unique(all_clients.begin(), all_clients.end()), all_clients.end());
  std::sort(all_products.begin(), all_products.end());
  all_products.erase(std::unique(all_products.begin(), all_products.end()), all_products.end());
}
