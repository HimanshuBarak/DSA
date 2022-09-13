<h2></h2>

  <h2> Solution </h2>
  
  ``` c++ 
  
    // Time Complexity of everything O(N)
     struct Node {
        Node* links[26];
        int cntPrefix=0;
        int cntEndsWith=0;
    
        bool containsKey(char ch)
          {
              return links[ch-'a']!=NULL;
          }

        void put(char ch,Node* node){
              links[ch-'a']=node;
          }
          Node* get(char ch)
          {
              return links[ch-'a'];
          }
          //for checking if the word is completed or not
        void increaseWordCnt()
        {
            cntEndsWith++;
        }
        void increasePrefix(){
            cntPrefix++;
        }
        void deleteWord(){
            cntEndsWith--;
        }
        void reducePrefixCnt(){
            cntPrefix--;
        }
    };
class Trie{
    Node* root;
    public:

    Trie(){
        root= new Node();
    }

    void insert(string &word){
        Node* node =root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node =node->get(word[i]);
            node->increasePrefix();
           
        }
        node->increaseWordCnt();
    }

    int countWordsEqualTo(string &word){
         Node* node =root;
        
        for(int i=0;i<word.length();i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cntEndsWith;
    }

    int countWordsStartingWith(string &word){
         Node* node =root;
        for(int i=0;i<word.length();i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void erase(string &word){
       Node* node =root;
       for(int i=0;i<word.length();i++){ 
         if (node -> containsKey(word[i])){
            node = node -> get(word[i]);
            node -> reducePrefixCnt();
          }else{
            return;
           }
       }
       node->deleteWord();
    }
};

  ```
</div>
