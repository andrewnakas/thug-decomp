struct Data_002BB700 {
    int m0;
    unsigned int m4;
};

struct Item_002BB700 {
    int m0;
    int m4;
    Data_002BB700* m8;
};

extern "C" Item_002BB700* func_002BB3B0(void* self, unsigned int i);
extern "C" void* func_002B6CF8(Data_002BB700* d);
extern "C" void func_002B70A8(void* p, void* a, int b);

struct Obj_002BB700 {
    char pad0[0x30];
    unsigned int m30;
    void Apply(void* a, int b);
};

void Obj_002BB700::Apply(void* a, int b)
{
    for (unsigned int i = 0; i < m30; i++) {
        Item_002BB700* it = func_002BB3B0(this, i);
        if (it->m8->m4 & 2) func_002B70A8(func_002B6CF8(it->m8), a, b);
    }
}
