extern "C" int func_00185578(int obj, unsigned int id);

struct Obj_0029E2C8 {
    char pad0[0xC];
    int mC;
    char pad10[0x28 - 0x10];
    int m28;
    void Resolve();
};

void Obj_0029E2C8::Resolve() {
    m28 = func_00185578(mC, 0x726E85AA);
}
