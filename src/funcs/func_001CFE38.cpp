extern "C" void* func_00104760(int size, int a, int b);

struct Registry_001CFE38;
extern "C" Registry_001CFE38* func_001CFED0(void* self);

extern Registry_001CFE38* D_0038DB38;
extern int D_0038DB3C;

Registry_001CFE38* func_001CFE38(int create)
{
    if (!D_0038DB38 && create) {
        D_0038DB38 = func_001CFED0(func_00104760(0x14, 0, 1));
    }
    D_0038DB3C++;
    return D_0038DB38;
}
