class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        stack<int> st;
        
        
        //step -1
        for(int i=0;i<n;i++){  //push all person in the stack
            st.push(i);
        }
        
        
        // step-2
        //run discard method to find possible celibrity
        while(st.size()!=1){
            
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            
            if(M[a][b]){       //if a knows b
                //a is not celibrity but b might be  so again push b in stack 
                st.push(b);
            }else if(M[b][a]){     //if b knows a
                st.push(a);  //b is not celibrity but a might be so again push a in stack 
            }
        }
        
        
        
        // step-3  check the single person in stack is actually celibrity
        int mightbecelibrity=st.top();
        st.pop();
        
        // verify 1 all row must be 0
        for(int i=0;i<n;i++){
            if(M[mightbecelibrity][i]!=0){
                return -1;
            }
        }
        
        // verify 2,column all column must be 1 except the diagonal;
        for(int i=0;i<n;i++){
            if(i==mightbecelibrity){  //skip the diagonal element
                continue;
            }
            if(M[i][mightbecelibrity]!=1){
                return -1;
            }
        }
        return mightbecelibrity;
    }
};