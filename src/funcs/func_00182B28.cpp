extern unsigned int D_0038C358;
extern void* D_0038C354;
extern "C" void func_00182C08(void* p, int mode);

void func_00182B28()
{
    if (D_0038C358 > 1) {
        D_0038C358--;
        return;
    }
    if (D_0038C354) {
        func_00182C08(D_0038C354, 3);
    }
    D_0038C354 = 0;
    D_0038C358 = 0;
}
