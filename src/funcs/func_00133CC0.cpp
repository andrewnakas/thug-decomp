extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_001D66F8(void* e);
extern char D_00389CE8[];

struct E_00133CC0 {
    char pad[0x14];
};

struct C_00133CC0 {
    char pad[0x158];
    int m158;
    E_00133CC0* m15C;
    void Dump();
};

void C_00133CC0::Dump()
{
    for (int i = 0; i < m158; i++) {
        func_00103F28(D_00389CE8, i, m158);
        func_001D66F8(&m15C[i]);
    }
}
