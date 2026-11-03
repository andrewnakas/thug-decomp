/* cflags: -fopt-stack */
extern "C" void func_001D4880(void* self);

struct Holder {
    char pad[0x20];
    char m_data[0x20];
    int m40;
    int m44;
    void* Get();
};

void* Holder::Get()
{
    if (m40) {
        func_001D4880(this);
        m40 = 0;
    }
    if (!m44) {
        return 0;
    }
    return m_data;
}
