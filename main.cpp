#include <fstream>
#include <iostream>
#include <algorithm>

int main() {
  std::ifstream myfile;
  int ans1 = 0;
  std::string g[3];
  int ans2 = 0;
  int iter = 0;
  myfile.open("input.txt");
  while (myfile) {
    std::string s;
    std::getline(myfile, s);
    std::string half = s.substr(0, s.length() / 2);
    std::sort(half.begin(), half.end());
    std::string otherHalf = s.substr(s.length() / 2);
    //std::cout<<half<<std::endl;
    for (int i = 0; i < half.length(); i++) 
    {
      if(i != 0 && half[i] == half[i-1])
        continue;
      if (otherHalf.find(half[i]) != std::string::npos) 
      {
        int val = half[i];
        if (val < 91)
          val -= 38;
        else
          val -= 96;
        ans1 += val;
        //std::cout << half[i] << val << std::endl;
      }
    }
    //logic 2
    g[iter%3]=s;
    if( (iter + 1) % 3 == 0)
    {
      //group ready
      bool found = false;
      std::sort(g[0].begin(), g[0].end());
      for (int i = 0; i < g[0].length(); i++) 
      {
        if( i != 0 && g[0][i] == g[0][i-1])
          continue;
        if (g[1].find(g[0][i]) != std::string::npos) 
        {
          if (g[2].find(g[0][i]) != std::string::npos)
          {
            int val = g[0][i];
            if (val < 91)
              val -= 38;
            else
              val -= 96;
            ans2 += val;
            //std::cout << iter << ":" << g[0][i] << val << std::endl;
          }
        }
      }
    }
    iter++;
  }
  std::cout<<"Answer1:"<<ans1<<std::endl;
  std::cout<<"Answer2:"<<ans2<<std::endl;
}