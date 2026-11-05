struct Ent_0011D960 {
    int m0;
    char pad[0x2C];
};

extern "C" int func_0011F4A8(void* src);
extern "C" int func_0011F4B0(void* src, int i);

struct Obj_0011D960 {
    char pad[0x18];
    Ent_0011D960* m_ents;
    void Load(void* src);
};

void Obj_0011D960::Load(void* src)
{
    for (int i = 0; i < func_0011F4A8(src); i++) {
        m_ents[i].m0 = func_0011F4B0(src, i);
    }
}
