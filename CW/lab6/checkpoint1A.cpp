#include <iostream>
#include <string>
#include <vector>


template <class T>
void print(std::vector<T> &data, const std::string &label) {
  std::cout << label << " ";
  for (int i = 0; i < data.size(); i++) {
    std::cout << " " << data[i];
  }
  std::cout << std::endl;
}


template <class T>
void reverse(std::vector<T> &data) {

  int s = data.size();
  if (s == 2) {
    T a = data[0];
    data[0] = data[1];
    data[1] = a;
  }
  for (int i = 0; i < s / 2; i++) {
      T a = data[i];
      data[i] = data[s-i-1];
      data[s-i-1] = a;
  }
  // bool b = s % 2 == 0;
  // if (b){
  //   for (int i = 0; i < s / 2; i++) {
  //     T a = data[i];
  //     data[i] = data[s-i-1];
  //     data[s-i-1] = a;
  //   }
  // }
  // else{
  //   for (int i = 0; i < s / 2; i++) {
  //     T a = data[i];
  //     data[i] = data[s-i];
  //     data[s-i] = a;
  //   }
  // }
  
}


int main() {
  std::vector<int> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(5);
  data.push_back(6);
  data.push_back(7);

  print(data,"before:");
  reverse(data);
  print(data,"after: ");

  std::vector<std::string> data2;
  data2.push_back("apple");
  data2.push_back("banana");
  data2.push_back("carrot");
  data2.push_back("date");

  print(data2,"before:");
  reverse(data2);
  print(data2,"after: ");
}
