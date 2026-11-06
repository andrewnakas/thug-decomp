extern char D_0038F658[];
extern "C" int func_0031F440(char* name, int mode, int a, int b, int c, int d);
extern "C" int func_00329108(int* status);

extern "C" int func_002170F0()
{
    while (func_0031F440(D_0038F658, 0x4402, 0, 0, 0, 0) < 0) {
    }
    int status;
    while (!func_00329108(&status) || status) {
    }
    return 1;
}
