// 3) The Grid

// You are in an (n x n) grid of numbers. You are initially at the top-left cell. To navigate through the grid, you need to follow some instructions. The number in your current cell determines the next step you will take. Let x be the remainder when this number is divided by 4.

// If x = 0, go up.
// If x = 1, go right.
// If x = 2, go down.
// If x = 3, go left.

// You are given the number of steps you have to take. Find the number in the cell you land in after taking the required number of steps. If you step out of the grid during the process, output -1 instead.

// Value of n: 7
// Required number of steps: 5
// 53 89 94 63 47 67 18
// 69 69 50 38 35 25 83
// 19 80 43 78 84 81 11
// 50 28 47 64 70 71 53
// 63 52 82 70 28 37 31
// 77 67 80 40 58 28 96
// 55 25 53 64 73 20 78
// 80

// (You go right, right, down, down, and left in this case.)
