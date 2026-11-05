struct Entry_001E3370 {
    char m_data[0x24];
};

extern unsigned int D_0038E280;
extern int D_0038E2B0;
extern char D_00364610[];
extern Entry_001E3370 D_00351D68[4];

extern "C" void func_001E3308();
extern "C" void func_0031CD60(const char* s);
extern "C" int func_001E31D8(Entry_001E3370* e);

extern "C" int func_001E3370()
{
    func_001E3308();
    if ((D_0038E280 & 0x40000000) && D_0038E2B0) {
        D_0038E2B0 = 0;
        func_0031CD60(D_00364610);
    }
    for (int i = 0; i < 4; i++) {
        int r = func_001E31D8(&D_00351D68[i]);
        if (r)
            return r;
    }
    return 0;
}
