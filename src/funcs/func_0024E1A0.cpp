extern char D_00374520[];
extern char D_003903C8[];
extern char D_003903D0[];
extern char D_00374530[];

struct Array_0024E1A0 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Goal_0024E1A0 {
    char m_pad[0x20];
    void* m_params;
    void* m_flags;
};

struct Score_0024E1A0 {
    char m_pad[0x18];
    int m_score;
};

extern void* D_0038FC78;

extern "C" bool func_001E82B8(void* params, const char* name, Array_0024E1A0** out, int assert_);
extern "C" void* func_001E9378(Array_0024E1A0* self, int index);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" void* func_0022DD38(void* self);
extern "C" Score_0024E1A0* func_00203360(void* skater);
extern "C" unsigned int func_00246258(Goal_0024E1A0* goal);
extern "C" void* func_00240850();
extern "C" void func_0023CF38(void* self, unsigned int id, unsigned int next, int a);
extern "C" void func_0023D198(void* self, unsigned int id);
extern "C" void func_0023BE68(void* self, unsigned int id, unsigned int next);
extern "C" void func_001E7268(void* params, const char* name, int value);

void func_0024E1A0(Goal_0024E1A0* self)
{
    Array_0024E1A0* spots;
    func_001E82B8(self->m_params, D_00374520, &spots, 1);
    int n = spots->m_size;
    unsigned int next;
    int score;
    int i;
    for (i = 0; i < n; i++) {
        void* spot = func_001E9378(spots, i);
        func_001E84E8(spot, D_003903C8, &next, 1);
        int done;
        func_001E7DE8(self->m_flags, next, &done, 1);
        if (!done) {
            if (!func_001E7E58(spot, D_003903D0, &score, 0)) {
                func_001E7E58(self->m_params, D_003903D0, &score, 1);
            }
            break;
        }
    }
    if (i != n) {
        int current = func_00203360(func_0022DD38(D_0038FC78))->m_score;
        if (current > 0) {
            unsigned int id = func_00246258(self);
            void* mgr = func_00240850();
            unsigned int target = next;
            if (score < current) {
                func_0023CF38(mgr, id, target, 1);
                func_0023D198(mgr, id);
            } else {
                func_0023BE68(mgr, id, target);
            }
        }
        func_001E7268(self->m_params, D_00374530, 0);
    }
}
