//
//
//  InfixPostfix
//
//  Created by Antoun, Sherine on 11/11/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
// Specification file for InfixToPostfix.h

#ifndef H_InfixToPostfix
#define H_InfixToPostfix
  
#include <string>  

using namespace std;

class infixToPostfix
{
public:
	void convertToPostfix();
	bool precedence(char opr1, char opr2);
	void getInfix(string);
	void showInfix();
	void showPostfix();
	infixToPostfix(string = ""); 
    
    string getInfx();
    string getPfx();
		
private:
	string  infx;
	string  pfx;
};

#endif
