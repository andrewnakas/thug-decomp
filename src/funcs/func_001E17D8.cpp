unsigned int Swap_001E17D8(unsigned int x)
{
    return (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
}
