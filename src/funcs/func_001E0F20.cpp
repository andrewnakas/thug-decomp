extern "C" int func_001DED20(void);
extern "C" int func_00331BB8(const char* s);

struct Rec_001E0F20 {
    char m_names[81][0x28];
    long m_pad;
};

extern long D_0038E170[];
extern Rec_001E0F20 D_003F0898[];

/* Returns the file-name part (after the last '\' or '/') of name slot of record rec. */
extern "C" char* func_001E0F20(int slot, int rec)
{
    if (func_001DED20()) {
        __builtin_memcpy(&D_003F0898[0], D_0038E170, 7);
        return (char*)D_003F0898;
    }
    Rec_001E0F20* rp = &D_003F0898[rec];
    char* name = rp->m_names[slot];
    char* r = name;
    int n = func_00331BB8(name);
    for (int i = 0; i < n; i++) {
        if (name[i] == '\\' || name[i] == '/') {
            r = &name[i + 1];
        }
    }
    return r;
}
