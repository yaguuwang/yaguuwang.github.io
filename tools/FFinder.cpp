/*	Blog - FFinder.cpp
 *
 *	Author:	Haoyu Wang
 *	Date:	2016-12-17
 *
 *	Description:
 *		Implementation file of class FFinder which is responsible for rename image files for my blog.
 *
 *	Version:
 *	1.0
 *	- First release
*/
#include "FFinder.h"

FFinder::FFinder()
{
	cout << "Number: "; cin >> number;
	cout << "Year:   ";	cin >> year;	// Only last two digits needed
	cout << "Month:  ";	cin >> month;
	generateFileName(year, month);
	renameFiles();
}

void FFinder::generateFileName(int year, int month)
{
	fileNames.resize(number);
	newFileNames.resize(number);
	for (int i = 0; i < number; i++) {
		string nameIncomplete = "Document-page-0";	// Complete file name should be Document-page-xxx
		// construct string for file name 
		if (i < 9) { 
			nameIncomplete.append("0").append(to_string(i+1));
			newFileNames[i].append(to_string(year)).append("-").append(to_string(month)).append("-").append("0").append(to_string(i+1)).append(".jpg");
		}
		else {
			nameIncomplete.append(to_string(i+1));
			newFileNames[i].append(to_string(year)).append("-").append(to_string(month)).append("-").append(to_string(i+1)).append(".jpg");
		}
		nameIncomplete.append(".jpg");
		fileNames.at(i) = nameIncomplete;
	}
}

void FFinder::renameFiles()
{
	for (int i = 0; i < number; i++) {
		const char *oldF = fileNames[i].c_str();
		const char *newF = newFileNames[i].c_str();
		// Handle the situation that user input of number is larger than number of exsiting files
		if (rename(oldF, newF) != 0) cout << "Failed to rename file \"" << oldF << "\"\n";
	}
}

