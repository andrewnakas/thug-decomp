struct Obj_001E2E08 {
    char pad[0xC];
    void* mC;
    int m10;
    int m14;
    bool Done();
};
extern "C" void func_0010ECF8(void* p);

bool Obj_001E2E08::Done()
{
    if (m14 < m10)
        return false;
    func_0010ECF8(mC);
    mC = 0;
    return true;
}
