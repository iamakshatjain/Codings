/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    if(head == NULL)//base case
            return head;
        
        Node* f = head;//fast
        Node* s = head;//slow
    
        bool flag = false;
        
        while( f!=NULL && f->next!=NULL && s != NULL ){
            
            f = f->next->next;
            s = s->next;
            
            if( f == s ){//if we check first then at the begining the flags were equal
                flag = true;
                break;
            }
        }
    return flag;
}
