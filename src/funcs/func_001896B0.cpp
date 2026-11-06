extern char D_00361D80[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_0018A8C0(void* table, unsigned int* key, int a);

class Obj_001896B0 {
public:
    int m0;
    int m_counter;
    void* m_table;

    unsigned int MakeUniqueName();
};

unsigned int Obj_001896B0::MakeUniqueName()
{
    char buf[0x40];
    unsigned int crc;
    do {
        func_003331D0(buf, D_00361D80, m_counter++);
        if (m_counter > 999999) {
            m_counter = 0;
        }
        crc = func_001F0D78(buf);
    } while (func_0018A8C0(m_table, &crc, 1));
    return crc;
}
