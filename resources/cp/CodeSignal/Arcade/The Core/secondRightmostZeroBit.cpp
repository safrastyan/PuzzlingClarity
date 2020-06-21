int secondRightmostZeroBit(int n) {
  return (~n) & ( (n | (n + 1 )) + 1);
}
