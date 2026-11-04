struct Vec_00223F20 {
    float x, y, z, w;
    Vec_00223F20() {}
    Vec_00223F20(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
};



struct Node_00223F20 {
    int pad0;
    int m_pri;
    int pad8;
    Node_00223F20* m_next;
};

static inline Node_00223F20* Valid_00223F20(Node_00223F20* n)
{
    return (n->m_pri != -1) ? n : 0;
}

struct Mgr_00223F20 {
    char pad[0x3C];
    Node_00223F20* m_head;
};

struct Obj_00223F20 {
    char pad[0x18];
    int m_id;
    char pad1C[0x34];
    Vec_00223F20 m_pos;
};

struct Player_00223F20 {
    char pad[0x30];
    int m_team;
};

struct Script_00223F20 {
    char pad[0x18];
    void* m_params;
    char pad1C[0xA0];
    Obj_00223F20* m_skater;
};

extern Mgr_00223F20* D_0038FC78;
extern void* D_00392068;

extern "C" bool func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int key, float* out, int required);
extern "C" Obj_00223F20* func_0022DE70(Mgr_00223F20* mgr, unsigned int i);
extern "C" Player_00223F20* func_002A52F0(void* a, unsigned short id);
extern "C" bool func_002B22B8(Player_00223F20* p);
extern "C" void func_001E7200(void* params, unsigned int key, int value);

static inline unsigned int Count_00223F20(Mgr_00223F20* mgr)
{
    unsigned int n = 0;
    for (Node_00223F20* p = Valid_00223F20(mgr->m_head); p; p = Valid_00223F20(p->m_next))
        n++;
    return n;
}

bool func_00223F20(void* params, Script_00223F20* script)
{
    int team = -1;
    int best = -1;
    float bestDist = 1000000.0f;
    void* out = script->m_params;
    Obj_00223F20* skater = script->m_skater;
    int t;
    func_001E7DE8(params, 0x6C2A140F, &t, 1);
    float r;
    func_001E7EB0(params, 0xC48391A5, &r, 1);
    r = (r * 144.0f) * r;
    for (unsigned int i = 0; i < Count_00223F20(D_0038FC78); i++) {
        Obj_00223F20* o = func_0022DE70(D_0038FC78, i);
        if (!o)
            continue;
        Player_00223F20* p = func_002A52F0(D_00392068, o->m_id);
        if (!p)
            continue;
        if (p->m_team == t && !func_002B22B8(p))
            continue;
        if (p->m_team == t || !func_002B22B8(p)) {
            Vec_00223F20 d(o->m_pos.x - skater->m_pos.x, o->m_pos.y - skater->m_pos.y,
                           o->m_pos.z - skater->m_pos.z, o->m_pos.w - skater->m_pos.w);
            float dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < r && dist < bestDist) {
                best = o->m_id;
                bestDist = dist;
            }
        }
    }
    if (best >= 0)
        team = func_002A52F0(D_00392068, best)->m_team;
    func_001E7200(out, 0x3B1F59E0, team);
    func_001E7200(out, 0x67E6859A, best);
    return true;
}
