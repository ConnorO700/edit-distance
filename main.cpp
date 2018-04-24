#include <SFML/System.hpp>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector> 
#include "ED.hpp"
#include <math.h>
#include <iomanip>

using namespace std;
int stringPenalty(char a, char b); 
void printM(vector<vector<int> > mat, int row, int col);
int main(int argc,char *argv[]){
	sf::Clock clock;
	sf::Time t; 
	string x;
	string y;
	cin >> x;
	cin >> y; 
	ED finder(y,x); 
	//printM(finder.get_M(), finder.get_row(), finder.get_col());
	//std::cout << " ___________ " << std::endl;
	//printM(finder.get_O(), finder.get_col(),finder.get_row());

	int editD = finder.OptDistance();

	
	//printM(finder.get_M(), finder.get_row(), finder.get_col());

	finder.Alignment(); 	

	for(unsigned int i=0;i<=finder.len()-1;i++){
		cout << finder.get_x(i) << " " << finder.get_y(i) << " " << stringPenalty(finder.get_x(i),finder.get_y(i)) <<endl;
	}

	//cout << "string length: "<< x.length() << endl; 
	//printM(finder.get_M(), finder.get_row(), finder.get_col());
	t=clock.getElapsedTime(); 
	cout << "Edit Distance: " << editD <<endl;
	cout << "Execution time is " << t.asSeconds() << " seconds" << endl;

}
int stringPenalty(char a, char b){
	if((a=='-')||(b=='-')){
		return 2; 
	}
	else if(a==b){
		return 0;
	}
	else{
		return 1; 
	}
	return -1; 
	
}
void printM(vector<vector<int> > mat, int row, int col){
	for(int i=0;i<=row;i++){
		for(int j=0;j<=col;j++){
			int t = mat[i][j]; 
			if(t<=9&&t>=0){
				cout << "[0" <<t << "]";
			}
			else{
				cout <<"[" <<t << "]"; 
			}
		}
		cout << endl; 
	}
}
