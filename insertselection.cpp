#include <iostream>
#include <vector>

void insertion_sort(const std::vector<int>& vec, std::vector<int>& sorted){
  int len = vec.size();
  sorted = vec;
  for (int i = 1; i < len; ++i){
    int key = sorted[i];
    int j = i - 1;
    while (j>=0 && sorted[j]>key) {
      sorted[j+1] = sorted[j];
      j = j - 1;
    }
    sorted[j+1] = key;
  } //i++和++i的区别
}

int main(){
  std::vector<int> vec = {3,4,7,6,6,7,8,5,2};
  std::vector<int> sorted;
  insertion_sort(vec, sorted); // 调用排序函数
  std::cout << "Sorted vector: ";
  for(int i = 0; i < sorted.size(); ++i) {
      std::cout << sorted[i] << " ";
  }
  std::cout << std::endl;
  return 0;
  }


