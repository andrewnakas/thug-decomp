/* fuzzy: 61.6 */
extern "C" int func_001DED20(int rec, int idx);
extern "C" int func_00331BB8(const char* s);

struct Rec_001E0F20 {
    char m_names[81][0x28];
    int m_pad[2];
};

extern int D_0038E170[];
extern Rec_001E0F20 D_003F0898[];

/* Returns the file-name part (after the last '\' or '/') of entry idx of record rec. */
extern "C" char* func_001E0F20(int rec, int idx)
{
    if (func_001DED20(rec, idx)) {
        __builtin_memcpy(&D_003F0898[0], &D_0038E170[0], 7);
        return (char*)D_003F0898;
    }
    char* name = D_003F0898[rec].m_names[idx];
    char* r = name;
    int n = func_00331BB8(name);
    int i = 0;
    while (i < n) {
        if (name[i] == '\\' || name[i] == '/') {
            i++;
            r = name + i;
        } else {
            i++;
        }
    }
    return r;
}
