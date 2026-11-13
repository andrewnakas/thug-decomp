/* fuzzy: 82.6 */
/* sym: _vt$13Node_0022F500 = 0x00373000 */
/* sym: _vt$14Score_0022F500 = 0x00372FE8 */
/* sym: _vt$13Head_0022F500 = 0x00372F70 */
extern char D_00371C78[];
extern char D_00372F58[];
extern char D_00372DD8[];
extern char D_00372DE8[];
extern char D_00372DF8[];
extern char D_00372E08[];
extern char D_00372E18[];
extern char D_00372E28[];
extern char D_00372E40[];
extern char D_00372E58[];
extern char D_00372E68[];
extern char D_00372E80[];
extern char D_00372E98[];
extern char D_00372EA8[];
extern char D_0038FC18[];
extern char D_0038FCD8[];
extern char D_0038FCE0[];
extern char D_0038FCE8[];
extern char D_0038FCF0[];
extern char D_0038FCF8[];
extern char D_0038FD00[];
extern char D_0038FD08[];
extern char D_0038FD10[];
extern char D_0038FD18[];

struct Heap_0022F500 {
    char pad[0xE4];
    void* m_E4;
};

extern Heap_0022F500* D_00388A70;
extern void* D_0038FC78;
extern void* D_00392068;

extern "C" void* func_001046B0(int size);
extern "C" void func_0010A950(Heap_0022F500* heap, void* a);
extern "C" void func_0010A9B0(Heap_0022F500* heap);
extern "C" void* func_001190D0(int size);
extern "C" char* func_001E54B8(char* key, int a);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7138(void* params, char* name, char* value);
extern "C" void func_001E7360(void* params, int name, unsigned int value);
extern "C" void func_001E73C8(void* params, char* name, unsigned int value);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_001F0370(char* script, void* params, int b, int c);
extern "C" char* func_00206A08(void* skater);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" int func_0024F590(void* p);
extern "C" unsigned int func_0024F938(void* p);
extern "C" int func_002A1DA8(void* net, int team);
extern "C" int func_002B0FB8(void* net, int team);
extern "C" int func_002B1FC8(void* player);
extern "C" int func_002B1108(void* net, int id);
extern "C" void* func_00240850();
extern "C" int func_0023DB90(void* p, int id);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Skater_0022F500 {
    char pad[0x18];
    int m_id;
};

struct Player_0022F500 {
    char pad0[0x18];
    Skater_0022F500* m_skater;
    char pad1C[0x30 - 0x1C];
    int m_team;
    char m_name[0x20];
};

struct PlayerIt_0022F500 {
    int m0;
    int m4;
    void* vt;
    PlayerIt_0022F500() { vt = D_00371C78; m4 = 0; }
    ~PlayerIt_0022F500() { vt = D_00371C78; }
};

extern "C" Player_0022F500* func_002A53F8(void* net, PlayerIt_0022F500* it, int a);
extern "C" Player_0022F500* func_002A5490(void* net, PlayerIt_0022F500* it, int a);

struct Node_0022F500 {
    int m0;
    void* data;
    int key;
    Node_0022F500* next;
    Node_0022F500* prev;
    Node_0022F500(void* d)
    {
        data = d;
        key = 0;
        next = this;
        prev = this;
    }
    virtual ~Node_0022F500()
    {
        prev->next = next;
        next->prev = prev;
        next = this;
        prev = this;
    }
    virtual void Key();
    void* Data() { return data; }
    Node_0022F500* Valid() { return (int)data != -1 ? this : 0; }
    void InsertBefore(Node_0022F500* n)
    {
        n->prev = prev;
        n->next = this;
        prev->next = n;
        prev = n;
    }
};

struct Score_0022F500 : Node_0022F500 {
    char m_name[0x20];
    int m_king;
    int m_hasFlags;
    int m_flags;
    int m_color;
    int m_score;
    int m_team;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Score_0022F500() : Node_0022F500(this) {}
    void Key();
};

struct Head_0022F500 : Node_0022F500 {
    Head_0022F500() : Node_0022F500((void*)-1) {}
    void Key();
    void InsertSorted(Score_0022F500* s)
    {
        for (Node_0022F500* n = next->Valid(); n; n = n->next->Valid()) {
            if (s->key >= n->key) {
                n->InsertBefore(s);
                return;
            }
        }
        InsertBefore(s);
    }
};

struct ListIt_0022F500 {
    int m0;
    Node_0022F500* cur;
    void* vt;
    ListIt_0022F500() { cur = 0; vt = D_00372F58; }
    ~ListIt_0022F500() { vt = D_00372F58; }
    Score_0022F500* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return (Score_0022F500*)cur->Data();
    }
    Score_0022F500* First(Node_0022F500* h)
    {
        cur = h;
        return Next();
    }
};

static inline void* NewParams_0022F500()
{
    return func_001E6978(func_001190D0(8));
}

static inline void FreeParams_0022F500(void* params)
{
    if (params)
        func_001E6AE8(params, 3);
}

#define TIMED_0022F500(game) \
    (func_0024F938(func_0022E358(game)) == func_001F0D78(D_0038FCF0) || \
     func_0024F938(func_0022E358(game)) == func_001F0D78(D_0038FCF8))

bool func_0022F500()
{
    PlayerIt_0022F500 pit;
    Head_0022F500 list;
    ListIt_0022F500 lit;
    char buf[0x40];
    char name[0x80];
    void* game = D_0038FC78;
    void* net = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m_E4);
    bool special = func_0024F938(func_0022E358(game)) == func_001F0D78(D_00372DD8);
    if (func_0024F540(func_0022E358(game))) {
        for (int i = 0; i < func_0024F590(func_0022E358(game)); i++) {
            if (!func_002A1DA8(net, i))
                continue;
            Score_0022F500* t = new Score_0022F500;
            t->m_king = 0;
            t->m_team = i;
            t->m_color = i + 2;
            t->m_score = func_002B0FB8(net, i);
            func_003331D0(buf, D_00372DE8, i + 1);
            func_003331D0(t->m_name, D_00372DF8, t->m_color, func_001E54B8(buf, 0), func_001E54B8(D_00372E08, 0));
            t->key = func_002B0FB8(net, i);
            list.InsertSorted(t);
        }
        int line = 0;
        Score_0022F500* t = lit.First(&list);
        while (t) {
            Score_0022F500* next = lit.Next();
            char* teamName = t->m_name;
            for (Player_0022F500* p = func_002A53F8(net, &pit, 0); p; p = func_002A5490(net, &pit, 0)) {
                if (p->m_team != t->m_team)
                    continue;
                unsigned int score;
                if (special)
                    score = func_0023DB90(func_00240850(), p->m_skater->m_id);
                else
                    score = func_002B1108(net, p->m_skater->m_id);
                if (func_002B1FC8(p))
                    func_003331D0(name, D_00372E18, t->m_color, p->m_name);
                else
                    func_003331D0(name, D_0038FCD8, t->m_color, p->m_name);
                void* params = NewParams_0022F500();
                func_001E7138(params, D_0038FCE0, name);
                func_001E73C8(params, D_0038FCE8, func_001F0D78(D_00372E28));
                func_001F0370(D_00372E40, params, 0, 0);
                FreeParams_0022F500(params);
                params = NewParams_0022F500();
                if (TIMED_0022F500(game)) {
                    unsigned int secs = score / 1000;
                    func_003331D0(buf, D_00372E58, secs / 60, secs % 60);
                } else
                    func_003331D0(buf, D_0038FC18, score);
                func_001E7138(params, D_0038FCE0, buf);
                func_001E73C8(params, D_0038FD00, func_001F0D78(D_0038FD08));
                func_001E73C8(params, D_0038FD10, line + 0x39447);
                func_001E73C8(params, D_0038FCE8, func_001F0D78(D_00372E68));
                func_001F0370(D_00372E80, params, 0, 0);
                FreeParams_0022F500(params);
                line++;
            }
            void* params = NewParams_0022F500();
            func_001E7138(params, D_0038FCE0, teamName);
            func_001E7360(params, 0, func_001F0D78(D_00372E98));
            func_001E73C8(params, D_0038FCE8, func_001F0D78(D_00372E28));
            func_001F0370(D_00372E40, params, 0, 0);
            FreeParams_0022F500(params);
            params = NewParams_0022F500();
            if (TIMED_0022F500(game)) {
                unsigned int secs = (unsigned int)t->key / 1000;
                func_003331D0(buf, D_00372EA8, t->m_color, secs / 60, secs % 60);
            } else
                func_003331D0(buf, D_0038FD18, t->m_color, t->key);
            func_001E7138(params, D_0038FCE0, buf);
            func_001E73C8(params, D_0038FD10, line + 0x39447);
            func_001E73C8(params, D_0038FD00, func_001F0D78(D_0038FD08));
            func_001E7360(params, 0, func_001F0D78(D_00372E98));
            func_001E73C8(params, D_0038FCE8, func_001F0D78(D_00372E68));
            func_001F0370(D_00372E80, params, 0, 0);
            FreeParams_0022F500(params);
            delete t;
            t = next;
            line++;
        }
    } else {
        for (Player_0022F500* p = func_002A53F8(net, &pit, 0); p; p = func_002A5490(net, &pit, 0)) {
            int score;
            if (special)
                score = func_0023DB90(func_00240850(), p->m_skater->m_id);
            else
                score = func_002B1108(net, p->m_skater->m_id);
            Score_0022F500* s = new Score_0022F500;
            func_00331A9C(s->m_name, func_00206A08(p->m_skater));
            s->key = score;
            list.InsertSorted(s);
        }
        int line = 0;
        Score_0022F500* s = lit.First(&list);
        while (s) {
            Score_0022F500* next = lit.Next();
            void* params = NewParams_0022F500();
            func_001E7138(params, D_0038FCE0, s->m_name);
            func_001E73C8(params, D_0038FCE8, func_001F0D78(D_00372E28));
            func_001F0370(D_00372E40, params, 0, 0);
            FreeParams_0022F500(params);
            params = NewParams_0022F500();
            if (TIMED_0022F500(game)) {
                unsigned int secs = (unsigned int)s->key / 1000;
                func_003331D0(buf, D_00372E58, secs / 60, secs % 60);
            } else
                func_003331D0(buf, D_0038FC18, s->key);
            func_001E7138(params, D_0038FCE0, buf);
            func_001E73C8(params, D_0038FD10, line + 0x39447);
            func_001E73C8(params, D_0038FD00, func_001F0D78(D_0038FD08));
            func_001E73C8(params, D_0038FCE8, func_001F0D78(D_00372E68));
            func_001F0370(D_00372E80, params, 0, 0);
            FreeParams_0022F500(params);
            delete s;
            s = next;
            line++;
        }
    }
    func_0010A9B0(D_00388A70);
    return true;
}
