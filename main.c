#include <stdio.h>
#include <stdlib.h>

//https://www.tutorialspoint.com/c-program-for-radix-sort

//Finder det højeste tal i et array
int findHighest(int arr[], int n){
    int high = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > high)
            high = arr[i];
        return high;
    }
}
void countSort(int arr[], int n, int t)
{
    int tempArray[n]; // output array
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / t) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Bygger det midlertidige array
    for (i = n - 1; i >= 0; i--) {
        tempArray[count[(arr[i] / t) % 10] - 1] = arr[i];
        count[(arr[i] / t) % 10]--;
    }
 printArray(tempArray,n);
    // Kopier tempArray ind i arr
    for (i = 0; i < n; i++)
        arr[i] = tempArray[i];

}
/**< 1000 numbers = 0.191 | 10000 = 1,291 | 100000 = 9.371 */
void sort(int arr[], int n){
int highest = findHighest(arr, n);

for (int i = 1; highest / i > 0; i *= 10)
        countSort(arr, n, i);
        printArray(arr,n);
}

// Udskriver array's elementer
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
/**< Bruges til at generere X antal tilfældige nummere */
void ManyNumbers(int numb){
    int mNumbers[numb];
     for(int i = 0; i<numb; i++)
        mNumbers[i] = rand();
        sort(mNumbers,  numb);
}

int main()
{
   // simpel test
   // int arr[] = { 105, 200, 2, 17, 654, 24, 221, 64 };
   // int n = sizeof(arr) / sizeof(arr[0]);

   //Farttest
   int amountNumbers = 100000;
  // int arr[amountNumbers];
  // int temparr[amountNumbers];

   ManyNumbers(amountNumbers);

    // for (i = 0; i < n; i++)
       // arr[i] = tempArray[i];


      // Function Call
     // sort(arr, n);
//    printArray(temparr, n);
    return 0;

}
