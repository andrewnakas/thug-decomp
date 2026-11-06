extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001441C0(void* mem, int n);
extern "C" void* func_001442A0(void* mem, int n);
extern "C" void* func_00144380(void* mem, int n);
extern "C" void* func_00144460(void* mem, int n);
extern "C" void func_0014F430();
extern "C" void func_00150D48();
extern "C" void func_00142F58(void* p);
extern void* D_00388A70;
extern void* D_0038A630;
extern void* D_0038A634;
extern void* D_0038A638;
extern void* D_0038A63C;
extern char D_003C3DC0[];

extern "C" void func_00143490()
{
    if (!D_0038A630)
        D_0038A630 = func_001441C0(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    if (!D_0038A634)
        D_0038A634 = func_001442A0(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    if (!D_0038A638)
        D_0038A638 = func_00144380(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    if (!D_0038A63C)
        D_0038A63C = func_00144460(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    func_0014F430();
    func_00150D48();
    func_00142F58(D_003C3DC0);
}
