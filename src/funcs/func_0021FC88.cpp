extern char D_003717B0[];
extern char D_00371620[];
extern char D_00371650[];
extern char D_0038F818[];
extern char D_003717C0[];
extern char D_00371660[];
extern char D_003717D0[];
extern char D_00371640[];
extern char D_003717E0[];

struct Mgr_0021FC88 {
    char m_pad[0x398];
    void* m398;
};

extern Mgr_0021FC88* D_0038FC78;

extern "C" void* func_0022E058(Mgr_0021FC88* self);
extern "C" void* func_0022E358(Mgr_0021FC88* self);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void* func_00202EF8(void* self, unsigned int key);
extern "C" int func_00202FC8(void* self, unsigned int key, unsigned int def);
extern "C" char* func_00202F78(void* self, unsigned int key, unsigned int def);
extern "C" bool func_001E8A50(void* self, const char* name, int* out, int assert_);
extern "C" void func_0024FA70(void* self, int type);
extern "C" bool func_0024F8D8(void* self, const char* name);
extern "C" char* func_00104028(char* dst, const char* src);
extern "C" void func_002525A8(void* self, char* str);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7A68(void* self, unsigned int key, int type, int value);
extern "C" void func_0024FBD8(void* self, void* params);
extern "C" void func_0022D728(Mgr_0021FC88* self, int value);
extern "C" void func_001E6AE8(void* self, int flags);

bool func_0021FC88()
{
    char buf[16];
    int checksum;
    void* prefs = func_0022E058(D_0038FC78);
    func_001E8A50(func_00202EF8(prefs, func_001F0D78(D_003717B0)), D_00371620, &checksum, 1);
    func_0024FA70(func_0022E358(D_0038FC78), checksum);
    func_00202FC8(prefs, func_001F0D78(D_00371650), func_001F0D78(D_0038F818));
    if (func_0024F8D8(func_0022E358(D_0038FC78), D_003717C0)) {
        int limit = func_00202FC8(prefs, func_001F0D78(D_00371660), func_001F0D78(D_0038F818));
        func_00104028(buf, func_00202F78(prefs, func_001F0D78(D_003717D0), func_001F0D78(D_00371640)));
        func_002525A8(D_0038FC78->m398, buf);
        void* params = func_001E6978(func_001190D0(8));
        func_001E7A68(params, func_001F0D78(D_003717E0), 1, limit);
        func_0024FBD8(func_0022E358(D_0038FC78), params);
        func_0022D728(D_0038FC78, limit);
        if (params) {
            func_001E6AE8(params, 3);
        }
    }
    return true;
}
