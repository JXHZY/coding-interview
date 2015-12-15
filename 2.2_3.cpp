/*
 @Ying Zhou
 Coding_Interview_2.2_3 (Iterative)
 11/25/2015
 */

#include <iostream>
#include <cstring>
#include <ext/hash_map>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

__gnu_cxx::hash_map<int, bool> dupNumber;
//bool hash[100];

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
 find the kth to last element of a singly linked list
 */
node* nthToLast(node *head, int k)
{
    if(k<=0)
        return NULL;
    node *p1=head;
    node *p2=head;
    for(int i=0;i<k-1;i++)
    {
        if(p2==NULL)
            return NULL;
        p2=p2->next;
    }
    if(p2==NULL)
        return NULL;
    while(p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
}

int main(){
    int n = 20;
    int test[] = {
        5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1
    };              //the right output should be:5 4 3 2 1
    node *head = init(test,n);
    node * result;
    result = nthToLast(head,5);
    cout << result->data << endl;
    return 0;
}
