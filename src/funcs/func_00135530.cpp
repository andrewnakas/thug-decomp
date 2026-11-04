extern "C" void func_0013C9A8(void* p);

struct Obj135530 {
    int m_pad[8];
    void* m20;
    void Release();
};

void Obj135530::Release()
{
    if (m20) {
        func_0013C9A8(m20);
    }
}
