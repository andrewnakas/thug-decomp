extern "C" void func_002B3BE0(void* a, void* b);

struct Obj_002B3BB0 {
    char pad0[0xA0];
    int mA0;
};

void func_002B3BB0(void* a, Obj_002B3BB0* b) {
    func_002B3BE0(a, b);
    b->mA0 = 1;
}
