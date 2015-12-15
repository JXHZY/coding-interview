/*
 @Ying Zhou
 Coding_Interview_2.3
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
 delete a node in the middle of a singly linked list
 */
 bool deleteNode(node *n)
{
    if(n == NULL || n->next == NULL)
    {
        return false;
    }
    node *keep = n->next;
    n->data = keep->data;
    n->next = keep->next;
    return true;
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
        5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1
    };              //the right output should be:5 4 3 2 1
    node *head = init(test,n);
    node *t = head->next->next->next;
    print(head);
    bool result;
    result = deleteNode(t);
    print(head);
    return 0;
}
