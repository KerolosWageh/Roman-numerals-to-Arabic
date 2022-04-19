// FCAI - Programming 1 -  2022 - Assignment 3
// Program name: xxxxxxxxx.cpp
// Last Modification Date:
// Author1 and ID and Group: Abobakr Osman - 20210005 - A
// Author2 and ID and Group: Kerolos Wageh - 20210307 - A
// Author3 and ID and Group: abdelrahman adel - 20211059 - A
// Teaching Assisstant:
// Purpose:



#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

// Functions
void loadImage();
void saveImage();
void bwFilter();    // Filter 1
void flipFilter();  // Filter 4
void invertImage(); // Filter 2
void rotateImage(); // Filter 5
void Darken_and_Lighten_Image(); //Filter 6

int main()
{
    string filterN;
    cout << "Hello user!" << endl;

    while (true)
    {
        cout << "\nNew" << endl;
        loadImage();

        cout << "\nPlease select a filter to apply or 0 to exit: " << endl;
        cout << "1- Black & White Filter\n" << "2- Invert Filter\n" << "3- Merge Filter\n" << "4- Flip image\n";
        cout << "5- Rotate Image\n" << "6- Darken and Lighten Image\n " /*<< "7- Detect Image Edges\n" << "8- Enlarge Image\n";
        cout << "9- Shrink Image\n" << "a- Mirror 1/2 Image\n" << "b- Shuffle Image\n" << "c- Blur Image\n";
        cout << "s- Save the image to a file\n"*/ << "0- Exit" << endl;
        // To choose which filter will be applied
        cin >> filterN;

        if (filterN == "1")
        {
            bwFilter();
            saveImage();
        }
        else if (filterN == "2")
        {
            invertImage();
            saveImage();
        }
        else if (filterN == "3")
        {

        }
        else if (filterN == "4")
        {
            flipFilter();
            saveImage();
        }
        else if (filterN == "5")
        {
            rotateImage();
            saveImage();
        }
        else if (filterN == "6")
        {
            Darken_and_Lighten_Image();
            saveImage();
        }
        else if (filterN == "0")
        {
            break;
        }
    }


  return 0;
}
// Function that loads the image
void loadImage()
{
   char imageFileName[100];

   cout << "Enter the source image file name: " << endl;
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
// Function that saves the image
void saveImage()
{
   char imageFileName[100];

   cout << "Enter the target image file name: " << endl;
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
// Black&White Function
void bwFilter()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > 127)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
}
// flip Function
void flipFilter()
{
    string flipChoice;

    cout << "\nFlip horizontally(h) or vertically(v)?" << endl;
    cin >> flipChoice;

    if (flipChoice == "h")
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < (SIZE/2); ++j)
            {
                swap(image[i][j], image[i][SIZE-j]);
            }
        }
    }
    else if (flipChoice == "v")
    {
        for (int i = 0; i < (SIZE/2); ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                swap(image[i][j], image[SIZE-i][j]);
            }
        }
    }
}
// Invert Function
void invertImage()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = (SIZE-1) - image[i][j];
        }
    }
}
// rotate function
void rotateImage()
{
    int number;
    cout << "choose number" << endl << "1-rotate the image clockwise by 90 degree" << endl;
    cout << "2-rotate the image clockwise by 180 degree" << endl << "3-rotate the image clockwise by 270 degree" << endl;
    cin >> number;

    if (number == 1 )
    {
        for (int i = 0; i < (SIZE); i++)
        {
            for (int j = 0; j < (SIZE); j++)
            {
                image[i][j] = image[-j][-(SIZE+SIZE/8)-i];
            }
        }
    }

    else if (number == 2)
    {
        for (int i = 0; i < (SIZE/2); i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                swap(image[i][j], image[SIZE-1-i][j]);
            }
        }

        for (int i = 0; i < (SIZE); i++)
            {
                for (int j = 0; j < (SIZE/2); j++)
                {
                    swap(image[i][j], image[i][SIZE-1-j]);
                }
            }
    }

    else if (number == 3)
        {
            for (int i = 0; i < (SIZE); i++)
            {
                for (int j = 0; j < (SIZE); j++)
                {
                    image[i][j] = image[j-SIZE-1][i-(SIZE+SIZE/8)];
                }
            }

        }
}
// Darken and Lighten function
void Darken_and_Lighten_Image()
{
    int number;
    cout<<"what are you want to do ;"<<"\n"<<"1-lighten"<<"\n"<<"2-darken"<<endl;
    cin >> number;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if (number==1){
                image[i][j]=pow(image[i][j],0.8)+150;
            }
            else if (number == 2){
                image[i][j] = (image[i][j])/2;}

    }
  }
}

