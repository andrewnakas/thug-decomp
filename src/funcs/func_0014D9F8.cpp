extern "C" void func_00172658(void* p, int on);
extern "C" int func_00170538(void* p);
extern "C" void func_00170578(void* p, int v);

struct Ins_0014D9F8 {
    char pad[0x60];
    unsigned int m60;
    int GetFlag() { return m60 & 1; }
};

struct Ent_0014D9F8 {
    char pad[0x18];
    Ins_0014D9F8* m18;
    int m1C;
    void* m20;
    void SetVisible(int v);
};

void Ent_0014D9F8::SetVisible(int v)
{
    if (m18 && v != m18->GetFlag())
        func_00172658(m18, v);
    if (m20 && v != func_00170538(m20))
        func_00170578(m20, v);
}
