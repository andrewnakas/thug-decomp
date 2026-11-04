struct Slot_002156C0 {
    int m_active;
    int pad[3];
};

struct Game_002156C0 {
    char pad0[0x3C8];
    Slot_002156C0 m_slots[2];
};

extern Game_002156C0* D_0038FC78;
extern void* D_0038C3C0;
extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int a);
extern "C" void func_001833B8(void* p, int i);
extern "C" void func_00183380(void* p, int i);

bool Cmd_002156C0(void* params, void* script)
{
    int on = 1;
    func_001E7DE8(params, 0, &on, 0);
    void* mgr = D_0038C3C0;
    Slot_002156C0* s = D_0038FC78->m_slots;
    for (int i = 0; i < 2; i++, s++) {
        if (s->m_active) {
            if (on)
                func_001833B8(mgr, i);
            else
                func_00183380(mgr, i);
        }
    }
    return true;
}
