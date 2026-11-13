/* fuzzy: 70.6 */
extern void* D_0038FC78;
extern char D_00390688[];
extern char D_00374B88[];
extern char D_00374BB8[];
extern char D_00390690[];
extern char D_00390698[];
extern char D_003906A0[];
extern char D_003906A8[];
extern char D_003906B0[];

struct Str_00250CA0 {
    int m0[4];
};

// One competitor: name, finishing position and three judged scores.
struct Entry_00250CA0 {
    Str_00250CA0 m_name;
    int m_pos;
    int m_score[3];
    int m_20;
};

struct Obj_00250CA0 {
    int m0;
    void* m_params;
    int m8;
    Entry_00250CA0 m_ent[8];
    float m_12C;
    float m_130;
    float m_134;
    float m_138;
    float m_13C;
    float m_140;
    float m_144;
    char pad148[0x160 - 0x148];
    char* m_judge[5];
    char pad174[0x184 - 0x174];
    int m_184;
    void Init(float low, float mid, float high, float a, float b, float c, float d);
};

extern "C" int func_00100080(int n);
extern "C" float func_001000D0(float range);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_00104110(Str_00250CA0* s, const char* v);
extern "C" const char* func_001041B8(Str_00250CA0* s);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, void** out, int required);
extern "C" const char* func_001E91C0(void* array, int i);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_0022E050(void* game);
extern "C" bool func_002623B8(void* p);
extern "C" bool func_00262430(void* p);
extern "C" const char* func_002624F0(void* p);
extern "C" int func_00262828(void* mgr);
extern "C" int func_00262830(void* mgr, int i);
extern "C" void* func_00262860(void* mgr, int i);
extern "C" void* func_00262990(void* mgr);
extern "C" void* func_002629B8(void* mgr, int id);
extern "C" int func_00250C50(Entry_00250CA0* e, int mode);
extern "C" void func_00251B70(Obj_00250CA0* self);

static inline float Round_00250CA0(float f)
{
    return (int)(f + 0.499999f);
}

void Obj_00250CA0::Init(float low, float mid, float high, float a, float b, float c, float d)
{
    int cand[100];
    int order[7];
    void* names;
    const char* playerName;
    int nCand = 0;
    int i;

    m_12C = low;
    m_130 = mid;
    m_134 = high;
    m_184 = 0;
    m_138 = a;
    m_13C = b;
    m_140 = c;
    m_144 = d;

    void* mgr = func_0022E050(D_0038FC78);
    func_00104110(&m_ent[0].m_name, func_002624F0(func_00262990(mgr)));

    // Collect every selectable profile other than the player's own.
    int count = func_00262828(mgr);
    for (i = 0; i < count; i++) {
        void* p = func_00262860(mgr, i);
        if (!func_002623B8(p) || func_00262430(p))
            continue;
        if (func_001F0D78(func_001041B8(&m_ent[0].m_name)) != func_001F0D78(func_002624F0(p)))
            cand[nCand++] = i;
    }
    for (i = 0; i < nCand; i++) {
        int j = func_00100080(nCand);
        int t = cand[i];
        cand[i] = cand[j];
        cand[j] = t;
    }

    // Random starting positions 1..7 for the opponents.
    for (int k = 0; k < 7; k++)
        order[k] = k + 1;
    for (i = 0; i < 7; i++) {
        int j = func_00100080(7);
        int t = order[i];
        order[i] = order[j];
        order[j] = t;
    }

    m_ent[0].m_pos = 0;
    for (int k = 0; k < 3; k++)
        m_ent[0].m_score[k] = 0;

    low += func_001000D0(2.0f);
    mid += func_001000D0(2.0f);
    high += func_001000D0(2.0f);
    if (high <= mid)
        mid = high - 0.1f;
    if (mid <= low)
        low = mid - 0.1f;

    for (i = 0; i < 7; i++) {
        float level;
        m_ent[i + 1].m_pos = order[i];
        Entry_00250CA0* e = &m_ent[i + 1];
        if (func_001E8248(m_params, 0x1CC6F48D, &names, 0))
            func_00104110(&e->m_name, func_001E91C0(names, i));
        else
            func_00104110(&e->m_name, func_002624F0(func_002629B8(mgr, func_00262830(mgr, cand[i]))));

        if (i == 0) {
            level = high;
        } else if (i == 1) {
            level = mid;
        } else if (i == 2) {
            level = low;
        } else {
            float spread = low * 0.125f;
            level = low - spread + func_001000D0(spread);
            if (low <= level)
                level = low - 0.1f;
        }

        float best = level + func_001000D0(2.0f);
        float worst = level + level - best;
        float base = best;
        if (worst < best)
            base = worst;

        int hi = func_00100080(3);
        int lo;
        do {
            lo = func_00100080(3);
        } while (lo == hi);

        for (int k = 0; k < 3; k++)
            e->m_score[k] = Round_00250CA0(base - 2.0f + func_001000D0(1.9f));
        e->m_score[hi] = Round_00250CA0(best);
        e->m_score[lo] = Round_00250CA0(worst);
    }

    func_00103F28(D_00390688);
    for (i = 0; i < 8; i++) {
        const char* name = func_001041B8(&m_ent[i].m_name);
        func_00103F28(D_00374B88, i, m_ent[i].m_pos, name, m_ent[i].m_score[0], m_ent[i].m_score[1],
                      m_ent[i].m_score[2], func_00250C50(&m_ent[i], 3));
    }

    func_00251B70(this);
    if (func_001E7C80(m_params, 0xFAF19012, &playerName, 0))
        func_00104110(&m_ent[0].m_name, playerName);

    func_00103F28(D_00374BB8);
    for (i = 0; i < 8; i++) {
        const char* name = func_001041B8(&m_ent[i].m_name);
        func_00103F28(D_00374B88, i, m_ent[i].m_pos, name, m_ent[i].m_score[0], m_ent[i].m_score[1],
                      m_ent[i].m_score[2], func_00250C50(&m_ent[i], 3));
    }

    m_judge[0] = D_00390690;
    m8 = -1;
    m_judge[1] = D_00390698;
    m_judge[2] = D_003906A0;
    m_judge[3] = D_003906A8;
    m_judge[4] = D_003906B0;
}
