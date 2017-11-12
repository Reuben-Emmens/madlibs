#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> findPrompts(const string& s) 
{
  vector<string> ret;

  typedef string::const_iterator iter;

  iter i = s.begin();

  while(i != s.end()) {

    i = find(i, s.end(), '[');

    iter j = find(i, s.end(), ']');

    if(i != s.end()) 
      ret.push_back(string(i, j));

    i = j;
  }
  return ret;
}
