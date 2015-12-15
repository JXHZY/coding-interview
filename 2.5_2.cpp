/*
 @Ying Zhou
 Coding_Interview_2.5_2 (forward order)
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
    int number1[n1];
    int number2[n2];
    int index1 = n1-1;
    int index2 = n2-1;
    
    (n1>n2)?maxLength=n1:maxLength=n2;
    int result[maxLength+1];
    
    
    for(int i=0; i<n1; i++)
    {
        number1[i] = add1->data;
        add1 = add1->next;
    }
    
    
    for(int j=0; j<n2; j++)
    {
        number2[j] = add2->data;
        add2 = add2->next;
    }
    
    for(int i=maxLength;i>=0;i--)
    {
        if((index1>=0)&&(index2>=0))
        {
            summery = number1[index1] + number2[index2] + push;
            push = summery/10;
            result[i] = summery%10;
            index1--;
            index2--;
        }
        else if(index1>=0)
        {
            summery = number1[index1] + push;
            push = summery/10;
            result[i] = summery%10;
            index1--;
        }
        else if(index2>=0)
        {
            summery = number2[index2] + push;
            push = summery/10;
            result[i] = summery%10;
            index2--;
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
