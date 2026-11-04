extern void* D_00464BF8[16];
extern int D_00388C8C;

extern "C" int func_0010E4A0(void* p);
extern "C" void func_0010E4B0(void* p);
extern "C" void func_0010E3F8(void* p);

extern "C" void* func_0010EE50()
{
    if (D_00388C8C < 16) {
        if (func_0010E4A0(D_00464BF8[D_00388C8C])) {
            int i;
            for (i = D_00388C8C + 1; i < 16; i++) {
                if (!func_0010E4A0(D_00464BF8[i])) {
                    void* t = D_00464BF8[i];
                    D_00464BF8[i] = D_00464BF8[D_00388C8C];
                    D_00464BF8[D_00388C8C] = t;
                    break;
                }
            }
            if (i == 16) {
                func_0010E4B0(D_00464BF8[D_00388C8C]);
            }
        }
        func_0010E3F8(D_00464BF8[D_00388C8C]);
        return D_00464BF8[D_00388C8C++];
    }
    return 0;
}
