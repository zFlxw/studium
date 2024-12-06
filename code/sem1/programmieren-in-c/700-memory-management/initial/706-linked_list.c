/* Linked list.c 

   The (linked/chained) list is a very important concept to manage sets of items dynamically:
   - The maximum number of elements does not need to be known in advance
   - Elements can have different sizes
   - Elements can be added and removed flexibly 

   Key concepts:
   - Each data item is stored in its own section of memory
   - There is a pointer to the first data item (or NULL, when the list is empty)
   - Each data item has a pointer to the next item in the list (or to NULL, if it's the last item in the list)
   
   The code below already contains some important definitions and functions.

   TO DO 1: Have a look at the program, get it to run and try to understand how it works.
            - Print out pointer values to keep track of what the program does.
			- At what position is a new item added to the list: beginning or end?
   TO DO 2: Extend the main function such that more items are added to the list
   TO DO 3: Complete the function print_items to print for each item in the list:
			- the name, the address in memory and the address of its successor
            In addition, calculate the sum of all data payloads.
   TO DO 4: Write a function find_item(...) that searches the list for an item with a given guid.
   TO DO 5: Change the program such that the memory required for 'data' can be allocated flexibly:
            in struct: unsigned char *data;
	        ptr->data=malloc(ptr->size*sizeof(unsigned char)); // Remember to check for NULL Pointer
   TO DO 6: (optional) Write a function delete_item(...) to delete an item from the list.
   TO DO 7: (optional) Experiment with 'memory leaks': 
            - Increase the size of the payload. 
			- 'Forget' in the delete function to free the memory correctly.
			- Add and remove items frequently in a big loop.
			- Use the task manager to see what happens with memory.
*/

#include <stdio.h>
#include <stdlib.h>

// Data structure of the individual items in the list.
struct myListItemStruct { 
    int guid;                 // a unique id to identify the list item
    char name[128];           // a name to represent the item 
	unsigned char data[200];  // arbitrary data 'payload'
	int size;                 // size of data
    struct myListItemStruct *next_item;   // pointer to next item
};

// Define an own type for shorter declarations
typedef struct myListItemStruct itemType;    

// create_item:
// Creates and initializes a new item, or returns NULL, if it could not allocate memory.
itemType *create_item()
{
   static int guid_ctr=0;    // static counter to create unique ids
   itemType *ptr;

   ptr=malloc(sizeof(itemType));   // Allocate memory for the list item
   if(ptr!=NULL) {
	  ptr->guid=guid_ctr++;   // Generate a unique ID
      printf("Enter name");
      scanf("%s",ptr->name);  // Enter a name
      // TODO ptr->data[..] = ....
      // TODO ptr->size=...;
   }
   return ptr;    // Return pointer to the new item
}

// Insert_item:
// Inserts an existing item into the (potentially empty) list
void insert_item(itemType *new_item, itemType **list_ptr)
{
	new_item->next_item=*list_ptr;   // Append existing list to new item
	*list_ptr=new_item;              // Set list_ptr to points to new item
}


// print all items
void print_items(itemType *list_start)
{
// TO DO.... 

}

// Finds an item with guid in the list 
itemType *find_item(int guid, itemType *list_start)
{

}

// Deletes an item and returns the successor of the deleted item
// The chaining of the previous and next element has to be done 
// by the caller.
itemType *simple_delete_item(itemType *item)
{


}

// Complete delete item
// Deletes item 'to_delete' from the 'list'
// return 0, if the item does not exist in the list, otherwise 1
int delete_item(itemType *to_delete, itemType **list_ptr)
{
	// TO DO: Check if list (i.e. *list_ptr) is not NULL
	// TO DO: Check special case, if first list element is to be deleted
	//        The list_ptr needs to be changed, to point to second list element
	// TO DO: General case: move through list with a helper pointer
	// TO DO: Don't forget to free the memory of the list element (TODO5: and its data payload)
}


int main() 
{
    itemType *my_list=NULL;
    itemType *current;

    current=create_item();
    insert_item(current,&my_list);
	current=create_item();
    insert_item(current,&my_list);

	print_items(my_list);
}
