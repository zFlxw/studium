/* Linked list.c 

   The (linked) list is a very important concept to manage sets of items dynamically:
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
#include <string.h> 

// Data structure of the individual items in the list.
struct myListItemStruct { 
    int guid;             // a unique id to identify the list item
    char name[128];       // a name to represent the item 
	unsigned char *data;  // arbitrary data 'payload'
	int size;             // size of data
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
      //printf("Enter name");
      //scanf("%s",ptr->name);  // Enter a name
	  //Eingabe auskommentiert, statt dessen automatische Erzeugung von Testdaten:
	  sprintf(ptr->name,"Name%d",ptr->guid);
	  ptr->size=1000;
	  ptr->data=malloc(ptr->size*sizeof(unsigned char));  // Allocate some memory for a payload
	  // TO DO: Have to check for NULL Pointer
      if(ptr->data==NULL) {
		free(ptr);
		return NULL;
	  }
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
void print_items(itemType *list)
{
	int total_size=0;

	while(list!=NULL) {
		printf("Item GUID=%d, Name=%s, Addr.=%p, Next=%p\n",list->guid, list->name, list, list->next_item);
		total_size+=list->size;
		list=list->next_item;
	}
	printf("Total size of payloads: %d\n", total_size);
}

// Finds an item with guid in the list 
itemType *find_item(int guid, itemType *list)
{
	while(list!=NULL) {
		if(list->guid==guid) 
			return list;
		list=list->next_item;
	}
	return NULL;
}

// Deletes an item and returns the successor of the deleted item
// The chaining of the previous and next element has to be done 
// by the caller.
itemType *simple_delete_item(itemType *item)
{
	itemType *successor;
	successor=item->next_item;
	free(item->data);
	free(item);
	return successor;
}


// Complete delete item
// Deletes item 'to_delete' from the 'list'
// return 0, if the item does not exist in the list, otherwise 1
int delete_item(itemType *to_delete, itemType **list_ptr)
{
	itemType *ptr;

	// Special case: empty list
	if(!*list_ptr)
		return 0;
	// Special case: first item is to be deleted
	if(to_delete==*list_ptr) {
		*list_ptr=to_delete->next_item;
		free(to_delete->data);
		free(to_delete);
		return 1;
	}

	// Finde item in remainder of list
	ptr=*list_ptr;
	while(ptr->next_item!=NULL) {
		if(ptr->next_item==to_delete) {
			ptr->next_item=to_delete->next_item;
			free(to_delete->data);
			free(to_delete);
			return 1;
		}
		ptr=ptr->next_item;
	}
	return 0;
}

int main() 
{
    itemType *my_list=NULL;
    itemType *current, *to_delete;
    int i, j;

    for(j=0; j<1; j++) {
        printf("\nLoop: %d\n",j);
        // Create 20 items
        for(i=0; i<20; i++) {
            current=create_item();
            if(current==NULL) {
                printf("Cannot create item. Program terminated.\n");
                return EXIT_FAILURE;
            }
            insert_item(current,&my_list);

            if(i==7) to_delete=current; // later delete 7th item
        }
        print_items(my_list);
        printf("Delete 7th:\n");
        delete_item(to_delete,&my_list);
        print_items(my_list);
		
        // Delete items
        printf("Delete more...\n");
        for(i=0; i<10; i++) {
            my_list=simple_delete_item(my_list);  // Delete from beginning
        }
        print_items(my_list);


        // Delete items
        printf("Delete...\n");
        for(i=0; i<5; i++) { // delete first
            printf("delete %d\n",delete_item(my_list,&my_list));
        }
        print_items(my_list);	
    }

	// Clean up: free all malloc items
	while(my_list) {
		current = my_list;
		my_list = my_list->next_item;
		free(current->data);
		free(current);
	}
	getchar();
}






