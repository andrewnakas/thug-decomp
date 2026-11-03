struct Mode_001AE868 {
    int m_pad[27];
    int m6C;
};

struct C_001AE868 {
    int m_pad[8];
    Mode_001AE868* m20;
    int m24[1174];
    int m127C;
    int m1280[10];
    int m12A8;
    int m12AC;
    void Poll();
};

extern "C" void func_001AE708(C_001AE868* self, int id, unsigned int mask, int arg);

void C_001AE868::Poll()
{
    if (m12A8 && m20->m6C) {
        func_001AE708(this, m12A8, 0xFFFFFFFB, 1);
        if (m12AC) return;
    }
    for (int i = 0; i < m127C; i++) {
        func_001AE708(this, m1280[i], 0xFFFFFFFF, 0);
    }
}
