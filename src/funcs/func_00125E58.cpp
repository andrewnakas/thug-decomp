extern void* D_0038E630[2];
extern int D_0038E640;
extern void* D_00388A70;
extern "C" int func_0010D2D0(void* heap, void* p);
extern "C" void func_0010D340(void* heap, void* p);
extern "C" void func_0010A8D8(void* pool, void* p);

void func_00125E58(void* p) {
    void* h = D_0038E630[D_0038E640];
    if (h && func_0010D2D0(h, p)) {
        func_0010D340(h, p);
        return;
    }
    h = D_0038E630[D_0038E640 ^ 1];
    if (h && func_0010D2D0(h, p)) {
        func_0010D340(h, p);
        return;
    }
    if (p) {
        func_0010A8D8(D_00388A70, p);
    }
}
