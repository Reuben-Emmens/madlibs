#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
using std::find;
using std::vector;
using std::istream;
using std::ifstream;

// Return a vector<string> of madlib prompts (e.g. noun) found in the supplied
// string 's'. Prompts should be enclosed in square brackets (e.g. The cat sat
// on the [noun].).
vector<string> findPrompts(const string& s) 
{
  vector<string> ret;

  typedef string::const_iterator iter;
  iter i = s.begin();

  while(i != s.end()) {
    i = find(i, s.end(), '[');

    if(i != s.end()) ++i;

    iter j = find(i, s.end(), ']');

    if(i != s.end()) 
      ret.push_back(string(i, j));

    i = j;
  }
  return ret;
}

// Read word from stdin after prompting the user with the supplied 'message'. 
string readWord(string message) 
{
  cout << message << ": ";
  string ret = "";
  if( !(cin >> ret) ) {
    cerr << "Could not read string. Using empty string instead." << endl;
  }
  return ret;
}

// Replace promeaapts of the form [noun] with 
void replacePrompts(string& s, vector<string>& prompts) {
  string::const_iterator i = s.begin();
  string::const_iterator e = s.end();
  vector<string>::size_type j = 0;
  
  while((j != prompts.size() && 
         (i = search(i, e, prompts[j].begin(), prompts[j].end())) != e)) {
    
    string replacement = readWord(prompts[j]);
    s.erase(i - 1, i + prompts[j].size() + 1);
    s.insert(i - 1, replacement.begin(), replacement.end());
    
    ++j;
  }
}

string readStory(string filename)
{
  ifstream infile(filename);

  if(infile.bad()) {
    cerr << "File not found, returning empty string.\n";
    return "";
  }

  std::stringstream buffer;
  buffer << infile.rdbuf();

  return buffer.str();
}

int main()
{
  string s = readStory("story.txt");
  
  vector<string> prompts = findPrompts(s);

  replacePrompts(s, prompts);
 
  cout << s << '\n';

  return 0;
}
