#include <string>
#include <iostream>
#include "ED.hpp"
#include <vector>



ED::ED(){
	row=0; 
	col=0; 
	x = ""; 
	y = ""; 
}
ED::ED(std::string xx, std::string yy){
	row=xx.length(); 
	col=yy.length();

	for(int i =0; i<= row+1;i++){
		std::vector<int> temp; 
		for(int j = 0; j<=col+1;j++){
			temp.push_back(-1);
		}
		NM.push_back(temp); 
	}
	x=xx;
	y=yy;
	
}
/*
std::vector<std::vector<int> > ED::get_O(){
	return other; 
}
*/
std::vector<std::vector<int> > ED::get_M(){
	return NM; 
}
int ED::get_row(){
	return row; 
}
int ED::get_col(){
	return col;
}
char ED::get_y(int index){
	return y.at(index); 
}
char ED::get_x(int index){
	return x.at(index);
}
unsigned int ED::len(){
	if(x.length()>=y.length()){
		return y.length(); 
	}
	else{
		return x.length(); 
	} 
}
// that returns the penalty for aligning chars a and b (this will be a 0 or a 1)
int ED::penalty(char a, char b){
	int re =1; 
	(a==b)?(re=0):(re=1);
	return re; 
	
}
// which returns the minimum of the three arguments.
int ED::min(int a, int b, int c){
	if(a<=b && a<=c){
		return a; 		
	}
	else if(b<=a && b<=c){
		return b;
	}
	else if(c<=a && c<=b){
		return c; 
	}
	else{
		std::cout << "something went wrong inside min" << std::endl; 
		return 0; 
	}
}
// which populates the matrix based on having the two strings, and returns the optimal distance (from the [0][0] cell of the matrix when done)
int ED::OptDistance(){
	int count = 0; 
	for(int i= row; i>=0;i--){
		NM[i][col] = count; 
		count = count +2; 
	}
	count =0; 
	for(int i= col; i>=0;i--){
		NM[row][i] = count; 
		count = count +2; 
	}
	
	
	for(int i=row-1;i>=0;i--){
		for(int j=col-1;j>=0;j--){
			int dia = NM[i+1][j+1];
			int below = NM[i][j+1];
			int left = NM [i+1][j];
			dia = dia + penalty(x.at(i),y.at(j));
			NM[i][j] = min( left+2,
					below+2,
					dia);
		}
		
	}
	return NM[0][0]; 
}

void ED::Alignment(){
	for(int i=0;i<=row;){
		for(int j=0;j<=col;){
			int current = NM[i][j];
			int below = NM[i][j+1];
			int left = NM [i+1][j];
			
			
			if(current-2 == below){
				x.insert(j,"-");
				j = j + 1;
				
			}
			else if(current-2==left){	
				y.insert(i,"-");
				i = i + 1;
				
			}
			else{
				j = j + 1;
				i = i + 1;
			}
			
		}
	}
}

