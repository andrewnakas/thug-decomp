extern "C" void* func_001046B0(int size);
extern "C" void* func_00122E00(void* p);

struct Obj_001200E8 {
    char pad[0x50];
    void* m_50;
    void Create();
};

void Obj_001200E8::Create()
{
    m_50 = func_00122E00(func_001046B0(0x44A0));
}
