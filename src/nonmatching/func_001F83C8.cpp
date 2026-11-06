/* fuzzy: 88.1 */
extern char D_0038EB90[];
extern "C" int func_0031BCE0(int sema);
extern "C" int func_0031F440(char* path, int mode, int a, int b, int c, int d);
extern "C" int func_00329108(int* status);

extern "C" void func_001F83C8(int sema)
{
    while (1) {
        func_0031BCE0(sema);
        while (func_0031F440(D_0038EB90, 0x4402, 0, 0, 0, 0) < 0) {
        }
        int status;
        while (!func_00329108(&status) || status != 0) {
        }
    }
}
