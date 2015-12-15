/*
 @Ying Zhou
 Coding_Interview_2.4_2 (book)
 11/30/2015
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;


//make the number in array to become a link
node* init(int a[],int n){
    node *head = NULL;
    node *help = NULL;
    for (int i=0;i<n;i++)
    {
        node *newNode = new node();
        newNode->data = a[i];
        if(i==0)
        {
            head = help = newNode;
            continue;
        }
        help->next = newNode;
        help = newNode;
    }
    return head;
}

/*soultion
 partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x
 */
node* partition(node *head,int x)
{
    node *start = head;
    node *tail = head;
    while(head)
    {
        node *next = head->next;
        if(head->data < x)
        {
            head->next = start;
            start = head;
        }
        else
        {
            tail->next = head;
            tail = head;
        }
        head =next;
    }
    tail->next = NULL;
    return start;
}

//Print the link
void print(node *head){
    cout<<"The answer is:" << endl;
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int n = 20;
    int test[] = {
        5, 6, 3, 2, 7, 5, 4, 3, 2, 8, 5, 1, 3, 2, 1, 3, 4, 3, 2, 1
    };              //the right output should be:5 4 3 2 1
    node *head = init(test,n);
    print(head);
    head = partition(head,2);
    print(head);
    return 0;
}
