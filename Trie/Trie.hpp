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
    class InnerNode;
    class BaseNode;
    
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
    
    //Class for the Nodes
    
    /*
     * BaseNode Class: Base Class for a node with a pointer on the fatherPointer.
     */
    class BaseNode {
        
    public:
        BaseNode(InnerNode* father = 0) : pFather(father){}
        
        virtual ~BaseNode() {}
        
        InnerNode* getParent() {
            return pFather;
        }
        
        void setParent(InnerNode& parent) {
            pFather = parent;
        }
        
        virtual void print(int level) = 0;
        
    private:
        InnerNode* pFather;
    };
    
    //InnerNode Class: Describes the inner nodes of the Trie.
    //				   Letters which have their origin in this node, and the node itself are saved in the map.
    
    class InnerNode : public BaseNode {
        
    public:
        /*
         * Constructor InnerNode and BaseNode with fatherPointer = 0
         */
        InnerNode(InnerNode* ) : BaseNode() {
        };
        
        /*
         * Constructor InnerNode with map, inserts and the BaseNode
         */
        InnerNode(std::map<E, BaseNode*> _map, BaseNode *father) : BaseNode(father) {
            map = _map;
        }
        
        ~InnerNode() {
            map.clear();
        }
        
        map<E, BaseNode*> getMap() {
            return map;
        }
        
    private:
        map<E, BaseNode*> children;
    };
    
    //LeafNode Class: Describes the leafs where the english words are saved.
    class LeafNode: public BaseNode {
        friend class Trie;
        
    public:
        
        LeafNode(T word, BaseNode *father) : BaseNode(father){
            value = word;
        }
        
        virtual ~LeafNode() {}
        
        T& getValue() {
            return value;
        }
        
    private:
        T value;
    };
    
private:
    InnerNode root;
};

#endif /* Trie_hpp */
