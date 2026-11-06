/* fuzzy: 80.3 */
struct Dma_00161D50 {
    unsigned short m0;
};

extern "C" unsigned int* func_00164D20(unsigned int* p);

extern "C" void func_00161D50(Dma_00161D50* d, int* out)
{
    unsigned int* end = (unsigned int*)((char*)d + (d->m0 * 16 + 16));
    unsigned int* p = (unsigned int*)((char*)d + 8);
    do {
        if ((*p & 0x7F000001) == 0x05000001) {
            p = func_00164D20(p);
            unsigned char* c = (unsigned char*)p;
            int n = ((unsigned char)(c[2] - 1) + 1) * 4;
            if ((c[3] & 0x7F) == 0x6C) {
                for (int i = 0; i < n; i++) {
                    *out++ = ((int*)(c + 4))[i];
                }
            } else {
                for (int i = 0; i < n; i++) {
                    *out++ = ((short*)(c + 4))[i];
                }
            }
        }
        p = func_00164D20(p);
    } while (p < end);
}
