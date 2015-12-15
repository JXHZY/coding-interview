/*
 @Ying Zhou
 Coding_Interview_2.1_1
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

//remove duplicates from an unsorted linked list
void remove_duplicates(node *head){
    node *p=head, *q=head->next;
    if(head==NULL)
        return;
    dupNumber[head->data]=true;
    while(q)
    {
        if(dupNumber[q->data])    //the number is duplicated, need to delete
        {
            node *keep = q;
            p->next = q->next;
            q = p->next;
            delete keep;
        }
        else
        {
            dupNumber[q->data]=true;
            p = q;
            q = q->next;
        }
    }
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
    remove_duplicates(head);
    print(head);
    return 0;
}
