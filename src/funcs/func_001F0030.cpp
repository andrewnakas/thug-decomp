struct Ent_001F0030 {
    void* m0;
    char pad4[0x28];
};

struct Obj_001F0030 {
    char pad0[0xC];
    int mC;
    char pad10[0x38 - 0x10];
    int m38;
    char pad3C[0x94 - 0x3C];
    Ent_001F0030* m94;
    char pad98[0xC8 - 0x98];
    void* mC8;
    bool Ready();
};

extern "C" int func_001E4FC8(void* p);

bool Obj_001F0030::Ready()
{
    if (!m38) {
        if (mC) return true;
        return func_001E4FC8(mC8) != 0;
    }
    if (!func_001E4FC8(mC8)) return false;
    for (int i = mC != 0; i < m38; i++) {
        if (!func_001E4FC8(m94[i].m0)) return false;
    }
    return true;
}
