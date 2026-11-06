struct Ent_00130AE0 {
    char m_name[0x18];
    void* m_obj;
};

extern Ent_00130AE0 D_003BE920[];
extern char D_003BEAE0[];
extern "C" int func_00331950(const char* a, const char* b);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_00130F30(void* list, unsigned int* crc);
extern "C" void func_0014A970(void* obj);

extern "C" void func_00130AE0(const char* name)
{
    for (int i = 0; i < 16; i++) {
        if (!func_00331950(D_003BE920[i].m_name, name)) {
            unsigned int crc = func_001F0D78(name);
            func_00130F30(D_003BEAE0, &crc);
            func_0014A970(D_003BE920[i].m_obj);
            D_003BE920[i].m_obj = 0;
            return;
        }
    }
}
