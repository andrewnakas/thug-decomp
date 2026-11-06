extern "C" void* func_00185578(void* obj, unsigned int name);

struct Comp_00272E30 {
    char pad[0x20];
    int m20;
};

struct Obj_00272E30 {
    char pad[0xC];
    void* mC;
    char pad2[0x30 - 0x10];
    void* m30;
    Comp_00272E30* m34;
    void Init();
};

void Obj_00272E30::Init()
{
    m30 = func_00185578(mC, 0x5BD63B29);
    m34 = (Comp_00272E30*)func_00185578(mC, 0x43686585);
    m34->m20 = -1;
}
