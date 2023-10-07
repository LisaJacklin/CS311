//hsscount.hpp
//Lisa Jacklin
//10/2/2023

#include "hsscount.hpp" //need to make sure that .hpp is included!
//now, all of hsscout has been defined here in the source file.

// Helper function for recursive backtracking
int hssCount_recurse(int dim_x, int dim_y, int hole_x, int hole_y,
    int start_x, int start_y, int finish_x, int finish_y,
    int current_x, int current_y, int visited) {
    // Base case: reached the finish square
    if (current_x == finish_x && current_y == finish_y) {
        // If all squares are visited, this is a valid scuttle
        if (visited == dim_x * dim_y) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int count = 0;

    // Define possible moves
    int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

    for (int i = 0; i < 8; ++i) {
        int next_x = current_x + dx[i];
        int next_y = current_y + dy[i];

        // Check if the next move is within bounds and not visited
        if (next_x >= 0 && next_x < dim_x &&
            next_y >= 0 && next_y < dim_y &&
            !(visited & (1 << (next_x * dim_y + next_y))) &&
            !(next_x == hole_x && next_y == hole_y)) {
            int new_visited = visited | (1 << (next_x * dim_y + next_y));
            count += hssCount_recurse(dim_x, dim_y, hole_x, hole_y,
                start_x, start_y, finish_x, finish_y,
                next_x, next_y, new_visited);
        }
    }

    return count;
}

// Public function to count holey spider scuttles
int hssCount(int dim_x, int dim_y, int hole_x, int hole_y,
    int start_x, int start_y, int finish_x, int finish_y) {
    // Mark the start square as visited
    int visited = 1 << (start_x * dim_y + start_y);
    return hssCount_recurse(dim_x, dim_y, hole_x, hole_y,
        start_x, start_y, finish_x, finish_y,
        start_x, start_y, visited);
}
