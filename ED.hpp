#pragma once
#include <string> 
#include <iostream>
#include <vector> 

class ED {
public:
	ED();
	ED(std::string x, std::string y);
	std::vector<std::vector<int> > get_M();
	//std::vector<std::vector<int> > get_O();
	int get_row();
	int get_col(); 
	char get_y(int index);
	char get_x(int index);
	int penalty(char a, char b);
	int min(int a, int b, int c);
	int OptDistance();
	void Alignment();
	unsigned int len();

private:  
	int row;
	int col;
	std::vector<std::vector<int> > NM; 
	//std::vector<std::vector<int> > other; 
	std::string x;
	std::string y;
};
