struct Mode_001AF298 {
    int m_pad[27];
    int m6C;
};

struct C_001AF298 {
    int m_pad[8];
    Mode_001AF298* m20;
    int m24[1192];
    int m12C4;
    int m12C8[10];
    int m12F0;
    void Poll();
};

extern "C" void func_001AF138(C_001AF298* self, int id, int arg);

void C_001AF298::Poll()
{
    if (m12F0 && m20->m6C) func_001AF138(this, m12F0, 1);
    for (int i = 0; i < m12C4; i++) {
        func_001AF138(this, m12C8[i], 0);
    }
}
