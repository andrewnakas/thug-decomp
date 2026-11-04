extern "C" void func_0013C9D0(void* p);

struct Obj135558 {
    int m_pad[8];
    void* m20;
    void Release();
};

void Obj135558::Release()
{
    if (m20) {
        func_0013C9D0(m20);
    }
}
