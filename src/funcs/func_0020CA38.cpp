extern int D_0038880C;
extern int D_00388818;
extern int D_0038881C;
extern int D_0038882C;
extern int D_00388830;
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_001109D0();
extern "C" void func_00110CF8();

bool func_0020CA38(void* params, void* script)
{
    unsigned int mode = 0;
    func_001E8398(params, 0x2B248E4A, &mode, 0);
    switch (mode) {
    case 0xD37CFDFF:
        D_0038880C = 2;
        break;
    case 0x508A31A1:
    case 0xCBE70ACB:
        D_0038880C = 3;
        break;
    case 0xA8469630:
    case 0x5DCBBF5E:
        D_0038880C = 5;
        break;
    }
    if (func_001E8708(params, 0xBA297025)) {
        if (!D_0038881C) {
            func_001109D0();
        }
        D_0038881C = 1;
    }
    if (func_001E8708(params, 0x2B6D7B32)) {
        if (D_0038881C) {
            func_00110CF8();
        }
        D_0038881C = 0;
    }
    if (func_001E8708(params, 0x38D23FD4)) {
        D_00388818 = 1;
    }
    if (func_001E8708(params, 0xAF11B50F)) {
        D_00388818 = 0;
    }
    if (func_001E8708(params, 0x6CAD3928)) {
        D_0038882C = 0;
    }
    if (func_001E8708(params, 0x86137A88)) {
        D_0038882C = 1;
    }
    int v = 60;
    if (func_001E7DE8(params, 0xEE2BC65F, &v, 0)) {
        D_00388830 = v;
    }
    return true;
}
