#include <fstream>
#include <iostream>

int main() {
  std::string s;
  std::ifstream myfile;
  int ans1 = 0;
  int ans2 = 0;
  myfile.open("test-input.txt");
  while (myfile) {
    std::getline(myfile, s);
    std::string half = s.substr(0, s.length() / 2);
    std::sort(half.begin(), half.end());
    std::string otherHalf = s.substr(s.length() / 2);
    for (int i = 0; i < half.length(); i++) {
      if (otherHalf.find(half[i]) != std::string::npos) {
        int val = half[i];
        if (val < 91)
          val -= 38;
        else
          val -= 96;
        ans1 += val;
        std::cout << half[i] << val << std::endl;
      }
    }
  }
}