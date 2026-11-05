struct Obj_001F1200 {
    char pad[0xDC];
    void* mDC;
    bool Fwd(int a, int b);
};
extern "C" void func_00188828(void* o, int a, Obj_001F1200* self, int b);

bool Obj_001F1200::Fwd(int a, int b)
{
    if (mDC)
        func_00188828(mDC, a, this, b);
    return true;
}
