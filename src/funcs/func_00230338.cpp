struct Skater_00230338 {
    char m_pad[0x31C];
    int m_local;
};

struct Game_00230338 {
    char m_pad[0x444];
    void* m_handlers[8];
};

extern char D_00372EB8[];
extern char D_00372EF8[];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" Skater_00230338* func_0022DE70(Game_00230338* self, int index);
extern "C" int func_002041F8(Skater_00230338* skater);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001BBA98(void* comp, void* handler);
extern "C" void* func_00203EE0(Skater_00230338* skater);

void func_00230338(Game_00230338* self)
{
    func_00103F28(D_00372EB8);
    for (int i = 0; i < 8; i++) {
        Skater_00230338* skater = func_0022DE70(self, i);
        if (skater && skater->m_local) {
            func_00103F28(D_00372EF8);
            int id = func_002041F8(skater);
            func_001BBA98(func_00185578(skater, 0x27D7CD28), self->m_handlers[id]);
            void* obj = func_00203EE0(skater);
            if (obj) {
                func_001BBA98(func_00185578(obj, 0x27D7CD28), self->m_handlers[id]);
            }
        }
    }
}
