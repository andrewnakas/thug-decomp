extern "C" void* func_00104760(int size, int a, int b);

struct Registry_001DC4A8;
extern "C" Registry_001DC4A8* func_001DC6F0(void* self);

extern Registry_001DC4A8* D_0038E0A0;
extern int D_0038E0A4;

Registry_001DC4A8* func_001DC4A8(int create)
{
    if (!D_0038E0A0 && create) {
        D_0038E0A0 = func_001DC6F0(func_00104760(0x8, 0, 1));
    }
    D_0038E0A4++;
    return D_0038E0A0;
}
