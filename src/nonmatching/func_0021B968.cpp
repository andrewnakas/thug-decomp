/* fuzzy: 88.0 */
/* blocked: the game's switch tree has root 0xA71394A2 with {0xE47F1B79, 0xEF59C100} on the right: balance_case_nodes only picks that root with a 4th case below 0xA71394A2 whose body equals default (its compare is then deleted by jump). That value is not pinned by the binary (any checksum below 0xA71394A2 fits), so per the case-value ruling it cannot be written. */
struct Array_0021B968 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" Array_0021B968* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(Array_0021B968* arr, unsigned int i);
extern "C" bool func_0022EEC0(void* game, void* node);
extern "C" bool func_0022EF38(void* game);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8870(void* s, unsigned int name, const char** out, int required);
extern "C" bool func_001E8708(void* s, unsigned int name);
extern "C" int func_00336228(const char* a, const char* b);
extern "C" void* func_00104008(void* str);
extern "C" void func_00131688(void* out, const char* name, const char* ext);
extern "C" void* func_00104170(void* str, void* other);
extern "C" void func_001040A8(void* str, int flags);
extern "C" const char* func_001041B8(void* str);
extern "C" void* func_00132100();
extern "C" void func_00132120(void* p);
extern "C" void func_0013D2F0(void* p, const char* name, int a, int b, int c, int d, int e);

extern void* D_0038FC78;
extern char D_00371520[];
extern char D_0038F7D8[];
extern char D_0038F7E0[];

bool Cmd_0021B968(void* params, void* script)
{
    char str[16];
    char tmp[16];
    func_0010BFC0(D_00371520);
    Array_0021B968* nodes = func_001E55B8(0xC472ECC5, 0);
    for (unsigned int i = 0; i < nodes->m_size; i++) {
        void* node = func_001E9378(nodes, i);
        if (func_0022EEC0(D_0038FC78, node)) {
            continue;
        }
        unsigned int type = 0;
        func_001E8398(node, 0x12B4E660, &type, 0);
        unsigned int skater = 0;
        func_001E8398(node, 0x7321A8D6, &skater, 0);
        if (!func_0022EF38(D_0038FC78)) {
            if (skater == 0xBEBB41F0 || skater == 0x836284A5 || skater == 0xC3EBE05E || skater == 0x4F8FF239
                || skater == 0x8CCA938A || skater == 0x041E5BCF || skater == 0xC2AF1EB1 || skater == 0xED3AD7FE) {
                continue;
            }
        }
        switch (type) {
        case 0xA71394A2:
            continue;
        case 0xE47F1B79:
        case 0xEF59C100: {
            const char* model = 0;
            if (func_001E8870(node, 0x286A8D26, &model, 0)) {
                const char* name;
                func_001E8870(node, 0x286A8D26, &name, 1);
                if (func_00336228(D_0038F7D8, name)) {
                    func_00104008(str);
                    func_00131688(tmp, name, D_0038F7E0);
                    func_00104170(str, tmp);
                    func_001040A8(tmp, 2);
                    void* p = func_00132100();
                    bool flag = func_001E8708(node, 0x6C37FDC7);
                    func_0013D2F0(p, func_001041B8(str), 0, 1, 0, flag, 0);
                    func_00132120(p);
                    func_001040A8(str, 2);
                }
            }
            break;
        }
        default:
            break;
        }
    }
    func_0010BFC8();
    return true;
}
