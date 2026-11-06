extern "C" unsigned int func_00142F08(int* counts)
{
    int best = counts[0];
    unsigned int bi = 0;
    for (unsigned int i = 0; i < 256; i++) {
        int v = counts[i];
        if (v == 0) {
            return i;
        }
        if (v < best) {
            best = v;
            bi = i;
        }
    }
    return bi;
}
