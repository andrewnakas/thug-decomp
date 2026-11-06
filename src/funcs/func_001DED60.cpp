struct Ent_001DED60 {
    int m0;
    int m_id;
    int m8;
    int mC;
    int m_handle;
    char pad[0x28 - 0x14];
};
extern Ent_001DED60 D_003EE8E0[3];
extern "C" int func_001E3C58(int handle);

extern "C" bool func_001DED60(int id)
{
    for (int i = 0; i < 3; i++) {
        if (D_003EE8E0[i].m_id == id && func_001E3C58(D_003EE8E0[i].m_handle) != 1)
            return false;
    }
    return true;
}
