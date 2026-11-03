extern "C" void* func_00104760(int size, int a, int b);

struct Registry_00253A30;
extern "C" Registry_00253A30* func_00253AD8(void* self);

extern Registry_00253A30* D_00390828;
extern int D_0039082C;

Registry_00253A30* func_00253A30(int create)
{
    if (!D_00390828 && create) {
        D_00390828 = func_00253AD8(func_00104760(0x174, 0, 1));
    }
    D_0039082C++;
    return D_00390828;
}
