struct Key_001427C0 {
    int v;
};

extern "C" void func_00142C38(void* p, Key_001427C0* k);

class Obj_001427C0 {
public:
    void* m_0;
    void Run(const Key_001427C0* k);
};

void Obj_001427C0::Run(const Key_001427C0* k)
{
    void* p = m_0;
    Key_001427C0 tmp;
    tmp.v = k->v;
    func_00142C38(p, &tmp);
}
