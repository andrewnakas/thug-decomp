struct Entry_002966C0 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[2];
    int m2A8;
    char pad3[0x350 - 0x2AC];
};
struct Obj_002966C0;
extern "C" void func_00296660(Obj_002966C0* self);
extern "C" int func_00291EC0();
extern "C" int func_00294888(Entry_002966C0* e);
extern "C" void func_00292630(Entry_002966C0* e);
extern "C" void func_002959D8(Obj_002966C0* self);

struct Obj_002966C0 {
    char pad0[0x20];
    Entry_002966C0 m20[50];
    Entry_002966C0* mA5C0;
    void Add();
};

void Obj_002966C0::Add()
{
    func_00296660(this);
    int idx = 0;
    int key = func_00291EC0();
    int unique;
    do {
        unique = 1;
        int i = 0;
        Entry_002966C0* e = m20;
        do {
            if (e->m2A5 && func_00294888(e) && e->m0 == key && e->m2A8 == idx) {
                idx++;
                unique = 0;
                break;
            }
            i++;
            e++;
        } while (i < 50);
    } while (!unique);
    for (int i = 0; i < 50; i++) {
        if (!m20[i].m2A5) {
            mA5C0 = &m20[i];
            func_00292630(&m20[i]);
            mA5C0->m2A5 = 1;
            mA5C0->m0 = key;
            mA5C0->m2A8 = idx;
            func_002959D8(this);
            return;
        }
    }
}
