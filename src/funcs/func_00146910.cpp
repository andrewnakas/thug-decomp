extern "C" void func_00170600(void* o, int v);

struct Obj_00146910 {
    int m0[12];
    void* m_30;
    void Reset();
};

void Obj_00146910::Reset()
{
    if (m_30)
        func_00170600(m_30, 0);
}
