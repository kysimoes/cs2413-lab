// Helper function to "sink" an island (turn '1's to '0's)
void sinkIsland(char** grid, int rows, int cols, int i, int j) {
    // If we're out of bounds or hit water, stop
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
        return;
    }
    
    // Sink this land ('1' → '0')
    grid[i][j] = '0';
    
    // Sink all connected land (up, down, left, right)
    sinkIsland(grid, rows, cols, i + 1, j); // Down
    sinkIsland(grid, rows, cols, i - 1, j); // Up
    sinkIsland(grid, rows, cols, i, j + 1); // Right
    sinkIsland(grid, rows, cols, i, j - 1); // Left
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0; // Empty grid = no islands
    
    int cols = gridColSize[0];
    int islandCount = 0;
    
    for (int i = 0; i < gridSize; i++) {       // Check each row
        for (int j = 0; j < cols; j++) {      // Check each column
            if (grid[i][j] == '1') {          // Found land!
                islandCount++;                // New island!
                sinkIsland(grid, gridSize, cols, i, j); // Sink it
            }
        }
    }
    
    return islandCount;
}
