extern "C" void* func_001317D0(void* p);
extern "C" void func_00135048(void* p, int v);

struct Obj_002B7150 {
    void* m0;
    void Apply(int v);
};

void Obj_002B7150::Apply(int v) {
    func_00135048(func_001317D0(m0), v);
}
