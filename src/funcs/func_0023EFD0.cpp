struct Array_0023EFD0 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

extern "C" void* func_0023D130(void* self, unsigned int id);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_0023EFD0** out, int assert_);
extern "C" void* func_00122CF8(int size);
extern "C" Array_0023EFD0* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(Array_0023EFD0* self, int size, int type);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_00247850(Array_0023EFD0* list, Array_0023EFD0* a, Array_0023EFD0* b, int index);
extern "C" void func_00247AF8(int x, int y, Array_0023EFD0* a, Array_0023EFD0* b, int z);
extern "C" void func_001E6518(Array_0023EFD0* self);
extern "C" void func_001E8DE8(Array_0023EFD0* self, int flags);

bool func_0023EFD0(void* self, unsigned int id, int x, int y, int z)
{
    void* params = func_0023D130(self, id);
    Array_0023EFD0* list;
    func_001E8248(params, 0x79704516, &list, 1);
    Array_0023EFD0* a = func_001E8DD0(func_00122CF8(0x10));
    Array_0023EFD0* b = func_001E8DD0(func_00122CF8(0x10));
    int size = list->m_size;
    func_001E8E98(a, size, 3);
    func_001E8E98(b, size, 3);
    int index = -1;
    if (func_001E8708(params, 0x8E6014F6)) {
        func_001E7DE8(params, 0x5B077CE1, &index, 1);
    }
    if (!func_00247850(list, a, b, index)) {
        func_001E6518(a);
        func_001E6518(b);
        if (a) {
            func_001E8DE8(a, 3);
        }
        if (b) {
            func_001E8DE8(b, 3);
        }
        return false;
    }
    func_00247AF8(x, y, a, b, z);
    func_001E6518(a);
    func_001E6518(b);
    if (a) {
        func_001E8DE8(a, 3);
    }
    if (b) {
        func_001E8DE8(b, 3);
    }
    return true;
}
