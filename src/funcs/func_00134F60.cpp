extern "C" void func_0013C478(void* p);

struct Obj134F60 {
    int m_pad[8];
    void* m20;
    void Release();
};

void Obj134F60::Release()
{
    if (m20) {
        func_0013C478(m20);
    }
}
