int seatsInTheater(int nCols, int nRows, int col, int row) 
{
    return (nRows - row) * (nCols - col + 1);
}
