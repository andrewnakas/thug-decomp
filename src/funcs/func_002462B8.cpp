struct Item_002462B8 {
    char pad[0x78];
    int m_78;
    int m_7C;
    int Get();
};

extern void* D_0038FC78;
extern void* D_00392068;
extern "C" bool func_002A19A8(void* a);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* a);

int Item_002462B8::Get()
{
    void* mgr = D_0038FC78;
    if ((func_002A19A8(D_00392068) && func_0024F938(func_0022E358(mgr)) == 0xEC200EAA) || func_0024F938(func_0022E358(mgr)) == 0x1C471C60) {
        return m_7C;
    }
    return m_78;
}
