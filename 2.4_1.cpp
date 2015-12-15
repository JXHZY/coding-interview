/*
 @Ying Zhou
 Coding_Interview_2.4 (by Ying)
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
/*make change in one list, also can used in array*/
void xOrder(node *head,int x)
{
    int signal = 0;    //if find the first element bigger or == to x, the signal will be 1
    node *firstMax = NULL;
    node *keep = NULL;
    int help = 0;
    while(head)
    {
        if(head->data < x)
        {
            if(signal == 0)   //until now, all the elements is samller than x
            {
                //do nothing
                head = head->next;
            }
            else      //need change the order
            {
                keep = firstMax;
                help = head->data;
                head->data = firstMax->data;
                firstMax->data = help;
                signal = 0;
                head = keep->next;
            }
        }
        else
        {
            if(signal == 1)
            {
                //do nothing
                head = head->next;
            }
            else
            {
                firstMax = head;
                signal = 1;
                head = head->next;
            }
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
        5, 6, 3, 2, 7, 5, 4, 3, 2, 8, 5, 1, 3, 2, 1, 3, 4, 3, 2, 1
    };              //the right output should be:5 4 3 2 1
    node *head = init(test,n);
    print(head);
    xOrder(head,2);
    print(head);
    return 0;
}
