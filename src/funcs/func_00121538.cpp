extern void* D_00389520;
extern void* D_00389518;
extern "C" void* func_0011FE18(void* o, unsigned int id);
extern "C" int func_001E8870(void* params, unsigned int id, const char** out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_0013DAC0(void* mgr, unsigned int id, const char* a, const char* b);

int func_00121538(void* self, unsigned int id)
{
    int r = 0;
    void* params = func_0011FE18(D_00389520, id);
    if (params) {
        const char* a;
        const char* b;
    if (func_001E8870(params, 0xF362DBBA, &a, 0)) {
        func_001E8870(params, 0x676F1DF1, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0xA01371B1, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    if (func_001E8870(params, 0x7A993873, &a, 0)) {
        func_001E8870(params, 0x9B03ADAD, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0xED189051, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    if (func_001E8870(params, 0xE39069C9, &a, 0)) {
        func_001E8870(params, 0x020AFC17, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0x7411C1EB, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    if (func_001E8870(params, 0x9497595F, &a, 0)) {
        func_001E8870(params, 0x750DCC81, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0x0316F17D, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    if (func_001E8870(params, 0x0AF3CCFC, &a, 0)) {
        func_001E8870(params, 0xEB695922, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0x9D7264DE, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    if (func_001E8870(params, 0x7DF4FC6A, &a, 0)) {
        func_001E8870(params, 0x9C6E69B4, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0xEA755448, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    if (func_001E8870(params, 0xE4FDADD0, &a, 0)) {
        func_001E8870(params, 0x0567380E, &b, 1);
        unsigned int c = id;
        func_001E8398(params, 0x737C05F2, &c, 0);
        r = func_0013DAC0(D_00389518, c, a, b);
    }
    }
    return r;
}
