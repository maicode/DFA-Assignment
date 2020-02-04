/*********(>'-')>**********
Written by Michael Giraldi
**********<('-'<)*********/
#include <vector>
#include <iostream>

using namespace std;

vector<string> Substrings(vector<char> v) {
    vector<string> str;

	//The 'A' loop.
	for(int i = 0; i < v.size(); i++) {
		if(v[i] == 'A') {
		    
			//The 'T' loop.
			for(int j = i+1; j < v.size(); j++) {
				if(v[j] == 'T') {
				    string s;

				    //Prints every match found.
					for(int k = i; k <= j; k++) {
						s += v[k];
						cout << v[k];
					}

					cout << endl;
					str.push_back(s);
				}
			}
		}
	}
	return str;
}

bool DFA(string substring) {
	bool yes = false;
	string state = "1";
	for(auto chr : substring) {
		if(state == "1") {
			if(chr == 'A')
				state = "2";
			else
				state = "4";
		}
		if(state == "2") {
			if(chr == 'T')
				state = "3";
			else
				state = "2";
		}
		if(state == "3") {
			if(chr == 'T')
				state = "3";
			else
				state = "2";
		}
	}
	if(state =="3")
		yes = true;
	return yes;
}


int main() {
	string input;
	cout << "Input a DNA sequence: ";
	cin >> input;

	cout << "\n" << "Matching patterns are: " << endl;
	vector<char> v(input.begin(), input.end());
	vector<string> resultsVec = Substrings(v);
	cout << endl;
	for(auto x : resultsVec) {
		bool ret = DFA(x);
		string s;
		if(ret == 1) s = "VALID";
		else s = "INVALID";
		cout << "The pattern: ";
		for(auto a : x)
			cout << a;
		cout << " is " << s << "." << endl;
	}

	return 0;
}