//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int pre = 1;
    Node* addOne(Node *head ,int i =0) 
    {
        // Your Code here
        // return head of list after adding one
        
        if(head == NULL)
        return NULL;
        
        addOne(head->next,i+1);
        head->data += pre;
        
        if(head->data>=10 && i!=0)
        {
            head->data%=10;
            pre = 1;
        }
        else if(head->data == 10 && i==0)
        {
            Node *temp = new Node(1);
            head->data = 0;
            temp->next = head;
            head = temp;
        }
        else if(head->data<10)
        pre = 0;
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends