struct Game_001364F8 {
    char pad[0x38];
    int m38;
};

extern Game_001364F8* D_00390828;
extern unsigned short* D_00389E40;
extern int D_00389E44;
extern int D_00389E48;
extern int D_00389E4C;
extern int D_00389E50;
extern void* D_00389E54;

extern "C" void func_001363F0();
extern "C" void* func_00229DF0(int id);
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void func_001375C0(int a, void* b);

extern "C" void func_001364F8()
{
    if (!D_00389E40)
        return;
    if (D_00390828->m38)
        return;
    if (D_00389E50 > D_00389E4C) {
        func_001363F0();
        return;
    }
    int end;
    if (D_00389E4C)
        end = D_00389E44 * D_00389E50 / D_00389E4C;
    else
        end = D_00389E44;
    for (int i = D_00389E48; i < end; i = ++D_00389E48) {
        void* p = func_00229DF0(D_00389E40[i]);
        int v = 0;
        func_001E8398(p, 0xA1DC81F9, &v, 0);
        func_001375C0(v, D_00389E54);
    }
    D_00389E50++;
}
