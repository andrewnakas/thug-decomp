extern char D_0038F658[];
extern char D_0038F660[];
extern char D_0038F668[];
extern "C" int func_0031F440(char* name, int mode, int a, int b, int c, int d);
extern "C" int func_00329108(int* status);

extern "C" int func_00217150()
{
    func_0031F440(D_0038F660, 0x5003, 0, 0, 0, 0);
    while (func_0031F440(D_0038F668, 0x4806, 0, 0, 0, 0) < 0) {
    }
    while (func_0031F440(D_0038F658, 0x4402, 0, 0, 0, 0) < 0) {
    }
    int status;
    while (!func_00329108(&status) || status) {
    }
    return 1;
}
