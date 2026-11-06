extern void* D_00388A70;
extern void* D_00388C28[2];
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_0010D340(void* pool, void* p);

extern "C" void func_0010D428(int i, void* p)
{
    if (D_00388C28[i]) {
        func_0010D340(D_00388C28[i], p);
    } else if (p) {
        func_0010A8D8(D_00388A70, p);
    }
}
