class Solution {
public:
    vector<int> findAnagrams(string s, string p) {


        vector<int> scount(26,0);
        vector<int> pcount(26,0);
        vector<int> result;

        int n = s.length();
        int k = p.length();

        if(k>n){
            return result;
        }

        for( char ch : p){
            pcount[ch - 'a']++;
        }

        for(int i = 0; i<k ; i++){
            scount[s[i] - 'a']++;

           
        }

         if(pcount ==scount){
                result.push_back(0);
            }
           

        
        for( int i = k; i<n ; i++){
            scount[s[i] - 'a']++;
            scount[s[i-k] - 'a']--;

             if(pcount ==scount){
                result.push_back(i-k+1);
            }
        }
        return result;
    }
};
