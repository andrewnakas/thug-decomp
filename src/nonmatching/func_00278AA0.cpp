/* cflags: -fno-gcse */
/* fuzzy: 78.2 */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));
union Vec_00278AA0 {
    qword q;
    struct {
        float x, y, z, w;
    };
    Vec_00278AA0() {}
    Vec_00278AA0(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

inline Vec_00278AA0 operator*(const Vec_00278AA0& a, float k) { return Vec_00278AA0(a.x * k, a.y * k, a.z * k, a.w * k); }
inline Vec_00278AA0 operator+(const Vec_00278AA0& a, const Vec_00278AA0& b)
{
    return Vec_00278AA0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline Vec_00278AA0 operator-(const Vec_00278AA0& a, const Vec_00278AA0& b)
{
    return Vec_00278AA0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Line_00278AA0 {
    Vec_00278AA0 start;
    Vec_00278AA0 end;
};

struct Msg_00278AA0 {
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    int m_8;
    int m_C;
    unsigned char m_10;
    char pad11[0x0F];
    void Set(void* d, unsigned short n, unsigned char t) { m_data = d; m_size = n; m_type = t; }
};

extern char D_00371C78[];

struct Iter_00278AA0 {
    void* m_node;
    int m_index;
    void* m_tag;
    Iter_00278AA0() : m_index(0) { m_tag = D_00371C78; }
    ~Iter_00278AA0() { m_tag = D_00371C78; }
};

struct Conn_00278AA0 {
    char pad0[0x30];
    int m_team;
};

struct Stats_00278AA0;
struct StatsHolder_00278AA0 {
    char pad0[0x1C];
    Stats_00278AA0* m_stats;
};

struct Skater_00278AA0 {
    char pad0[0x18];
    unsigned short m_id;
    char pad1A[0x2D8 - 0x1A];
    StatsHolder_00278AA0* m_2D8;
    struct Bump_00278AA0* m_bump;
};

struct Driving_00278AA0 {
    char pad0[0xA0];
    int m_A0;
    char padA4[0x180 - 0xA4];
    int m_driving;
};

struct Flagged_00278AA0 {
    char pad0[0x524];
    int m_bumped;
};

// Bump report sent with message 0x43: other skater id (+driving bit) and the separation.
struct BumpInfo_00278AA0 {
    unsigned char m_id;
    char pad1[0xF];
    Vec_00278AA0 m_sep;
};

struct Pair_00278AA0 {
    unsigned char m_id;
    unsigned char m_team;
};

struct Game_00278AA0;
extern Game_00278AA0* D_0038FC78;
extern void* D_00392068;
extern char D_00376A48[];

extern "C" void* func_001FA800(void* self);
extern "C" void func_001FF970(void* client, int conn, void* msg);
extern "C" void func_00101F38(Line_00278AA0* l);
extern "C" bool func_00101F60(Line_00278AA0* a, Line_00278AA0* b, Vec_00278AA0* pa, Vec_00278AA0* pb, float* mua,
                              float* mub, int clamp);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_003233B8(Vec_00278AA0* d, Vec_00278AA0* s);
extern "C" float func_001E5370(const char* name, int a);
extern "C" bool func_002166E8(int a, int b);
extern "C" Skater_00278AA0* func_0022DE70(Game_00278AA0* g, int i);
extern "C" void* func_0022E358(Game_00278AA0* g);
extern "C" void func_00239198(Stats_00278AA0* s, int v);
extern "C" int func_002392B8(Stats_00278AA0* s);
extern "C" bool func_0024F050(void* mode);
extern "C" bool func_0024F540(void* mode);
extern "C" unsigned int func_0024F938(void* mode);
extern "C" void* func_002A39D8(void* net);
extern "C" bool func_002A24D8(void* net);
extern "C" Conn_00278AA0* func_002A52F0(void* net, unsigned short id);
extern "C" Conn_00278AA0* func_002A53F8(void* net, Iter_00278AA0* it, int kind);
extern "C" Conn_00278AA0* func_002A5490(void* net, Iter_00278AA0* it, int kind);
extern "C" bool func_002A8560(void* net);
extern "C" bool func_002B1FC8(Conn_00278AA0* c);
extern "C" void func_002B2020(Conn_00278AA0* c);
extern "C" bool func_002B2070(Conn_00278AA0* c);
extern "C" bool func_002B22B8(Conn_00278AA0* c);
extern "C" int func_002B22C8(Conn_00278AA0* c);
extern "C" void func_002B2518(Conn_00278AA0* c, int team);
extern "C" void func_002B2990(Conn_00278AA0* c);
extern "C" void func_002B2BC0(Conn_00278AA0* c, int v);
extern "C" bool func_002B2F30(Conn_00278AA0* c);
extern "C" int func_002B3080(Conn_00278AA0* c);

struct Bump_00278AA0 {
    char pad0[0xC];
    Skater_00278AA0* m_skater;
    void CheckCollisions(int first);
};

extern "C" void func_00279D18(Vec_00278AA0* out, Bump_00278AA0* b);
extern "C" void func_00279D88(Vec_00278AA0* out, Bump_00278AA0* b);
extern "C" float func_00279DB0(Bump_00278AA0* b, int driving);
extern "C" float func_00279E30(Bump_00278AA0* b, int driving, int otherDriving);

static inline bool Near_00278AA0(const Vec_00278AA0& a, const Vec_00278AA0& b, float r)
{
    return (a - b).Length() < r;
}

void Bump_00278AA0::CheckCollisions(int first)
{
    void* net = D_00392068;
    Conn_00278AA0* myConn = func_002A52F0(net, m_skater->m_id);
    if (!myConn || func_002B2070(myConn))
        return;
    if (!func_002A24D8(D_00392068) && !func_002B2F30(myConn) && !func_002B22B8(myConn))
        return;

    int authority = 0;
    Driving_00278AA0* drv = (Driving_00278AA0*)func_00185578(m_skater, 0x43686585);
    if (!drv->m_A0 || func_002166E8(0, 0))
        authority = 1;
    if (!authority && !func_002B2F30(myConn) && !func_002B22B8(myConn))
        return;
    int driving = drv->m_driving;

    Vec_00278AA0 pos, vel, dir;
    func_00279D88(&pos, this);
    func_00279D18(&vel, this);
    dir = vel;
    func_003233B8(&dir, &dir);
    Line_00278AA0 mine;
    func_00101F38(&mine);
    mine.start = pos;

    for (int i = first; i < 8; i++) {
        Skater_00278AA0* other = func_0022DE70(D_0038FC78, i);
        if (!other || other == m_skater)
            continue;
        Driving_00278AA0* odrv = (Driving_00278AA0*)func_00185578(other, 0x43686585);
        if (odrv->m_A0)
            continue;
        Conn_00278AA0* oconn = func_002A52F0(D_00392068, other->m_id);
        if (func_002B2070(oconn) || func_002B2F30(oconn))
            continue;
        if (func_002B22B8(myConn) && func_002B22B8(oconn) && func_002B22C8(myConn) != oconn->m_team)
            continue;
        if (func_0024F540(func_0022E358(D_0038FC78)) && oconn->m_team == myConn->m_team)
            continue;

        int otherDriving = odrv->m_driving;
        Vec_00278AA0 opos, ovel, odir;
        func_00279D88(&opos, other->m_bump);
        func_00279D18(&ovel, other->m_bump);
        odir = ovel;
        func_003233B8(&odir, &odir);
        if (ovel.Length() > 100.0f)
            continue;

        float radius = func_00279E30(this, driving, otherDriving);
        if (driving)
            func_001E5370(D_00376A48, 0);
        if (otherDriving)
            func_001E5370(D_00376A48, 0);

        mine.end = mine.start + dir * func_00279DB0(this, driving);
        Line_00278AA0 theirs;
        func_00101F38(&theirs);
        theirs.start = opos;
        theirs.end = theirs.start + odir * func_00279DB0(other->m_bump, otherDriving);

        // Closest approach of the two motion segments, or nearest endpoints.
        Vec_00278AA0 pa, pb;
        float mu;
        bool hit = false;
        if (func_00101F60(&mine, &theirs, &pa, &pb, &mu, &mu, 1)) {
            hit = Near_00278AA0(pa, pb, radius);
        } else if (Near_00278AA0(theirs.start, mine.start, radius)) {
            hit = true;
            pb = theirs.start;
            pa = mine.start;
        } else if (Near_00278AA0(theirs.start, mine.end, radius)) {
            hit = true;
            pb = theirs.start;
            pa = mine.end;
        } else if (Near_00278AA0(theirs.end, mine.start, radius)) {
            hit = true;
            pb = theirs.end;
            pa = mine.start;
        } else if (Near_00278AA0(theirs.end, mine.end, radius)) {
            hit = true;
            pb = theirs.end;
            pa = mine.end;
        }
        if (!hit)
            continue;

        // The faster (or driving) skater must be one we control.
        if ((driving == otherDriving && ovel.Length() < vel.Length()) || (driving && !otherDriving)) {
            if (!func_002B2F30(myConn))
                continue;
        }

        void* client = func_002A39D8(D_00392068);
        if (authority) {
            Msg_00278AA0 msg;
            BumpInfo_00278AA0 info;
            unsigned char from;
            func_001FA800(&msg);
            info.m_id = other->m_id | (otherDriving << 7);
            info.m_sep = pa - pb;
            Flagged_00278AA0* f = (Flagged_00278AA0*)func_00185578(m_skater, 0x27D7CD28);
            if (f)
                f->m_bumped = 1;
            func_002B2020(myConn);
            msg.Set(&info, sizeof(info), 0x43);
            msg.m_C = 2;
            msg.m_10 = 8;
            func_001FF970(client, func_002B3080(myConn), &msg);
            from = m_skater->m_id | (driving << 7);
            msg.Set(&from, 1, 0x44);
            func_001FF970(client, func_002B3080(oconn), &msg);
            if (func_002166E8(0, 0)) {
                Stats_00278AA0* s = other->m_2D8->m_stats;
                func_00239198(s, func_002392B8(s) + 1);
            }
        }

        unsigned int mode = func_0024F938(func_0022E358(D_0038FC78));
        if (mode == 0x6EF8FDA0 || func_0024F938(func_0022E358(D_0038FC78)) == 0x5D32129C) {
            if (func_0024F050(func_0022E358(D_0038FC78)))
                return;
            if (!func_002B2F30(myConn))
                continue;
            func_002B2BC0(oconn, 1);
            Iter_00278AA0 it;
            for (Conn_00278AA0* c = func_002A53F8(D_00392068, &it, 1); c; c = func_002A5490(D_00392068, &it, 1)) {
                if (func_002B1FC8(c))
                    continue;
                Msg_00278AA0 m;
                unsigned char id;
                func_001FA800(&m);
                id = other->m_id;
                m.Set(&id, 1, 0x55);
                m.m_C = 2;
                m.m_10 = 8;
                func_001FF970(client, func_002B3080(c), &m);
            }
        } else if (func_0024F938(func_0022E358(D_0038FC78)) == 0x6C5FF266) {
            if (func_002A8560(D_00392068))
                return;
            if (!func_002B22B8(myConn))
                continue;
            Msg_00278AA0 m;
            Pair_00278AA0 pair;
            func_001FA800(&m);
            pair.m_id = other->m_id;
            pair.m_team = func_002B22C8(myConn);
            bool sameTeam = func_002B22C8(myConn) == oconn->m_team;
            Iter_00278AA0 it;
            for (Conn_00278AA0* c = func_002A53F8(D_00392068, &it, 1); c; c = func_002A5490(D_00392068, &it, 1)) {
                if (sameTeam) {
                    if (func_002B1FC8(c)) {
                        func_002B2990(oconn);
                    } else {
                        m.Set(&pair, 2, 0x73);
                        m.m_C = 2;
                        m.m_10 = 8;
                        func_001FF970(client, func_002B3080(c), &m);
                    }
                } else {
                    if (func_002B1FC8(c)) {
                        func_002B2518(oconn, func_002B22C8(myConn));
                    } else {
                        m.Set(&pair, 2, 0x74);
                        m.m_C = 2;
                        m.m_10 = 8;
                        func_001FF970(client, func_002B3080(c), &m);
                    }
                }
            }
        }
    }
}
