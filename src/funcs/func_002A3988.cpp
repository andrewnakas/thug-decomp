extern "C" void func_001048F0(int p);

struct Obj_002A3988 {
    char pad0[0xAC];
    int mAC;
    void FreeAC();
};

void Obj_002A3988::FreeAC() {
    func_001048F0(mAC);
}
