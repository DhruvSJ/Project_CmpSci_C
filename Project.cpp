/*
 Dhruv Jaiswal
 
 We need to determine the number of peaks and valleys in the given terain,
 while also giving the location of the peaks and valleys.
 
 Input: Text file provided
 
 Output: Number of peaks and valleys, location of peaks and valleys and
        the overall average of heights.
 
 Processing: In the main function we will have the user input the file and
            then we initalize the values in the arrays for the peaks and valleys.
            
            We then call the fileopen function to open the file.
            Then we move onto the peak and valley function where we will use
            a if else if statment to check if there are any peaks or valleys.
        
            We then go to the third function where we will calculate the overall
            average using the given formula.
 
            Lastly we will use an output function to output the number of
            peaks and valleys as well as the elevation and locations
            associated with them.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Define function before main

void fileopen(int Array2[][100], int &num_row, int &num_col, string file2);
void peakandvalley(int Array3[][100], int val_rows, int val_col, int valley[][100], int peak[][100]);
double average(int Array4[][100], int row, int col);
void output(int rows, int columns, int valley[][100], int peak[][100]);

int main()
{
    int Array1[100][100];
    string thefile;
    int row_total=0, column_total = 0;
    int valley[100][100], peak[100][100];
    double average_total;
   
    cout << "Please enter the name of the file you would like to use.\n";
    cin >> thefile;
    
    for (int n = 0; n < 100; n++)
    {
        for (int i = 0; i < 100; i++)
        {
            peak[n][i] = -1;
        }
    }
    for (int n = 0; n < 100; n++)
    {
        for (int i = 0; i < 100; i++)
        {
            valley[n][i] = -1;
        }
    }
    
    fileopen(Array1, row_total, column_total, thefile);
    
    peakandvalley(Array1, row_total, column_total, valley, peak);
    
    average_total = average(Array1, row_total, column_total);
    
    output(row_total, column_total, valley, peak);
    
    cout << "The total average of the elevation is " << average_total << "." <<endl;
}

/*
 Purpose: To open the file given by the user
 Input: File given by user
 Output: Opened File
 Processing: We use an ifstream to open the file and it reads the number of rows
            and then columns.
            Then the file is put into the given array.
 */

void fileopen(int Array2[][100], int &num_row, int &num_col, string file2)
{
    ifstream openfile;
    openfile.open(file2);
    openfile >> num_row >> num_col;
    
    for(int a = 0; a < num_row; a++)
    {
        for (int b = 0; b < num_col; b++)
        {
            openfile >> Array2[a][b];
        }
    }
    openfile.close();
}
/*
Purpose: To calculate the peaks and valleys of the data of the given file
Input: File data
Output: Calculated peaks and valleys
Processing: As it goes through the file it checks every single point in the
            array and uses an if statment to check if it is greater than
            or less than the 8 points surronding it to see if it is a peak
            or valley.
 */


void peakandvalley(int Array3[][100], int val_rows, int val_col, int valley[][100], int peak[][100])
{
    for ( int a = 1; a < val_rows - 1; a++)
    {
        for ( int b = 1; b < val_col - 1; b++)
        {
            if (Array3[a][b] < Array3[a-1][b] && Array3[a][b] < Array3[a+1][b] && Array3[a][b] < Array3[a][b-1] && Array3[a][b] < Array3[a][b+1] && Array3[a][b] < Array3[a-1][b-1] && Array3[a][b] < Array3[a-1][b+1] && Array3[a][b] < Array3[a+1][b-1] && Array3[a][b] < Array3[a+1][b+1])
            {
                valley[a][b] = Array3[a][b];
            }
            else if (Array3[a][b] > Array3[a-1][b] && Array3[a][b] > Array3[a+1][b] && Array3[a][b] > Array3[a][b-1] && Array3[a][b] > Array3[a][b+1] && Array3[a][b] > Array3[a-1][b-1] && Array3[a][b] > Array3[a-1][b+1] && Array3[a][b] > Array3[a+1][b-1] && Array3[a][b] > Array3[a+1][b+1])
            {
                peak[a][b] = Array3[a][b];
            }
        }
    }
}

/*
Purpose: To calculate the average elevation
Input: Data from file
Output: average of elevation
Processing: We use a for loop, that contains an accumlator.
            We then solve for the average using the given formula.
 */

double average(int Array4[][100], int row, int col)
{
    int total = 0;
    int count = 0;
    double avg;
    
    for (int a=0; a < row; a++)
    {
        for (int b=0; b < col; b++)
        {
            total += Array4[a][b];
            
            count++;
        }
    }
    avg = total/count;
    return avg;
}

/*
Purpose: To output the number of peaks and valleys as well as there
         locations and elevation.
Input: File data
Output: Location and elevation of peaks and valleys.
Processing: The first set of foor loops counts how many peaks and valleys
            there are and we output that for the user.
            The second set of for loops we output the location and elevation
            of each valley and peak.
 */

void output(int rows, int columns, int valley[][100], int peak[][100])
{
    int valley_count = 0, peak_count = 0;
    
    for (int a = 0; a < rows; a++)
    {
        for (int b = 0; b < columns; b++)
        {
            if(!(valley[a][b] == -1))
            {
                valley_count++;
            }
            if(!(peak[a][b] == -1))
            {
                peak_count++;
            }
        }
    }
    cout << "There are " <<valley_count<< "total valleys and " << peak_count << " total peaks. \n";
    
    for (int a = 0; a < rows; a++)
    {
        for (int b = 0; b < columns; b++)
        {
            if(!(valley[a][b] == -1))
            {
                valley_count++;
                
                cout << "There is a valley located at row " << a + 1 << " and a column located at " << b + 1 << "with a elevation of " << valley[a][b] << ".\n";
            }
            if(!(peak[a][b] == -1))
            {
                peak_count++;
                
                cout << "There is a peak located at row " << a + 1 << " and a column located at " << b + 1 << "with a elevation of " << peak[a][b] << ".\n";
            }
        }
    }
}
