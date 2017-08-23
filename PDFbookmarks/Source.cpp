#include <iostream>
#include "pdfbookmarks.h"



int main()
{
	PDFbookmarks p;
	
	if (!p.loadFromFile("bookmarks.txt")) {
		std::cout << "No FILE!\n\n";
	}
	else {
		p.process(32);
		p.writeToFile("out.txt");
	}

	return 0;
}