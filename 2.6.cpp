/*
 @Ying Zhou
 Coding_Interview_2.6 （book）
 12/17/2015
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef struct node{
    char data;
    node *next;
}node;

/*soultion*/
node* firstInCircle(node *head)
{
    node *fast = head;
    node *slow = head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            break;
        }
    }
    
    if((fast == NULL)||(fast->next == NULL))
    {
        return NULL;
    }
    
    slow = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return fast;
}

int main(){
    node *head = new node();
    node *newNode1 = new node();
    node *newNode2 = new node();
    node *newNode3 = new node();
    node *newNode4 = new node();
    
    head->data = 'A';
    newNode1->data = 'B';
    newNode2->data = 'C';
    newNode3->data = 'D';
    newNode4->data = 'E';
    
    head->next = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;
    newNode3->next = newNode4;
    newNode4->next = head;                //change this one to see the different
    
    node *result = firstInCircle(head);
    cout << "The node at the beginning of the loop is: " << result->data << endl;
    return 0;
}
