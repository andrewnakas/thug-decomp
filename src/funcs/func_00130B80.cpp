extern char D_003BEAE0[];

struct Entry_00130B80 {
    int m0[6];
    int m_18;
};

extern "C" Entry_00130B80* func_00130FE8(void* table, int* key, int n);

int Lookup_00130B80(int key)
{
    Entry_00130B80* e = func_00130FE8(D_003BEAE0, &key, 1);
    if (e)
        return e->m_18;
    return 0;
}
