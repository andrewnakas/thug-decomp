/* sym: _$_12Prm_001363F0 = 0x001E6AE8 */
struct Prm_001363F0 {
    int m0;
    int m4;
    ~Prm_001363F0();
};

extern void* D_00389E40;
extern int D_00389E44;
extern int D_00389E48;
extern int D_00389E4C;
extern int D_00389E50;
extern Prm_001363F0* D_00389E54;
extern "C" void func_0010BEB8(void* p);

extern "C" void func_001363F0()
{
    if (D_00389E40) {
        func_0010BEB8(D_00389E40);
        D_00389E40 = 0;
    }
    D_00389E44 = 0;
    D_00389E48 = 0;
    D_00389E4C = 0;
    D_00389E50 = 0;
    if (D_00389E54) {
        delete D_00389E54;
        D_00389E54 = 0;
    }
}
