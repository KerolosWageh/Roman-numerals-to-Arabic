/*
problem 7 (Roman Numerals to Arabic )
Made by Kerolos Wageh Farouk (20210307)
faculty of Computers and Artifical Intelligence Cairo University
*/


#include <iostream>
#include<string>

using namespace std;

int main()
{
    string Roman_Numerals ;
    int Arabic_Numerals = 0 ;

    cout<<"Enter Capital Roman letter (such as MDLXXIV):   "<<endl;
    cin>>Roman_Numerals; //User enter roman letter

    for( int k=0;k<=Roman_Numerals.size();k++){ // Loop to walk to all of user enter

        if( Roman_Numerals[k] == 'C' && Roman_Numerals[k+1] == 'M' ){
            Arabic_Numerals=Arabic_Numerals+900; // if (C) behind (M) then M - C= 900
            k++;
        }

        else if ( Roman_Numerals[k] == 'C' && Roman_Numerals[k+1] == 'D' ){
            Arabic_Numerals=Arabic_Numerals+400; // if (C) behind (D) then D - C = 400
            k++;
        }

        else if ( Roman_Numerals[k] == 'L' && Roman_Numerals[k+1] == 'D' ){
            Arabic_Numerals=Arabic_Numerals+450; // if (L) behind (D) then D - L =450
            k++;
        }

        else if ( Roman_Numerals[k] == 'X' && Roman_Numerals[k+1] == 'C' ){
            Arabic_Numerals=Arabic_Numerals+90; // if (X) behind (C) then C - X =90
            k++;
        }

        else if ( Roman_Numerals[k] == 'X' && Roman_Numerals[k+1] == 'L' ){
            Arabic_Numerals=Arabic_Numerals+40; // if (X) behind (L) then L - X =40
            k++;
        }

        else if ( Roman_Numerals[k] == 'I' && Roman_Numerals[k+1] == 'X' ){
            Arabic_Numerals=Arabic_Numerals+9; // if (I) behind (X) then X - I =9
            k++;
        }

        else if ( Roman_Numerals[k] == 'I' && Roman_Numerals[k+1] == 'V' ){
            Arabic_Numerals=Arabic_Numerals+4; // if (I) behind (V) then V - I =4
            k++;
        }

        else if (Roman_Numerals[k] == 'M'){
            Arabic_Numerals=Arabic_Numerals+1000; //if user choose (M) then print 1000
        }

        else if(Roman_Numerals[k] == 'D' ){
            Arabic_Numerals=Arabic_Numerals+500; //if user choose (D) then print 500
        }

        else if(Roman_Numerals[k] == 'C'){
            Arabic_Numerals=Arabic_Numerals+100; //if user choose (C) then print 100
        }

        else if(Roman_Numerals[k] == 'L'){
            Arabic_Numerals=Arabic_Numerals+50; //if user choose (L) then print 50
        }

        else if(Roman_Numerals[k] == 'X'){
            Arabic_Numerals=Arabic_Numerals+10; //if user choose (X) then print 10
        }

        else if(Roman_Numerals[k] == 'V'){
            Arabic_Numerals=Arabic_Numerals+5; //if user choose (V) then print 5
        }

        else if(Roman_Numerals[k] == 'I'){
            Arabic_Numerals=Arabic_Numerals+1; //if user choose (I) then print 1
        }

    }

    cout<<"Arabic Numeral of "<<Roman_Numerals<<" is:  "<<Arabic_Numerals<<endl;
}
