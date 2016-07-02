#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 15;

int main()
{
    int triangle[][SIZE] = {
        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20,  4, 82, 47, 65},
        {19,  1, 23, 75,  3, 34},
        {88,  2, 77, 73,  7, 63, 67},
        {99, 65,  4, 28,  6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
    };

    int sum = 0;
    vector<int> sumArr;
    // loop
    //   - sum
    //   - nth and (n+1)th element in the next row

    for(int a = 0; a < 1; a++){
    for(int b = a; b < a + 2; b++){
    for(int c = b; c < b + 2; c++){
    for(int d = c; d < c + 2; d++){
    for(int e = d; e < d + 2; e++){
    for(int f = e; f < e + 2; f++){
    for(int g = f; g < f + 2; g++){
    for(int h = g; h < g + 2; h++){
    for(int i = h; i < h + 2; i++){
    for(int j = i; j < i + 2; j++){
    for(int k = j; k < j + 2; k++){
    for(int l = k; l < k + 2; l++){
    for(int m = l; m < l + 2; m++){
    for(int n = m; n < m + 2; n++){
    for(int o = n; o < n + 2; o++){
        sum = triangle[0][a];
        sum += triangle[1][b];
        sum += triangle[2][c];
        sum += triangle[3][d];
        sum += triangle[4][e];
        sum += triangle[5][f];
        sum += triangle[6][g];
        sum += triangle[7][h];
        sum += triangle[8][i];
        sum += triangle[9][j];
        sum += triangle[10][k];
        sum += triangle[11][l];
        sum += triangle[12][m];
        sum += triangle[13][n];
        sum += triangle[14][o];
        sumArr.push_back(sum);
    }}}}}}}}}}}}}}}

    int max = sumArr[0];
    for(int i = 0; i < sumArr.size(); i++){
        if (sumArr[i] > max){
            max = sumArr[i];
        }
    }
    cout << "sumArr.size() = " << sumArr.size() << endl;
    cout << "max is " << max << endl;

    return 0;
}
