struct Event_002C6C18 {
    unsigned int m0;
    int m4;
    unsigned int m8;
};

struct Obj_002C6C18 {
    char pad0[0x60];
    unsigned int m60;
    char pad64[0x3C];
    void* mA0;
    char padA4[0x8];
    unsigned int mAC;
    int mB0;
    void OnEvent(Event_002C6C18* e);
};

void Obj_002C6C18::OnEvent(Event_002C6C18* e)
{
    if (mAC != 0x7ECA21E5) return;
    if (!mA0) return;
    if (mB0) return;
    unsigned int id = e->m8;
    unsigned int key = e->m0;
    if (id != 0x56A1EAE3) return;
    switch (key) {
    case 0x30A4F836: m60 |= 0x200; break;
    case 0x0FD1AC26: m60 |= 0x400; break;
    case 0x6949DB75: m60 |= 0x8; break;
    case 0x05DDD87C: m60 |= 0x10; break;
    }
}
