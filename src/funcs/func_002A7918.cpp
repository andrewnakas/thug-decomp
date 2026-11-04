extern "C" void func_001048F0(int v);

struct Obj_002A7918 {
    char pad0[0x90];
    int m90;
    void Release();
};

void Obj_002A7918::Release() {
    func_001048F0(m90);
}
