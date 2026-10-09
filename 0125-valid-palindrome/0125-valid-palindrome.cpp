class Solution { 
public: 
    bool isPalindrome(string s) { 
        int i = 0; 
        int n = s.length(); 
        int j = n - 1; 

        // FIXED: Boundary check comes first to prevent segmentation faults
        while (i < n && !isalnum(s[i])) { 
            i++; 
        } 

        // FIXED: Boundary check comes first
        while (j >= 0 && !isalnum(s[j])) { 
            j--; 
        } 

        while (i < j) { 
            if (tolower(s[i]) == tolower(s[j])) { 
                i++; 
                j--; 
            } else { 
                return false; 
            } 

            // FIXED: Boundary check comes first
            while (i < j && !isalnum(s[i])) { 
                i++; 
            } 

            // FIXED: Boundary check comes first
            while (i < j && !isalnum(s[j])) { 
                j--; 
            } 
        } 

        return true; 
    } 
};
