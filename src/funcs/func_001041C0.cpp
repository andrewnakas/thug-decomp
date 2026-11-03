extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);

struct Str_001041C0 {
    int m0;
    int m4;
    char* m_buf;
    int m_size;
    void Set(const char* s, int start, int end);
};

void Str_001041C0::Set(const char* s, int start, int end)
{
    if (s != 0 && end >= start) {
        if (s[start] == 0) {
            if (m_buf) {
                func_0010A8D8(D_00388A70, m_buf);
            }
            m_buf = (char*)func_0010A638(D_00388A70, 1, 1, 0);
            m_buf[0] = 0;
            m_size = 2;
        } else {
            int n = end - start + 2;
            if (n <= 3) {
                n = 4;
            }
            if (m_buf) {
                if (m_size < n) {
                    func_0010A8D8(D_00388A70, m_buf);
                    m_buf = 0;
                }
            }
            if (m_buf == 0) {
                m_size = n;
                m_buf = (char*)func_0010A638(D_00388A70, n, 1, 0);
            }
            int j = 0;
            for (int i = start; i <= end; i++) {
                m_buf[j++] = s[i];
            }
            m_buf[j] = 0;
        }
    } else if (m_buf) {
        func_0010A8D8(D_00388A70, m_buf);
        m_buf = 0;
    }
}
