class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     int m = matrix.size();
        int n = matrix[0].size();

        bool row = false, col = false;

        // check first row and column
        for(int i = 0; i < m; i++)
            if(matrix[i][0] == 0) col = true;

        for(int j = 0; j < n; j++)
            if(matrix[0][j] == 0) row = true;


        // mark rows and columns
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


        // make zero using markers
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }


        // first row
        if(row){
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }


        // first column
        if(col){
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }  
    
};