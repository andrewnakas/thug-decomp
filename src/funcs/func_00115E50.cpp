extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Obj_00115E50;
extern "C" void func_001160A0(Obj_00115E50* self, int a, int size, int b);

struct Obj_00115E50 {
    char pad[0xC];
    void* m_data;
    char pad10[0x2C - 0x10];
    int m2C;
    void SetData(const void* src, int size, int a);
};

void Obj_00115E50::SetData(const void* src, int size, int a)
{
    m2C = 0;
    m_data = func_0010BDE0(size);
    func_00331404(m_data, src, size);
    func_001160A0(this, a, size, 1);
}
