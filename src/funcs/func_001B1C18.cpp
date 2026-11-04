extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001A7A78(void* c);
extern "C" void func_001A8BE0(void* c);

struct C_001B1C18 {
    int m_pad[3];
    void* mC;
    int m10[4];
    unsigned int m20;
    void Update();
};

extern "C" int func_001B2268(C_001B1C18* self);
extern "C" int func_001B2968(C_001B1C18* self);
extern "C" void func_001B2630(C_001B1C18* self);
extern "C" void func_001B2C78(C_001B1C18* self);
extern "C" void func_001B3230(C_001B1C18* self);

void C_001B1C18::Update()
{
    if (!(m20 & 2)) return;
    void* c = func_00185578(mC, 0x0A015E17);
    int r = func_001B2268(this);
    if (!func_001B2968(this) && !r) func_001B2630(this);
    func_001A7A78(c);
    func_001B2C78(this);
    func_001B3230(this);
    func_001A8BE0(c);
}
