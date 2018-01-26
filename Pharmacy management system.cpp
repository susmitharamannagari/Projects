#include <iostream>
#include<string>

using namespace std;

struct node {
	int key;
	string medname;
	int stock;
	int price;
	struct node * next;
};

node *head = NULL;
struct node *searchNode(int n) {
	if(head == NULL) return head;
	node *cur = head;
	node *prev = head;
	while(cur) {
		if(cur->key == n) return cur;
		prev = cur;
		cur = cur->next;
	}
	return cur;
}
struct node *searchNode(string n) {
	if(head == NULL) return head;
	node *cur = head;
	node *prev = head;
	while(cur) {
		if(cur->medname == n) return cur;
		prev = cur;
		cur = cur->next;
	}
	return cur;
}

void addNode(int n,string name,int x,int y) {
	node *newNode = new node;
	newNode->key = n;
	newNode->next = NULL;
	newNode->medname=name;
	newNode->stock=x;
	newNode->price=y;

	if(head == NULL) {
		head = newNode;cout<<"\n product is added.";
		return;
	}
	node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;cout<<"\n product is added";
			return;
		}
		cur = cur->next;
	}
}
void deleteNode(int n) {
	node *ptr = searchNode(n);
	if(ptr == NULL)
		cout << "No product with id = " << n << endl;
	if(ptr == head) {
		head = ptr->next;
		return;
	}
	node *cur = head;
	node *prev = head;

	while(cur) {
		if(cur == ptr) {
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}
void deleteNode(string n) {
	node *ptr = searchNode(n);
	if(ptr == NULL)
		cout << "No product with name = " << n << endl;
	if(ptr == head) {
		head = ptr->next;
		return;
	}
	node *cur = head;
	node *prev = head;

	while(cur) {
		if(cur == ptr) {
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void display() {
	struct node *list = head;
	cout<<"\nPID\tPNAME\tSTOCK\tPricePerUnit\n";
	while(list) {
		cout << list->key<<"\t";
		cout<< list->medname<<"\t";
		cout<<list->stock<<"\t";
		cout<<list->price<<"\n";
		list = list->next;
	}
	cout << endl;
}
void update(node *cur)
{int choice,up;
 cout<<"\n Is stock sold or added: 1.Sold 2.Added";cin>>choice;
 if(choice==1)
 {
     cout<<"\n Enter the amount of stock sold:";cin>>up;
     cur->stock=cur->stock - up;
     cout<<"\n Updated stock after selling="<<cur->stock;
 }
 else
 {
     cout<<"\n Enter the amount of stock added:";cin>>up;
     cur->stock=cur->stock + up;
     cout<<"\n Updated stock after adding="<<cur->stock;
 }
}

int main()
{ int pid,choice1,choice2,choice3,flag=0,quantity,cost;
  node *temp;
  string pname;
  cout<<"                            PHARMACY SYSTEM                                                 ";
  while(flag==0)
  {
   cout<<"\n enter your choice: 1.Add product   2.Delete product   3.Display products   4.Search products   5.Update Stock   6.Exit\n";
   cin>>choice1;
   switch(choice1)
   {
    case 1: cout<<"\n enter the product id:";
            cin>>pid;cout<<"\n enter the name of product:";
            cin>>pname;
            cout<<"\n Enter the quantity:";cin>>quantity;
            cout<<"\n Enter the price for 1 unit:";cin>>cost;
	        addNode(pid,pname,quantity,cost);break;

    case 2:cout<<"\n choose how u want to delete:  1.using product id   2. using product name\n";
           cin>>choice2;
           switch(choice2)
           {
               case 1: cout<<"\n enter id:";
                        cin>>pid;
                       deleteNode(pid);
                       display();
                       break;
               case 2: cout<<"\n enter product name:";
               cin>>pname;
               deleteNode(pname);
	           display();break;
	           default: cout<<"\n wrong choice.";
           }break;
    case 3: display();break;
    case 4:cout<<"\n choose how u want to search:    1.using product id    2. using product name\n"; cin>>choice3;
        switch(choice3)
           {
               case 1: cout<<"\n enter id:";
                        cin>>pid;
                       temp=searchNode(pid);
                       if(temp)
                        cout<<"\n product found";
                        else
                            cout<<"\n product not found.";
                        break;
               case 2: cout<<"\n enter product name:";
               cin>>pname;
               temp=searchNode(pname);
               if(temp)
                cout<<"\n product found.";
               else
                cout<<"\n product not found.";
	           break;
	           default: cout<<"\n wrong choice.";
           }break;
    case 5:cout<<"\n Enter the ID of the product to be modified:";cin>>pid;
           temp=searchNode(pid);
           update(temp);
           break;
    case 6: flag=1;break;
    default: cout<<"wrong choice";
}
  }
return 0;
}
