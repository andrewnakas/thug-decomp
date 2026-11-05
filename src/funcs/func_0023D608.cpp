struct Mgr_0023D608 {
    char pad[0x34];
    int m_34;
    int m_38;
    void Add(int n);
};

extern "C" int func_0023C048(Mgr_0023D608* self, int a);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);

void Mgr_0023D608::Add(int n)
{
    m_34 += n;
    m_38 += n;
    if (func_0023C048(this, 0) <= 0) {
        func_001F0210(0x888EF05E, 0, 0, 0, 0);
    }
}
