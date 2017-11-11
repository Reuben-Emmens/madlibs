#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::endl;
using std::ostream;
using std::cout;
using std::cin;
using std::cerr;

string readWord(istream& in, string message, ostream& out) {
  out << message ;
  string ret = "";
  if( !(in >> ret) ) {
    cerr << "Could not read string. Using empty string instead." << endl;
  }
  return ret;
}

void displayStory(ostream& out, string noun) {
  out << "The cat sat on the " << noun << endl;
}

int main()
{
  string noun;

  noun = readWord(cin, "a noun: ", cout);

  displayStory(cout, noun);

  return 0;
}
