struct Vec_002BB1B0 {
    float x;
    float y;
    float z;
};

struct Item_002BB1B0 {
    int m0;
    int m4;
    int m8;
};

extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" Item_002BB1B0* func_002BB3B0(void* self, unsigned int i);
extern "C" void* func_001190D0(unsigned int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, int name, int v);
extern "C" void func_002BB010(Vec_002BB1B0* out, void* self, unsigned int i);
extern "C" void func_001E7410(void* s, int name, float x, float y, float z);
extern "C" void func_001E9170(void* arr, unsigned int i, void* s);

struct Obj_002BB1B0 {
    char pad0[0x30];
    unsigned int m30;
    void Export(void* arr);
};

void Obj_002BB1B0::Export(void* arr)
{
    func_001E8E98(arr, m30, 10);
    for (unsigned int i = 0; i < m30; i++) {
        Item_002BB1B0* it = func_002BB3B0(this, i);
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0, it->m8);
        Vec_002BB1B0 v;
        func_002BB010(&v, this, i);
        func_001E7410(s, 0, v.x, v.y, v.z);
        func_001E9170(arr, i, s);
    }
}
