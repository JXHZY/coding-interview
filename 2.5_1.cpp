/*
 @Ying Zhou
 Coding_Interview_2.5_1 (reverse order)
 12/11/2015
 */

#include <iostream>
#include <cstring>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;


//make the linked list
node* creat(int a[],int n){
    node *head = NULL;
    node *help = NULL;
    int j = 0 ;
    
    while((a[j]==0) && (j<n))
    {
        j++;
    }
    
    for (int i=j;i<n;i++)
    {
        node *newNode = new node();
        newNode->data = a[i];
        if(i==j)
        {
            head = help = newNode;
            continue;
        }
        help->next = newNode;
        help = newNode;
    }
    return head;
}

/*soultion*/
node* add(node *add1,node *add2, int n1, int n2)
{
    int maxLength = 0;
    int summery = 0;
    int push = 0;
    node* number1 = add1;
    node* number2 = add2;
    
    (n1>n2)?maxLength=n1:maxLength=n2;
    int result[maxLength+1];
    
    for(int i=maxLength;i>=0;i--)
    {
        if((number1!=NULL)&&(number2!=NULL))
        {
            summery = number1->data + number2->data + push;
            push = summery/10;
            result[i] = summery%10;
            number1 = number1->next;
            number2 = number2->next;
        }
        else if(number1!=NULL)
        {
            summery = number1->data + push;
            push = summery/10;
            result[i] = summery%10;
            number1 = number1->next;
        }
        else if(number2!=NULL)
        {
            summery = number2->data + push;
            push = summery/10;
            result[i] = summery%10;
            number2 = number2->next;
        }
    }
    result[0] = push;
    node* head= creat(result,maxLength+1);
    return head;
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
    int n1 = 4;
    int n2 = 3;
    int add1[] = {7,1,6,1};
    int add2[] = {5,9,2};
    node *head1 = creat(add1,n1);
    node *head2 = creat(add2,n2);
    node *result = add(head1,head2,n1,n2);
    print(result);
    return 0;
}
