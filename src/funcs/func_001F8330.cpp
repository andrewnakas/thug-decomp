extern "C" void* func_00104760(int size, int a, int b);

struct Registry_001F8330;
extern "C" Registry_001F8330* func_001F9AB8(void* self);

extern Registry_001F8330* D_0038EB78;
extern int D_0038EB7C;

Registry_001F8330* func_001F8330(int create)
{
    if (!D_0038EB78 && create) {
        D_0038EB78 = func_001F9AB8(func_00104760(0x3310, 0, 1));
    }
    D_0038EB7C++;
    return D_0038EB78;
}
