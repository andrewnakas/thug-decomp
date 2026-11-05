extern char D_0037C690[];
extern char D_0037C2D8[];
extern char D_0037C2E8[];
extern char D_0037C2F8[];
extern char D_0037C308[];
extern char D_0037C318[];
extern char D_0037C330[];
extern char D_0037C348[];
extern char D_00392D90[];
extern char D_00392D98[];
extern char D_00392DA0[];
extern char D_00392DA8[];
extern char D_00392DB0[];
extern char D_00392DB8[];

struct Ent_002D69A8;

struct Node_002D69A8 {
    int m0;
    Ent_002D69A8* m4;
    int m8;
    Node_002D69A8* mC;
    Node_002D69A8* m10;
    Ent_002D69A8* GetData() { return m4; }
    Node_002D69A8* Valid() { return (int)m4 != -1 ? this : 0; }
    void Append(Node_002D69A8* s)
    {
        s->m10 = m10;
        s->mC = this;
        m10->mC = s;
        m10 = s;
    }
};

struct Ent_002D69A8 : Node_002D69A8 {
    char pad14[4];
    char m18[0x20];
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    char m50[0x100];
    char m150[0x100];
};

struct It_002D69A8 {
    int m0;
    Node_002D69A8* cur;
    void* vt;
    It_002D69A8() { vt = D_0037C690; cur = 0; }
    ~It_002D69A8() { vt = D_0037C690; }
    Ent_002D69A8* Next()
    {
        cur = cur->mC->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Ent_002D69A8* First(Node_002D69A8* h)
    {
        cur = h;
        return Next();
    }
};

struct Rec_002D69A8 {
    int id;
    int type;
    char name[0x100];
    char path[0x108];
};

struct Src_002D69A8 {
    int m0;
    int m4;
    int m8;
};

struct Owner_002D69A8 {
    char pad[0x14];
    Node_002D69A8 m14;
};

struct List_002D69A8 {
    char pad[0xC];
    int mC;
};

struct Pool_002D69A8 {
    char pad[0x108];
    int m108;
};

extern Pool_002D69A8* D_00388A70;
extern void* D_00392068;

extern "C" void* func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002E8C38(Owner_002D69A8* o, int v, Rec_002D69A8* r);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" char* func_003317AC(const char* s, int c);
extern "C" char* func_00336558(char* s, char* delim);
extern "C" int func_00334120(char* s);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void* func_002A6070(void* m);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" List_002D69A8* func_00202F28(void* goals, unsigned int name);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void* func_001E9378(List_002D69A8* a, int i);
extern "C" void func_001E6A00(void* d, void* s);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_002030B8(void* goals, unsigned int name, void* arr);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, const char* value);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void* func_001046B0(int size);
extern "C" Ent_002D69A8* func_002D88A8(void* p);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" bool func_001E7D18(void* params, char* name, char** out, int required);

void func_002D69A8(void* self, Src_002D69A8* src, Owner_002D69A8* owner)
{
    Rec_002D69A8 rec;
    It_002D69A8 it;
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_002E8C38(owner, src->m8, &rec);
    int found = 0;
    Ent_002D69A8* e;
    int i;
    for (e = it.First(&owner->m14); e; e = it.Next()) {
        if (e->m38 != rec.id)
            continue;
        e->m3C = rec.type;
        func_00331A9C(e->m150, rec.name);
        if (e->m3C == 2) {
            char* p = func_003317AC(rec.path, ':');
            p = func_003317AC(p + 1, ':');
            p = func_003317AC(p + 1, ':');
            func_00331A9C(e->m50, p + 1);
            e->m44 = func_00334120(func_00336558(rec.path, D_00392D90));
            e->m48 = func_00334120(func_00336558(0, D_00392D90));
            e->m4C = func_00334120(func_00336558(0, D_00392D90));
        } else {
            func_00331A9C(e->m50, rec.path);
        }
        char* label = e->m18;
        if (e->m40) {
            void* mgr = D_00392068;
            void* p = func_001E6978(func_001190D0(8));
            func_001E7138(p, D_0037C2D8, label);
            func_001F0370(D_0037C2E8, p, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
            e->m40 = 0;
            void* goals = func_002A6070(mgr);
            i = 0;
            List_002D69A8* list = func_00202F28(goals, func_001F0D78(D_0037C2F8));
            void* arr = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr, list->mC + 1, 10);
            for (; i < list->mC; i++) {
                void* s = func_001E9378(list, i);
                void* c = func_001E6978(func_001190D0(8));
                func_001E6A00(c, s);
                func_001E9170(arr, i, c);
            }
            void* c = func_001E6978(func_001190D0(8));
            func_001E7268(c, D_00392D98, e->m38);
            func_001E7138(c, D_00392DA0, label);
            func_001E9170(arr, i, c);
            func_002030B8(goals, func_001F0D78(D_0037C2F8), arr);
        }
        void* p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_00392DA8), 3, label);
        func_001E7A30(p, func_001F0D78(D_00392DB0), 3, e->m150);
        func_001E7A30(p, func_001F0D78(D_0037C308), 3, e->m50);
        func_001E7A68(p, func_001F0D78(D_00392DB8), 13, func_001F0D78(D_0037C318) + e->m38);
        func_001F0370(D_0037C330, p, 0, 0);
        if (p)
            func_001E6AE8(p, 3);
        found = 1;
        break;
    }
    if (!found) {
        void* goals = func_002A6070(D_00392068);
        e = func_002D88A8(func_001046B0(0x250));
        e->m38 = rec.id;
        e->m3C = rec.type;
        func_00331A9C(e->m150, rec.name);
        func_003331D0(e->m18, D_0037C348);
        if (e->m3C == 2) {
            char* p = func_003317AC(rec.path, ':');
            p = func_003317AC(p + 1, ':');
            p = func_003317AC(p + 1, ':');
            func_00331A9C(e->m50, p + 1);
            e->m44 = func_00334120(func_00336558(rec.path, D_00392D90));
            e->m48 = func_00334120(func_00336558(0, D_00392D90));
            e->m4C = func_00334120(func_00336558(0, D_00392D90));
        } else {
            func_00331A9C(e->m50, rec.path);
        }
        owner->m14.Append(e);
        List_002D69A8* list = func_00202F28(goals, func_001F0D78(D_0037C2F8));
        if (list) {
            for (i = 0; i < list->mC; i++) {
                void* s = func_001E9378(list, i);
                int id;
                func_001E7E58(s, D_00392D98, &id, 1);
                if (id == rec.id) {
                    char* str = 0;
                    func_001E7D18(s, D_00392DA0, &str, 1);
                    func_00331A9C(e->m18, str);
                }
            }
        }
    }
    func_0010A9B0(D_00388A70);
}
