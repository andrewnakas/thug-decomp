extern short D_003F5988[0x4000];
extern char D_0038FB58[];

struct Array_00229528 {
    char pad[0xC];
    unsigned int m_size;
};

extern "C" Array_00229528* func_001E55B8(unsigned int key, int a);
extern "C" void* func_001E9378(Array_00229528* a, unsigned int i);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);

void func_00229528()
{
    for (int i = 0; i < 0x4000; i++)
        D_003F5988[i] = -1;
    Array_00229528* arr = func_001E55B8(0xC472ECC5, 0);
    for (unsigned int i = 0; i < arr->m_size; i++) {
        void* e = func_001E9378(arr, i);
        unsigned int key = 0;
        if (func_001E84E8(e, D_0038FB58, &key, 0)) {
            unsigned int h = (unsigned short)key & 0x3FFF;
            while (D_003F5988[h] != -1)
                h = (h + 1) & 0x3FFF;
            D_003F5988[h] = i;
        }
    }
}
