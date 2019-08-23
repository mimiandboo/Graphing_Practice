#include <iostream>
#include <fstream>
#include <string>
#include "adjacencyList.cpp"

using namespace std;

int fileRead(int argc, char* argv[]);
int outputFile(int argc, char* argv[], int counter);
void parseString(string s);
bool checkIfNum(string s);
void removeDuplicates(string s);

// main function
int main(int argc, char* argv[]){
	fileRead(argc, argv);
}

// reads file
int fileRead(int argc, char* argv[]){
	int counter;				// do i need to keep the first num in the file? TODO
	
	for(int i = 1; i < argc - 1; i++){		// reads all files 
		if(argc > 1){
			// displays file name at i
			cout << "argv[" << i << "] = " << argv[i] << endl;
		}	
		else{
			// exits if no file name is entered
			cout << "No file name entered. Exit." << endl;
			return -1;
		}

		ifstream infile(argv[i]);	// opens file
	
		// if file is open and if stream state is good
		// prints out file contents
		if(infile.is_open() && infile.good()){	
			cout << "File is open.\n";
			string line = "";
			
			// outputs all contents of file 
			while(getline(infile, line)){
				parseString(line);
				if(argc == 2){
					counter++;
				}
			}
		}
		// else, file is unable to open display error message 
		else{
			cout << "Failed to open" << endl;
		}
		
		infile.close();			// closes filee
		cout << "File is closed.\n" << endl;
	}

	outputFile(argc, argv, counter);			// outputFile() function called here
	return 0;
}

// writes into output file
int outputFile(int argc, char* argv[], int counter){
	ofstream outputFile;
	outputFile.open(argv[argc - 1]);
	string s = "";
	
//	for(int i = 0; i < counter; i++){
//		s = "Flight " + i + ":\n";
//		outputFile << s;
		
//	}		
	outputFile.close();
	return 0;
}

// parses string using delimeter |
void parseString(string s){
	string token = "";
	size_t pos = 0;
	string delim = "|";
	ofstream file("List", ios::app);
		
	while((pos = s.find(delim)) != std::string::npos){
		token = s.substr(0, pos);
		if(!checkIfNum(token)){
			file << token << endl;
		}
		s.erase(0, pos + delim.length());
	}

	file.close();
	cout << s << endl;
}

// checks if string is int
bool checkIfNum(string s){
	if(isdigit(s[0])){
		return true;
	}

	return false;
}

// removes duplicate strings
//TODO
void removeDuplicates(){
	ofstream file2("List", ios::app);
	string line = "";
	string s = "";
	bool flag = false;

	//getline(file2, s);
	cout << "running duplicate finder" << endl;

	/*while(getline(file, line)){
		while(getline(file2, s)){
			if(s.compare(line) == 0){
				cout << line << endl;
				s.replace(s.begin(), s.end(), "");
				cout << "found a duplicate" << endl;
				flag = true;
				break;
			}
		}

		if(file.eof() || flag == true){
			break;
		}
	}*/

	file2.close();
}
