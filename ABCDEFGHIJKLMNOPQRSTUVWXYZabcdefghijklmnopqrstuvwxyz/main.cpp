#include <iostream>
#include <regex>
#include <filesystem>
#include <vector>
#include <fstream>
#include <string>

const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", output_dir = "output/";

void increment_string(std::string &s) {
  std::cout << s << std::endl;
  if(s == "") {
    s = characters[0];
    return;
  }
  auto it = s.rbegin();
  while(*it == characters.back() && it != s.rend())
    ++it;
  if(it != s.rend()) {
    *it = *next(std::find(characters.begin(), characters.end(), *it));
  }
  else {
    s = std::string(s.size() + 1, characters[0]);
    return;
  }
  std::string::iterator itt = it.base();
  while(itt != s.end()) {
    *++itt = characters[0];
  }
  return;
}

int main() {
  std::cout << "Program start" << std::endl;
  std::vector<std::string> files;
  constexpr long long line_count = 10000;
  if(!std::filesystem::exists(output_dir)) {
    std::filesystem::create_directory(output_dir);
  }
  std::regex file_pattern("(\\d+)\\.txt");
  for(const auto &entry : std::filesystem::directory_iterator(output_dir)) {
    if(std::regex_match(entry.path().filename().string(), file_pattern)) {
      files.push_back(entry.path().filename().string());
    }
  }
  std::cout << "Listed files" << std::endl;
  sort(files.begin(), files.end(), [&](const std::string &a, const std::string &b) {
    std::smatch res1, res2;
    std::regex_match(a, res1, file_pattern);
    std::regex_match(b, res2, file_pattern);
    return std::stoll(res1[1]) < std::stoll(res2[1]);
  });
  std::cout << "Sorted files" << std::endl;
  std::string last = "";
  if(!files.empty()) {
    std::fstream f(output_dir + files.back());
    while(f >> last) ;
  }
  std::cout << "Last number " << last << std::endl;
  std::smatch last_file;
  if(!files.empty())
    std::regex_match(files.back(), last_file, file_pattern);
  std::ofstream output_file(files.empty() ? output_dir + std::string("0.txt") : output_dir + (std::to_string(1 + std::stoll(last_file[1])) + std::string(".txt")));
  std::cout << "Initialized file" << std::endl;
  for(long long i = 0; i < line_count; ++i) {
    increment_string(last);
    std::cout << i << std::endl;
    output_file << last << std::endl;;
  }
  return 0;
}