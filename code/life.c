#include <stdio.h>
#include "life.h"

// You are only allowed to change the contents of this file with respect
// to improving the performance of this program



// If you need to initialize some data structures for your implementation
// of life then make changes to the following function, otherwise
// do not change this function.

void initLife() {
}



// When completed this file will contain several versions of the life() function and
// conditional compilation will be used to determine which version runs.  Each
// version will be surrounded with  an ifdef, undef, and endif as illustrated
// immediately below this comment block. To select the version of the life function
// to use, put the #define USE USE immediately infront of the version of the life()
// to compile.  Your version of life() must produce a correct result.

// You are required to document the changes you make in the README.txt file. For each entry
// in the README.txt file there is to be a version of the matching  life() function here such
// that the markers can see, and run if needed,  the actual code that you used
// to produce your results for the logged change to the life function.


#ifdef USE
int life(long oldWorld[N][N], long newWorld[N][N]) {
  return 0;
}
#undef USE
#endif






// For each version of life you are testing duplicate the code between the
// ifdef and endif and make your changes. To use the new version, move the the #define
// just about this comment to be just in front of the ifdef for the new version.

#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }

  int col, row;
  int q = -1;


  // Count the cells to the top left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Count the cells immediately above
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the top right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

 // Count the cells to the immediate left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
       newWorld[j][i] += oldWorld[j][col];
    }
  }

  // Count the cells to the immediate right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      newWorld[j][i] += oldWorld[j][col];
    }
  }

// Count the cells to the bottom left
  for (i = 0; i < N; i++) {
    col = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Count the cells immediately below
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the bottom right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] = checkHealth(newWorld[j][i], oldWorld[j][i]);
      alive += newWorld[j][i] ? 1:0;
    }

  return alive;
}
#undef USE
#endif


#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 1
      // initialize the world in row-major order
      newWorld[i][j] =  0;
    }

  int col, row;
  int q = -1;


  // Count the cells to the top left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Count the cells immediately above
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the top right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

 // Count the cells to the immediate left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
       newWorld[j][i] += oldWorld[j][col];
    }
  }

  // Count the cells to the immediate right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      newWorld[j][i] += oldWorld[j][col];
    }
  }

// Count the cells to the bottom left
  for (i = 0; i < N; i++) {
    col = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Count the cells immediately below
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the bottom right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] = checkHealth(newWorld[j][i], oldWorld[j][i]);
      alive += newWorld[j][i] ? 1:0;
    }

  return alive;
}
#undef USE
#endif


#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 1
      // initialize the world in row-major order
      newWorld[i][j] =  0;
    }

  int col, row;
  int q = -1;


  // Count the cells to the top left
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j - 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Count the cells immediately above
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
        // Improvement 2
        // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][j];
    }
  }

  // Count the cells to the top right
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Count the cells to the immediate left
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      col = (j - 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[i][col];
    }
  }

  // Count the cells to the immediate right
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      col = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[i][col];
    }
  }

  // Count the cells to the bottom left
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j - 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Count the cells immediately below
  for (i = 0; i < N; i++) {
    row = (i + 1 + N ) % N;
    for (j = 0; j < N; j++) {
        // Improvement 2
        // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][j];
    }
      }

  // Count the cells to the bottom right
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] = checkHealth(newWorld[j][i], oldWorld[j][i]);
      alive += newWorld[j][i] ? 1:0;
    }

  return alive;
}
#undef USE
#endif


#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 1
      // initialize the world in row-major order
      newWorld[i][j] =  0;
    }

  int col, row;
  int q = -1;


  // Count the cells to the top left
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j - 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Count the cells immediately above
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
        // Improvement 2
        // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][j];
    }
  }

  // Count the cells to the top right
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Count the cells to the immediate left
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      col = (j - 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[i][col];
    }
  }

  // Count the cells to the immediate right
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      col = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[i][col];
    }
  }

  // Count the cells to the bottom left
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j - 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Count the cells immediately below
  for (i = 0; i < N; i++) {
    row = (i + 1 + N ) % N;
    for (j = 0; j < N; j++) {
        // Improvement 2
        // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][j];
    }
      }

  // Count the cells to the bottom right
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      col = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      newWorld[i][j] += oldWorld[row][col];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 3
      // compute the world in row-major order
      newWorld[i][j] = checkHealth(newWorld[i][j], oldWorld[i][j]);
      alive += newWorld[i][j] ? 1 : 0;
    }

  return alive;
}
#undef USE
#endif


#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 1
      // initialize the world in row-major order
      newWorld[i][j] =  0;
    }

  int colLeft, colRight, row;
  int q = -1;


  // Count the cells immediately above, to the top left and to the top right
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      colLeft = (j - 1 + N) % N;
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      newWorld[i][j] += oldWorld[row][j] + oldWorld[row][colLeft] + oldWorld[row][colRight];
    }
  }

  // Count the cells to the immediate left and to the immediate right
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      colLeft = (j - 1 + N) % N;
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      newWorld[i][j] += oldWorld[i][colLeft] + oldWorld[i][colRight];
    }
  }

  // Count the cells immediately below, to the bottom left and to the bottom right
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      colLeft = (j - 1 + N) % N;
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      newWorld[i][j] += oldWorld[row][j] + oldWorld[row][colLeft] + oldWorld[row][colRight];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 3
      // compute the world in row-major order
      newWorld[i][j] = checkHealth(newWorld[i][j], oldWorld[i][j]);
      alive += newWorld[i][j] ? 1 : 0;
    }

  return alive;
}
#undef USE
#endif


#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  int colLeft, colRight, row;
  int q = -1;


  // Count the cells immediately above, to the top left and to the top right
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      colLeft = (j - 1 + N) % N;
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      // Improvement 5
      // initialize the world at the same time of computing the first set of values
      newWorld[i][j] = oldWorld[row][j] + oldWorld[row][colLeft] + oldWorld[row][colRight];
    }
  }

  // Count the cells to the immediate left and to the immediate right
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      colLeft = (j - 1 + N) % N;
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      newWorld[i][j] += oldWorld[i][colLeft] + oldWorld[i][colRight];
    }
  }

  // Count the cells immediately below, to the bottom left and to the bottom right
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      colLeft = (j - 1 + N) % N;
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      newWorld[i][j] += oldWorld[row][j] + oldWorld[row][colLeft] + oldWorld[row][colRight];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 3
      // compute the world in row-major order
      newWorld[i][j] = checkHealth(newWorld[i][j], oldWorld[i][j]);
      alive += newWorld[i][j] ? 1 : 0;
    }

  return alive;
}
#undef USE
#endif


#define USE

#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;

  int colLeft, colRight, row;
  int q = -1;


  // Count the cells immediately above, to the top left and to the top right
  for (i = 0; i < N; i++) {
    row = (i - 1 + N) % N;
    int lastLeft;
    int lastMiddle = oldWorld[row][N-1];
    int lastRight = oldWorld[row][0];
    for (j = 0; j < N; j++) {
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      // Improvement 5
      // initialize the world at the same time of computing the first set of values
      // Improvement 6
      // store the elements read for the next iteration
      int right = oldWorld[row][colRight];
      newWorld[i][j] = lastMiddle + lastRight + right;
      lastLeft = lastMiddle;
      lastMiddle = lastRight;
      lastRight = right;
    }
  }

  // Count the cells to the immediate left and to the immediate right
  for (i = 0; i < N; i++) {
    int lastMiddle = oldWorld[i][N-1];
    int lastRight = oldWorld[i][0];
    for (j = 0; j < N; j++) {
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      // Improvement 6
      // store the elements read for the next iteration
      int right = oldWorld[i][colRight];
      newWorld[i][j] += lastMiddle + right;
      lastMiddle = lastRight;
      lastRight = right;
    }
  }

  // Count the cells immediately below, to the bottom left and to the bottom right
  for (i = 0; i < N; i++) {
    row = (i + 1 + N) % N;
    int lastLeft;
    int lastMiddle = oldWorld[row][N-1];
    int lastRight = oldWorld[row][0];
    for (j = 0; j < N; j++) {
      colRight = (j + 1 + N) % N;
      // Improvement 2
      // access and write the world in row-major order
      // Improvement 4
      // access the same row at the same time
      // Improvement 6
      // store the elements read for the next iteration
      int right = oldWorld[row][colRight];
      newWorld[i][j] += lastMiddle + lastRight + right;
      lastLeft = lastMiddle;
      lastMiddle = lastRight;
      lastRight = right;
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      // Improvement 3
      // compute the world in row-major order
      newWorld[i][j] = checkHealth(newWorld[i][j], oldWorld[i][j]);
      alive += newWorld[i][j] ? 1 : 0;
    }

  return alive;
}
#undef USE
#endif
