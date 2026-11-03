extern "C" void* func_00104760(int size, int a, int b);

struct Registry_0022C098;
extern "C" Registry_0022C098* func_0022D790(void* self);

extern Registry_0022C098* D_0038FC78;
extern int D_0038FC7C;

Registry_0022C098* func_0022C098(int create)
{
    if (!D_0038FC78 && create) {
        D_0038FC78 = func_0022D790(func_00104760(0x490, 0, 1));
    }
    D_0038FC7C++;
    return D_0038FC78;
}
