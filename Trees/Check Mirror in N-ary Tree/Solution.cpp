class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        unordered_map<int ,stack<int>> mp;
        
        //pushing all the children of a node in one stack
        for(int i=0;i<e*2;i+=2)
        {
            mp[A[i]].push(A[i+1]);
        }
        
        //now due to the properties of stack,the children are reversed
        
        for(int i=0;i<e*2;i+=2)
        {
           if(mp[B[i]].top()!=B[i+1])
               return 0;
           
           mp[B[i]].pop();
        }
        
        return 1;
    }
};
