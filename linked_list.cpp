/******************************************************************************
FILENAME:     linked_list.cpp 
COURSE:       MREN 178
LAB:          1
STUDENTS:    [Coleman Farvolden 20335398 and Hannah Vibien 20332596] 
DATE:         

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE] 
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////    
/* MREN 178 - Code is missing from the implmentation of this linked list.  
 * Fill in the missing code to get the linked list working on the Arduino!  
 */
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "linked_list.h"

// Function to create a new node
Node* create_node (int val) {
    // Declaration of local node pointer, with mem allocation
    Node *p_new = (Node *) malloc (sizeof (Node));

    if (p_new != NULL) {
        // Now fill with data. Notice the syntax. You can read this as "assign 
        // value in d to data_val field in Node pointed to by p_new".
        p_new->data_val = val;
        p_new->p_next_node = NULL; 
    }
    
    // Get here with pn pointing to a filled-in structure, or with p_new equal
    // to NULL because malloc() failed. In either case, return p_new.
    return p_new;
}

// Function to insert node at front of the list
int insert_data_at_head (int val){
    Node *p_new = create_node (val);
    // Make sure node creation worked
    if (p_new == NULL) {
        return EXIT_ERROR;
    }

    // New node goes at the head of the list. The current head of the list is 
    // pointed to by p_head, so we make the new node point to the place that 
    // p_head points to and make p_head point to the new node. So the new node 
    // is at the 'beginning' and points to the remainder of the list. Remember 
    // to check to see if new node is the very first node added - if so, we have 
    // to update the p_end pointer as well.

    /*-------------------------insert your code here--------------------------*/

//Case #1 the linked list is empty
//New node becomes the pointer and the tail of the linked list
  if (p_head==NULL){         
        p_head = p_new;      
        p_tail = p_new;
       return EXIT_OK; ;
    }

//case #2 the head is attached to a linked list
p_new->p_next_node=p_head; //New pointer points to the head of the linked list
p_head=p_new; //Make the new pointer the head of the linked list
    return EXIT_OK;   
}

 
// Insert new item of data at the back of the linked list
int insert_data_at_tail (int val) {
    Node *p_new = create_node (val);
    // Make sure node creation worked
    if (p_new == NULL) {
        return EXIT_ERROR;
    }

    // New node goes at back of list. If the list is currently empty,
    // then both the head and back pointers need to be updated.
  
    /*-------------------------insert your code here--------------------------*/

 // Case #1 The head points to a linked list 
 
    if (p_head != NULL){ 
    p_tail->p_next_node=p_new;  // The tail points to the new node
    p_tail=p_new; // The new node becomes the tail of the linked list
    return EXIT_OK;
    }

    // Case #2 The head does not point to linked list

    else{
     p_tail = p_new;  // Make the new node the tail of the linked list
     p_head = p_new;     // Make the new node the head of the linked list
     return EXIT_OK;
    }
}

int insert_data_at_middle(int search_val, int val) {
    Node *p_temp;      // Pointer to one of the LL nodes
    p_temp = p_head;   // pointer to first node

    Node *p_new = create_node (val);
    // Make sure node creation worked
    if (p_new == NULL) {
        return EXIT_ERROR;
    }

//case #1 List is empty
    if(p_head == NULL){

       return EXIT_ERROR;
    }
   
    // Loop through all nodes
    while (p_temp != NULL) {

        // Does ptemp point to node with sought value?
        if (p_temp->data_val == search_val) {
            // Yes it does. This is node we want to add a node after.
            /*---------------------insert your code here-----------------------*/

//Case #2 Inserting at tail
     if(p_temp == p_tail){

     p_temp->p_next_node = p_new; //the tail node now points to p_new
     p_tail = p_new; //make new node the tail
     return EXIT_OK;
        }


        //Case # 3 Inserting at middle
        
            p_new->p_next_node=p_temp->p_next_node;//setting the new pointer pointing adress to the temporary pointers pointing address
            p_temp->p_next_node=p_new;//set the temporary pointers pointer to the address of the new pointer 
            
            return EXIT_OK;
       }


       // if we've reached here, node was not found yet - move on to next node
       
       /*-------------------------insert your code here--------------------------*/

       //Increment to looking at next node
        p_temp=p_temp->p_next_node;
    }

    return EXIT_ERROR;
}

// Find node that holds the value val, and remove the node from the list, 
// without breaking the list of course. Returns                                                                                                                                                                                                                                   ITEM_ERROR if the number 
// could not be found, and EXIT_OK if the item was found and deleted.  
int find_and_delete_data (int val) {
        Node *p_temp;      // Pointer to one of the LL nodes
    Node **pp_node;    // pointer to a pointer to a node
    p_temp = p_head;   // pointer to first node
    pp_node = &p_head; // pointer to pointer that points to first node
      Node *p_follower; //Creats following pointer
    

//Case #1 check if list is empty
if(p_head == NULL){
   return EXIT_ERROR;
}

   
    // Loop through all nodes
    while (p_temp != NULL) {
        // Does ptemp point to node with sought value?



        
       if (p_temp->data_val == val) {

           // Remember: it's possible that we're deleting the first, a middle,
           // or the last node in the list. It is also possible we're about to
           // delete the only item in the list. Handle each of these cases.
           
           /*---------------------insert your code here-----------------------*/


//Case # 2 if deleting only item in list
if(p_temp == p_tail && p_temp == p_head){

  delete_all_data(); //Free all pointers and delete last element in list
  
   return EXIT_OK;
}
           
   
//Case # 3 if deleating head
     if(p_temp == p_head){ //Check if the value is in the head

   p_head = p_temp->p_next_node; //Change head to the next node
   
   free(p_temp); //Free the old head
   return EXIT_OK;
     }

//Case # 4 if deleting tail
if(p_temp == p_tail){

  p_tail = p_follower; //Make previous node the tail
  p_follower->p_next_node = NULL; //Make the tails next node NULL
  free(p_temp); //Free temp node/old tail
    return EXIT_OK;
}

  //Case # 5 deleting in middle of list
         p_follower->p_next_node=p_temp->p_next_node;//set the followers next node pointer to the transversers next node pointer so they are both pointing to the same thing 
         p_temp->p_next_node=NULL;//delete the node with the value
         free(p_temp);//free transverser node 
          return EXIT_OK;
        }
       
        // if we've reached here, node was not found yet - move on to next node
   
        /*------------------------insert your code here-----------------------*/

         p_follower=p_temp;//points to transversers nodes address
         p_temp=p_temp->p_next_node;//iterate through the loop, the follower will be one behind 


    }
    // get here only if we searched whole list and found nothing
    return EXIT_ERROR;
}


// We want to delete all nodes in the linked list. Rememeber to take care of both
// the head and tail pointers.

int delete_all_data() {
    Node *p_temp; //Create node pointer
  p_temp=p_head;  //Start temp node at head
 
    // Loop through all nodes
    while (p_head != NULL) {
        /*-----------------------insert your code here-------------------------*/
       p_head = p_temp->p_next_node; //Make the next node the head
       free(p_temp);  //Free the current node
        p_temp = p_head; //move on to freeing next node and make ptemp the next node 
    }
     free(p_temp); //Free the temp pointer
    free(p_head); //Free the head pointer
    free(p_tail); //Free the tail pointer
    return EXIT_OK;
}
