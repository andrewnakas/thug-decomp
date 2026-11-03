extern "C" void* func_00104760(int size, int a, int b);

struct Registry_001F2BC0;
extern "C" Registry_001F2BC0* func_001F2CD8(void* self);

extern Registry_001F2BC0* D_0038E8A4;
extern int D_0038E8A8;

Registry_001F2BC0* func_001F2BC0(int create)
{
    if (!D_0038E8A4 && create) {
        D_0038E8A4 = func_001F2CD8(func_00104760(0x28, 0, 1));
    }
    D_0038E8A8++;
    return D_0038E8A4;
}
