/**
 * this is a backtracking solution.
 * my solution takes about 0.8s.
 */
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//#define PRINTALL

void print_sudoku(uint8_t mat[9][9]);
/**
 * check if a row of sudoku doesn't have conflict
 */
bool check_row(const uint8_t mat[9][9], const uint8_t row, const uint8_t ans) 
{
  int i;
  for (i = 0; i < 9; i++) {
    if (mat[row][i] == ans) {
      return false;
    }
  }
  return true;
}

/**
 * check if a col of sudoku doesn't have conflict
 */
bool check_col(const uint8_t mat[9][9], const uint8_t col, uint8_t ans) 
{
  int i;
  for (i = 0; i < 9; i++) {
    if (mat[i][col] == ans) {
      return false;
    }
  }
  return true;
}

/**
 * check if a 3x3 block of sudoku doesn't have conflict
 */
bool check_block(const uint8_t mat[9][9], const uint8_t row, const uint8_t col, uint8_t ans) 
{
  int i, j;
  uint8_t row_base, col_base;
  /*
  if (col < 3) {
    col_base = 0; 
  } else if (col < 6) {
    col_base = 3;
  } else {
    col_base = 6;
  }
  if (row < 3) {
    row_base = 0; 
  } else if (row < 6) {
    row_base = 3;
  } else {
    row_base = 6;
  }
  //*/
  col_base = (col/3)*3; // simplifies above 
  row_base = (row/3)*3;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (mat[row_base + i][col_base + j] == ans) {
        return false;
      }
    }
  }
  return true;
}

/**
 * find the coordinate of the next zero.
 */
bool find_next_zero(uint8_t mat[9][9], uint8_t row, uint8_t col, uint8_t* row_next, uint8_t* col_next) 
{
  uint8_t i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (mat[i][j] == 0) {
        *row_next = i;  
        *col_next = j;  
        return true; 
      }
    }
  }
  return false;
}


bool check_rules(uint8_t mat[9][9], uint8_t row, uint8_t col, uint8_t ans)
{
  //return check_row(mat, row, ans) && check_col(mat, col, ans) 
  //  && check_block(mat, row, col, ans);
  int i;
  for (i = 0; i < 9; i++) {
    if (mat[row][i] == ans || mat[i][col] == ans) { // optimize
      return false;
    }
  }
  return check_block(mat, row, col, ans);
}


/**
 * @return true if all rules are complied, else false.
 */
bool solve_sudoku(uint8_t mat[9][9], uint8_t row, uint8_t col) {
  uint8_t ans; 
  for (ans = 1; ans < 10; ans++) { // brute force
#ifdef PRINTALL // print all steps. NOTE: fun to watch
    printf("solving(%d,%d):\n\r", row, col);
    print_sudoku(mat);
#endif
    if (check_rules(mat, row, col, ans) == true) {
      mat[row][col] = ans;
      uint8_t row_next, col_next;
      if (find_next_zero(mat, row, col, &row_next, &col_next) == true) { 
        // recursive case
        if (solve_sudoku(mat, row_next, col_next) == false) {
          mat[row_next][col_next] = 0; // reset to zero since it fails at the next zero, need to be able to find the next zero again.
          continue; // 
        } else {
          return true;
        }
      } else {
        // base case: cannot find anymore zero
        return true;
      }
    } 
  }
  return false; // try all numbers but fail rules
}

void print_sudoku(uint8_t mat[9][9]) {
  int i, j;
  for (i = 0; i < 9; i++) {
    printf ("[");
    for (j = 0; j < 9; j++) {
      printf("%d", mat[i][j]); 
      if (j < 8) {
        if (j == 2 || j == 5) {
          printf("|");
        } else {
          printf(",");
        }
      }
    }
    printf("]\n");
  }
}

int main() {
  /* test
     uint8_t mat[9][9] = 
     { {0, 0, 3, 0, 2, 0, 6, 0, 0},
     {9, 0, 0, 3, 0, 5, 0, 0, 1},
     {0, 0, 1, 8, 0, 6, 4, 0, 0},
     {0, 0, 8, 1, 0, 2, 9, 0, 0},
     {7, 0, 0, 0, 0, 0, 0, 0, 8},
     {0, 0, 6, 7, 0, 8, 2, 0, 0},
     {0, 0, 2, 6, 0, 9, 5, 0, 0},
     {8, 0, 0, 2, 0, 3, 0, 0, 9},
     {0, 0, 5, 0, 1, 0, 3, 0, 0}};


     assert(check_row(mat, 0) == true);
     mat[0][0] = 3;
     assert(check_row(mat, 0) == false);
     mat[0][0] = 0;// reset
     assert(check_col(mat, 0) == true);
     mat[0][0] = 9;
     assert(check_col(mat, 0) == false);
     mat[0][0] = 0;// reset
     assert(check_block(mat, 0, 0) == true);
     mat[0][0] = 3;
     assert(check_block(mat, 0, 0) == false);
     mat[0][0] = 0;// reset

     printf("problem:\n\r");
     print_sudoku(mat);
     uint8_t row_next, col_next;
     find_next_zero(mat, 0, 0, &row_next, &col_next);
     solve_sudoku(mat, row_next, col_next);
     printf("solution:\n\r");
     print_sudoku(mat);
  //*/

  FILE *fp;
  char buf[20];
  size_t size = 20;
  fp = fopen("p0096_sudoku.txt", "r");
  int tmp, i, j;
  int sum = 0;
  
  while (EOF != fscanf(fp, "%s %d", &buf, &tmp)) { // get rid of "Grid XX"
    uint8_t mat[9][9];
    //printf("%s %d\n", buf, tmp);
    // place into 9 rows
    for (j = 0; j < 9; j++) {
      fscanf(fp, "%d", &tmp);
      //printf("%d\n", tmp);
      // put numbers in columns
      for (i = 8; i >= 0; i--) {
        mat[j][i] = tmp % 10;
        tmp /= 10;
      }
    }

    //printf("problem:\n");
    //print_sudoku(mat);
    uint8_t row_next, col_next;
    find_next_zero(mat, 0, 0, &row_next, &col_next);
    solve_sudoku(mat, row_next, col_next);
    //printf("solution:\n");
    //print_sudoku(mat);
    sum += 100*mat[0][0] + 10*mat[0][1] + mat[0][2];
  }
  printf("sum = %d\n", sum);

  fclose(fp);
  return 0;
}
