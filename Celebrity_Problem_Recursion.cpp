
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    
    bool knows(vector<vector<int> >& M, int i, int j){

        if(M[i][j]==1){
            return true;
        }
        
        return false;
    }
    
    int Check_Celeb(vector<vector<int> >& M, int n,int size){
        if(n==1){
            int temp=0;
            for(int i=0;i<size;i++){
                if(M[size-n][i]==1){
                    temp=1;
                    break;
                }
            }

            if(temp==1){
                return -1;
            }

            else
            return (size-n);
        }
        
        int current_Celeb = Check_Celeb(M,n-1,size);
        int current_Cand = size-n;

        if(current_Celeb!=-1 ){
            if(knows(M,current_Cand,current_Celeb) && !knows(M,current_Celeb,current_Cand)){
                current_Celeb = current_Celeb;
            }
            
            else{
                current_Celeb=-1;
            }
        }

        else{
            int temp=0;
            for(int i=0;i<size;i++){
                if(M[size-n][i]==1){
                    temp=1;
                    break;
                }
            }

            if(temp==1){
                return -1;
            }

            else
            current_Celeb=current_Cand;
        }
    
        return current_Celeb ;
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int result=-1;
        result=Check_Celeb(M,n,n);
        if(result==0){
            int temp=0;
            for(int i=1;i<n;i++){
                if(M[i][0]!=1){
                    temp=1;
                }
            }

            if(temp==1){
                result = -1;
            }
        }
        
        return result;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
