extern "C" void func_00263460(void* p, const int& k);

struct Obj_002629B8 {
    int m0;
    int m_sub;
    void Fn(int k);
};

void Obj_002629B8::Fn(int k)
{
    func_00263460(&m_sub, k);
}
