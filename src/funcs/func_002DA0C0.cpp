extern "C" void func_002F2300(void* p, int arg);

struct Obj_002DA0C0 {
    char pad0[8];
    int m8;
    void* mC;
    void Update(int arg);
};

void Obj_002DA0C0::Update(int arg)
{
    if (m8 == 6)
        func_002F2300(mC, arg);
}
