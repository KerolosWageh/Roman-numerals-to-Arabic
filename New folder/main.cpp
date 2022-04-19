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
unsigned char image[SIZE][SIZE][RGB];
unsigned char image1[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
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






  return 0;
}


void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}


void loadImage2(){
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}

void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);

}

void saveImageEnlarge () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image2);

}


void InvertImage() {        //num=2
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int n = 0;n < RGB ;n++){
       image[i][j][n] = (SIZE-1) - image[i][j][n];
            }

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
                    for (int n = 0;n < RGB ;n++){
                image[i][j][n] = image[-j][-(SIZE+SIZE/8)-i][n];
            }
            }
        }
    }

    else if (number == 2){
        for (int i = 0; i < (SIZE/2);i++){
            for (int j = 0; j < SIZE;j++){
                for (int n = 0;n < RGB ;n++){
                swap(image[i][j][n] , image[SIZE-1-i][j][n]);
            }
            }
        }
        for (int i = 0; i < (SIZE);i++){
            for (int j = 0; j < (SIZE/2);j++){
                for (int n = 0;n < RGB ;n++){
                swap(image[i][j][n] , image[i][SIZE-1-j][n]);
                }
            }
        }
    }

    else if (number == 3){
        for (int i = 0; i < (SIZE);i++){
            for (int j = 0; j < (SIZE);j++){
                for (int n = 0;n < RGB ;n++){
                image[i][j][n] = image[j-SIZE-1][i-(SIZE+SIZE/8)][n];
            }
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
                for (int n = 0;n < RGB ;n++){
                image2[i][j][n] = image[k][z][n];
                image2[i+1][j][n] = image[k][z][n];
                image2[i][j+1][n] = image[k][z][n];
                image2[i+1][j+1][n] = image[k][z][n];
                }
            }
        }
    }

    else if (part == 2){
        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){
                for (int n = 0;n < RGB ;n++){
                image2[i][j][n] = image[k][z+127][n];
                image2[i+1][j][n] = image[k][z+127][n];
                image2[i][j+1][n] = image[k][z+127][n];
                image2[i+1][j+1][n] = image[k][z+127][n];
            }}
        }
    }

    else if (part == 3){
        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){
                for (int n = 0;n < RGB ;n++){
                image2[i][j][n] = image[k+127][z][n];
                image2[i+1][j][n] = image[k+127][z][n];
                image2[i][j+1][n] = image[k+127][z][n];
                image2[i+1][j+1][n] = image[k+127][z][n];
            }}
        }
    }

    else if (part == 4){
        for (int i = 0, k = 0 ; i < SIZE ; k++, i+= 2){
            for (int j = 0,z = 0 ; j < SIZE ; z++, j+= 2){
                for (int n = 0;n < RGB ;n++){
                image2[i][j][n] = image[k+127][z+127][n];
                image2[i+1][j][n] = image[k+127][z+127][n];
                image2[i][j+1][n] = image[k+127][z+127][n];
                image2[i+1][j+1][n] = image[k+127][z+127][n];
            }
            }
        }
    }


}







