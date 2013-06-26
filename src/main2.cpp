#include <iostream>
#include <string>
#include <map>
using namespace std;

class WTF {
public:
  int myVar;  WTF();
  ~WTF();
  void addMe();
  void sendString(string& str);
  string getString();
};

WTF::WTF(){
  cout << "wtf constructor" << "\n";
  myVar = 2;
}
WTF::~WTF(){
  cout << "wtf desctructor" << "\n";
}
void WTF::addMe(){
  myVar ++;
}
void editString(string* s){
  s->erase(2, 3);
}
void WTF::sendString(string& str){
  
}

string WTF::getString(){
  string s = "";
  return s;
}

void copy(WTF* wtf){
  cout << "inside the copy" << wtf->myVar << "\n";
}

int main(){
  // string s1 = "hello";
  // cout << "before: " << s1 << "\n";
  // editString(&s1);
  // cout << "before: " << s1 << "\n";

  WTF* wtf = new WTF();
  string test = wtf->getString();
  wtf->sendString(test);

  // size_t pos;
  // std::string input = "this is a test     ";
  // pos = input.find_first_of(' ', 0);
  // std::cout <<  "'" << input << "'\n";
  // input.erase(pos, input.length()-1);
  // std::cout <<  "'" << input << "'\n";
  delete wtf;
  
}
