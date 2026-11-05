struct Item_002376C0 {
    char pad[0x18];
    unsigned int m_flags;
};

struct Obj_002376C0 {
    char pad[0x44];
    char m_44[0x14];
    int m_58;
    char pad5C[0x64 - 0x5C];
    int m_64;
    void Update(int a);
};

extern "C" Item_002376C0* func_0023AFE8(void* list, int index);
extern "C" void func_00237728(Obj_002376C0* self, int a);

void Obj_002376C0::Update(int a)
{
    if (m_58 && m_64 >= 0 && !(func_0023AFE8(m_44, m_64)->m_flags & 2)) {
        func_00237728(this, a);
    }
}
