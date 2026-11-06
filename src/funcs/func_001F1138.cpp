extern void* D_0038C7B0;
struct Obj_001F1138 {
    char pad[0xDC];
    void* mDC;
    void Send(int msg);
};
extern "C" void func_00188498(void* o, int msg);
extern "C" void func_00189D80(void* mgr, int msg, Obj_001F1138* self);

void Obj_001F1138::Send(int msg)
{
    if (mDC) {
        func_00188498(mDC, msg);
        func_00189D80(D_0038C7B0, msg, this);
    }
}
