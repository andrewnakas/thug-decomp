struct Heap_001EE7F8 {
    char pad0[0xEC];
    void* m_EC;
};

struct Src_001EE7F8 {
    unsigned int m_name;
    unsigned char* m_data;
};

extern Heap_001EE7F8* D_00388A70;

extern "C" void func_0010A950(Heap_001EE7F8* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_001EE7F8* mgr);
extern "C" void* func_0010BDE0(unsigned int size);
extern "C" unsigned char* func_001ECD40(unsigned char* data);

struct Obj_001EE7F8 {
    char pad0[0xC];
    unsigned char* m_data;

    void Load(Src_001EE7F8* src, int a, int b);
};

extern "C" void func_001EE640(Obj_001EE7F8* self, unsigned int name, unsigned char* data, int a, int b);

void Obj_001EE7F8::Load(Src_001EE7F8* src, int a, int b)
{
    unsigned int size = func_001ECD40(src->m_data) - src->m_data;
    func_0010A950(D_00388A70, D_00388A70->m_EC);
    unsigned char* data = (unsigned char*)func_0010BDE0(size);
    func_0010A9B0(D_00388A70);
    unsigned char* s = src->m_data;
    unsigned char* d = data;
    for (unsigned int i = 0; i < size; i++)
        *d++ = *s++;
    func_001EE640(this, src->m_name, data, a, b);
    m_data = data;
}
