struct Ent_001121A0 {
    int m0;
    int m_id;
    int m8;
    volatile int m_free; // volatile as in the matched interrupt handler func_00112048 (same field)
    volatile int m_next; // written by the interrupt handler func_00112048 (its m_arg); it and func_00112238 still match with this field volatile
};

extern Ent_001121A0 D_00464DD0[64];
extern char D_004652D0[];
extern int D_00388E74;
extern "C" void func_0031D560(int a);
extern "C" void func_00320438();
extern "C" void func_00320490();
extern "C" void func_0031D0D0(void* buf, int n);
extern "C" void func_0031D0E8(int a, void (*fn)(), int b);
extern "C" void func_00112048();

extern "C" void func_001121A0()
{
    func_0031D560(0);
    func_00320438();
    func_0031D0D0(D_004652D0, 16);
    func_0031D0E8(1, func_00112048, 0);
    func_00320490();
    for (int i = 0; i < 64; i++) {
        D_00464DD0[i].m_free = 1;
        D_00464DD0[i].m_id = -1;
        D_00464DD0[i].m_next = -1;
    }
    D_00388E74 = 0;
}
