#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Linked list item struct
struct Item {
  int value;
  Item *next;
};

// Global declarations of an array and linked list head pointer
const int MAXSIZE = 10000;
int list[MAXSIZE];
Item *head;

int arraySequentialSearch( int value ) {
  //An array-based sequential search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  for ( int loc=0; loc<MAXSIZE; loc++ ) {
    if ( list[loc] == value ) {
      return loc;
    }
  }

  return -1;
}

Item *linkedSequentialSearch( int value ) {
  //An linked-list-based sequential search algorithm. Returns a pointer to the item
  //containing the value if found and a null otherwise
  Item *current = head;

  while ( current != NULL ) {
    if ( current->value == value ) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

int arrayBinarySearch( int value ) {
  //An array-based binary search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  int first=0, last=MAXSIZE-1, mid;

  while ( first <= last ) {
    mid = (first + last) / 2;

    if ( list[mid] == value ) {
      //Found it
      return mid;
    }

    //Haven't found it, yet. Determine which sublist to continue with and
    //adjust first or last
    if ( list[mid] > value ) {
      //Go left, so adjust last to be mid-1
      last = mid - 1;
    } else {
      //Go right, so adjust first to be mid+1
      first = mid + 1;
    }
  }
  return -1;
}



// **************** CHANGE ME ************************
// Change the code to populate data with random numbers
// between 0 and 1,000,000 and insert them in sorted order
void populateLinkedList() {
  //Appends MAXSIZE even numbers in the list
  Item *temp, *last;
  
  head = new Item;
  head->value = 0;
  head->next=NULL;
  last=head;
  
  for(int i=1; i<MAXSIZE; i++){
  	temp=new Item;
  	temp->value = rand() % 100000 +1;
  	temp->next=NULL;
  	last->next=temp;
  	last=temp;
  }
  }
 /* Item *newItem, *last;
  Item  *current;
  srand(time(NULL));
  //Create the first item so that in the for loop we don't
  //have to check for head == NULL
  head = new Item;
  head->value = rand() % 100000 + 1;
  cout << "head before: " << head->value << endl;
  //head->next = NULL;
  Item *prev;

  for (int i=1; i<MAXSIZE; i++) {
    prev=head;
    newItem = new Item;
    current=head->next;
    newItem->value = rand() % 100000+1;
    cout << "temp->value: " << newItem->value << endl;
    while(current!=NULL){
    if(current->value < newItem->value){
  		prev=current;
  		current=current->next;
  	}
    else{
    	break;
    }	
   }
   //cout << "current" << current->value << endl;
   if(current->next == NULL){
   	//head=temp;
   }
  
   else{
   	prev->next=newItem;
   	newItem->next=current;
   }
  }
  cout << "head after: " << head->value << endl;
Item* check;
check=head;
while(check->next!=NULL){
	cout << "check: " << check->value << endl;
	check=check->next;
 }
}*/


// **************** CHANGE ME ************************
// Change the code to populate data with random numbers
// between 0 and 1,000,000
void populateArrayList() {
  //Puts MAXSIZE even numbers in the list
  for ( int i=0; i<MAXSIZE; i++ ) {
    list[i] = rand() % 100000+1;
  }
}


// **************** WRITE ME ************************
// Add your code (function(s)) to implement Selection Sort
int selectionSort() {
	
	
	for (int i=0; i< MAXSIZE; i++){
		int min=i;
		for(int j=i+1; j<MAXSIZE; j++){
			if (list[j]<list[min]){
				min=j;
			}
		}
		swap(list[i], list[min]);
	}	
	
	return 0;
}

void swap(int *i, int *min){
	int temp =*i;
	*i=*min;
	*min=temp; 
}


int other[MAXSIZE];
// **************** WRITE ME ************************
// Add your code (function(s)) to implement Merge sort
void merge(int low, int middle, int high)
{
    int* tmp = new int[high-low+1];
    int i = low;
    int j = middle+1;
    int k = 0;
    while ((i <= middle) && (j <= high))
    {
        if (list[i] < list[j])
            tmp[k++] = list[i++];
        else
            tmp[k++] = list[j++];
    }
    if (i <= middle)
    {
        while (i <= middle)
            tmp[k++] = list[i++];
    }
    if (j <= high)
    {
        while (j <= high)
            tmp[k++] = list[j++];
    }
    /*See how are we adjusting tmp array index below*/
    for (k = low; k <= high; ++k){
        list[k] = tmp[k-low];
        }
    delete[] tmp;
}
/*For an array of size N call with 0 as low and N-1 as high*/
int mergeSort(int low, int high)
{
    if (low < high)
    {
        int middle = (high + low)/2;
        mergeSort(low, middle);
        mergeSort(middle+1, high);
        merge(low, middle, high);
    }
}

int main() {
  clock_t start, finish;
  double  duration;
  cout << "List size of " << MAXSIZE << endl;

  //Put data into the two types of lists
  populateArrayList();
  cout << "finish array list populate" << endl;
  populateLinkedList();
  
  
  cout << "finish linked list populate" << endl;
  start = clock();
  //selectionSort();
  // Add your call to either selection or merge sort here.
  mergeSort(0, MAXSIZE);

  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Total CPU for sort time: "<<duration << endl;

  // Write a for loop to check that data in your array is 
  // in sorted order
for (int i=0; i<MAXSIZE; i++){//prints out the list after sorting
		cout << list[i] << endl;
	}
for (int i=0; i<MAXSIZE-1; i++){//prints out an error message if the list is not sorted correctly
		if (list[i+1]<list[i]){
			cout << "Incorrect order" << endl;
		}
	}

  //Let's start off with a value not in the list and see how long it takes.
  int numiters = 100000;
  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arraySequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for array sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    linkedSequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for linked sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arrayBinarySearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU time for array binary searches time: "<<duration/numiters<<endl;


  return 0;
}

