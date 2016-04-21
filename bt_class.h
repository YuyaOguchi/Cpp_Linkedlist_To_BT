#pragma once
#include <cstdlib>    // Provides size_t
#include "bintree.h"  // Provides binary_tree_node<Item> template class

    template <typename Item>
    class binary_tree
    {
    public:
        // CONSTRUCTORS and DESTRUCTOR

        binary_tree( );
        binary_tree(const binary_tree& source);
        binary_tree(const Item& entry);
        ~binary_tree( );
        // MODIFICATION MEMBER FUNCTIONS
        void create_first_node(const Item& entry);
        void shift_to_root( );
        void shift_up( );
        void shift_left( );
        void shift_right( );
        void change(const Item& new_entry);
        void add_left(const Item& entry);
        void add_left_tree(const binary_tree *BT);
        void add_right(const Item& entry);
        void add_right_tree(const binary_tree *BT);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t size( ) const;
        Item retrieve( ) const;
        bool has_parent( ) const;
        bool has_left_child( ) const;
        bool has_right_child( ) const;
    //private:
        binary_tree_node<Item> *root;
        binary_tree_node<Item> *current;
        int nodecounter;
    };
    //bt_class.cpp that extends from bintree
    //Yuya Oguchi ID: W1048226
    //Ch 10 project 3

    template <typename Item>
    binary_tree<Item>::binary_tree( ){ //initial state
        root = NULL;
        current = NULL;
        nodecounter = 0;
    }

    template <typename Item>
    binary_tree<Item>::binary_tree(const binary_tree<Item>& source){ //copy the trees
        root = tree_copy(source.root);
        current = root;
        nodecounter = source.nodecounter;
    }

    template <typename Item>
    binary_tree<Item>::binary_tree(const Item& entry) {
        nodecounter = 0;
        create_first_node(entry);
    }

    template <typename Item>
    binary_tree<Item>::~binary_tree( ){ //deconstructor
        tree_clear(root);
    }

    template <typename Item>
    // create the first node with no child and set that as rot
    void binary_tree<Item>::create_first_node(const Item& entry){
        if(size() == 0){
            root = new binary_tree_node<Item>(entry);
            current = root;
            nodecounter++;
        }
    }

    template <typename Item>
    void binary_tree<Item>::shift_to_root( ){ //move currrent cursor to root
        if(size() > 0){
            current = root;
        }
    }

    template <typename Item>
    void binary_tree<Item>::shift_up( ){ // move current cursor to its parent if it exist
        if(has_parent() == true){
            current = current->parent();
        }
    }

    template <typename Item>
    void binary_tree<Item>::shift_left( ){ // move current cursor to its left child if it exist
        if(has_left_child() == true){
            current = current->left();
        }
    }

    template <typename Item>
    void binary_tree<Item>::shift_right( ){// move current cursor to its right child if it exist
        if(has_right_child() == true){
            current = current->right();
        }
    }

    template <typename Item>
    void binary_tree<Item>::change(const Item& new_entry){ // change the value of the current node
        if(size() > 0){
            current->set_data(new_entry);
        }
    }

    template <typename Item>
    void binary_tree<Item>::add_left(const Item& entry){ //add the child to left if child doesnt exist yet
        if(size() > 0 && has_left_child() ==false){
            current->set_left(new binary_tree_node<Item>(entry, NULL, NULL, current));
        }
    }

    template <typename Item>
    void binary_tree<Item>::add_left_tree(const binary_tree *BT){
        if(size() > 0 && has_left_child() ==false){
            if (BT!=NULL) {
                current->set_left(BT->root);
                nodecounter += BT->nodecounter;
            }
        }
    }

    template <typename Item>
    void binary_tree<Item>::add_right(const Item& entry){//add the child to right if child doesnt exist yet
        if(size() > 0 && has_right_child() ==false){
            current->set_right(new binary_tree_node<Item>(entry, NULL, NULL, current));
        }
    }

    template <typename Item>
    void binary_tree<Item>::add_right_tree(const binary_tree *BT){
        if(size() > 0 && has_right_child() ==false){
            if (BT!=NULL) {
                current->set_right(BT->root);
                nodecounter += BT->nodecounter;
            }
        }
    }

    template <typename Item>
    std::size_t binary_tree<Item>::size( ) const{ //return the size of nodes
        return nodecounter;
    }

    template <typename Item>
    Item binary_tree<Item>::retrieve( ) const{ //retrieve the data of current node
        if(size() > 0){
            return current->data();
        }
        return Item();
    }

    template <typename Item>
    bool binary_tree<Item>::has_parent( ) const{ // check if current has parent
        if(size() > 0 && current->parent() != NULL){
            return true;
        }
        return false;
    }

    template <typename Item>
    bool binary_tree<Item>::has_left_child( ) const{// check if current has left child
        if(current ->left() != NULL){
            return true;
        }
        return false;
    }

    template <typename Item>
    bool binary_tree<Item>::has_right_child( ) const{// check if current has right child
        if(current ->right() != NULL){
            return true;
        }
        return false;
    }
