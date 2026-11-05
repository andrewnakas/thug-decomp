extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int req);
extern "C" int func_001E87B8(void* params, char* name);
extern "C" void* func_0022E358(int a);
extern "C" void func_0024F3A0(void* a, bool b);
extern "C" void func_0024F3C8(void* a, int b);
extern int D_0038FC78;
extern char D_00371858[];

bool Cmd_00220938(void* params)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_0024F3A0(func_0022E358(D_0038FC78), v != 0);
    if (!v && func_001E87B8(params, D_00371858)) {
        func_0024F3C8(func_0022E358(D_0038FC78), 1);
    } else {
        func_0024F3C8(func_0022E358(D_0038FC78), 0);
    }
    return true;
}
