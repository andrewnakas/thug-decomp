extern "C" void func_00134F60(void* p);
extern "C" void func_00134FD8(void* p, unsigned int v);

struct Node_00299238 {
    char pad0[0x24];
    int m24;
    char pad28[4];
    Node_00299238* m2C;
    Node_00299238* m30;
    void* m34;
    void* m38;
    void Stop();
};

void Node_00299238::Stop()
{
    if (!m24) return;
    if (m38) {
        func_00134F60(m38);
        func_00134FD8(m38, 0xFFFFFFFF);
    }
    if (m34) {
        func_00134F60(m34);
        func_00134FD8(m34, 0xFFFFFFFF);
    }
    if (m30 && m30->m34) {
        func_00134F60(m30->m34);
        func_00134FD8(m30->m34, 0xFFFFFFFF);
    }
    if (m2C && !m2C->m2C && m2C->m38) {
        func_00134F60(m2C->m38);
        func_00134FD8(m2C->m38, 0xFFFFFFFF);
    }
    if (m30 && !m30->m30 && m30->m38) {
        func_00134F60(m30->m38);
        func_00134FD8(m30->m38, 0xFFFFFFFF);
    }
    m24 = 0;
}
