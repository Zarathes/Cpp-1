#include"stdafx.h"
#include <fstream>
#include "ReadTextFile.h"
#include <sstream>
using std::cout;
using std::cin;
using std::endl;

std::vector<std::string> ReadTextFile::readFile(std::string source){
	source = "../../TextFiles/Room/size.txt";
	std::ifstream input_file{ source };
	std::string line;
	std::vector<std::string> strings;

	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	while (std::getline(input_file, line, ';')) { // getline() geeft false zodra end-of-file is bereikt
		strings.push_back(line);
		cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe
	}
	// zodra input_file weer uit scope raakt (aan het eind van dit block) wordt de file automatisch gesloten
	return strings;
}

std::string randomNize(std::vector<std::string> strings){
	/*int randomIndex = rand() % strings.size();
	std::string result = strings[randomIndex];
	return result;*/
	return "heloooafodfioadfoadfa";
}