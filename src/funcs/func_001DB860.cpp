struct Arr_001DB860 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern "C" Arr_001DB860* func_001E55B8(unsigned int, int);
extern "C" void* func_001E9378(Arr_001DB860*, unsigned int);
extern "C" int func_001E8398(void*, unsigned int, unsigned int*, int);
extern "C" int func_001E8180(void*, unsigned int, void**, int);
extern "C" int func_001DB060(unsigned int);
extern "C" void func_001E6A00(void*, void*);
extern "C" void func_001E6A50(void*, void*);

int func_001DB860(int key, void* out)
{
    unsigned int id;
    void* a = 0;
    void* b = 0;
    void* c = 0;
    void* d = 0;
    unsigned int i = 0;
    Arr_001DB860* arr = func_001E55B8(0x1C2C4218, 0);
    for (; !(a && b) && i < arr->mC; i++) {
        void* e = func_001E9378(arr, i);
        func_001E8398(e, 0x3789AC4E, &id, 1);
        int r = func_001DB060(id);
        if (r == 0)
            func_001E8180(e, 0x5C969C50, &a, 0);
        else if (r == key)
            func_001E8180(e, 0x5C969C50, &b, 0);
        if (a && b)
            break;
    }
    arr = func_001E55B8(0x96218951, 0);
    if (arr) {
        for (i = 0; i < arr->mC; i++) {
            void* e = func_001E9378(arr, i);
            func_001E8398(e, 0x3789AC4E, &id, 1);
            int r = func_001DB060(id);
            if (r == 0)
                func_001E8180(e, 0x5C969C50, &c, 0);
            else if (r == key)
                func_001E8180(e, 0x5C969C50, &d, 0);
            if (c && d)
                break;
        }
    }
    func_001E6A00(out, a);
    if (c)
        func_001E6A50(out, c);
    if (b)
        func_001E6A50(out, b);
    if (d)
        func_001E6A50(out, d);
    return 1;
}
