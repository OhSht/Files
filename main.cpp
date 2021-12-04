#include <iostream>
#include <fstream>
using namespace std;
// to have fuctions calculate sum of the grades for each students, and store it in one integer array.

int sum;
int gradesT = 0;
double grades[5][5];
double sumGrades[5];
string StudentName[5];
double average[5];
char gradeLetter[5];
// To have another function finds the average of each stude's grade and save it in one array of type double,
void averageOfGrades(double *sumGrades, int size, double *average)
{
    for (int i = 0; i < size; i++)
    {
        average[i] = sumGrades[i] / size;
    }
}

// to have another function that finds letter grade of each students and save it in a character array .
void letterOfGrades(double *average, int size, char *gradeLetter)
{
    char letter;
    for (int i = 0; i < size; i++)
    {
        double score = average[i];
        if (score >= 90 && score <= 100)
            letter = 'A';
        else if (score >= 80 && score <= 89)
            letter = 'B';
        else if (score >= 70 && score <= 79)
            letter = 'C';
        else if (score >= 60 && score <= 69)
            letter = 'D';
        else
            letter = 'F';
        gradeLetter[i] = letter;
    }
}
int searchList(const string list[], int numElems, string value)
{
    int index = 0; // Used as a subscript to search array
    while (index < numElems)
    {
        if (list[index] == value)
        { // If the value is found'
            cout << "Found at index: " << index << endl;
            cout << StudentName[index] << "| Grade: " << gradeLetter[index] << "| Avg: " << average[index] << "| Sum: " << sumGrades[index] << endl;
        }
        ++index;
    }
    return -1;
}

// function to read the student's name from the file and display them
void read()
{

    string filename = "names.txt";
    ifstream fin;
    // open the file names.txt
    fin.open(filename);
    // create array to store student's names    // input the names
    for (int i = 0; i < 5; i++)
    {
        getline(fin, StudentName[i]);
    }

    // close previous file
    fin.close();
    // now input and display the grades
    filename = "grades.txt";
    fin.open(filename);
    // array to store the grades
    // double grades[5][5];

    // input the grades
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fin >> grades[i][j];
            gradesT += grades[i][j];
        }
        sumGrades[i] = gradesT;
        gradesT = 0;
    }
    averageOfGrades(sumGrades, 5, average);
    letterOfGrades(average, 5, gradeLetter);
    ofstream myfile("out.txt");
    if (myfile.is_open())
    {
        ;
        for (int i = 0; i < 5; i++)
        {
            cout << StudentName[i] << "| Grade: " << gradeLetter[i] << "| Avg: " << average[i] << "| Sum: " << sumGrades[i] << endl;
            myfile << StudentName[i] << "| Grade: " << gradeLetter[i] << "| Avg: " << average[i] << "| Sum: " << sumGrades[i] << endl;

            for (int j = 0; j < 5; j++)
            {
                cout << "\n : Grade: " << grades[i][j] << endl;
                myfile << "\n : Grade: " << grades[i][j] << endl;
            }
        }
    }

    // close the file
    fin.close();
    string input;
    cout << "Search for: ";
    getline(cin, input);
    searchList(StudentName, 4, input);
}
// main function
int main()
{
    // call the function

    read();

    return 0;
}