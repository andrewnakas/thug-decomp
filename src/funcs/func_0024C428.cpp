struct Slot_0024C428 {
    int m0;
    int m4;
    int m8;
    int m_id;
    int m_done;
    int m14;
    int m18;
    int m1C;
    int m20;
};

struct Goal_0024C428 {
    char pad[0x20];
    void* m_params;
    char pad24[0x80];
    Slot_0024C428 m_slots[30];
    int m4DC;
    int m4E0;
    int m4E4[30];
};

extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" bool func_0024E048(Goal_0024C428* self);

void func_0024C428(Goal_0024C428* self)
{
    int time;

    self->m4DC = 0;
    self->m4E0 = 0;
    func_001E7DE8(self->m_params, 0xDED8540A, &time, 1);
    func_001E7200(self->m_params, 0x648D8D2A, time);
    func_001E7200(self->m_params, 0x8D958F01, 0);
    if (func_0024E048(self))
        self->m4E0 = 0;
    else
        self->m4E0 = time - 200;
    for (int i = 0; i < 30; i++) {
        self->m_slots[i].m_done = 1;
        self->m_slots[i].m0 = 0;
        self->m_slots[i].m4 = 0;
        self->m_slots[i].m8 = 0;
        self->m_slots[i].m1C = 0;
        self->m_slots[i].m20 = 1;
        self->m_slots[i].m14 = 0;
        self->m4E4[i] = 0;
    }
}
