struct Msg_001F53E8 {
    long m0;
    long m8;
    int m10;
    int m14;
};
struct Obj_001F53E8 {
    char pad[0x48];
    int m48;
    void Send(long a, long b, int t, int v);
};

extern int D_0038E320;
extern "C" void func_001F6758(int p, Msg_001F53E8* m, int base);

void Obj_001F53E8::Send(long a, long b, int t, int v)
{
    Msg_001F53E8 m;
    m.m0 = a;
    m.m8 = b;
    m.m10 = t - m48;
    m.m14 = v;
    func_001F6758(D_0038E320 + 0x673608, &m, m48);
}
