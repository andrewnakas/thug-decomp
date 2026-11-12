/* fuzzy: 88.5 */
/* nonmatch func_002B11C8 (0xA10): fresh draft from the asm. Rebuilds the score list (teams or players, sorted by score when ranked) and sends one "update_score" per line. */
/* sym: _vt$13Node_002B11C8 = 0x00373000 */
/* sym: _vt$14Score_002B11C8 = 0x00372FE8 */
/* sym: _vt$13Head_002B11C8 = 0x00372F70 */
extern char D_00371C78[];
extern char D_00372F58[];
extern char D_003795A0[]; /* "clear_scores" */
extern char D_003795B0[];
extern char D_003795D0[];
extern char D_003795F0[];
extern char D_00379608[]; /* "update_score" */
extern char D_00392368[]; /* "> %s" */
extern char D_00392370[];
extern char D_00392378[];
extern char D_00392380[];
extern char D_00392388[];
extern char D_00392390[];
extern char D_00392398[];
extern unsigned int D_00392360;
extern void* D_00389A30;
extern void* D_0038FC78;

extern "C" void* func_001046B0(int size);
extern "C" unsigned int func_0010FC30();
extern "C" void* func_001190D0(int size);
extern "C" void func_00183CB8(void* p, void* pp);
extern "C" char* func_001E5488(unsigned int name, int a);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, char* v);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, unsigned int value);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" int func_0024F590(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_002A1DA8(void* net, int team);
extern "C" int func_002A25F0(void* net);
extern "C" int func_002B0FB8(void* net, int team);
extern "C" int func_002B1FC8(void* player);
extern "C" int func_002B2280(void* player);
extern "C" int func_002B22B8(void* player);
extern "C" int func_002B22C8(void* player);
extern "C" int func_002B2F30(void* player);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Skater_002B11C8 {
    char pad[0x18];
    int m_id;
};

struct Player_002B11C8 {
    char pad0[0x18];
    Skater_002B11C8* m_skater;
    char pad1C[0x30 - 0x1C];
    int m_team;
    char m_name[0x20];
};

struct PlayerIt_002B11C8 {
    int m0;
    int m4;
    void* vt;
    PlayerIt_002B11C8() { vt = D_00371C78; m4 = 0; }
    ~PlayerIt_002B11C8() { vt = D_00371C78; }
};

extern "C" Player_002B11C8* func_002A53F8(void* net, PlayerIt_002B11C8* it, int a);
extern "C" Player_002B11C8* func_002A5490(void* net, PlayerIt_002B11C8* it, int a);
extern "C" int func_002B1108(void* net, int id);

struct Node_002B11C8 {
    int m0;
    void* data;
    int key;
    Node_002B11C8* next;
    Node_002B11C8* prev;
    Node_002B11C8(void* d)
    {
        data = d;
        key = 0;
        next = this;
        prev = this;
    }
    virtual ~Node_002B11C8()
    {
        prev->next = next;
        next->prev = prev;
        next = this;
        prev = this;
    }
    virtual void Key();
    Node_002B11C8* Valid() { return (int)data != -1 ? this : 0; }
    void InsertBefore(Node_002B11C8* n)
    {
        n->prev = prev;
        n->next = this;
        prev->next = n;
        prev = n;
    }
};

struct Score_002B11C8 : Node_002B11C8 {
    char m_name[0x20];
    int m_king;
    int m_hasFlags;
    int m_flags;
    int m_color;
    int m_score;
    char pad4C[0x50 - 0x4C];
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Score_002B11C8() : Node_002B11C8(this) {}
    void Key();
};

struct Head_002B11C8 : Node_002B11C8 {
    Head_002B11C8() : Node_002B11C8((void*)-1) {}
    void Key();
    void InsertSorted(Score_002B11C8* s)
    {
        int key = s->key;
        Node_002B11C8* n = this;
        while ((n = n->next->Valid()) != 0) {
            if (key >= n->key) {
                n->InsertBefore(s);
                return;
            }
        }
        InsertBefore(s);
    }
};

struct ListIt_002B11C8 {
    int m0;
    Node_002B11C8* cur;
    void* vt;
    ListIt_002B11C8() { cur = 0; vt = D_00372F58; }
    ~ListIt_002B11C8() { vt = D_00372F58; }
    void Begin(Node_002B11C8* h) { cur = h; }
    Score_002B11C8* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return (Score_002B11C8*)cur->data;
    }
};

struct Handler_002B11C8 {
    int m0;
    int m4;
    virtual void Dummy();
    virtual void Update(void* params);
};

struct Ref_002B11C8 {
    Handler_002B11C8* p;
    int m4;
    int m8;
    void Clear()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
};

extern "C" void func_0012DB48(Ref_002B11C8* r, void* root, unsigned int name, int a);

struct Obj_002B11C8 {
    char pad[0x20];
    void* m_net;
    void UpdateScores();
};

void Obj_002B11C8::UpdateScores()
{
    PlayerIt_002B11C8 pit;
    Head_002B11C8 list;
    ListIt_002B11C8 lit;
    void* game = D_0038FC78;
    void* net = m_net;
    void* root = D_00389A30;
    func_0022E358(game);
    bool ranked = func_0024F938(func_0022E358(game)) != 0x1C471C60;
    bool timed = false;
    if (func_0024F938(func_0022E358(game)) == 0x6EF8FDA0 || func_0024F938(func_0022E358(game)) == 0x5D32129C)
        timed = true;

    unsigned int now = func_0010FC30();
    if (now - D_00392360 < 1000)
        return;
    D_00392360 = now;
    func_001F0370(D_003795A0, 0, 0, 0);

    if (ranked && func_002A25F0(net)) {
        Score_002B11C8* teams[4];
        char buf[0x30];
        for (int i = 0; i < func_0024F590(func_0022E358(game)); i++) {
            if (func_002A1DA8(net, i) > 0) {
                unsigned int name;
                switch (i) {
                case 0:
                    name = 0x3224348D;
                    break;
                case 1:
                    name = 0xB4B04623;
                    break;
                case 2:
                    name = 0x7FEC9586;
                    break;
                case 3:
                    name = 0x62E9A53E;
                    break;
                default:
                    name = 0;
                    break;
                }
                teams[i] = new Score_002B11C8;
                func_00331A9C(teams[i]->m_name, func_001E5488(name, 0));
                teams[i]->m_king = 0;
                teams[i]->m_hasFlags = 0;
                teams[i]->m_flags = 0;
                teams[i]->m_color = i + 2;
                teams[i]->m_score = func_002B0FB8(net, i);
            }
        }
        for (Player_002B11C8* p = func_002A53F8(net, &pit, 0); p; p = func_002A5490(net, &pit, 0)) {
            if (!func_002B2280(p))
                continue;
            if (func_002B1FC8(p)) {
                func_003331D0(buf, D_00392368, teams[p->m_team]->m_name);
                func_00331A9C(teams[p->m_team]->m_name, buf);
            }
            if (func_002B2F30(p))
                teams[p->m_team]->m_king = 1;
            if (func_002B22B8(p)) {
                teams[p->m_team]->m_hasFlags = 1;
                teams[p->m_team]->m_flags |= 1 << func_002B22C8(p);
            }
        }
        for (int i = 0; i < func_0024F590(func_0022E358(game)); i++) {
            if (func_002A1DA8(net, i) > 0) {
                teams[i]->key = teams[i]->m_score;
                list.InsertSorted(teams[i]);
            }
        }
    } else {
        for (Player_002B11C8* p = func_002A53F8(net, &pit, 0); p; p = func_002A5490(net, &pit, 0)) {
            if (!func_002B2280(p))
                continue;
            Score_002B11C8* s = new Score_002B11C8;
            if (func_002B1FC8(p))
                func_003331D0(s->m_name, D_00392368, p->m_name);
            else
                func_00331A9C(s->m_name, p->m_name);
            s->m_king = func_002B2F30(p);
            int color;
            if (func_0024F540(func_0022E358(game)))
                color = p->m_team;
            else
                color = p->m_skater->m_id;
            s->m_color = color + 2;
            if (func_002B22B8(p)) {
                s->m_hasFlags = 1;
                s->m_flags |= 1 << func_002B22C8(p);
            }
            if (ranked) {
                s->key = func_002B1108(net, p->m_skater->m_id);
                list.InsertSorted(s);
            } else {
                list.InsertBefore(s);
            }
        }
    }

    lit.Begin(&list);
    int rank = 0;
    Score_002B11C8* s = lit.Next();
    while (s) {
        char line[0x40];
        char tag[0x10];
        tag[0] = 0;
        if (s->m_king) {
            func_003331D0(tag, D_00392370);
        } else if (s->m_hasFlags) {
            if (s->m_flags & 1)
                func_00331678(tag, D_00392378);
            if (s->m_flags & 2)
                func_00331678(tag, D_00392380);
            if (s->m_flags & 4)
                func_00331678(tag, D_00392388);
            if (s->m_flags & 8)
                func_00331678(tag, D_00392390);
        } else {
            tag[0] = 0;
        }
        Score_002B11C8* next = lit.Next();
        if (ranked) {
            if (timed) {
                int secs = (unsigned int)s->key / 1000;
                if (secs >= 3600)
                    func_003331D0(line, D_003795B0, tag, s->m_color, s->m_name, s->m_color,
                                  secs / 3600, secs % 3600 / 60, secs % 60);
                else
                    func_003331D0(line, D_003795D0, tag, s->m_color, s->m_name, s->m_color, secs / 60, secs % 60);
            } else {
                func_003331D0(line, D_003795F0, tag, s->m_color, s->m_name, s->m_color, s->key);
            }
        } else {
            func_003331D0(line, D_00392398, s->m_color, s->m_name);
        }
        unsigned int id;
        switch (rank) {
        case 0:
            id = 0x2B083809;
            break;
        case 1:
            id = 0xB20169B3;
            break;
        case 2:
            id = 0xC5065925;
            break;
        case 3:
            id = 0x5B62CC86;
            break;
        case 4:
            id = 0x2C65FC10;
            break;
        case 5:
            id = 0xB56CADAA;
            break;
        case 6:
            id = 0xC26B9D3C;
            break;
        case 7:
            id = 0x52D480AD;
            break;
        default:
            id = 0;
            break;
        }
        void* params = func_001E6978(func_001190D0(8));
        func_001E7A30(params, 0xC4745838, 3, line);
        func_001E7A68(params, 0x40C698AF, 0xD, id);
        Ref_002B11C8 ref;
        func_0012DB48(&ref, root, id, 0);
        Handler_002B11C8* h = ref.p;
        ref.Clear();
        if (h)
            h->Update(params);
        func_001F0370(D_00379608, params, 0, 0);
        if (params)
            func_001E6AE8(params, 3);
        delete s;
        s = next;
        rank++;
    }
}
