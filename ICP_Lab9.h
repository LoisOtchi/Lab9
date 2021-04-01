#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int A[110][110];

/*
Populate a random number of indices in a 2D array by changing elements of the 
indices to 1 where element is undefined, and increasing an element by 1
where the element is positive.
*/
void populateArray(int n){
    int num = 1;
    while(num <= n){
        int i = rand() % 100 + 1;
        int j = rand() % 100 + 1;
        if(A[i][j] == 0){
            A[i][j] = 1;
        }else{
            A[i][j] += 1;
        }
        num++;
    }
}


/*
Construct and search within a bounded rectangular box and output indices with positive values.
*/

void searchValidEntries(int i1, int j1, int i2, int j2){
    for(int i = i1; i <= i2; i++){
        for(int j = j1; j <= j2; j++){
            if(A[i][j] != 0){
                cout << i << ", "<< j << "; "<< A[i][j]<< endl;
            }
        }
    }
}

// main method
int main()
{
    srand (time(NULL));
    populateArray(2000); // set method to generate 2000 pairs.
   
   // Constrcuting 5 bounding boxes.
    for(int i = 0; i < 5; i++){ 
        int i1, j1, i2, j2;
        
        cout << "Please type in the upper right and lower left indices:"<<endl;
        cin >> i1 >> j1 >> i2 >> j2;
        
        cout<< "Output:"<<endl;
        searchValidEntries(i1, j1, i2, j2); // construct the rectangular box using the upper right and lower left indices.
    }
    return 0;
}
