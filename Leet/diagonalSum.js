/**
 * @param {number[][]} mat
 * @return {number}
 */
var diagonalSum = function(mat) {
    let center = Math.trunc(mat.length/2);
    let row = 0, col = 0;
    let sum = 0;

    while(row < mat.length) 
    {
        sum += (row === center && col === center && mat.length % 2 !== 0)? 0 :mat[row][col];
        row++;
        col++;
    }

    row = 0;
    col--;

    while(row < mat.length)
    {
        sum += (row === center && col === center && mat.length % 2 !== 0)? 0 :mat[row][col];
        row++;
        col--;
    }

    if(mat.length % 2 === 0)
    {
        return sum
    }
    else {
        return sum + mat[center][center];
    }
};
