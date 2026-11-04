struct Ent_00296968 {
    unsigned int m0;
    char pad4[0x2A5 - 4];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

extern "C" void func_002928C0(Ent_00296968* e);

struct Obj_00296968 {
    char pad[0x20];
    Ent_00296968 ents[50];
    void Refresh();
};

void Obj_00296968::Refresh()
{
    for (int i = 0; i < 50; i++) {
        Ent_00296968* e = &ents[i];
        if (e->m2A5 && e->m0 == 0xE8B4B836)
            func_002928C0(e);
    }
}
