#include <iostream>
#include <string>
#include <cstdlib> //atoi
 
using namespace std;
 
int main() {

	int i;
	string vetor[4001] = { "0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
 
    for (i = 11; i < 4000; i++ ) 
    {
        if (i<40) vetor[i] = vetor[10] + vetor[i-10];
        else if(i==40) vetor[i] = "XL";
        else if(i<50) vetor[i] = vetor[40] + vetor[i-40];
        else if(i==50) vetor[i] = "L"; 
               
        else if(i<90) vetor[i] = vetor[50] + vetor[i-50];
        else if(i==90) vetor[i] = "XC";
        else if(i<100) vetor[i] = vetor[90] + vetor[i-90];
        else if(i==100) vetor[i] = "C";
        
        else if(i<400) vetor[i] = vetor[100] + vetor[i-100];
        else if(i==400) vetor[i] = "CD";
        else if(i<500) vetor[i] = vetor[400] + vetor[i-400];
        else if(i==500) vetor[i] = "D";
        
        else if(i<900) vetor[i] = vetor[500] + vetor[i-500];
        else if(i==900) vetor[i] = "CM";
        else if(i<1000) vetor[i] = vetor[900] + vetor[i-900];
        else if(i==1000) vetor[i] = "M";
        
        else if(i<4000) vetor[i] = vetor[1000] + vetor[i-1000];     
     }
 
 
    string temp;
 
    while ( cin >> temp) 
    {
        if ( isdigit (temp [0]) )
        {
        	cout << vetor [atoi(temp.c_str())] << endl;
        }	
        else 
        {
            for (i = 1; i < 4000; i++ ) 
            {
                if ( vetor [i] == temp ) 
                { 
                	cout << i << endl; 
                	break; 
                }
            }
        }
    }
 
    return 0;
}

