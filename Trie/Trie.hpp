//
//  Trie.hpp
//  Trie
//
//  Created by Basti Funtasty on 28/11/16.
//  Copyright © 2016 Funtasty. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
using namespace std;

template <class T, class E=char> class Trie {
    
public:
    typedef basic_string<E> key_type;                   // string=basic_string<char>
    typedef pair<const key_type, T> value_type;
    typedef T mapped_type;
    class inner_node;
    class base_node;
    
    //typedef ... iterator;
    
    bool empty()const;
    //iterator insert(const value_type &);
    void erase(const key_type& value);
    void clear();                                       // erase all
    iterator lower_bound(const key_type& testElement);  // first element >= testElement
    iterator upper_bound(const key_type& testElement);  // first element > testElement
    iterator find(const key_type& testElement);         // first element == testElement
    iterator begin();                                   // returns end() if not found
    iterator end();
    
    class base_node {
        
    public:
        //base_node(inner_node* pParent = 0) : ptrParent(pParent) {}
        
        virtual ~base_node() {}
        
//        inner_node* &parent() {
//            return ptrParent;
//        }
        
        //virtual void print(int level) = 0;
        
    private:
        inner_node* ptrParent;
        
    };
    
    class inner_node : public base_node {
        
    public:
        //inner_node(inner_node* pParent = 0) : base_node(pParent) {}
        

        
    private:
        map<E, base_node*> children;
    };
    
    class leaf_node : public base_node {
        
    public:
        
    private:
        
    };
    
private:
    inner_node root;
};

#endif /* Trie_hpp */
