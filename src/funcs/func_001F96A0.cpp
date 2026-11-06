extern char D_003666C0[];
extern char D_003666D0[];
extern char D_003666E0[];
extern char D_003666F0[];
extern char D_00366700[];
extern char D_00366710[];
extern char D_00366720[];
extern char D_00366918[];
extern char D_0038EBA8[];
extern char D_0038EBB0[];
extern char D_0038EBB8[];
extern int D_0038882C;

extern "C" int func_001FA648(void* n);
extern "C" int func_001FA650(void* n);
extern "C" void func_001FA658(void* n, int err);
extern "C" int func_00106B98(const char* name, int argc, const char* args, int flag);
extern "C" void func_001F8450();

int Call_001F96A0(void* n)
{
    switch (func_001FA648(n)) {
    case 3:
        switch (func_001FA650(n)) {
        case 1:
            if (func_00106B98(D_003666C0, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            if (func_00106B98(D_003666D0, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            return 1;
        case 3:
            if (func_00106B98(D_003666C0, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            if (func_00106B98(D_003666E0, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            if (func_00106B98(D_0038EBA8, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            func_001F8450();
            if (func_00106B98(D_0038EBB0, 0, 0, 0) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            return 1;
        default:
            func_001FA658(n, 1);
            return 0;
        }
    case 2:
        switch (func_001FA650(n)) {
        case 1:
            if (func_00106B98(D_003666F0, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            return 1;
        case 3:
            if (func_00106B98(D_00366700, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            if (func_00106B98(D_0038EBA8, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            func_001F8450();
            if (func_00106B98(D_0038EBB0, 0, 0, 0) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            return 1;
        default:
            func_001FA658(n, 1);
            return 0;
        }
    case 1:
        switch (func_001FA650(n)) {
        case 2:
            if (func_00106B98(D_00366710, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            return 1;
        case 4:
            if (!D_0038882C) {
                func_001FA658(n, 4);
                return 0;
            }
            if (func_00106B98(D_00366720, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            if (func_00106B98(D_0038EBA8, 0, 0, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            func_001F8450();
            if (func_00106B98(D_0038EBB8, 0x27, D_00366918, 1) < 0) {
                func_001FA658(n, 4);
                return 0;
            }
            return 1;
        default:
            func_001FA658(n, 1);
            return 0;
        }
    default:
        func_001FA658(n, 1);
        return 0;
    }
}
