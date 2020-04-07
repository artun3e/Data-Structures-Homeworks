#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

template<class T>
struct avl_node {

    /*T name;
    T sname;
    T fullname; // the key!
    T Tel;
    T City;*/
    T key;
    T number;
    T city;
    
    avl_node<T> * right;
    avl_node<T> * left;
    
    avl_node<T>(const T& keyValue,T & number , T & city, avl_node<T>* rightChild, avl_node<T> *leftChild)
    : key(keyValue),number(number), city(city) ,right(rightChild), left(leftChild) {}
    //node(const T& Name, const T& Sname,const T& fname ,const T& tel, const T& city, node* leftChild, node* //rightChild) :
       // name(Name), sname(Sname),fullname(fname) ,Tel(tel), City(city), left(leftChild), right(rightChild) {}


};

template<class T>
class AVL {

public:
    
    

    void createPhBook(ifstream & fbookFile);
    int getHeight(avl_node<T> * root);
    int getDiff(avl_node<T> * root);
/*
    typename node* Rotate_RR(node * root);
    typename node* Rotate_LL(node * root);
    typename node* Rotate_LR(node * root);
    typename node* Rotate_RL(node * root);
*/
    void Balance(avl_node<T> *& root);

    bool isBalanced(avl_node<T>* root);
    int height(avl_node<T>* node);
    
    std::string toUpper(string & word);
    
     avl_node<T>* insert(avl_node<T>*& t, avl_node<T>* contact);
     avl_node<T>* singleRightRotate(avl_node<T>* t);
     avl_node<T>* doubleRightRotate(avl_node<T>* t);
     avl_node<T>* singleLeftRotate(avl_node<T>* t);
     avl_node<T>* doubleLeftRotate(avl_node<T>* t);
     avl_node<T>* remove(avl_node<T>* t, T& key);
     avl_node<T>* findMin(avl_node<T>* t);
     avl_node<T>* findMax(avl_node<T>* t);
     avl_node<T>* findContact(avl_node<T>* t, T& key);
     
     //void addNode(node*& root, node* Contact);
    int comparator(T first, T firstS, T second, T secondS);
    void listContact(avl_node<T>*& root, T & key);
    void listing(avl_node<T>* node, T & key, bool & found);
    void deleteContact(avl_node<T> *& root,  T & fullname);
    void printPhoneBook(avl_node<T> *& head);
    void saveToFile(avl_node<T> *& head, std::ofstream &output);
    void printAVL(const std::string& prefix, avl_node<T>* head, bool isLeft,std::ofstream & outputfile);
    void printAVL(avl_node<T>* head,std::ofstream & outputfile);
    //void saveToFilePreOrder(avl_node<T> * head, std::ofstream &output);
    void saveToFilePreOrder(avl_node<T> *root, std::ofstream &output);
    std::string getFullName(std::string first_name, std::string last_name);
    avl_node<T>*& getRoot();

    AVL();
    ~AVL();


private:

    avl_node<T>* root;

};


template<class T>
AVL<T>::AVL() {
    root = NULL;
}

template<class T>
AVL<T>::~AVL() {
    delete root;
}

template<class T>
std::string AVL<T>::toUpper(std::string & word)
{
    for(int i = 0; i < word.length(); i++) word[i] = toupper(word[i]);
    return word;
}


/*template<class T>
void AVL<T>::createPhBook(ifstream & fbookFile) {

    //cout << "Creating the phone book ... " << endl;
    //ifstream fbookFile("PhoneBook-mod.txt");
    string line, Name, surname, phoneNum, city;
   // string fullname = Name + " " + surname;

    if (fbookFile.is_open())
        //        while (getLine(fbookFile, line)) {
        //cout << "I am here" << endl;
        while (fbookFile >> Name >> surname >> phoneNum >> city) {
            toUpper(Name);
            toUpper(surname);
            string fullname = Name + " " + surname;
            //cout << Name << " " << surname << " " << phoneNum << endl;
            typename AVL<T>::node* newCnt = new AVL<T>::node(Name, surname,fullname ,phoneNum, city, NULL, NULL);
            insert(getRoot(), newCnt);
        }
}*/


template<class T>
int AVL<T>::getHeight(avl_node<T> * root) {
    int height = 0;
    if (root) {
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        int maximum_l_r = max(left_height, right_height);
        height = maximum_l_r;
    
    }
    return height;

}

template<class T>
int AVL<T>::height(avl_node<T>* node)
{
    /* base case tree is empty */
    if (node == NULL)
        return 0;

    /* If tree is not empty then
    height = 1 + max of left
        height and right heights */
    return 1 + max(height(node->left),
        height(node->right));
}


template<class T>
int AVL<T>::getDiff(avl_node<T> * root) {
    int left_height = height(root->left);
    int right_height = height(root->right);

    return left_height - right_height;

}

/*
template<class T>
void AVL<T>::addNode(node *& root, node* contact) {

    if (!root) {
        root = contact;
        return;
    }

    node* tempo = root;
    node* parent = NULL;

    while (tempo != NULL) {
        parent = tempo;

        if (comparator(tempo->name, tempo->sname, contact->name, contact->sname) == 3)
            if (tempo->right)
                tempo = tempo->right;
            else {
                tempo->right = contact;
                Balance(tempo);
                //root = tempo;
                return;
            }
        else {
            if (tempo->left)
                tempo = tempo->left;
            else {
                tempo->left = contact;
                Balance(tempo);
                //root = tempo;
                return;
            }
        }
    }

    
}
*/




template<class T>
avl_node<T>* AVL<T>::singleRightRotate(avl_node<T>* t)
{
    avl_node<T>* u = t->left;
    t->left = u->right;
    u->right = t;
    
    return u;
};

template<class T>
avl_node<T>* AVL<T>::singleLeftRotate(avl_node<T>* t)
{
    avl_node<T>* u = t->right;
    t->right = u->left;
    u->left = t;
    
    return u;
};

template<class T>
avl_node<T>* AVL<T>::doubleLeftRotate(avl_node<T>* t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
};

template<class T>
avl_node<T>* AVL<T>::doubleRightRotate(avl_node<T>* t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
};


template<class T>
std::string AVL<T>::getFullName(std::string first_name, std::string last_name) {

    return first_name + " " + last_name;

}

template<class T>
avl_node<T>* AVL<T>::insert(avl_node<T>*& t, avl_node<T>* contact)
{
    // T name_surname = t->name + " " + t->sname; // this is the node we are comparing
    // T contact_name_surname = contact->name + " " + contact->sname;
    if (t == NULL)
    {
        t = contact;
    }

    else
    {
        if (contact->key < t->key)
        {
            t->left = insert(t->left, contact);

            if (height(t->left) - height(t->right) == 2)
            {
                if (contact->key < t->left->key)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        if (contact->key > t->key)
        {
            t->right = insert(t->right, contact);
            if (height(t->right) - height(t->left) == 2)
            {
                if (contact->key > t->right->key)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }

        }
    }
    //t->height = max(height(t->left), height(t->right)) + 1;
    return t;
};


template<class T>
int AVL<T>::comparator(T first, T firstS, T second, T secondS) {
    if (first < second || (first == second && firstS < secondS))
        return 3;
    else if (first > second || (first == second && firstS > secondS))
        return 1;
    else if (first == second && firstS == secondS)
        return 2;
    else
        return 0;
}


template<class T>
void AVL<T>::listing(avl_node<T>* node, T & key, bool & found) {

    if (node) {

        if (node->key.substr(0, key.length()) == key) {
            //cout << node->name << " " << node->sname << " " << node->Tel << " " << node->City << endl;
            cout << node->key << " " << node->number << " " << node->city << endl;
            found = true;
        }
         if ( node->key.substr(0, key.length()) > key && node->left)
            listing(node->left, key, found);

        if ( node->key.substr(0, key.length()) < key  && node->right)
            listing(node->right, key, found);

    }
    
   // else
     //   cout << "Error, NULL pointer is passed " << endl;
}


template<class T>
void AVL<T>::listContact(avl_node<T>*& root, T & key) { // this is the search function
    avl_node<T>* tmp = root;
    avl_node<T>* tmp1 = tmp;
    bool found = false;
    cout << "Phone book : Section (" << key << ")" << endl;
    cout << "====================================\n" << endl;
    
  
  
    while (root) {
        if (tmp->key.substr(0, key.length()).compare(key) == 0) {
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
        cout << "Contact not found in the AVL tree" << endl;
    else
        cout << "Contact has been found!!!\n";
    root = tmp1;
}

/*
template<class T>
typename avl_node<T>* AVL<T>::Rotate_RR(avl_node<T> * root) {

    avl_node<T> * tmp;
    tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    return tmp;
}

template<class T>
typename avl_node<T>*  AVL<T>::Rotate_LL(avl_node<T> * root) {

    avl_node<T> * tmp;
    tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    return tmp;
}


template<class T>
typename avl_node<T>* AVL<T>::Rotate_LR(avl_node<T> * root) {

    avl_node<T>* tmp;
    tmp = root->left;
    root->left = Rotate_RR(tmp);

    return Rotate_LL(root);

}

template<class T>
typename avl_node<T>* AVL<T>::Rotate_RL(avl_node<T> * root) {

    avl_node<T>* tmp;
    tmp = root->right;
    root->right = Rotate_LL(tmp);

    return Rotate_RR(root);

}

template<class T>
void AVL<T>::Balance(avl_node<T> *& root) {

    int balancing_diff = getDiff(root);

    if (balancing_diff > 1) {
        if (getDiff(root->left) > 0) {
            root = Rotate_LL(root);
        }
        else {
            root = Rotate_LR(root);
        }
    }
    else if (balancing_diff < -1) {

        if (getDiff(root->right) > 0) {
            root = Rotate_RR(root);
        }
        else {
            root = Rotate_RL(root);
        }
    }

}
*/


template<class T>
avl_node<T>* AVL<T>::findMin(avl_node<T>* t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

template<class T>
avl_node<T>* AVL<T>::findMax(avl_node<T>* t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

template<class T>
avl_node<T>* AVL<T>::findContact(avl_node<T>* t, T& key) {

    if (t) {
    
        if (t->key == key)
            return t;
        if (t->key < key)
            return findContact(t->right, key);
        if (t->key > key)
            return findContact(t->left, key);

    }
    return t;
}

template<class T>
avl_node<T>* AVL<T>::remove(avl_node<T>* t, T& key)
{
    bool found = false;
    avl_node<T>* temp;
    avl_node<T>* tmp;
    // Element not found
    if (t == NULL)
        return NULL;
    
    else if (key < t->key)
        t->left = remove(t->left, key);
    else if (key > t->key)
        t->right = remove(t->right, key);
       
    // Searching for element
    ///t = findContact(t, key);
    // Element found
    // With 2 children
    //if (tmp) {
        if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->key = temp->key;
            t->right = remove(t->right, t->key);
        }
        // With one or zero child
        else
        {
            //temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            //delete temp;
            found = true;
        }
        if (t == NULL)
            return t;

        //    t->height = max(height(t->left), height(t->right)) + 1;

            // If node is unbalanced
            // If left node is deleted, right case
        if (height(t->left) - height(t->right) == 2)
        {
            // right right case
            if (height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if (height(t->right) - height(t->left) == 2)
        {
            // left left case
            if (height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }

    //}
    return t;
}

template<class T>
void AVL<T>::deleteContact(avl_node<T> *& root, T & fullname) {

   // fullname = toUpper(fullname);
    bool found = false;
    if (root) // if root is not null
    {
        if (root->key == fullname) // check if the name is equal
        {

            avl_node<T>* temp; // to store
            if (root->right && root->left) // if root has bit
            {

                if (root->right->left)
                {
                    temp = root->right->left; // minimum of the right subtree
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
                    deleteContact(root->right->left, fullname);
                    //Balance(root);
                }
                else // minimum of the right subtree is the root of right subtree itself
                {
                    root->key = root->right->key;
                    root->city = root->right->city;
                    root->number = root->right->number;
                  //  root->sname = root->right->sname;
                    //root->fullname = root->right->fullname;
                    //root->Tel = root->right->Tel;

                    temp = root->right->right;
                    delete root->right;
                    root->right = temp;
                    found = true;
                    Balance(root);
                }
            }
            else // one child or no child
            {
                temp = root;
                root = root->right ? root->right : root->left;
                delete temp;
                found = true;
                Balance(root);
            }
        }
        else if (root->key > fullname)
            deleteContact(root->left, fullname);
        
        else if (root->key < fullname)
            deleteContact(root->right, fullname);
    }
    /*else {
        cout << "Not found in AVL" << endl;
    }*/
    
    if(found)
        cout << "Deleted succesfully...\n";
    //else
        //cout << "Does not exist...\n";

}



template<class T>
void AVL<T>::Balance(avl_node<T> *& t) {

    if (t) {
        if (height(t->left) - height(t->right) == 2)
        {
            if (t->key < t->left->key)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    
        else if (height(t->right) - height(t->left) == 2)
        {
            if (t->key > t->right->key)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }

    }
}
    /*int balancing_diff = getDiff(root);

    if (balancing_diff > 1) {
        if (getDiff(root->left) > 0) {
            root = Rotate_LL(root);
        }
        else {
            root = Rotate_LR(root);
        }
    }
    else if (balancing_diff < -1) {

        if (getDiff(root->right) > 0) {
            root = Rotate_RR(root);
        }
        else {
            root = Rotate_RL(root);
        }
    }
    
    */



/*
int max(int a, int b)
{
    return (a >= b) ? a : b;
}
*/

/* The function Compute the "height"
of a tree. Height is the number of
nodes along the longest path from
the root node down to the farthest leaf node.*/

template<class T>
bool AVL<T>::isBalanced(avl_node<T>* root) {

    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    /* If we reach here then
    tree is not height-balanced */
    return 0;

}

/*
template<class T>
typename AVL<T>::node* AVL<T>::Rotate_RR(node * root) {

    node * tmp;
    tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    return tmp;
}

template<class T>
typename AVL<T>::node*  AVL<T>::Rotate_LL(node * root) {
    
    node * tmp;
    tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    
    return tmp;
}


template<class T>
typename AVL<T>::node* AVL<T>::Rotate_LR(node * root) {

    node* tmp;
    tmp = root->left;
    root->left = Rotate_RR(tmp);

    return Rotate_LL(root);

}

template<class T>
typename AVL<T>::node* AVL<T>::Rotate_RL(node * root) {

    node* tmp;
    tmp = root->right;
    root->right = Rotate_LL(tmp);

    return Rotate_RR(root);

}

*/

template<class T>
void AVL<T>::printPhoneBook(avl_node<T> *& head) {

    if (root != NULL)
    {
        if (head->left != NULL)
            printPhoneBook(head->left);
        cout << head->key << " " << head->number << " " << head->city << endl;
        if (head->right != NULL)
            printPhoneBook(head->right);

    }
    else {
        cout << "The phone book is empty !!" << endl;
    }

}


template<class T>
void AVL<T>::saveToFile(avl_node<T> *& head, std::ofstream &output) {

    if (root != NULL)
    {
        if (head->left)
            saveToFile(head->left, output);

        output << head->key << "  " << head->number << " " << head->city << "\n";

        if (head->right)
            saveToFile(head->right, output);
    }
    else {
        cout << "The phone book is empty !!" << endl;
    }

}
/*
template<class T>
void AVL<T>::saveToFilePreOrder(avl_node<T> * head, std::ofstream &output) {

    if (root == NULL)
        return;
    //{

        output << head->key << "  " << head->number << " " << head->city << "\n";
        saveToFile(head->left, output);
        saveToFile(head->right, output);
        
}*/
template<class T>
void AVL<T>::saveToFilePreOrder(avl_node<T> *root, std::ofstream &output)
{
    if (root == NULL)
        return;

    //cout << root->key << " " << root->number << " " << root->city << endl;
    output << root->key << "  " << root->number << " " << root->city << "\n";
    saveToFilePreOrder(root->left, output);
    saveToFilePreOrder(root->right, output);
}

template<class T>
void AVL<T>::printAVL(const std::string& prefix, avl_node<T>* head, bool isLeft,std::ofstream & outputfile)
{
    if (head != NULL)
    {
        outputfile << prefix;

        outputfile<< (isLeft ? "|--" : "|__");

        // print the value of the node
        outputfile << " " << head->key << std::endl;

        // enter the next tree level - left and right branch
        printAVL(prefix + (isLeft ? "|   " : "    "), head->left, true,outputfile);
        printAVL(prefix + (isLeft ? "|   " : "    "), head->right, false,outputfile);
    }
}

template<class T>
void AVL<T>::printAVL(avl_node<T>* head,std::ofstream & outputfile)
{
    printAVL("", head, false,outputfile);
}




template<class T>
avl_node<T> *& AVL<T>::getRoot() {
    return root;
}










