//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *ahead;
    
    while(curr!=NULL)
    {
        ahead = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }
    return prev;
    
}

Node *addtwoLL(Node* first,Node *second)
{
    Node * ans = new Node(-1);
    Node *temp = ans;
    
    int carry = 0;
    int sum ;
    
    while(first!=NULL || second != NULL || carry!=0)
    {
        sum = 0;
        if(first!=NULL)
        {
            sum+= first->data;
            first = first->next;
        }
        if(second!=NULL)
        {
            sum+=second->data;
            second = second->next;
        }
        
        sum+= carry;
        carry = sum/10;
        Node *curr = new Node(sum%10);
        temp->next = curr;
        temp = curr;
        
    }
    return ans->next;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        Node *final_ans = addtwoLL(first,second);
        
        return reverse(final_ans);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends