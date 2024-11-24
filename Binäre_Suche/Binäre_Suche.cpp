#include <iostream>
#include <unordered_set>
#include <vector>
template<typename Container, typename T>
auto search(Container& data, const T& taret){
auto begin = data.begin();
auto end = data.end();
while(begin < end){
auto pivot = begin + (end-begin) / 2;
if(*pivot == taret){
return pivot;
}
 else if(*pivot < taret){
begin = pivot + 1;
 }
 else{
end = pivot;
 }
}

if(begin != data.end() && *begin == taret){
return begin;
}
 else{
return data.end();
 }
}

int main(){
auto vec = std::vector<int>{-5, 23, 25, 42, 80};
if(auto iter=search(vec, 23); iter != vec.end()){
  std::cout << "Found in vector : " << *iter << "\n";
 }else{
std::cout << "Not found\n";
 }
}
