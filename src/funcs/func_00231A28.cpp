struct Src_00231A28 {
    int m0;
    int m4;
};

struct Dst_00231A28 {
    char pad[0x44];
    int m_44;
};

struct Obj_00231A28 {
    Src_00231A28* m0;
    char pad4[0x14 - 4];
    int m_14;
    int Apply();
};

extern void* D_00392068;
extern "C" Dst_00231A28* func_002A5248(void* a, int id);

int Obj_00231A28::Apply()
{
    Dst_00231A28* d = func_002A5248(D_00392068, m_14);
    if (!d) {
        return 3;
    }
    d->m_44 = m0->m4;
    return 1;
}
