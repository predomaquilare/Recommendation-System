#include "../include/purchase_history_modulelib.cpp"



PurchaseHistory::PurchaseHistory() {


}


PurchaseHistory::~PurchaseHistory(){}


void PurchaseHistory::load_csv(int num, char **file) {
  for(int i = 0; i < num-1; i++) { 
    std::ifstream arquivo("../../sales_data/" + file[i+1]);
    std::string linha;
    while (std::getline(arquivo, linha)) {

      std::stringstream ss(linha);
      std::string data, cliente, produto, nome;

      std::getline(ss, data, ',');
      std::getline(ss, cliente, ',');
      std::getline(ss, produto, ',');
      std::getline(ss, nome);

      std::cout << "Data: " << data << std::endl;
      std::cout << "Cliente: " << cliente << std::endl;
      std::cout << "Produto: " << produto << std::endl;
      std::cout << "Nome: " << nome << std::endl;
      std::cout << "-------------------" << std::endl;
    }
  }



}
