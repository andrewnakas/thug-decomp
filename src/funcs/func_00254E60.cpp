struct Array_00254E60 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Ent_00254E60 {
    int m0;
    int m4;
    int m8;
};

struct Mgr_00254E60 {
    char pad0[0x54];
    Ent_00254E60 m54[2];
};

extern char D_00375270[];
extern char D_00375280[];
extern char D_00390878[];
extern Mgr_00254E60* D_00390828;
extern "C" bool func_001E8A80(void* params, int i, Array_00254E60** out, int required);
extern "C" unsigned int func_001E9300(Array_00254E60* a, int i);
extern "C" unsigned int func_001F0D78(char* s);

bool Cmd_00254E60(void* params, void* script)
{
    Array_00254E60* arr;
    func_001E8A80(params, 0, &arr, 1);
    Ent_00254E60* e = D_00390828->m54;
    for (int i = 0; i < 2; i++, e++) {
        unsigned int v = func_001E9300(arr, i);
        int m = 0;
        if (v != func_001F0D78(D_00375270)) {
            if (v == func_001F0D78(D_00390878)) {
                m = 1;
            } else if (v == func_001F0D78(D_00375280)) {
                m = 2;
            }
        }
        e->m0 = m;
    }
    return true;
}
