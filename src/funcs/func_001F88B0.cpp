extern "C" int func_00326618(int);
extern "C" int func_003267F8();
extern "C" unsigned int func_0010FC30();
extern "C" int func_001FA650(void*);
extern "C" void func_001FA658(void*, int);
extern "C" int func_00327958(int, int*, short*, short*);
extern "C" void func_003247E8(int);

int func_001F88B0(void* n)
{
    short err;
    short sub;
    int state;
    unsigned int timeout;
    unsigned int start;
    int r = func_00326618(6);
    if (r != 0) {
        if (r != 0x6B) {
            func_001FA658(n, 1);
            return 0;
        }
    } else if (func_003267F8()) {
        goto fail;
    }
    timeout = 10000;
    state = -1;
    start = func_0010FC30();
    if (func_001FA650(n) == 4)
        timeout = 15000;
    while (state == -1) {
        if (func_00327958(0, &state, &err, &sub))
            goto fail;
        if (state == -1)
            func_003247E8(10);
        if (func_0010FC30() - start > timeout)
            break;
    }
    if (state < 3) {
        if (state >= 0)
            return 1;
    }
    if (err == 0)
        func_001FA658(n, 2);
    else
        func_001FA658(n, 5);
    return 0;
fail:
    func_001FA658(n, 1);
    return 0;
}
