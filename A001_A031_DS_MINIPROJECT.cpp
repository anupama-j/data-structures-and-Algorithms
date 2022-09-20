


#include<iostream>
using namespace std;

struct node{
    string image_name;
    struct node* prev;
    struct node* next;
}*head,*tail,*ptr1,*ptr2,*special_ptr;

struct node* create_new_node(string image_name){
    struct node *p = new struct node();
    p->image_name = image_name;
    p->prev = NULL;
    p->next = NULL;
    return p;
}


void append(string IMAGE_name){
    ptr1 = create_new_node(IMAGE_name);
    if (head == NULL)
    {
        head = ptr1;
    }
    else{
        ptr2 = head;
        while(ptr2->next != NULL){
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr1;
        ptr1->prev = ptr2;
        tail = ptr1;
    }
    cout<<"\n\nIMAGE Added Successfully\n\n";
}

int get_number_of_nodes(){
    ptr1 = head;
    int i = 0;
    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        i++;
    }
    return i;
}

void get(int index){
    //helps to get node by index
    ptr1 = head;
    int i = 0;
    while(ptr1 != NULL){
        if(i == index){
            special_ptr = ptr1;
            return;
        }
        i++;
        ptr1 = ptr1->next;
    }
}

void traversal(){
    if(head == NULL){
        cout<<"\n\nNo Web IMAGES to Display\n\n";
        return;
    }
    int choice;
    int flag = 0;
    int flag2 = 0;
    ptr1 = head;
    do
    {
        system("cls");
        cout<<ptr1->image_name;
        if(flag == 1){
            cout<<"\n\n(No previous IMAGE to IMAGE \""<<ptr1->image_name<<"\")\n\n";
            flag = 0;
        }
        if(flag == 2){
            cout<<"\n\n(No Next IMAGE to IMAGE \""<<ptr1->image_name<<"\")\n\n";
            flag = 0;
        }
        cout<<"\n\n\n1.GO TO PREVIOUS IMAGE\n2.GO TO NEXT IMAGE\n3.BACK\n\nENTER YOUR CHOICE : ";
        cin>>choice;
        if (choice == 1)
        {
            if (ptr1->prev == NULL)
            {
                // cout<<"\n\n(No previous IMAGE)\n\n";
                flag = 1;
                
            }
            else{
                ptr1 = ptr1->prev;
            }
        }
        else if (choice == 2)
        {
            if(ptr1->next == NULL){
                // cout<<"\n\n(No Next IMAGE)\n\n";
                flag = 2;
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
        else if (choice == 3)
        {
            system("cls");
        }
        else{
            cout<<"Please enter valid choice\n\n";
        }
    } while (choice != 3); 
}

void deletion(){
    if(head == NULL){
        cout<<"\n\nNo Web IMAGEs to Delete\n\n";
        return;
    }
    struct node* temp_ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete(temp_ptr);
    cout<<"\n\nIMAGE Deleted Successfully\n\n";
}








int main(){
    int pos;
    int choice;
    string IMAGE_name;
    do
    {
        cout<<"\n\n\n1.INSERT NEW IMAGE\n2.DELETE IMAGE\n3.DISPLAY\n4.Display Number of Web IMAGEs\n5.Search IMAGE By its Position\n6.EXIT\n\nENTER YOUR CHOICE : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\n\nEnter the IMAGE name : ";
            cin>>IMAGE_name;
            append(IMAGE_name);
            break;

        case 2:
            deletion();
            break;

        case 3:
            traversal();
            break;

        case 4:
            cout<<"\n\nThere are "<<get_number_of_nodes()<<" number of IMAGEs in Linked List\n\n";
            break;

        case 5:
            if(!get_number_of_nodes()){
                cout<<"\n\nThere are no IMAGEs in the List.\n\n";
                break;
            }
            cout<<"Enter the Position of IMAGE : ";
            cin>>pos;
            if(get_number_of_nodes()<pos){
                cout<<"\n\nInvalid Position!.There are \""<<get_number_of_nodes()<<"\" IMAGEs and Postion is \""<<pos<<"\" which is more than total number of IMAGEs\n\n";
            }
            else if(pos < 0){
                cout<<"\n\nPosition can't be negative\n\n";
            }
            else{
                get(pos-1);
                cout<<"\n\nThe IMAGE found at Position \""<<pos<<"\" is \""<<special_ptr->image_name<<"\"\n\n";
            }

        case 6:
            //do nothing
            break;
        
        default:
            cout<<"\n\nPlease enter valid choice\n\n";
            break;
        }
    } while (choice != 6); 
    return 0;
}
