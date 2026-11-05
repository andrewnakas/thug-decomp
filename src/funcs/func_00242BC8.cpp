extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_00240850();
extern "C" void func_0023F278(void* game, unsigned int id, int n, bool flag);

bool func_00242BC8(void* params)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    bool flag = func_001E8708(params, 0x1A4E0EF9);
    int n = 0;
    func_001E7DE8(params, 0x5B8AB877, &n, 0);
    int count = n + 1;
    func_0023F278(func_00240850(), id, count, flag);
    return true;
}
