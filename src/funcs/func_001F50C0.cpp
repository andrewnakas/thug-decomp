struct Slot_001F50C0 {
    int m_state;
    char m_pad4[0x4CE40 - 4];
};

extern "C" void func_00320438();
extern "C" void func_00320490();

struct Ring_001F50C0 {
    int m0;
    Slot_001F50C0* m_slots;
    volatile int m_write;
    volatile int m_count;
    int m_size;
    void Push();
};

void Ring_001F50C0::Push()
{
    func_00320438();
    m_slots[m_write].m_state = 2;
    m_count++;
    m_write = (m_write + 1) % m_size;
    func_00320490();
}
