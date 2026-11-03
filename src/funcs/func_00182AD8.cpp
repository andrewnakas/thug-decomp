extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_00182B70(void* p);
extern void* D_0038C354;
extern int D_0038C358;

void* func_00182AD8(int create)
{
    if (!D_0038C354 && create) {
        D_0038C354 = func_00182B70(func_00104760(0x24, 0, 1));
    }
    D_0038C358++;
    return D_0038C354;
}
