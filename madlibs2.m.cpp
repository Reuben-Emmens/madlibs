#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;

void readWord(string message, string& word) 
{
  cout << message;
  word = "";
  if( !(cin >> word) ) {
    cerr << "Could not read string. Using empty string instead." << endl;
  }
}

void writeStory(string noun) 
{
  cout << "The cat sat on the " << noun << endl;
}

int main()
{
  string noun;

  readWord("a noun: ", noun);

  writeStory(noun);

  return 0;
}
