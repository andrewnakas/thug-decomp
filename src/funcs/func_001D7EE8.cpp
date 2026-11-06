extern unsigned short D_0034EDE8[0x1770];

struct Obj_001D7EE8 {
    char m_pad0[0x34];
    int m34;
    bool Func();
};

bool Obj_001D7EE8::Func()
{
    if (D_0034EDE8[0] != 0) {
        for (int i = 0x176F; i >= 0; i--)
            D_0034EDE8[i] = i;
    }
    return m34 != 0;
}
