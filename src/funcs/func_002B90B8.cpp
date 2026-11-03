struct Entry_002B90B8 {
    unsigned int m0;
    int m4;
    void* m8;
};

struct Arr_002B90B8 {
    char pad[0xC];
    int mC;
};

extern int D_00394178;
extern "C" int func_001E9270(void* p, int i);
extern "C" void* func_001E9378(Arr_002B90B8* a, int i);
extern "C" int func_001E8958(void* p, unsigned int key, int v, int f);
extern "C" int func_001E8A30(void* p, unsigned int key, int* out, int flag);

struct Obj_002B90B8 {
    char pad[0xA4];
    Entry_002B90B8* mA4;
    int* mA8;
    int mAC;
    int Find(Arr_002B90B8* p, int type, int sub, int val, int* flag, int* out);
};


int Obj_002B90B8::Find(Arr_002B90B8* p, int type, int sub, int val, int* flag, int* out)
{
    int found1 = -1;
    int found2 = -1;
    if (sub < 0)
        D_00394178 = 0;
    int i = D_00394178;
    int n = p->mC;
    for (; i < n; i++) {
        if (mA4[i].m0 != 0x8E6B02AD)
            continue;
        int v = -1;
        if (mA4[i].m8)
            v = func_001E9270(mA4[i].m8, 0);
        int t = mA4[i].m4;
        if (sub >= 0) {
            if (v != sub)
                continue;
            found1 = i;
            for (int k = 0; k < mAC; k++)
                if (mA8[k] == found1)
                    found1 = -1;
            if (found1 != -1)
                break;
            continue;
        }
        if (type != t)
            continue;
        if (D_00394178 == 0)
            D_00394178 = i;
        if (v == -1) {
            found2 = i;
            for (int k = 0; k < mAC; k++)
                if (mA8[k] == found2)
                    found2 = -1;
            if (found2 != -1)
                break;
            continue;
        }
        if (found1 != -1)
            continue;
        found1 = i;
            for (int k = 0; k < mAC; k++)
                if (mA8[k] == found1)
                    found1 = -1;
    }
    int r = -1;
    if (found1 != -1) {
        *flag = 1;
        r = found1;
    }
    if (found2 != -1) {
        r = found2;
        *flag = 0;
    }
    if (r == -1)
        return -1;
    int c = mAC;
    mA8[c] = r;
    mAC = c + 1;
    void* q = func_001E9378(p, r);
    func_001E8958(q, 0x7F261953, val, 1);
    int tmp;
    func_001E8A30(q, 0x54CF8532, &tmp, 1);
    *out = tmp;
    return r;
}
