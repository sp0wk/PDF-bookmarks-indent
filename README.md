# PDF-bookmarks-indent

Program opens text file "bookmarks.txt" with bookmarks list (exported from PDF), parses this list and adds proper indent to each line based on the bookmark's nesting in overall bookmarks structure and then saves the result in "out.txt". Then you can import corrected bookmarks into PDF. 
For import/export of the bookmarks list use 3rd-party apps (like [JPdfbookmarks](https://sourceforge.net/projects/jpdfbookmarks/), for example).

To see an example of program's output check out initial "[bookmarks.txt](https://github.com/sp0wk/PDF-bookmarks-indent/blob/master/PDFbookmarks/bookmarks.txt)" and outputted "[out.txt](https://github.com/sp0wk/PDF-bookmarks-indent/blob/master/PDFbookmarks/out.txt)".