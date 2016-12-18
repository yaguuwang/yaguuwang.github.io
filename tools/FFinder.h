/*	Blog - FFinder.h
 *
 *	Author:	Haoyu Wang
 *	Date:	2016-12-17
 *
 *	Description:
 *		Header file of class FFinder which is responsible for rename image files for my blog.
 *
 *	Version:
 *	1.0
 *	- First release
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FFinder
{
	public:
		// Default constructor which triggers the whole process
		FFinder();
		// generate old file name and new file name
		void generateFileName(int year, int month);
		void renameFiles();

	private:
		vector<string> fileNames;
		vector<string> newFileNames;
		// Number of files needed to be renamed, input by user and better to be large
		int number;
		int year;
		int month;

};
