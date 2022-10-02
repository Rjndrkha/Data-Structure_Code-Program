// Java Program to Implement Triply Linked List
 
// Importing all utility classes
import java.util.*;
 
// Main Class
public class TriplyLinkedList {
 
    // First let us create a Node class
    class Node {
 
        // Data refers to the value in node
        int data;
 
        // Being triply linked list,
        // three pointers needs to be defined
        Node prev;
        Node next;
        Node top;
 
        // Parameterized constructor of Node class
        // to initialize the node whenever created
        Node(int data)
        {
 
            // this keyword refers to current object itself
            this.data = data;
 
            // Initializing all 3 pointers to null
            prev = null;
            next = null;
            top = null;
        }
    }
 
    // Defining two new pointers for iterate over to perform
    // operations over the triply linked list Head and Tail
    // pointer
    Node head = null, tail = null;
 
    // Declaring and initializing variable to
    // keep track of the number of nodes
    int node_count = 0;
 
    // To insert a new node
    public void insert(int new_data)
    {
 
        // Create new node with the given data
        Node new_node = new Node(new_data);
 
        // curr_node to traverse the List
        Node curr_node = null;
 
        // If List is empty then
        // make head and tail
        // equal to this node
        if (node_count == 0) {
 
            // Case 1: Of LinkedList is empty
            // If there is no such node existing
            tail = new_node;
            head = new_node;
            curr_node = head;
 
            // So next will be assigned a null
            curr_node.next = null;
            curr_node.prev = null;
            curr_node.top = null;
 
            // Increment the node count
            node_count++;
        }
 
        // Case 2: If LinkedList is not empty
 
        // Case 2(A): If given node is less then the head
        else {
 
            // Make curr_node point to head
            curr_node = head;
 
            // If given node is less then the head
            // insert at the beginning
            if (new_node.data < curr_node.data) {
 
                // Linking two nodes through addresses
                new_node.next = curr_node;
                curr_node.prev = new_node;
                new_node.prev = null;
                head = new_node;
                curr_node = head;
 
                // Adjusting the tail
                do {
 
                    curr_node = curr_node.next;
                } while (curr_node.next != null);
                tail = curr_node;
            }
 
            // CAse 2(B): If given node is not less then the
            // head
            else {
 
                // last_node to keep track of
                // the last visited node
                Node last_node = curr_node;
 
                // Goal is to traverse the List and
                // find first node greater than new_node
                while (curr_node != null
                       && new_node.data > curr_node.data) {
                    last_node = curr_node;
                    curr_node = curr_node.next;
 
                    // If curr_node is null that
                    // means we have reached the
                    // end of the list so insert the
                    // node at the end and update the tail
                    if (curr_node == null) {
 
                        last_node.next = new_node;
                        new_node.prev = last_node;
                        new_node.next = null;
                        tail = new_node;
 
                        // Haulting the execution of the
                        // program using break keyword
                        break;
                    }
 
                    else if (new_node.data
                             <= curr_node.data) {
 
                        // If curr_node is greater than
                        // the new_node then insert the
                        // new_node before curr_nod and
                        // update the tail
                        if (new_node.data
                            < curr_node.data) {
 
                            last_node.next = new_node;
                            new_node.prev = last_node;
                            new_node.next = curr_node;
                            curr_node.prev = new_node;
                            if (curr_node.next != null) {
 
                                do {
 
                                    curr_node
                                        = curr_node.next;
                                }
 
                                while (curr_node.next
                                       != null);
                            }
 
                            tail = curr_node;
 
                            break;
                        }
 
                        // If curr_node is equal to the
                        // new_node then insert the
                        // new_node to the top of the
                        // curr_nod and update the tail
                        else if (curr_node.data
                                 == new_node.data) {
                            last_node = curr_node;
                            while (last_node.top != null) {
 
                                last_node = last_node.top;
                            }
 
                            last_node.top = new_node;
                            new_node.top = null;
 
                            break;
                        }
                    }
                }
            }
        }
    }