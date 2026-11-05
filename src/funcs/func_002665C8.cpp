extern void* D_0038FC78;
extern "C" void* func_0022E048(void* p);
extern "C" bool func_00265778(void* g, unsigned int id);

struct List_002665C8 {
    int m0;
    unsigned int m4[0x200];
    unsigned int m804;
    unsigned int Collect(unsigned int* out, unsigned int size);
};

unsigned int List_002665C8::Collect(unsigned int* out, unsigned int size)
{
    unsigned int n = m804;
    if (n > 0x200) n = 0x200;
    void* g = func_0022E048(D_0038FC78);
    unsigned int bytes = 0;
    for (unsigned int i = 0; i < n; i++) {
        if (func_00265778(g, m4[i])) {
            *out++ = m4[i];
            bytes += 4;
        }
        if (bytes >= size) break;
    }
    return bytes;
}
