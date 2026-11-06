struct Slot_00111F70 {
    int m0;
    volatile int m_used;
    void* m_owner;
};

extern Slot_00111F70 D_00464DB8[];

extern "C" void func_00111F70(void* owner)
{
    for (int i = 0; i < 2; i++) {
        if (D_00464DB8[i].m_owner == owner) {
            D_00464DB8[i].m_used = 0;
            return;
        }
    }
}
