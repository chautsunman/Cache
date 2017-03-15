
Put your answers to questions 1 and 3 in this file
along with the table produced for question 4.

All answers are to be in plain text ASCII.


1a.
Address:
Bit: 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
     CT CT CT CT CT CT CT CT CT CI CI CI CO CO CO

1b.
Operation  Address  Cache Set  Tag  Hit?  Value
  Read     0x02F8     Set 7    00B   F
  Read     0x35DD     Set 3    0D7   T    E0D95748F728EB65
  Read     0x7A2F     Set 5    1E8   F
  Read     0x2055     Set 2    080   F


3.
The 2D array is stored in a row-major order 64*64*4=16384 bytes sequence of bytes in the memory.
Each "row" is 64*4=256 bytes long.
The cache size is 128*16=2048 bytes.
Therefore, the array can be considered as 16384/2048=8 repeated sections
that map to the whole cache
Each cache block can store 16/4=4 integers.

3a.
The miss rate is 0.25.
sumA does a row-major order access to sum up the elements.
sumA accesses the data from the first byte to the last byte sequentially.
For the first 512 accesses (2048 bytes), there are cache misses every 4 bytes,
all map to different cache lines, but miss because the cache is empty,
and just the first of 4 accesses is a miss, as each cache block can store 4 integers,
so the subsequent 3 accesses can access the data from the cache.
For the remaining accesses, with 2048 bytes as a cycle,
there are also cache misses every 4 bytes, with the first of 4 accesses as a miss,
as the cache line is not empty, storing the data block from 2048 bytes before.
Therefore, there is 1 miss for each 4 accesses, so the miss rate is 0.25.

3b.
The miss rate is 1.
sumB does a column-major order access to sum up the elements.
The access pattern jumps around the data 256 bytes apart back and forth.
Since 256=128*2, 2 bytes of 256 bytes apart with map to the same cache line.
With a direct-mapped cache, this access pattern results in misses for each pair of accesses.
Starting with an empty cache, all accesses will be misses.
After the cache is filled, all accesses will also be misses.
Therefore, the miss rate is 1.

3c.
The miss rate is 0.5.
sumC, similar to sumB, also does a column-major-like order access to sum up the elements,
with 2 rows and 2 columns jump for each iteration.
This access pattern results in misses for each iteration.
However, for each iteration, the program sums up 4 elements at a time,
2 pairs of elements, 1 pair of the same row, 1 pair of the same column.
Since each cache line can store 4 integers, the second access of each pair can
access the data from the cache brought in for the first miss access.
Therefore, this reduces the miss rate by half, so the miss rate is 0.5.

3d.
The miss rate is 0.25.
sumB does a column-major order to sum up the elements.
With N=68, the access pattern jumps around the data 68*4=272 bytes apart back and forth.
However, unlike 3b, 272 is not a multiple of 128, so jumping around will not
update the cache whenever jumping forward, resulting in misses when jumping back.
Therefore, this is like 3a, but a sequential access mapping to non-sequential cache lines.
Jumping forward, then back, will not remove the old cache line, as the forward
one maps to a different cache line.
Since each cache line can store 4 integers, there is 1 miss for each 4 accesses,
so the miss rate is 0.25.


4.
Improvement 1
 - initialize the world in row-major order (newWorld[i][j])
 - this improves spatial locality, as 2D arrays in C are stored in row-major order,
   and this access pattern accesses the array sequentially
 - Measurement 1:
 - Measurement 2:
 - Measurement 3:
 - Measurement 4:
 - Measurement 5:
 - Measurement 6:
 - Measurement 7:
 - Measurement 8:
 - Measurement 9:
 - Measurement 10:
 - Average:

Improvement 2
 - access and write the world in row-major order (oldWorld[row][col], newWorld[i][j])
 - the old code accesses and writes the world in column-major order, despite
   the naming convention for using i/row as row index and j/col as column index
 - this improves spatial locality, as 2D arrays in C are stored in row-major order,
   and this access pattern accesses the array sequentially
 - Measurement 1:
 - Measurement 2:
 - Measurement 3:
 - Measurement 4:
 - Measurement 5:
 - Measurement 6:
 - Measurement 7:
 - Measurement 8:
 - Measurement 9:
 - Measurement 10:
 - Average:

Results
Improvement  Average time  Performance improvement ratio
Base
1
2
