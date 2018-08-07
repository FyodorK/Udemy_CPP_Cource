/*
Atribute Parser. Hackerrank practice

https://www.hackerrank.com/challenges/attribute-parser/problem

Simple imput:

4 3  - number of the strings and queries 

tagged strings:
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>

queries :
tag1.tag2~name
tag1~name
tag1~value

Simple output:

Name1
Not Found!
HelloWorld

*/

#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() 
{
	int N{}, Q{};
	size_t pos{};

	string raw_input{}, tag{}, op_tag{}, word{}, attribute{}, value{};
	map <string, string> dictionary;

	cin >> N >> Q;
	cin.ignore();
	
	// Processing tagged strings

	for (int i{ 0 }; i < N; ++i) {
		getline(cin, raw_input);

		stringstream ss(raw_input);

		while (getline(ss, word, ' ')) {
			if (word[0] == '<') {                           // <tag> 
				if (word[1] == '/') {                       // </tag>
					tag = word.substr(2);
					tag = tag.substr(0, tag.length() - 1);
					pos = op_tag.find("." + tag);
					if (pos == string::npos) {               // end of line
						op_tag = "";
					}
					else {
						op_tag = op_tag.substr(0, pos);
					}
				}
				else {
					tag = word.substr(1);
					if(tag.find(">") != string::npos)
						tag = tag.substr(0, tag.length() - 1);
					if (op_tag == "") {
						op_tag = tag;
					}
					else {
						op_tag = op_tag + "." + tag;
					}
						
				}
			}
			else if (word[0] == '"') {
				pos = word.find_last_of('"');
				value = word.substr(1, pos - 1);
				dictionary[attribute] = value;                     // like python dict ... or .... oh.
			}
			else if (word[0] != '=') {
				attribute = op_tag + "~" + word;
			}
		}
	}

	// Processing queries

	for (int i{ 0 }; i < Q; ++i) {
		getline(cin, raw_input);
		if (dictionary.find(raw_input) == dictionary.end()) {
			cout << "Not Found!" << "\n";
		}
		else {
			cout << dictionary[raw_input] << "\n";
		}
	}

	return 0;
}
