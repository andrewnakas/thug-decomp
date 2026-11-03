extern "C" void* func_001317D0(void* p);
extern "C" void func_00134FD8(void* p, int v);

struct Obj_002B7188 {
    void* m0;
    void SetOn(int on);
};

void Obj_002B7188::SetOn(int on) {
    func_00134FD8(func_001317D0(m0), on ? 0xFF : 0);
}
