#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
using namespace std;


bool email_check(string email){
	
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match( email , pattern );
}

main(){
	
	string email;
	
	cout << "\n\n\t\tENTER EMAIL: ";
	cin >> email;
	
	if ( email_check(email) ){
		
		cout << "\n\t\tVALID EMAIL!";
	}else{
		
		cout << "\n\t\tINVALID EMAIL!";
	}
	
	return 0;
}
