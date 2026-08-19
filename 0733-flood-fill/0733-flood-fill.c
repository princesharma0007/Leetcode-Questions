void dfs(int** image, int rows, int cols, int r, int c, int original, int color) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (image[r][c] != original)
        return;

    image[r][c] = color;

    dfs(image, rows, cols, r - 1, c, original, color);
    dfs(image, rows, cols, r + 1, c, original, color);
    dfs(image, rows, cols, r, c - 1, original, color);
    dfs(image, rows, cols, r, c + 1, original, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int original = image[sr][sc];

    *returnSize = imageSize;

    *returnColumnSizes = malloc(imageSize * sizeof(int));

    for (int i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[i];

    if (original == color)
        return image;

    dfs(image, imageSize, imageColSize[0], sr, sc, original, color);

    return image;
}