extern void* D_00391EB0[2];
extern int D_00391EC0;
extern void* D_00388A70;
extern "C" int func_0010D2D0(void* heap, void* p);
extern "C" void func_0010D340(void* heap, void* p);
extern "C" void func_0010A8D8(void* pool, void* p);

void func_0029C410(void* p) {
    void* h = D_00391EB0[D_00391EC0];
    if (h && func_0010D2D0(h, p)) {
        func_0010D340(h, p);
        return;
    }
    h = D_00391EB0[D_00391EC0 ^ 1];
    if (h && func_0010D2D0(h, p)) {
        func_0010D340(h, p);
        return;
    }
    if (p) {
        func_0010A8D8(D_00388A70, p);
    }
}
