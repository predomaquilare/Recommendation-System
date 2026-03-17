#include "../include/purchase_history_modulelib.hpp"

PurchaseHistory::PurchaseHistory(int num, char **file, bool terminal) {
  quit_flag = false;
  PurchaseHistory::load_csv(num, file);
  if(terminal) PurchaseHistory::terminal_access();
}

PurchaseHistory::~PurchaseHistory(){}

void PurchaseHistory::load_csv(int num, char **file) {
  unsigned long int client_count = 0, product_count = 0;

  for (int i = 1; i <= num; i++) {
    std::ifstream arquivo(file[i]);
    std::string linha;
    if (!arquivo.is_open()) {
      std::cerr << "Erro ao abrir arquivo: " << file[i] << std::endl;
      continue;
    }
    while (std::getline(arquivo, linha)) {
      std::stringstream ss(linha);
      std::string data, cliente, produto, nome;
      std::getline(ss, data, ',');
      if(data == "DATA_COMPRA") continue;
      std::getline(ss, cliente, ',');
      std::getline(ss, produto, ',');
      std::getline(ss, nome);
      if (map_client_to_id.find(cliente) == map_client_to_id.end()){
        map_client_to_id[cliente] = client_count;
        map_id_to_client[client_count] = cliente;
        purchase_history.push_back(std::list<int>());
        client_count++;
      }
      if (map_product_to_id.find(nome) == map_product_to_id.end()) {
        map_product_to_id[nome] = product_count;
        map_id_to_product[product_count] = nome;
        product_count++;
      }
      int client_id = map_client_to_id[cliente];
      int product_id = map_product_to_id[nome];
      purchase_history[client_id].push_back(product_id);
    }
  }
  std::cout << "Quantidade de clientes únicos: " << client_count << std::endl;
  std::cout << "Quantidade de produtos únicos: " << product_count << std::endl;
}

std::string PurchaseHistory::get_client_code_by_id(int client) {
  return map_id_to_client[client];
}

std::string PurchaseHistory::get_product_code_by_id(int product) {
  return map_id_to_product[product];
}

int PurchaseHistory::get_id_by_product_code(std::string product) {
  return map_product_to_id[product];
}

int PurchaseHistory::get_id_by_client_code(std::string client) {
  return map_client_to_id[client];
}

std::unordered_map<int,int> PurchaseHistory::get_items_from_client(int client_id) {
  std::unordered_map<int,int> product_count;
  for(int product : purchase_history[client_id]) {
    product_count[product]++;
  }
  return product_count;
}

void PurchaseHistory::terminal_access() {
  int option_choosen;
  int id;
  do {
    option_choosen = 0;
    id = 0;
    std::cout << "\033[2J\033[H"; // limpa terminal
    std::cout << "<=== PurchaseHistoryModule Menu ===>" << std::endl;
    std::cout << "<===      Choose an option      ===>" << std::endl;
    std::cout << "<=   1 -> Get client items        =>" << std::endl;
    std::cout << "<=   2 -> Get client code by id   =>" << std::endl;
    std::cout << "<=   3 -> Get product code by id  =>" << std::endl;
    std::cout << "<=   4 -> Quit                    =>" << std::endl;
    std::cin >> option_choosen;

    switch(option_choosen) {
      case 1: {
                std::cout << "Type the client's id: ";
                std::cin >> id;
                auto items = PurchaseHistory::get_items_from_client(id);
                for(auto &p : items) std::cout << get_product_code_by_id(p.first) << " -> " << p.second << std::endl;
                sleep(3);
              }
              break;

      case 2: {
                std::cout << "<===      Choose an option      ===>" << std::endl;
                std::cout << "<===    Type the client's id    ===>" << std::endl;
                std::cin >> id;
                std::cout << PurchaseHistory::get_client_code_by_id(id) << std::endl;
                sleep(3);
              }
              break;

      case 3: {
                std::cout << "<===      Choose an option      ===>" << std::endl;
                std::cout << "<===   Type the product's id    ===>" << std::endl;
                std::cin >> id;
                std::cout << PurchaseHistory::get_product_code_by_id(id) << std::endl;
                sleep(3);
              }
              break;

      case 4:
              quit_flag = true;
              break;
    }


  } while(quit_flag == false);


}
