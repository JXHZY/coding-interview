/*
 @Ying Zhou
 Coding_Interview_2.2_1
 11/23/2015
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
int nthToLast(node *head, int k)
{
    if(head==NULL)
        return 0;
    int i = nthToLast(head->next,k)+1;
    if(i==k)
    {
        cout << head->data;
    }
    return i;
}

int main(){
    int n = 20;
    int test[] = {
        5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1
    };              //the right output should be:5 4 3 2 1
    node *head = init(test,n);
    nthToLast(head,6);
    return 0;
}
