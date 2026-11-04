extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int crc, int* out, int req);
extern "C" void* func_0022E050(int a);
extern "C" void* func_002629A8(void* a, int b);
extern "C" int func_00261E40(void* a, int b, int c);
extern int D_0038FC78;

void Cmd_0021D4E0(void* params)
{
    int a;
    int b;
    int c;
    func_001E7DE8(params, 0x67E6859A, &a, 1);
    func_001E8398(params, 0, &b, 0);
    func_001E7DE8(params, 0, &c, 0);
    func_00261E40(func_002629A8(func_0022E050(D_0038FC78), a), b, c);
}
