#ifndef PDFBOOKMARKS_CLASS
#define PDFBOOKMARKS_CLASS

#include <string>

using std::string;

class PDFbookmarks
{
public:
	//ctors and dtors
	PDFbookmarks() = default;
	explicit PDFbookmarks(string& text) : input(text) {};
	explicit PDFbookmarks(const char* text) : input(text) {};
	~PDFbookmarks() = default;
	
	//methods
	void setString(const string& str);
	string getOutput() const;
	bool loadFromFile(const string& filename);
	bool writeToFile(const string& filename) const;
	void process(int page_diff = 0);


private:
	string output = "";
	string input = "";
};


#endif