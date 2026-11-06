struct Data_00122618 {
    char pad0[0x20];
    int m_on;
    float m_x;
    float m_y;
    float m_z;
};

extern "C" void func_001388C8(void* self, int a, float x, float y, float z);

extern "C" int func_00122618(void* self, Data_00122618* d)
{
    if (d->m_on) {
        func_001388C8(self, 0, d->m_x, d->m_y, d->m_z);
        return 1;
    }
    return 0;
}
