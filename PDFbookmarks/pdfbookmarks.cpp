#include "pdfbookmarks.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>



bool PDFbookmarks::loadFromFile(const string& filename)
{
	std::ifstream file(filename);

	if (!file.is_open()) {
		return false;
	}

	file.seekg(0, std::ios::end);   
	this->input.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	this->input.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	file.close();

	return true;
}


bool PDFbookmarks::writeToFile(const string& filename) const
{
	std::ofstream file(filename);

	if (!file.is_open()) {
		return false;
	}

	file << this->output;
	file.close();

	return true;
}


void PDFbookmarks::process(int page_diff)
{
	string bookmark;
	std::istringstream bkstream(this->input);

	std::smatch m, mnum;
	std::regex bk_regex(R"(^(?:(Part|Chapter|Appendix)\s+)?(?:((?:[A-Z]|[[:d:]]+)(?:\.[[:d:]]+)*)\s+)?(.+?/)([[:d:]]+?)$)");
	
	std::regex bk_num("([[:alnum:]]+)\\.");

	string part, num, title, newpage;
	
	//lambda - append space to string if not empty
	auto apsp = [](string& str)->string& { if (!str.empty()) str.append(" "); return str; };
	
	if (this->input != "") {
		//for every bookmark in string
		while (std::getline(bkstream, bookmark)) {
			if (std::regex_match(bookmark, m, bk_regex)) {
				part = m[1].str();
				num = m[2].str();
				title = m[3].str();
				newpage = std::to_string(std::stoi(m[4].str()) + page_diff);
								

				if (!num.empty()) {				
					if (!part.empty()) { 
						if (part != "Part") {
							part.insert(0, 1, '\t');		//indent for chapters, appendixes and etc.
						}							
					}
					else {	//only nums
						std::sregex_iterator end;
						for (std::sregex_iterator si(num.begin(), num.end(), bk_num); si != end; ++si) {
							num.insert(0, 1, '\t');	
						}
						num.insert(0, 1, '\t');
					}
				}
				
				//add title and page
				this->output.append(apsp(part) + apsp(num) + title + newpage + "\n");
			}
		}
	}
}


