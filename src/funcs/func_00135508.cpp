extern "C" void func_0013C980(void* p);

struct Obj135508 {
    int m_pad[8];
    void* m20;
    void Release();
};

void Obj135508::Release()
{
    if (m20) {
        func_0013C980(m20);
    }
}
