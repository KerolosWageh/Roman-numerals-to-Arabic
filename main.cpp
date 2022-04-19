// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];
char name1[100];
char name2[100];
char name3[100];

void loadImage ();
void loadImage2();
void saveImage ();
void InvertImage ();
void RotateImage ();
void EnlargeImage ();
void saveImageEnlarge () ;
void ShuffleImage ();



int main(){
    loadImage();

    char num ;
    cout<<"choose number of filter"<<endl<< "2-InvertImage"<< endl << "5-RotateImage"<<endl<<"8-EnlargeImage"<<endl<<"b-ShuffleImage"<<endl;
    cin >>num;

    if (num == '1'){
        void detectEdgesFilter();

        }

    else if (num == '2'){
        InvertImage();
        saveImage();
        }

    else if (num == '5' ){
        RotateImage ();
        saveImage();
        }

    else if (num == '8'){
        EnlargeImage ();
        saveImageEnlarge ();
        }



     else if (num == 'b'){
        ShuffleImage ();
        saveImage();

    }




  return 0;
}


void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}


void loadImage2(){
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);

}

void saveImageEnlarge () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image2);

}


void InvertImage() {        //num=2
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

       image[i][j] = (SIZE-1) - image[i][j];

// do something with the image
    }
  }
}


void RotateImage() {        //num=5
    int number;
    cout<<"choose number"<<endl<<"1-rotate the image clockwise by 90 degree"<<endl;
    cout<<"2-rotate the image clockwise by 180 degree"<<endl<<"3-rotate the image clockwise by 270 degree"<<endl;
    cin>> number;

    if(number == 1 ){
        for (int i = 0; i < (SIZE);i++){
            for (int j = 0; j < (SIZE);j++){

                image[i][j] = image[-j][-(SIZE+SIZE/8)-i];
            }
        }
    }

    else if (number == 2){
        for (int i = 0; i < (SIZE/2);i++){
            for (int j = 0; j < SIZE;j++){

                swap(image[i][j] , image[SIZE-1-i][j]);
            }
        }
        for (int i = 0; i < (SIZE);i++){
            for (int j = 0; j < (SIZE/2);j++){

            swap(image[i][j] , image[i][SIZE-1-j]);
            }
        }
    }

    else if (number == 3){
        for (int i = 0; i < (SIZE);i++){
            for (int j = 0; j < (SIZE);j++){

                image[i][j] = image[j-SIZE-1][i-(SIZE+SIZE/8)];
            }
        }

    }
}


void EnlargeImage (){       //num=8
    int part;
    cout<<"choose part"<<endl<<"1-first part"<<endl<<"2-second part"<<endl;
    cout<<"3-third part"<<endl<<"4-forth part"<<endl;
    cin>> part;

    if(part == 1 ){

        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){

                image2[i][j] = image[k][z];
                image2[i+1][j] = image[k][z];
                image2[i][j+1] = image[k][z];
                image2[i+1][j+1] = image[k][z];

            }
        }
    }

    else if (part == 2){
        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){

                image2[i][j] = image[k][z+127];
                image2[i+1][j] = image[k][z+127];
                image2[i][j+1] = image[k][z+127];
                image2[i+1][j+1] = image[k][z+127];
            }
        }
    }

    else if (part == 3){
        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){

                image2[i][j] = image[k+127][z];
                image2[i+1][j] = image[k+127][z];
                image2[i][j+1] = image[k+127][z];
                image2[i+1][j+1] = image[k+127][z];
            }
        }
    }

    else if (part == 4){
        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){

                image2[i][j] = image[k+127][z+127];
                image2[i+1][j] = image[k+127][z+127];
                image2[i][j+1] = image[k+127][z+127];
                image2[i+1][j+1] = image[k+127][z+127];
            }
        }
    }


}

void ShuffleImage (){       //num=b
    int n1,n2,n3,n4;
    cout << "enter 4 number from 1 to 4 not same:  "<<endl;
    cin >> n1 >> n2 >> n3 >> n4 ;

    while(n1 == n2 == n3 == n4 ){

    cout << "enter 4 number from 1 to 4 not same:  "<<endl;
    cin >> n1 >> n2 >> n3 >> n4 ;

    }








}







