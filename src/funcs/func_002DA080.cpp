extern "C" void func_002F1FB0(void* p);

struct Obj_002DA080 {
    int m0;
    int m4;
    int m8;
    void* mC;
    void Stop();
};

void Obj_002DA080::Stop()
{
    m8 = 4;
    if (mC) {
        func_002F1FB0(mC);
        mC = 0;
    }
}
