extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern void* D_0038E0A0;

struct Entry_001A3060 {
    unsigned int m_id;
    int m_pad[11];
};

struct C_001A3060 {
    int m_pad[15];
    Entry_001A3060 m_entries[2];
    int Call(unsigned int name, void* params, void* script);
};

extern "C" void func_001DCF30(void* mgr, C_001A3060* self, unsigned int id);
extern "C" void func_001A3850(C_001A3060* self, void* params, void* script);
extern "C" void func_001A3208(C_001A3060* self, void* params);
extern "C" void func_001A3170(C_001A3060* self, void* params);

int C_001A3060::Call(unsigned int name, void* params, void* script)
{
    switch (name) {
    case 0xAFA20E18:
        func_001A3208(this, params);
        return 1;
    case 0x3E5E8023:
        func_001A3850(this, params, script);
        return 1;
    case 0x4E4132D6: {
        unsigned int id = 0;
        func_001E8398(params, 0, &id, 0);
        func_001DCF30(D_0038E0A0, this, id);
        for (int i = 0; i < 2; i++) {
            if (m_entries[i].m_id == id) m_entries[i].m_id = 0;
        }
        return 1;
    }
    case 0xE8347171:
        func_001A3170(this, params);
        return 1;
    }
    return 2;
}
