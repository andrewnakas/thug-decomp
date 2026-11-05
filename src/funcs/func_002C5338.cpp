extern "C" void func_002CBE00(void* p, int f);

struct Obj_002C5338 {
    char pad0[0xBC];
    void* mBC;
    void Release();
};

void Obj_002C5338::Release()
{
    if (mBC) {
        func_002CBE00(mBC, 3);
        mBC = 0;
    }
}
