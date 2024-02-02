#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
////////////////////////////////////////////////////////// STACK /////////////////////////////////////////////////////////////////////////////////

class SNode
{
public:
   string data;
   SNode *next;
};


class Stack {
public:
   SNode* top;

    Stack() {
        top = NULL;
    }

    // Function to push an element onto the stack
    void push(string x) {
        SNode* new_node = new SNode;
        new_node->data = x;
        new_node->next = top;
        top = new_node;
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == NULL) {
            cout << "Error: stack underflow" << endl;
            return  ;
        }
        SNode* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to get the top element of the stack
    string peek() {
        if (top == NULL) {
            cout << "Error: stack is empty" << endl;
            return NULL;
        }
        return top->data;
    }

    // Function to print all the elements of the stack
    void print() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        SNode* temp = top;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }



    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }
    
    
};

////////////////////////////////////////////////////////     Queue     /////////////////////////////////////////////////////////////////////////////////////////////

class QNode {
	public:
		string data;
		QNode* next;
	
		QNode(string d)
		{
			data = d;
			next = NULL;
		}
};

class Queue {
	public:
		
		QNode *front, *rear;
		
		Queue() 
		{ 
			front = rear = NULL; 
		}
	
		void enqueue(string x)
		{
	
			QNode* temp = new QNode(x);
			if (rear == NULL) {
				front = rear = temp;
				return;
			}
			rear->next = temp;
			rear = temp;
		}
		void dequeue()
		{
			if (front == NULL)
				return;
			QNode* temp = front;
			front = front->next;
			if (front == NULL)
				rear = NULL;
	
			delete (temp);
		}
		bool isEmpty()
		{
			return front == NULL && rear == NULL;
		}
		string Front()
		{
			return front->data;
		}
		string Rear()
		{
			return rear->data;
		}
		int queueSize()
		{
			QNode *tmp = front;
			int size = 0;
			while(tmp != NULL)
			{
				size ++;
				tmp = tmp->next;
			}
			return size;
		}
		void display()
		{
			QNode *tmp = front;
			while(tmp != NULL)
			{
				cout << tmp->data<<endl;
				tmp = tmp->next;
			}
		} 
		
};

////////////////////////////////////////////////////////////////////// Classes ///////////////////////////////////////////////////////////////////////////////

class Spare_parts {
    private:
        string partName;
        int partNumber;
        float partCost;
        int partQuantity;

    public:
        // constructor
        Spare_parts() {};
        Spare_parts(string pname, int pnum, float pcost, int Pquantity) {
            partName = pname;
            partNumber= pnum;
            partCost= pcost;
            partQuantity= Pquantity;
        }

        // setters and getters
        void setPartName(string pname) { partName = pname; }
        void setPartNumber(int pnum) { partNumber = pnum; }
        void setPartCost(float pcost) {  partCost = pcost; }
        void setpartQuantity(int Pquantity) { partQuantity = Pquantity; }

        string getPartName() { return partName; }
        int getPartNumber() { return partNumber; }
        float getPartCost() { return partCost; }
        int getpartQuantity() { return partQuantity; }

        // to input spare pares data
        void getSpareData () {
            cout << ".....Enter Spare Part Data below\n\n";
            cout << "Enter Part Name : "; cin >> partName;
            cout << "\nEnter Part Number : "; cin >> partNumber;
            cout << "\nEnter Part Cost in pounds : "; cin >> partCost;
            cout << "\nEnter Number of existing Parts : "; cin >> partQuantity; cout << "\n\n";
        }

        // to display spare parts data
        void putSpareData(){
            cout << "Part Name : " << partName;
            cout << "\nPart Number : " << partNumber;
            cout << "\nPart Cost in pounds : " << partCost;
            cout << "\nNumber of existing Parts : " << partQuantity; cout << "\n\n";      
        }

        // to modify spare part information.
        void modifySpareData() {
        int choice;

        while (true) {
            cout << "Choose which spare part information you want to change" << endl;
            cout << "0) Nothing" << endl;
            cout << "1) Part name" << endl;
            cout << "2) Part number" << endl;
            cout << "3) Cost" << endl;
            cout << "4) Part quantity" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new part name: ";
                    cin.ignore();
                    getline(cin, partName);
                    break;

                case 2:
                    cout << "Enter new part number: ";
                    cin >> partNumber;
                    break;

                case 3:
                    cout << "Enter new cost: ";
                    cin >> partCost;
                    break;

                case 4:
                    cout << "Enter new part quantity: ";
                    cin >> partQuantity;
                    break;

                case 0:
                    return;
                
                default:
                    cout << "Invalid choice. Please choose a valid option." << endl;
                    break;
            }
        }
    }
        
};


class Supplier {
    private:
        // data members
        string supplierName, supplierAddress, supplierEmail;
        int supplierCode, supplierTelephone;

    public:
        // constructor
        Supplier(){};
        Supplier(string sName, int sCode, string sAddress, string sEmail, int sTelephone) {
            supplierAddress= sAddress;
            supplierEmail = sEmail;
            supplierTelephone = sTelephone;
            supplierName = sName;
            supplierCode = sCode;
        }

        // setters and getters
        void setSuppplierName(string sName) { supplierName = sName;}
        void setSuppplierCode(int sCode) { supplierCode = sCode;}
        void setSupplierAddress(string sAddress) { supplierAddress = sAddress; }
        void setSupplierEmail(string sEmail) { supplierEmail = sEmail; }
        void setSupplierTelephone(int sTelephone) { supplierTelephone = sTelephone; }

        string getSupplierName() { return supplierName; }
        int getSupplierCode() { return supplierCode; }
        string getSupplierAddress() { return supplierAddress; }
        string getSupplierEmail() { return supplierEmail; }
        int getSupplierTelephone() { return supplierTelephone; }

        // to input supplier data
        void getSupplierData () {
            cout << ".....Enter Supplier Data below " << endl;
            cout << "\nSupplier Name : "; cin >> supplierName;
            cout << "\nSupplier Code : "; cin >> supplierCode;
            cout << "\nSupplier Address : "; cin >> supplierAddress;
            cout << "\nSupplier Email : "; cin >> supplierEmail;
            cout << "\nSupplier Telephone : "; cin >> supplierTelephone; cout << "\n\n";
        }

        // to display supplier data
        void putSupplierData () {
            cout << "\nSupplier Name : " << supplierName << endl;
            cout << "Supplier Code : " << supplierCode << endl;
            cout << "Supplier Address : " << supplierAddress << endl;
            cout << "Supplier Email : " << supplierEmail << endl;
            cout << "Supplier Telephone : " << supplierTelephone << "\n\n"; 
        }

        // to modify supplier data
        void modifySupplierData() {
            int choice;

            while (true) {
                cout << "Choose which supplier information you want to change" << endl;
                cout << "0) Nothing" << endl;
                cout << "1) Supplier name" << endl;
                cout << "2) Supplier code" << endl;
                cout << "3) Supplier address" << endl;
                cout << "4) Supplier telephone" << endl;
                cout << "5) Supplier email" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter new supplier name: ";
                        cin.ignore();
                        getline(cin, supplierName);
                        break;

                    case 2:
                        cout << "Enter new supplier code: ";
                        cin >> supplierCode;
                        break;

                    case 3:
                        cout << "Enter new supplier address: ";
                        cin.ignore();
                        getline(cin, supplierAddress);
                        break;

                    case 4:
                        cout << "Enter new supplier telephone: ";
                        cin >> supplierTelephone;
                        break;

                    case 5:
                        cout << "Enter new supplier email: ";
                        cin.ignore();
                        getline(cin, supplierEmail);
                        break;

                    case 0:
                        return;
                        break;

                    default:
                        cout << "Invalid choice. Please choose a valid option." << endl;
                        break;
                }
            }
        }
};

////////////////////////////////////////////////////////// LINKED LISTs /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// LINKED LISTs /////////////////////////////////////////////////////////////////////////////////

template <class T>
class Node {
public:
    T* data;
    Node<T> *next;
    Node(T* val) {
        data = val;
        next = NULL;
    }
};




// Linked List of Spare Parts
template <class T>
class Spare_parts_List {

public:
    Node<T> *head;
    Spare_parts_List() {
        head = NULL;
    }

    void addSparePart() {
        Spare_parts *sp = new Spare_parts();
        sp->getSpareData();
        Node<T> *newNode = new Node<T>(sp);
        newNode->next = head;
        head = newNode;        
    }

    void displaySpareParts() {
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->data -> putSpareData();
            temp = temp->next;
        }
    }

    void modifySparePart(int partNumber) {
        Node<T> *temp = head;
        while (temp != NULL) {
            if (temp-> data -> getPartNumber() == partNumber) {
                temp-> data -> modifySpareData();
                return;
            }
            temp = temp->next;
        }
        cout << "Spare part with Number " << partNumber << " does not exist !!!!!!!!" << endl;
    }
};






// Linked List of Supplier Data
template <class T>
class Supplier_List {
    
    public:
        Node<T> *head;
        // constructor
        Supplier_List () { head = NULL; }

        void addSupplier() {
            Supplier *supplier = new Supplier();
            supplier->getSupplierData();

            Node<T> *newNode = new Node<T>(supplier);
            newNode->next = head;
            head = newNode;
        }

        void displaySuppliers() {
            Node<T>* temp = head;
            while (temp != NULL) {
                temp -> data -> putSupplierData();
                temp = temp->next;
            }
        }

        void modifySupplier(int sCode) {
        Node<T> *temp = head ;
        while(temp != NULL){
            if(temp-> data -> getSupplierCode() == sCode){
                temp -> data -> modifySupplierData();
                return;
            }
            temp = temp ->  next;
        }
        cout<<"Supplier Code "<< sCode<<" does not exist !!!!!!!!";
    }
};

////////////////////////////////////////////////////////// SPARE PARTS BINARY TREE /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// SPARE PARTS BINARY TREE /////////////////////////////////////////////////////////////////////////////////

template<class T>
class TNode
{
public:
    T value;
    TNode<T> *Right;
    TNode<T> *Left;
    T* subPointer;
    TNode(T v)
    {
        value = v;
        Right = NULL;
        Left = NULL;
        subPointer = NULL;
    }

};

// Define a specific TNode for int
template <>
class TNode<int> {
public:
    int value;
    TNode<int> *Right;
    TNode<int> *Left;
    TNode<Supplier>* subPointer;

    TNode(int v) {
        value = v;
        Right = NULL;
        Left = NULL;
        subPointer = NULL;
    }
};





template<class T>
class SpareParts_BST
{
public:
    TNode<T> *root;
    int Size;

    SpareParts_BST()
    {
        root = NULL;
        Size = 0;
    }

    TNode<T>* insert(TNode<T> * &root, Spare_parts v)
    {
        TNode<T>* Nnode = new TNode<T>(v);
        if (root == NULL)
        {
            root = Nnode;
            Size++;
            return root;
        }
        if (v.getPartNumber()  > root -> value.getPartNumber())
        {
            root->Right = insert(root->Right, v);
        }
        else
        {
            root->Left = insert(root->Left, v);
        }
        return root;
    }

    bool search(TNode<T> * &root, Spare_parts v)
    {
        if(root == NULL)
            return false;
        if(root->value.getPartNumber() == v.getPartNumber())
            return true;
        if(root->value.getPartNumber() > v.getPartNumber())
            return search(root->Left,v);
        if(root->value.getPartNumber() < v.getPartNumber())
            return search(root->Right,v);
    }

    T minValue(TNode<T> * &root)
    {
        if(root == NULL)
            return T();
        else if (root->Left == NULL)
            return root->value;
        else return minValue(root->Left);
    }

    T maxValue(TNode<T> * &root)
    {
        if(root == NULL)
            return T();
        else if (root->Right == NULL)
            return root->value;
        else return maxValue(root->Right);
    }

    TNode<T> * _delete(TNode<T> * &root, Spare_parts v) {
    if (root == NULL) {
        return NULL;
    }
    if (v.getPartNumber() < root->value.getPartNumber()) {
        root->Left = _delete(root->Left, v);
    }
    else if (v.getPartNumber() > root->value.getPartNumber()) {
        root->Right = _delete(root->Right, v);
    }
    else {
		if (root->Left == NULL && root->Right == NULL)
			root = NULL;
        else if (root->Left == NULL && root->Right  != NULL)
		{
            TNode<T> *temp = root->Right;
            delete root;
            return temp;
        }
        else if (root->Right == NULL && root->Left != NULL)
		{
            TNode<T> *temp = root->Left;
            delete root;
            return temp;
        }
		else {
        T minValue = this->minValue(root->Right);
        root->value = minValue;
        root->Right = _delete(root->Right, minValue);
		}
    }
    return root;
}



    TNode<T> *modify(TNode<T> * &root, Spare_parts v, Spare_parts_List<T> & sparePartsList) {
        if (root == NULL) {
            return NULL;
        }
        if (v.getPartNumber() < root->value.getPartNumber()) {
            root->Left = modify(root->Left, v, sparePartsList);
        }
        else if (v.getPartNumber() > root->value.getPartNumber()) {
            root->Right = modify(root->Right, v,sparePartsList);
        }
        else {
            sparePartsList.modifySparePart(v.getPartNumber());
        }
        return root;   
    }

    void inorder(TNode<T> * &root)
        {
            if(root == NULL)
                return;
            inorder(root->Left);
            root->value.putSpareData();
            cout << endl;
            inorder(root->Right);
        }



    void SparePartList_to_SparePart_Tree(Spare_parts_List<T> spList){
        Node<T> *temp = spList.head;
        while (temp != NULL) {
            insert(root, *(temp->data));
            temp = temp->next;
        }
    }
        

};

////////////////////////////////////////////////// SUBTREE IN SUPPLIER TREE CARRY CODE TO SPAREPARTS  ///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// SUBTREE IN SUPPLIER TREE CARRY CODE TO SPAREPARTS  ///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// SUBTREE IN SUPPLIER TREE CARRY CODE TO SPAREPARTS  ///////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class SubTree_partNumberCode_BST
{
public:
    TNode<T> *root;
    int Size;
    
    SubTree_partNumberCode_BST()
    {
        root = NULL;
        Size = 0;
    }

    TNode<T>* insert(TNode<T> * &root, int v)
    {
        // if(v !=  )
        TNode<T>* Nnode = new TNode<T>(v);
        if (root == NULL)
        {
            root = Nnode;
            Size++;
            return root;
        }
        if (v > root -> value)
        {
            root->Right = insert(root->Right, v);
        }
        else
        {
            root->Left = insert(root->Left, v);
        }
        return root;
    }

    bool search(TNode<T> *root,int v)
    {
        if(root == NULL)
            return false;
        if(root->value == v)
            return true;
        if(root->value > v)
            return search(root->Left,v);
        if(root->value < v)
            return search(root->Right,v);
    }

    int minValue(TNode<T> *root)
    {
        if(root==NULL)
            return NULL;
        else if (root->Left == NULL)
            return root->value;
        else return minValue(root->Left);
    }

    int maxValue(TNode<T> *root)
    {
        if(root==NULL)
            return NULL;
        else if (root->Right == NULL)
            return root->value;
        else return maxValue(root->Right);
    }

    TNode<T> * _delete(TNode<T> *root, T v) {
    if (root == NULL) {
        return NULL;
    }

    if (v < root->value) {
        root->Left = _delete(root->Left, v);
    }
    else if (v > root->value) {
        root->Right = _delete(root->Right, v);
    }
    else {

		if (root->Left == NULL && root->Right == NULL)
			root=NULL;
        else if (root->Left == NULL && root->Right  != NULL)
		{
            TNode<T> *temp = root->Right;
            delete root;
            return temp;
        }
        else if (root->Right == NULL && root->Left != NULL)
		{
            TNode<T> *temp = root->Left;
            delete root;
            return temp;
        }
		else {
        T minValue = this->minValue(root->Right);
        root->value = minValue;
        root->Right = _delete(root->Right, minValue);
		}
    }
    return root;
}


void inorder(TNode<T> *root)
    {
        if(root == NULL)
            return;
        inorder(root->Left);
        root->value;
        cout<<endl;
        inorder(root->Right);
    }




};

////////////////////////////////////////////////////////// SUPPLIER BINARY TREE /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// SUPPLIER BINARY TREE /////////////////////////////////////////////////////////////////////////////////

template<class T>
class Supplier_BST
{
public:
    TNode<T> *root;
    int Size;

    Supplier_BST()
    {
        root = NULL;
        Size = 0;
    }

    TNode<T>* insert(TNode<T> * &root, Supplier v)
    {
        TNode<T>* Nnode = new TNode<T>(v);
        if (root == NULL)
        {
            root = Nnode;
            Size++;
            return root;
        }
        if (v.getSupplierCode()  > root -> value.getSupplierCode())
        {
            root->Right = insert(root->Right, v);
        }
        else
        {
            root->Left = insert(root->Left, v);
        }
        return root;
    }

    bool search(TNode<T> * &root, Supplier v)
    {
        if(root == NULL)
            return false;
        if(root->value.getSupplierCode() == v.getSupplierCode())
            return true;
        if(root->value.getSupplierCode() > v.getSupplierCode())
            return search(root->Left,v);
        if(root->value.getSupplierCode() < v.getSupplierCode())
            return search(root->Right,v);
    }

    T minValue(TNode<T> * &root)
    {
        if(root != NULL) {
             if (root->Left == NULL)
                return root->value;
            else return minValue(root->Left);
        }
    }

    T maxValue(TNode<T> *root)
    {
        if(root==NULL)
            return NULL;
        else if (root->Right == NULL)
            return root->value;
        else return maxValue(root->Right);
    }

    TNode<T> * _delete(TNode<T> * &root, Supplier v) {
    if (root == NULL) {
        return NULL;
    }
    if (v.getSupplierCode() < root->value.getSupplierCode()) {
        root->Left = _delete(root->Left, v);
    }
    else if (v.getSupplierCode() > root->value.getSupplierCode()) {
        root->Right = _delete(root->Right, v);
    }
    else {
		if (root->Left == NULL && root->Right == NULL)
			root=NULL;
        else if (root->Left == NULL && root->Right  != NULL)
		{
            TNode<T> *temp = root->Right;
            delete root;
            return temp;
        }
        else if (root->Right == NULL && root->Left != NULL)
		{
            TNode<T> *temp = root->Left;
            delete root;
            return temp;
        }
		else {
        T minValue = this->minValue(root->Right);
        root->value = minValue;
        root->Right = _delete(root->Right, minValue);
		}
    }
    return root;
}


    TNode<T> *modify(TNode<T> * &root, Supplier v, Supplier_List<T> & supplierList) {
        if (root == NULL) {
            return NULL;
        }
        if (v.getSupplierCode() < root->value.getSupplierCode()) {
            root->Left = modify(root->Left, v, supplierList);
        }
        else if (v.getSupplierCode() > root->value.getSupplierCode()) {
            root->Right = modify(root->Right, v,supplierList);
        }
        else {
            supplierList.modifySupplier(v.getSupplierCode());
        }
        return root;   
    }


void inorder(TNode<T> * &root)
    {
        if(root == NULL)
            return;
        inorder(root->Left);
        root->value.putSupplierData();
        cout << endl;
        inorder(root->Right);
    }
    

void inorderTraversal_for_printing_partNumbers_inSubTree(TNode<int>* root) {
    if (root != NULL) {
        inorderTraversal_for_printing_partNumbers_inSubTree(root->Left);
        cout << root->value << endl;
        inorderTraversal_for_printing_partNumbers_inSubTree(root->Right);
    }
}

void inorderTraversal_inSubTree_for_getting_numbers(SpareParts_BST<Spare_parts> sparePartTree , TNode<int>* root) {
    if (root != NULL) {
        inorderTraversal_inSubTree_for_getting_numbers(sparePartTree,root->Left);

        search_sparePartData_from_sparePartTree(sparePartTree,root->value);

        inorderTraversal_inSubTree_for_getting_numbers(sparePartTree,root->Right);
    }
}


void search_sparePartData_from_sparePartTree(SpareParts_BST<Spare_parts> sparePartsTree, int partNumber) {
    TNode<Spare_parts> *temp = sparePartsTree.root;
    while (temp != NULL) {
        if (temp->value.getPartNumber() == partNumber) {
            temp->value.putSpareData();
            return;
        }
        if (partNumber > temp->value.getPartNumber()) {
            temp = temp->Right;
        } else {
            temp = temp->Left;
        }
    }
    cout << "Spare part with Number " << partNumber << " does not exist !!!!!!!!" << endl;
}




void SupplierList_to_SUpplier_Tree(Supplier_List<T> sList){


    Node<T> *temp = sList.head;
    while (temp != NULL) {
        insert(root, *(temp->data));
        temp = temp->next;
    }
}


void Link_partNumber_subTree_with_Supplier(Supplier_BST<T> supplierTree, SubTree_partNumberCode_BST<int> subtree, int supplierCode) {
    TNode<T> *temp = supplierTree.root;
    while (temp != NULL) {
        if (temp->value.getSupplierCode() == supplierCode) {
            temp->subPointer = subtree.root;
            return;
        }
        if (supplierCode > temp->value.getSupplierCode()) {
            temp = temp->Right;
        } else {
            temp = temp->Left;
        }
    }
}

void print_partNumber_subTree(Supplier_BST<T> supplierTree, int supplierCode) {
    TNode<T> *temp = supplierTree.root;
    while (temp != NULL) {
        if (temp->value.getSupplierCode() == supplierCode) {
            TNode<int> *tempRoot = temp->subPointer;

            inorderTraversal_for_printing_partNumbers_inSubTree(tempRoot);
            
        
            return;
        }
        if (supplierCode > temp->value.getSupplierCode()) {
            temp = temp->Right;
        } else {
            temp = temp->Left;
        }
    }
}

void print_partData_from_sparePartTree(Supplier_BST<T> supplierTree, SpareParts_BST<Spare_parts> spTree, int supplierCode){
    TNode<T> *temp = supplierTree.root;
    while (temp != NULL) {
        if (temp->value.getSupplierCode() == supplierCode) {
            TNode<int> *tempRoot = temp->subPointer;

            inorderTraversal_inSubTree_for_getting_numbers(spTree, tempRoot);
        
            return;
        }
        if (supplierCode > temp->value.getSupplierCode()) {
            temp = temp->Right;
        } else {
            temp = temp->Left;
        }
    }
}

  

};

////////////////////////////////////////////////////////// INT MAIN /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// INT MAIN /////////////////////////////////////////////////////////////////////////////////

int main() {
    string str;
    int pN,sC;
    Spare_parts_List<Spare_parts> sparePartsList;
    Supplier_List<Supplier> supplierList;
    SpareParts_BST<Spare_parts> sparePartsTree;
    Supplier_BST<Supplier> supplierTree;
    Stack sk;
    Queue qu;
    Spare_parts part;
    Supplier supp;

    
    cout << "Welcome to Spare Parts/Supplier Management System" << endl;
    cout << "Press any key to continue....." << endl;
    getch();
    system("cls");

while (1) {
    cout << "------------------- Linked List System------------------------" << endl;
    cout << "1) Spare Parts Management(LinkedList)" << endl;
    cout << "2) Supplier Management(LinkedList)" << endl;
    cout << "3) Convert your LinkedList to Binary Search Tree" << endl;
    cout << "4) Show History(Stacks)"<<endl;
    cout << "5) Show Queue"<<endl;
    cout << "6) Exit" << endl;
    cout << "Enter your choice : ";
    
    int choice;
    cin >> choice;
    system("cls");

    switch (choice) {
        case 1:
        {
            while (1) {
                
                int exit1 = 0;
                cout << "1) Add Spare Part" << endl;
                cout << "2) Display Spare Parts" << endl;
                cout << "3) Modify Spare Part" << endl;
                cout << "4) Return to previous Page" << endl;
                cout << "Enter your choice : ";
                
                int choice1;
                cin >> choice1;
                system("cls");

                switch (choice1) {
                    case 1:
                        cout << "Add Spare Part" << endl;
                        cout << endl;
                        sparePartsList.addSparePart();
                            
                        pN = sparePartsList.head->data->getPartNumber();
                        str = "User added spare part with Number " + to_string(pN);
                        sk.push(str);
                        qu.enqueue(str);
                        
                        
                        getch();
                        system("cls");
                        break;

                    case 2:
                        cout << "Display All Spare Parts" << endl;
                        cout << endl;
                        sparePartsList.displaySpareParts();
                        str = "User displayed all spare part ";
                        sk.push(str);
                        getch();
                        system("cls");
                        break;

                    case 3:
                        cout << "Modify Spare Part" << endl;
                        cout << endl;
                        cout << "Enter Part Number : ";
                        int num;
                        cin >> num;
                        sparePartsList.modifySparePart(num);
                        str = "User modified spare part with Number " + to_string(num);
                        sk.push(str);
                        qu.enqueue(str);
                        getch();
                        system("cls");
                        break;

                    case 4:
                        cout << "Return to home" << endl;
                        exit1 = 1;
                        getch();
                        system("cls");
                        break;

                    default:
                        cout << "Invalid Choice" << endl;
                        break;
                }

                if (exit1 == 1) {
                    system("cls");
                    break;
                }
            }
            break;
        }

        case 2:
        {
            while (1) {
                int exit1 = 0;
                cout << "1) Add Supplier" << endl;
                cout << "2) Display Suppliers" << endl;
                cout << "3) Modify Supplier" << endl;
                cout<< "4) Return to previous Page"<<endl;
                cout << "Enter your choice : ";

                int choice2;
                cin >> choice2;
                system("cls");

                switch (choice2) {
                    case 1:
                        cout << "Add Supplier" << endl;
                        cout << endl;
                        supplierList.addSupplier();
                        sC = supplierList.head->data->getSupplierCode();
                        str = "User added supplier with Code " + to_string(sC);
                        sk.push(str);
                        qu.enqueue(str);
                        system("cls");
                        break;

                    case 2:
                        cout << "Display All Suppliers" << endl;
                        cout << endl;
                        supplierList.displaySuppliers();
                        str = "User displayed all suppliers ";
                        sk.push(str);
                        getch();
                        system("cls");
                        break;

                    case 3:
                        cout << "Modify Supplier" << endl;
                        cout << endl;
                        int num;
                        cin >> num;
                        supplierList.modifySupplier(num);
                        str = "User modified supplier with Code " + to_string(num);
                        sk.push(str);
                        qu.enqueue(str);
                        getch();
                        system("cls");
                        break;

                    case 4:
                        cout << "Return to home" << endl;
                        exit1 = 1;
                        system("cls");
                        break;

                    default:
                        cout << "Invalid Choice" << endl;
                        break;
                }

                if (exit1 == 1) {
                    system("cls");
                    break;
                }
            }
            break;
        }

    



        case 3:
        {   
            sparePartsTree.SparePartList_to_SparePart_Tree(sparePartsList);
            supplierTree.SupplierList_to_SUpplier_Tree(supplierList);
            while(1){
            int exist1 =0;
            cout<<"------------------- Binary Search Trees Systemm------------------------"<<endl;
            cout<<"1) Spare Parts Management(Binary Search Tree)"<<endl;
            cout<<"2) Supplier Management(Binary Search Tree)"<<endl;
            cout<<"3) Link Spare Parts SubTree with a Supplier"<<endl;
            cout<<"4) Print parts numbers of certain supplier"<<endl;
            cout<<"5) Print parts data of certain supplier"<<endl;
            cout<<"6) Show History (Stacks)"<<endl;
            cout<<"7) Show queue" << endl;
            cout<<"Enter your choice : ";
            int choice3;
            cin>>choice3;
            system("cls");
            switch(choice3)
            {
                case 1:
                {
                    while(1){
                    int exit1=0;
                    cout<<"-------------------Spare Parts Management(Binary Search Tree)------------------------"<<endl;
                    cout<<"1) Insert in Spare Parts Tree"<<endl;
                    cout<<"2) Search in Spare Parts Tree"<<endl;
                    cout<<"3) Delete in Spare Parts Tree"<<endl;
                    cout<<"4) Modify in Spare Parts Tree"<<endl;
                    cout<<"5) Return to previous Page"<<endl;
                    cout<<"Enter your choice : ";
                    int choice31;
                    cin>>choice31;
                    system("cls");
                    switch(choice31)
                        {
                            case 1:
                            {
                                //use insert function
                                
                                cout << "Insert in Spare Parts Tree\n";
                                part.getSpareData();
                                sparePartsTree.insert(sparePartsTree.root, part);
                                pN = part.getPartNumber();
                                str = "User inserted spare part in the BinaryTree with Number " + to_string(pN);
                                sk.push(str);
                                qu.enqueue(str);
                                getch();
                                system("cls");
                                break;
                            }
                            case 2:
                            {
                                // use search function
                                int search;
                                cout << "Enter Part Number to search for\n"; cin >> search;
                                part.setPartNumber(search);
                                str = "User searched for a spare part in the BinaryTree with Number " + to_string(search);
                                sk.push(str);
                                if (sparePartsTree.search(sparePartsTree.root, part)) cout << "Found\n\n";
                                else cout << "Not Found\n\n";

                               getch();
                                break;
                            }
                            case 3:
                            {
                                //use delete function
                                int del;
                                cout << "Enter a Part Number to delete\n"; cin >> del;
                                part.setPartNumber(del);
                                if (sparePartsTree.search(sparePartsTree.root, part)) {
                                    sparePartsTree._delete(sparePartsTree.root, part);
                                    cout << "Spare Part " << del << " has been deleted successfully\n\n";
                                    str = "User deleted spare part in the BinaryTree with Number " + to_string(del);
                                    sk.push(str);
                                    qu.enqueue(str);
                                }
                                else 
                                    cout << "Not found\n\n";
                                getch();
                                break;
                            }
                            case 4:
                            {
                                //use modify function
                                int mod;
                                cout << "Enter a Part Number to modify\n"; cin >> mod;
                                part.setPartNumber(mod);
                                if (sparePartsTree.search(sparePartsTree.root, part)) {
                                    sparePartsTree.modify(sparePartsTree.root, part, sparePartsList); 
                                    cout << "Spare Part with Part Number " << mod << "has been modified successfully\n\n";  
                                    str = "User modified spare part in the BinaryTree with Number " + to_string(mod);
                                    sk.push(str);
                                    qu.enqueue(str);
                                }
                                else
                                    cout << "Not found\n\n";
                                getch();
                                break;
                            }
                            case 5:
                            {
                                cout<<"Return "<<endl;
                                exit1=1;
                                system("cls");
                                break;
                            }
                        
                        }
                        if(exit1 == 1)
                        break;
                    }
                    break; 
                }
                case 2:
                {
                    while(1){
                    int exit1=0;
                    cout<<"-------------------Supplier Management(Binary Search Tree)------------------------"<<endl;
                    cout<<"1) Insert in Supplier Tree"<<endl;
                    cout<<"2) Search in Supplier Tree"<<endl;
                    cout<<"3) Delete in Supplier Tree"<<endl;
                    cout<<"4) Modify in Supplier Tree"<<endl;
                    cout<<"5) Return to previous Page"<<endl;
                    cout<<"Enter your choice : ";
                    int choice32;
                    cin>>choice32;
                    system("cls");
                    switch(choice32)
                        {
                            case 1:
                            {
                                //use isnert function
                                cout << "Insert in Suppliers Tree\n";
                                supp.getSupplierData();
                                supplierTree.insert(supplierTree.root, supp);
                                sC = supp.getSupplierCode();
                                str = "User inserted supplier in the BinaryTree with Code " + to_string(sC);
                                sk.push(str);
                                qu.enqueue(str);
                                system("cls");
                                break;
                            }
                            case 2:
                            {
                               //use search function
                                int search;
                                cout << "Enter Supplier Code to search for\n"; cin >> search;
                                supp.setSuppplierCode(search);
                                if (supplierTree.search(supplierTree.root, supp)) {
                                    cout << "Found\n\n";
                                    str = "User searched for a supplier in the BinaryTree with Code " + to_string(search);
                                    sk.push(str);
                                }
                                else cout << "Not Found\n\n";
                                break;
                            }
                            case 3:
                            {
                                //use delete function
                                int del;
                                cout << "Enter a Supplier code to delete\n"; cin >> del;
                                supp.setSuppplierCode(del);
                                if (supplierTree.search(supplierTree.root, supp)) {
                                    supplierTree._delete(supplierTree.root, supp);
                                    cout << "Supplier Code " << del << " has been deleted successfully\n\n";
                                    str = "User deleted supplier in the BinaryTree with Code " + to_string(del);
                                    sk.push(str);
                                    qu.enqueue(str);
                                }
                                else 
                                    cout << "Not found\n\n";
                                break;
                            }
                            case 4:
                            {
                                //use modify function
                                int mod;    
                                cout << "Enter a Supplier Code to modify\n"; cin >> mod;
                                supp.setSuppplierCode(mod);
                                if (supplierTree.search(supplierTree.root, supp)) {
                                    supplierTree.modify(supplierTree.root, supp, supplierList); 
                                    cout << "Supplier Code " << mod << "has been modified successfully\n\n";     
                                    str = "User modified supplier in the BinaryTree with Code " + to_string(mod);
                                    sk.push(str);
                                    qu.enqueue(str);             
                                    break;
                                }
                                case 5:
                                {
                                    cout<<"Return "<<endl;
                                    exit1=1;
                                    system("cls");
                                    break;
                                }
                        
                        }
                    
                           
                    }
                    if(exit1 == 1){
                        break;}
                     
                }
                break; 

                case 3:
                {
                    cout<<"-------------------Link Spare Parts SubTree with a Supplier------------------------"<<endl;
                    // Linking with supplier

                    // 1. Create subtree
                    // 2. Link it with supplier
                    
                    SubTree_partNumberCode_BST<int> subTree;
                    cout << "Enter the number of parts you want to add in the subtree: ";
                    int nparts;
                    cin >> nparts;
                
                    while (nparts--) {
                        int partNumber;
                        cout << "Enter part number: ";
                        cin >> partNumber;
                        subTree.insert(subTree.root, partNumber);
                    }
                
                    cout << endl;
                    cout << "Enter supplier code: ";
                    int supplierCode;
                    cin >> supplierCode;
                
                    supplierTree.Link_partNumber_subTree_with_Supplier(supplierTree, subTree, supplierCode);
                    getch();
                    break;
                }
                
                case 4:
                {
                    cout<<"-------------------Print parts numbers of certain supplier------------------------"<<endl;
                    // Print part numbers of a certain supplier
                    cout << "Enter supplier code: ";
                    int supplierCode;
                    cin >> supplierCode;
                    supplierTree.print_partNumber_subTree(supplierTree, supplierCode);
                    getch();
                    break;
                }
                
                case 5:
                {
                    cout<<"-------------------Print parts data of certain supplier------------------------"<<endl;
                    // Print part data of a certain supplier
                    cout << "Enter supplier code: ";
                    int supplierCode;
                    cin >> supplierCode;
                    supplierTree.print_partData_from_sparePartTree(supplierTree, sparePartsTree, supplierCode);
                    getch();
                    break;
                }
                case 6:
                {
                    cout<<"-------------------Show History(Stacks)------------------------"<<endl;
                    //show history
                    getch();
                    system("cls");
                    break;
                }
                case 7:
                {
                    cout<<"-------------------Show Queue------------------------"<<endl;
                    //show queue
                    getch();
                    system("cls");
                    break;
                }
            }
            }
        }

        case 4: {
            cout<<"-------------------Show History(Stacks)------------------------"<<endl;
            //show history
            sk.print();
            getch();
            system("cls");
            break;
        }
        case 5: {
            cout<<"-------------------Show Queue------------------------"<<endl;
            //show queue
            qu.display();
            getch();
            system("cls");
            break;
        }
        case 6:
        {
            cout<<"-------------------Close Program------------------------"<<endl;
            getch();
            return 0;
        }

    }
    }
}
    return 0;




};
