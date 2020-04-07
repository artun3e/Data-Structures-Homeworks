#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>

using namespace std;



/*
template<class T>
struct node {

    T name;
    T sname;
    T Tel;
    T City;
    node * right;
    node * left;
    node(const T& Name, const T& Sname, const T& tel, const T& city, node* leftChild, node* rightChild) :
        name(Name), sname(Sname), Tel(tel), City(city), left(leftChild), right(rightChild) {}


};
*/
template<class T>
struct node {

   /*T name;
    T sname;
    T fullname; // the key!
    T Tel;
    T City;*/
    T key;
    T city;
    T number;
    node * right;
    node * left;
    
    node(T& keyValue,T & theCity, T & theNumber ,node* rightChild, node *leftChild)
    : key(keyValue), city(theCity), number(theNumber)  ,right(rightChild), left(leftChild) {}
    //node(const T& Name, const T& Sname,const T& fname ,const T& tel, const T& city, node* leftChild, node* //rightChild) :
       // name(Name), sname(Sname),fullname(fname) ,Tel(tel), City(city), left(leftChild), right(rightChild) {}



};

template <class T>
class BST {

public:

    
    BST();
    //BST(node Node);
    ~BST();

    void createPhBook(ifstream & fbookFile);
    void addContact(node<T>* contact);
    void deleteContact(node<T> *& root, node<T> *& contact);
    void deleteContact(node<T> *& root, T& key);
    void findContact(node<T>* root, T singleKey);
    void listContact(node<T>* root, T& key);
    void listing(node<T>* node, T & key, bool & found);
    
    std::string toUpper(string & word);
    
    int getHeight(node<T> * root);
    int height(node<T>* node);
    bool isBalanced(node<T>* root);
   // std::string getFullName(std::string first_name, std::string last_name);
    //node* findContact(T name, T surname, T tel, T city);
    void printPhoneBook(node<T> *& head);
    int comparator(T first, T firstS, T second, T secondS);
    void saveToFile(node<T>*& head, std::ofstream &output);
    void printBST(node<T>* head,std::ofstream & outputfile);
    void printBST(const std::string& prefix, node<T>* head, bool isLeft,std::ofstream & outputfile);
    node<T>*& getRoot();
    //int compare(char a, char b);

private:

    node<T>* root;

};


template<class T>
BST<T>::BST()
{
    root = NULL;
}



template<class T>
BST<T>::~BST()
{
    delete root;
}




template<class T>
std::string BST<T>::toUpper(string & word)
{
    for(int i = 0; i < word.length(); i++) word[i] = toupper(word[i]);
    return word;
}

template<class T>
void BST<T>::addContact(node<T>* contact) {
    
    if (!root) {
        root = contact;
        return;
    }
    
    node<T>* tempo = root;
    node<T>* parent = NULL;

    while (tempo != NULL) {
        parent = tempo;
       // toUpper(tempo->key);
       // string fullnameCurrent = tempo->name + " " + tempo->sname;
        //string fullnameContact = contact->name + " " + contact->sname;
        
        
        
        if (tempo->key < contact->key)
        //if (comparator(tempo->name, tempo->sname, contact->name, contact->sname) == 3)
            if (tempo->right)
                tempo = tempo->right;
            else {
                tempo->right = contact;
                return;
            }
        else {
            if (tempo->left)
                tempo = tempo->left;
            else {
                tempo->left = contact;
                return;
            }
        }
    }
    
}

template<class T>
void BST<T>::deleteContact(node<T> *& root, node<T> *& contact) {
    
    bool found = false;
    if (root)
    {
        
        if (root->fullname == contact->fullname)
        {
            
            node<T>* temp;
            if (root->right && root->left)
            {
                
                if (root->right->left)
                {
                    temp = root->right->left;
                    while (temp->left)
                    {
                        temp = temp->left;
                    }
                    root->name = temp->name;
                    root->sname = temp->sname;
                    root->fullname = temp->fullname;
                    root->Tel = temp->Tel;
                    deleteContact(root->right->left, contact);
            
                }
                else
                {
                    root->name = root->right->name;
                    root->sname = root->right->sname;
                    root->fullname = root->fullname;
                    root->Tel = root->right->Tel;
                    
                    temp = root->right->right;
                    delete root->right;
                    root->right = temp;
                    found = true;
                }
            }
            else
            {
                temp = root;
                root = root->right ? root->right : root->left;
                
            }
        }
        else if (root->name > contact->name){
            deleteContact(root->left, contact);
            }
        else if (root->name < contact->name)
            deleteContact(root->right, contact);
    }

}

template<class T>
void BST<T>::deleteContact(node<T> *& root, T& key) {

    key = toUpper(key);
    if (root)
    {
        if (root->key == key)
        {
            node<T>* temp;
            if (root->right && root->left)
            {
                if (root->right->left)
                {
                    temp = root->right->left;
                    while (temp->left)
                    {
                        temp = temp->left;
                    }
                    root->key = temp->key;
                    root->city = temp->city;
                    root->number = temp->number;
                   // root->sname = temp->sname;
                    //root->fullname = temp->fullname;
                    //root->Tel = temp->Tel;
                    deleteContact(root->right->left, root->key);

                }
                else
                {
                    root->key = root->right->key;
                    root->city = root->right->city;
                    root->number = root->right->number;
                   // root->sname = root->right->sname;
                    //root->fullname = root->fullname;
                    //root->Tel = root->right->Tel;

                    temp = root->right->right;
                    delete root->right;
                    root->right = temp;
                }
            }
            else
            {
                temp = root;
                root = root->right ? root->right : root->left;
            }
        }
        else if (root->key > key)
            deleteContact(root->left, key);
        else if (root->key < key)
            deleteContact(root->right, key);
    }
    //else
    //    cout << "Not found in BST " << endl;

}

template<class T>
void BST<T>::findContact(node<T>* root, T key) {

    if (root) {
        if (root->name == key) {
            node<T>* Contact = new node<T>(root->name, root->sname, root->Tel, root->City, NULL, NULL);
            printContactDetails(Contact);
        }
        else if (root->name > key) {
            findContact(root->left, key);
        }
        else if (root->name < key) {
            findContact(root->right, key);
        }
        
    }
}




template<class T>
void BST<T>::listing(node<T>* node, T & key, bool & found) {

   // key = toUpper(key);
    if (node) {

        if (node->key.substr(0, key.length()) == key) {
            cout << node->key << " " << node->city << " " << node->number << endl;
            found = true;
            if(node->left->key.substr(0,key.length()) == key)
                listing(node->left,key,found);
            else if(node->right->key.substr(0,key.length()) == key)
                listing(node->right,key,found);
        }

        if ( node->key.substr(0, key.length()) > key && node->left)
            listing(node->left, key, found);

        if ( node->key.substr(0, key.length()) < key && node->right)
            listing(node->right, key, found);

    }
    //else
    //    cout << "Error, NULL pointer is passed " << endl;
}




template<class T>
void BST<T>::listContact(node<T>* root, T & key) {
    node<T>* tmp = root;
    node<T>* tmp1 = tmp;
    bool found = false;
    cout << "Phonebook : Searching for: (" << key << ")" << endl;
    cout << "====================================\n" << endl;
    //key[0] = toupper(key[0]);
    //cout << "Key is: " << key << " and current node is: " << tmp->fullname << endl;
    while (root) {
        if (tmp->key.substr(0, key.length()).compare(key) == 0
            || tmp->key.find(key) != std::string::npos) {
            //cout << tmp->name[0] << " : " << key << endl;
            //cout << "Equal" << endl;
            root = tmp;
            listing(root, key, found);
            break;
        }
        else if (tmp->key.substr(0, key.length()).compare(key) < 0 || tmp->key.find(key) != std::string::npos) {
            //cout << tmp->name[0] << " : " << key << endl;
            //cout << "Less" << endl;
            ///tmp1 = tmp;
            ///tmp = tmp->right;
            ///root = tmp;
            listing(tmp->right, key, found);
            ///tmp1 = tmp1->left;
            ///root = tmp1;
            listing(tmp->left, key, found);
            break;
        }
        else if (tmp->key.substr(0, key.length()).compare(key) > 0 || tmp->key.find(key) != std::string::npos) {
            //cout << tmp->name[0] << " : " << key << endl;
            //cout << "Greater" << endl;
            ///tmp1 = tmp;
            ///tmp = tmp->left;
            ///root = tmp;
            listing(tmp->left, key, found);
            ///tmp1 = tmp1->right;
            ///root = tmp1;
            listing(tmp->right, key, found);
            break;
        }
    }
    if (!found)
        cout << "Contact not found in the BST tree " << endl;
    root = tmp1;
}

/*
template<class T>
node<T>* BST<T>::findContact(T name, T surname, T email, T city) {

}
*/

template<class T>
int BST<T>::comparator(T first, T firstS, T second, T secondS) {
    if (first < second || (first == second && firstS < secondS))
        return 3;
    else if (first > second || (first == second && firstS > secondS) ||
        (first == second && firstS == secondS))
        return 1;
    else
        return 0;
}

template<class T>
void printContactDetails(typename BST<T>::node* Contact) {

    cout << "Contact name: " << Contact->name << endl;
    cout << "Contact surname: " << Contact->sname << endl;
    cout << "Contact Tel number: " << Contact->Tel << endl;
    cout << "Contact's city: " << Contact->City << endl;
}
/*
template<class T>
void BST<T>::createPhBook(ifstream & fbookFile ) {

    //cout << "Creating the phone book ... " << endl;
    //ifstream fbookFile("PhoneBook-mod.txt");
    string line, Name, surname, phoneNum, city;
    
    if (fbookFile.is_open())
        //        while (getLine(fbookFile, line)) {
        //cout << "I am here" << endl;
        while (fbookFile >> Name >> surname >> phoneNum >> city){
            //cout << Name << " " << surname << " " << phoneNum << endl;
            toUpper(Name);
            toUpper(surname);
            typename BST<T>::node* newCnt = new BST<T>::node(Name, surname,Name + " " + surname ,phoneNum, city, NULL, NULL);
            addContact(newCnt);
        }
}*/

template<class T>
void BST<T>::printPhoneBook(node<T> *& head) {

    if (root != NULL)
    {
        if (head->left != NULL)
            printPhoneBook(head->left);
        cout << head->key << " " << head->city << " " << head->number << endl;
        if (head->right != NULL)
            printPhoneBook(head->right);

    }
    else {
        cout << "The phone book is empty !!" << endl;
    }

}

template<class T>
void BST<T>::saveToFile(node<T> *& head, std::ofstream &output) {

    if (root != NULL)
    {
        if (head->left != NULL)
            saveToFile(head->left, output);
        
        output << head->key << "  " << head->number << " " << head->city << "\n";

        if (head->right != NULL)
            saveToFile(head->right, output);
    }
    else {
        cout << "The phone book is empty !!" << endl;
    }

}

template<class T>
void BST<T>::printBST(const std::string& prefix, node<T>* head, bool isLeft,std::ofstream & outputfile)
{
    if (head != NULL)
    {
        outputfile << prefix;

       outputfile << (isLeft ? "|--" : "|__");

        // print the value of the node
        outputfile << " " << head->key<< std::endl;

        // enter the next tree level - left and right branch
        printBST(prefix + (isLeft ? "|   " : "    "), head->left, true,outputfile);
        printBST(prefix + (isLeft ? "|   " : "    "), head->right, false,outputfile);
    }
}

template<class T>
void BST<T>::printBST(node<T>* head,std::ofstream & outputfile)
{
    printBST("", head, false,outputfile);
}


template<class T>
int BST<T>::getHeight(node<T> * root) {
    int height = 0;
    if (root) {
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        int maximum_l_r = max(left_height, right_height);
        height = maximum_l_r;

    }
    return height;

}


int max(int a, int b)
{
    return (a >= b) ? a : b;
}


template<class T>
int BST<T>::height(node<T>* node)
{

    if (node == NULL)
        return 0;

    return 1 + max(height(node->left),
        height(node->right));
}

template<class T>
bool BST<T>::isBalanced(node<T>* root) {

    int left_h;
    int right_h;

    // If tree is empty then return true
    if (root == NULL)
        return 1;

    // Getting the height of left and right sub-trees
    left_h = height(root->left);
    right_h = height(root->right);

    if (abs(left_h - right_h) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        cout << "I am here " << endl;
        return 1;
    }

    // Tree is not balanced if the flow of execution reaches here
    return 0;

}

template<class T>
node<T> *& BST<T>::getRoot() {
    return root;
};




