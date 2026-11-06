struct Entry_001DCA18 {
    unsigned int m_id;
    char m_pad[0x1C];
};

extern Entry_001DCA18 D_003E82F8[512];
extern int D_0038E0B4;
extern int D_0038E0B0;

extern "C" bool func_001DC418();

extern "C" Entry_001DCA18* func_001DCA18(void* self, unsigned int id)
{
    if (func_001DC418())
        return 0;
    int i;
    for (i = 0; i < D_0038E0B4; i++) {
        if (id == D_003E82F8[i].m_id)
            return &D_003E82F8[i];
    }
    for (i = 0; i < D_0038E0B0; i++) {
        if (id == D_003E82F8[i + 256].m_id)
            return &D_003E82F8[i + 256];
    }
    return 0;
}
