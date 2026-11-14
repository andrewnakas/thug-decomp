struct Slot_00111EE8 {
    unsigned int m_size;
    volatile int m_used; // volatile as in the matched siblings func_00111F70 / func_00111FB8
    void* m_mem;
};

extern Slot_00111EE8 D_00464DB8[2];
extern "C" void func_00320438();
extern "C" void func_00320490();

extern "C" void* func_00111EE8(unsigned int size)
{
    void* p = 0;
    func_00320438();
    for (int i = 0; i < 2; i++) {
        if (D_00464DB8[i].m_size >= size && D_00464DB8[i].m_used == 0) {
            p = D_00464DB8[i].m_mem;
            D_00464DB8[i].m_used = 1;
        }
    }
    func_00320490();
    return p;
}
