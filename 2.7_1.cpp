/*
 @Ying Zhou
 Coding_Interview_2.7.1  (don't know the size of the link)
 12/18/2015
 */

#include <iostream>
#include <cstring>
#include <stack>
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
bool palindrome(node *head)
{
    bool result = true;
    node *slow = head;
    node *fast = head;
    int keep;
    stack<int> firstPart;
    
    //put the first half part into stack with reverse order
    while(fast->next!=NULL)
    {
        firstPart.push(slow->data);
        if(fast->next->next!=NULL)          //if the size of the link list is odd
        {
            fast = fast->next->next;
        }
        else
        {
            break;
        }
        slow = slow->next;
    }
    
    //check it is palindrome or not
    slow = slow->next;
    while((!firstPart.empty()) && (slow!=NULL))
    {
        keep = firstPart.top();
        firstPart.pop();
        if(keep!=slow->data)
        {
            result = false;
            break;
        }
        slow = slow->next;
    }
    if(!firstPart.empty())
    {
        result = false;
    }
    return result;
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
    int n = 5;
    bool result;
    int test[] = {1,2,3,2,1};
    node *head = creat(test,n);
    print(head);
    result = palindrome(head);
    if(result)
    {
        cout << "The linked list is a palindrome!" << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome!!" << endl;
    }
    return 0;
}
