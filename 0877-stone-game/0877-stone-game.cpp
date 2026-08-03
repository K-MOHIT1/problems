class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int a=0;
        int b=0;

        int i=0;
        int j=piles.size()-1;
        bool flag=true;

        while(i<=j){
            
            int x=max(piles[i],piles[j]);

            (flag)?a+=x:b+=x;

            flag!=flag;

            if(piles[i]>piles[j]) i++;
            else j--;

            
        }

        return (a>b);
    }
};