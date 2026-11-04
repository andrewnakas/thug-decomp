struct Mode_001AE488 {
    int m_pad[27];
    int m6C;
};

struct C_001AE488 {
    int m_pad[8];
    Mode_001AE488* m20;
    int m24[1161];
    int m1248;
    int m124C[10];
    int m1274;
    int m1278;
    void Poll();
};

extern "C" void func_001AE340(C_001AE488* self, int id, int arg, int mask);

void C_001AE488::Poll()
{
    if (m1274 && m20->m6C) func_001AE340(this, m1274, 1, m1278);
    for (int i = 0; i < m1248; i++) {
        func_001AE340(this, m124C[i], 0, m1278);
    }
}
