extern "C" void func_00188BA8(void* p, void* o);
extern "C" void func_00188558(void* p, int a);
extern "C" void func_00188B08(void* p, void* o);

struct Obj_001F1188 {
    char pad0[0xDC];
    void* mDC;
    void Apply(int a);
};

void Obj_001F1188::Apply(int a)
{
    if (mDC) {
        func_00188BA8(mDC, this);
        func_00188558(mDC, a);
        func_00188B08(mDC, this);
    }
}
