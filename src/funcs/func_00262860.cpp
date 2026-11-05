extern "C" void func_00263320(void* p, const int& k, int z);

struct Obj_00262860 {
    int m0;
    int m_sub;
    void Fn(int k);
};

void Obj_00262860::Fn(int k)
{
    func_00263320(&m_sub, k, 0);
}
