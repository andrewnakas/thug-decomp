extern "C" void func_00263320(void* p, const int& k, int* out);

struct Obj_00262830 {
    int m0;
    int m_sub;
    int Fn(int k);
};

int Obj_00262830::Fn(int k)
{
    int v;
    func_00263320(&m_sub, k, &v);
    return v;
}
