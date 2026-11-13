/* fuzzy: 89.6 */
/* const: 0x3C5600 */
/* const: 0x1CA200 */
/* const: 0x3C45C0 */
/* const: 0x32A900 */
extern char* D_0038E320;
extern int D_0038E318;
extern int D_0038881C;
extern int D_00394110;
extern int D_00394114;
extern char D_0038F3F0[];
extern char D_00364728[];
extern char D_00364740[];
extern char D_00364750[];
extern char D_00364760[];
extern "C" void func_001F6D78(void*);
extern "C" void func_0032A338();
extern "C" void func_001F5218(void*, void*, int, void*, void*, int, void*, int);
extern "C" int func_001E34A0();
extern "C" void func_001F7A78(void*, void*, int, int, int);
extern "C" int func_001F5320(void*, int, int, void*, void*);
extern "C" void func_001F6E80();
extern "C" void func_001F6FB0();
extern "C" void func_001F5040(void*, unsigned int, void*, int);
extern "C" void func_001E4BD0();
extern "C" void func_001F5578();
extern "C" void func_001F77B0();
extern "C" void func_001F7970();
extern "C" int func_0031BAA0(void*);
extern "C" int func_0031BAC0(int, int);
extern "C" int func_00106818();
extern "C" void func_003331D0(char*, const char*, ...);
extern "C" unsigned int func_00331BB8(const char*);
extern "C" void func_0010FE68();
extern "C" int func_001DFD90();
extern "C" void func_00103F28(const char*, ...);
extern "C" int func_001F6A10(void*, char*, int);
extern "C" int func_0031B980(int, void*, int);
extern "C" int func_0031B9B0(int, void*, int);
extern "C" int func_0031C2D0(int);
extern "C" int func_0031C3A0(int);

struct ThreadParam_001E4710 {
    int status;
    void* entry;
    void* stack;
    int stackSize;
    void* gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
};

int func_001E4710(const char* name)
{
    ThreadParam_001E4710 tp;
    char buf[256];
    unsigned int i;

    *(volatile int*)0x1000E000 |= 3;
    *(volatile int*)0x1000E010 = 4;
    func_001F6D78(D_0038E320 + 0x623540);
    func_0032A338();
    func_001F5218(D_0038E320 + 0x6735C0, D_0038E320 + 0x3C5600, 0x1CA200, D_0038E320 + 0x59C0C0,
                  D_0038E320 + 0x3C45C0, 0x100, D_0038E320 + 0x620500, 0x200);
    char* g = D_0038E320;
    char* a = g + 0x673680;
    char* b = g + 0x590080;
    int v = func_001E34A0();
    func_001F7A78(a, b, 0xC000, 0x6000, v);
    func_001F5320(D_0038E320 + 0x6735C0, 0, 0, (void*)func_001F6E80, D_0038E320 + 0x623540);
    if (D_0038E318)
        func_001F5320(D_0038E320 + 0x6735C0, 2, 0, (void*)func_001F6FB0, D_0038E320 + 0x623540);
    func_001F5040(D_0038E320 + 0x673700, ((unsigned int)(D_0038E320 + 0x8C0) & 0x0FFFFFFF) | 0x20000000,
                  D_0038E320 + 0x32A900, 2);

    tp.entry = (void*)func_001E4BD0;
    tp.stack = D_0038E320 + 0x58F840;
    tp.stackSize = 0x800;
    tp.initPriority = 1;
    tp.gpReg = D_0038F3F0;
    tp.option = 0;
    D_00394114 = func_0031BAA0(&tp);
    func_0031BAC0(D_00394114, 0);

    tp.entry = (void*)func_001F5578;
    tp.stack = D_0038E320 + 0x61C4C0;
    tp.stackSize = 0x4000;
    tp.initPriority = 1;
    tp.gpReg = D_0038F3F0;
    tp.option = 0;
    D_00394110 = func_0031BAA0(&tp);
    func_0031BAC0(D_00394110, 0);

    char* path;
    if (D_0038881C) {
        path = buf;
        func_003331D0(path, D_00364728, func_00106818(), name);
        i = 7;
        goto test;
    body:
        if (path[i] >= 'a' && path[i] <= 'z')
            path[i] -= 0x20;
        else if (path[i] == '/')
            path[i] = '\\';
        i++;
    test:
        if (i < func_00331BB8(path))
            goto body;
    } else {
        func_003331D0(buf, D_00364740, name);
        path = buf;
    }
    func_0010FE68();
    if (func_001DFD90())
        return 0;

    int result = 0;
    for (int k = 0;;) {
        if (k < 10) {
            func_00103F28(D_00364750, k);
            if (func_001F6A10(D_0038E320 + 0x673580, path, func_001E34A0() + 0x2E040)) {
                result = 1;
            } else {
                func_00103F28(D_00364760, path);
                k++;
                continue;
            }
        }
        *(int*)(D_0038E320 + 0x673674) = func_0031B980(2, (void*)func_001F77B0, 0);
        func_0031C2D0(2);
        *(int*)(D_0038E320 + 0x673670) = func_0031B9B0(2, (void*)func_001F7970, 0);
        func_0031C3A0(2);
        return result;
    }
}
