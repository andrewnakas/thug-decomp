struct Array_0020CF98 {
    char pad[0xC];
    unsigned int m_size;
    unsigned int GetSize() { return m_size; }
};

struct Obj_0020CF98 {
    char pad[0xBC];
    int mBC;
};

extern "C" bool func_001E8398(void*, unsigned int, unsigned int*, int);
extern "C" bool func_001E8248(void*, unsigned int, Array_0020CF98**, int);
extern "C" bool func_001E8180(void*, unsigned int, void**, int);
extern "C" void* func_001190D0(int);
extern "C" void* func_001E6978(void*);
extern "C" void func_001E6B30(void*);
extern "C" void* func_001E9378(Array_0020CF98*, int);
extern "C" void func_001E6A50(void*, void*);
extern "C" void func_001F0210(unsigned int, void*, int, int, int);
extern "C" void func_001E6AE8(void*, int);

bool Cmd_0020CF98(void* params, Obj_0020CF98* obj)
{
    unsigned int name = 0;
    func_001E8398(params, 0x62BA3F6A, &name, 0);
    Array_0020CF98* arr = 0;
    func_001E8248(params, 0, &arr, 0);
    void* st = 0;
    func_001E8180(params, 0x7031F10C, &st, 0);
    if (st) {
        void* s = func_001E6978(func_001190D0(8));
        for (unsigned int i = 0; i < arr->GetSize(); i++) {
            func_001E6B30(s);
            void* v = func_001E9378(arr, i);
            if (v)
                func_001E6A50(s, v);
            if (st)
                func_001E6A50(s, st);
            func_001F0210(name, s, obj->mBC, 0, 0);
        }
        if (s)
            func_001E6AE8(s, 3);
    } else {
        for (unsigned int i = 0; i < arr->GetSize(); i++)
            func_001F0210(name, func_001E9378(arr, i), obj->mBC, 0, 0);
    }
    return true;
}
