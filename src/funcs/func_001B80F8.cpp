extern "C" void func_00114DD8(void* p);

struct Obj1B80F8 {
    int m_pad[8];
    void* m20;
    void Release();
};

void Obj1B80F8::Release()
{
    if (m20) {
        func_00114DD8(m20);
    }
}
