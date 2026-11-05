extern int D_00464BF8[16];
extern int D_00388C8C;

extern "C" int func_0010EF80(int id)
{
    for (int i = 0; i < 16; i++) {
        if (id == D_00464BF8[i]) {
            D_00388C8C--;
            D_00464BF8[i] = D_00464BF8[D_00388C8C];
            D_00464BF8[D_00388C8C] = id;
            return 1;
        }
    }
    return 0;
}
