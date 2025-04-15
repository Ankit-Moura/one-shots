#include "./binary_tree.h"



struct b_node * init_binary_tree(int data){
    struct b_node * root = (struct b_node *)malloc(sizeof(struct b_node));
    if(!root){
        printf("overflow condition couldn't initialise the tree\n");
        return NULL;
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;  
    return root;
}

result* search(struct b_node *root, int item){
    result *r = (result *) malloc(sizeof(result));
    r->location = NULL;
    r->parent =  NULL;
    if(!root)
        return r;
    struct b_node * temp = root;
    while (temp)
    {
    if (temp->data == item){
        r->location = temp;
        return r;
    }
    r->parent = temp;
    if (temp->data > item){  
        temp = temp->left;
        continue;
    }
    temp = temp->right;
    }
    return r;
}

struct b_node * insert_node(struct b_node * root, int data){
 if(!root){
    struct b_node * r = init_binary_tree(data);
    return r;
 }
 result *res = search(root, data);
 if(res->location != NULL){
    printf("item %d already exists in binary tree\n", data);
    return root;
 }   
 if(!res->parent){
    return init_binary_tree(data);
 }
 struct b_node * n = init_binary_tree(data);
 if (res->parent->data > data){
    res->parent->left = n;
    return root;
 }
 res->parent->right = n;
 return root;
}

void pre_order_traversal(struct b_node * root){
    struct b_node * ptr = root;
    if(!root){
        return;
    }
    // init stack
    stack *s = init_stack(20);
    push(s, NULL);
    while (ptr)
    {
        printf("%d ", ptr->data);
        if(ptr->right){
        s = push(s, ptr->right);
    }
        ptr = ptr->left;
        if(!ptr){
            ptr = pop(s);
        }
    }
    printf("\n");
    destroy_Stack(s);
}

void in_order_traversal(struct b_node * root){
    struct b_node * ptr = root;
    if(!ptr) return ;
    // init stack with NULL padding
    stack * s = init_stack(20);
    s = push(s,NULL);
    while (ptr || s->top)
    {
        if(ptr){
            s = push(s, ptr);
            ptr = ptr->left;
            continue;
        }
        ptr = pop(s);
        if(ptr){
            printf("%d ", ptr->data);
            ptr = ptr->right;
        }
        
    }
    printf("\n");
}

void post_order_traversal(struct b_node * root){
    struct b_node * ptr;
    if(!root) return ;
    // init stack s1 and s2 with NULL padding
    stack * s1 = init_stack(20);
    s1 = push(s1,NULL);
    stack * s2 = init_stack(20);
    s2 = push(s2,NULL);
    s1 = push(s1, root);
    while (s1->top)
    {
        ptr = pop(s1);
        s2 = push(s2, ptr);
        if(ptr->left){
            s1 = push(s1, ptr->left);
        }
        if(ptr->right){
            s1 = push(s1, ptr->right);
        }
    }
    while(s2->top){
        struct b_node * n = pop(s2);
        if(n)
        printf("%d ", n->data);
    }
    printf("\n");
}

r2* find_min_max(struct b_node * root){
    if(!root){
        return NULL;
    }
    r2 * result = (r2 *)malloc(sizeof(r2));
    struct b_node * ptr, *ptr2;
    ptr = root;
    ptr2 = root;
    while(ptr->left || ptr2->right){
        if(ptr->left){
            ptr = ptr->left;
        }
        if(ptr2->right){
            ptr2 = ptr2->right;
        }

    }
    result->min = ptr;
    result->max = ptr2;
    return result;
}   


int sum(struct b_node*root){
    struct b_node * ptr = root;
    if(!root){
        printf("empty tree\n");
        return -1;
    }
    int total = 0;
    // init stack
    stack *s = init_stack(20);
    push(s, NULL);
    while (ptr)
    {
        total += ptr->data;

        if(ptr->right){
        s = push(s, ptr->right);
    }
        ptr = ptr->left;
        if(!ptr){
            ptr = pop(s);
        }
    }
    destroy_Stack(s);
    return total;
}

struct b_node * delete_node(struct b_node * root, int item){
    if(!root){
        return root;
    }
    result * r = search(root, item);
    // case 1 location is null
    if(!r->location){
        return root;
    }
    // case 2 no child exists 
    if(!r->location->left && !r->location->right){
        if(!r->parent){
            return NULL;
        }
        else{
            // parent exists
            if(r->parent->data>r->location->data){
                r->parent->left = NULL;
            }else{
                r->parent->right = NULL;
            }
            return root;
        }
    }
    //case 3  location contains 1 or 0 nodes
    if(!r->location->left || !r->location->right){
        
        if(r->parent){
            if(r->parent->data>r->location->data){
                r->parent->left = (r->location->left)?r->location->left:r->location->right;
            }else
            {
                r->parent->right = (r->location->left)?r->location->left:r->location->right;
            }
            return root;
        }
        else{
              // choose new root now 
              return r->location->left?r->location->left:r->location->right;
        }
    }
    //case 4 location contains 2 children
    if (r->location->right && r->location->left){
        struct b_node * left_child, *loc, *hold_node;
        left_child = r->location->left;
        loc = r->location->right;
        printf("loc->%d\n", loc->data);
        while (loc && left_child)
        {
            hold_node = loc->left;
            // while (left_child<hold_node)
            // {
            //     /* code */
            // }
            
            loc->left = left_child;
            left_child = hold_node;
            loc = loc->right;
        }
        // check if root was deleted
        if(!r->parent){
            return root->right;
        }
        else{
            return root;
        }
        
    }
}