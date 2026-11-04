extern "C" void* func_001E9378(void* arr, unsigned int i);
extern "C" int func_001E8398(void* s, unsigned int crc, unsigned int* out, int req);
extern "C" void func_0026B538(void* self, unsigned int i, void* s);

struct Arr_0026B5E8 {
    char pad0[0xC];
    unsigned int m_size;
};

struct Obj_0026B5E8 {
    char pad0[0x50];
    Arr_0026B5E8* m_50;
    void Init(Arr_0026B5E8* a);
};

void Obj_0026B5E8::Init(Arr_0026B5E8* a)
{
    m_50 = a;
    for (unsigned int i = 0; i < a->m_size; i++) {
        void* s = func_001E9378(a, i);
        unsigned int type = 0;
        func_001E8398(s, 0x12B4E660, &type, 0);
        if (type == 0xD18719D5) {
            func_0026B538(this, i, s);
        }
    }
}
