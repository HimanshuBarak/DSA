<h2>LRU Cache</h2>
<h3>Medium</h3><hr>
<div><p>
  Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 
</p>


[Problem Link](https://leetcode.com/problems/lru-cache/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
<strong>Output:</strong> [null, null, null, 1, null, -1, null, -1, 3, 4]
<strong>Explanation:</strong> LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class LRUCache {
public:
   
    //creating a doubly linked list
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int k,int v)
        {
            key=k;
            val=v;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
     map<int,node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next= tail;
        tail->prev = head;
    }
    void addnode(node* newnode)
    {  //node next to head is the most recently used key
        node* temp = head->next;
        newnode->next=temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev=newnode;
    }
    
    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node* res = mp[key];
            int ans = res->val;
            mp.erase(key);
            deletenode(res); //remove from wherever it is
            addnode(res); //add in front of head
            mp[key] = head->next; //store the new address
            return ans;
        }else{
            return -1;
        }
        
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
           node * existingnode = mp[key];
            mp.erase(key); 
            deletenode(existingnode);
        }
        //if size is maxcapacity
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next; //store value in hashma[]
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
  ```
</div>
