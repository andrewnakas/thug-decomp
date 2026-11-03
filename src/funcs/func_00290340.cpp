/* cflags: -fopt-stack */
extern "C" void* func_001046B0(int size);
extern "C" void* func_00290368(void* self);

void* func_00290340_create() {
    return func_00290368(func_001046B0(0x20));
}
