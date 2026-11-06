struct Item_002458C0 {
    char pad[0x84];
    int m_84;
    void Stop();
};

extern void* D_00392068;
extern "C" bool func_002A19A8(void* a);
extern "C" void func_00243FB0(Item_002458C0* self);
extern "C" int func_00248800(Item_002458C0* self, unsigned int name);

void Item_002458C0::Stop()
{
    if (m_84) {
        m_84 = 0;
        if (!func_002A19A8(D_00392068)) {
            func_00243FB0(this);
            func_00248800(this, 0x951B4F10);
        }
    }
}
