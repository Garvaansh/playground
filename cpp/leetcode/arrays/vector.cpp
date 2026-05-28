#include <iostream>
#include <vector>
#include <set>
using namespace std; 

class uniquenum{
  vector<int> nums;
  public: 
  void display(void) {
      for(int x : nums) 
        cout << x << " ";
    }

    void read(void) {
      int num;
      cout << "Enter numbers (-1 to stop): ";
      while(cin >> num, num!= -1) 
      nums.push_back(num);
    }
    
    void remove_dupe() {
      set<int> unique;
      for (int num : nums) {            
          bool is_duplicate = false;     // Flag to track duplicates
          
          // Check if 'num' already exists in 'unique'
          for (int u : unique) {
              if (u == num) {
                  is_duplicate = true;
                  break;
              }
          }
          
          // Add to 'unique' only if it's not a duplicate
          if (!is_duplicate) {
              unique.insert(num);
          }
      }
      for(auto x : unique) 
      cout << x << " ";
    }
};

int main()
{
  uniquenum num1;
  num1.read();
  num1.remove_dupe();

    return 0;
}