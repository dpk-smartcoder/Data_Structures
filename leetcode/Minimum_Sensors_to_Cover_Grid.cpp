class Solution {
public:
    int minSensors(int n, int m, int k) {
        int size = 2*k+1;
        int rowCov = (n+size-1) / size;
        int colCov = (m+size-1) / size;

        return (rowCov * colCov);
    }
};