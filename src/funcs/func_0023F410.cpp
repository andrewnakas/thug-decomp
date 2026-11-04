struct GapList_0023F410 {
    int m0;
    unsigned int m_gaps[512];
    int m_numGaps;
};

struct Comp_0023F410 {
    char m_pad[0x1404];
    GapList_0023F410 m_gapList;
};

struct Info_0023F410 {
    char m_pad[0x18];
    int m18;
};

extern void* D_0038FC78;

extern "C" void* func_0022DD38(void* self);
extern "C" Info_0023F410* func_00203360(void* skater);
extern "C" Comp_0023F410* func_00185578(void* self, unsigned int id);
extern "C" void func_0023D230(void* self, unsigned int gap, int value);

void func_0023F410(void* self)
{
    void* skater = func_0022DD38(D_0038FC78);
    int value = func_00203360(skater)->m18;
    GapList_0023F410 list = func_00185578(skater, 0x270F56E1)->m_gapList;
    int n = list.m_numGaps;
    if (n > 512) {
        n = 512;
    }
    for (int i = 0; i < n; i++) {
        func_0023D230(self, list.m_gaps[i], value);
    }
}
