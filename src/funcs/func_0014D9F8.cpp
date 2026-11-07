struct Ins_0014D9F8;
extern "C" void func_00172658(Ins_0014D9F8* p, unsigned int v);
extern "C" unsigned int func_00170538(void* p);
extern "C" void func_00170578(void* p, unsigned int v);

struct Ins_0014D9F8 {
    char pad[0x60];
    int m60;
    void SetVisible(unsigned int v)
    {
        if (v != (m60 & 1))
            func_00172658(this, v);
    }
};

struct Ent_0014D9F8 {
    char pad[0x18];
    Ins_0014D9F8* m18;
    int m1C;
    void* m20;
    void SetVisible(unsigned int v);
};

void Ent_0014D9F8::SetVisible(unsigned int v)
{
    if (m18)
        m18->SetVisible(v);
    if (m20 && v != func_00170538(m20))
        func_00170578(m20, v);
}
