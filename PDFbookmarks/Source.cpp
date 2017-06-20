#include <iostream>
#include <regex>
#include "pdfbookmarks.h"

using namespace std;

int main(int argc, char* argv[])
{
	PDFbookmarks p/*("27.6.1 Output/1082")*/;
	if (!p.loadFromFile("bookmarks.txt")) cout << "No FILE!\n\n";
	p.process(32);
	p.writeToFile("out.txt");

	//std::smatch mnum;
	//string num = "10.10 A standard input loop/397";
	//std::regex bk_regex(R"(^(?:(Part|Chapter|Appendix)\s+)?(?:((?:[A-Z]|[[:d:]]+)(?:\.[[:d:]])*)\s+)?(.+?/)([[:d:]]+?)$)");	
	//std::regex bk_num("[[:alnum:]]+\\.?");

	//std::sregex_iterator end;
	//for (std::sregex_iterator si(num.begin(), num.end(), bk_num); si != end; ++si) {
	//	num.insert(0, 1, '\t');	
	//}

	//if (std::regex_match(tst, bk_regex)) cout << "OK!!\n";
	
	//cout << p.getOutput();
	
	//system("pause");

	return 0;
}