extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_001325A0(void* self);
extern void* D_00388A70;

class Obj_0015C348 {
public:
    char pad[0x1AC];
    void* m_1AC;
    void Release();
};

void Obj_0015C348::Release()
{
    func_001325A0(this);
    if (m_1AC)
        func_0010A8D8(D_00388A70, m_1AC);
}
