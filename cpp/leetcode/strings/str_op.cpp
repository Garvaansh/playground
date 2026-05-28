#include <iostream>
#include <string>
using namespace std; 

class Binary {
  string s;
  void display(void);

  public:
    void read(void);
    void chk_bin(void);
    void ones_complement(void);
};

void Binary :: read(void){
  cout << "Enter a binary number: ";
  cin >> s;
}

void Binary :: chk_bin(void){
  for(int i = 0; i < s.length(); i++){
    if(s[i] != '0' && s[i] != '1'){
      cout << "Invalid binary number. Please enter again." << endl;
      exit(0);
    }
  }
  display();
}

void Binary :: ones_complement(void){
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '0'){
      s[i] = '1';
    }
    else{
      s[i] = '0';
    }
  }
  display();
}

void Binary :: display(void){
  cout << "Binary number: ";
  for(int i = 0; i < s.length(); i++){
    cout << s[i]; 
}
cout << "\n";
}

int main()
{
  Binary b;
  b.read();
  b.chk_bin();
  // b.display();
  b.ones_complement();
  // b.display();

    return 0;
}