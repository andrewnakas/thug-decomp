struct Info_00113BB8 {
    int m_0;
    int m_4;
    unsigned char m_present[8];
};

struct Dir_00113BB8 {
    int m_0;
    int m_4;
    int m_8;
};

extern int D_00388F28;
extern int D_00388F2C;
extern int D_00393ED4;
extern int D_00393ED0;
extern unsigned char* D_00388F24;
extern Info_00113BB8 D_003BD740;
extern Dir_00113BB8 D_003BD7C8;
extern char D_003BD850[];
extern int D_00393EC8[2];

extern "C" int func_00318CA0(Info_00113BB8* info);
extern "C" int func_003191C8(int mode, int* result);
extern "C" void func_00113F00(int port);
extern "C" int func_00318D48(int port, Dir_00113BB8* dir);
extern "C" int func_00318E28(int port, int* out);
extern "C" int func_00113F88(int port, char* buf);

extern "C" void func_00113BB8()
{
    int result;
    int i;
    if (!D_00388F28 || !D_00388F2C) {
        return;
    }
    D_00393ED4 = 0;
    result = func_00318CA0(&D_003BD740);
    if (result) {
        return;
    }
    func_003191C8(0, &result);
    if (result) {
        return;
    }
    for (i = 0; i < D_00393ED0; i++) {
        if (!D_003BD740.m_present[i]) {
            continue;
        }
        if (!D_00388F24[i]) {
            func_00113F00(i);
        }
        result = func_00318D48(i, &D_003BD7C8);
        if (result) {
            continue;
        }
        func_003191C8(0, &result);
        if (result || !D_003BD7C8.m_8) {
            continue;
        }
        result = func_00318E28(i, D_00393EC8);
        if (result) {
            continue;
        }
        func_003191C8(0, &result);
        if (result) {
            continue;
        }
        D_00393ED4 = func_00113F88(i, D_003BD850);
    }
    for (i = 0; i < D_00393ED0; i++) {
        D_00388F24[i] = D_003BD740.m_present[i];
    }
}
