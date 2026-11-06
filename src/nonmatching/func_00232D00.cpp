/* fuzzy: 82.6 */
/* One queued gameplay event of a remote player (0x5C bytes, ring of 20). */
struct Event_00232D00 {
    unsigned char type;
    unsigned char id;
    unsigned char m2;
    unsigned char m3;
    unsigned int time;
    int m8;
    int mC;
    int m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    int m28;
    int m2C;
    float m30[5];
    int m44;
    int m48;
    int m4C;
    float m50;
    float m54;
    int m58;
};

struct Snap_00232D00 {
    char pad[0x90];
};

struct Ring_00232D00 {
    char pad0[0x1C];
    int count;
    Snap_00232D00 snaps[20];
    char pad[0xB60 - 0x20 - 20 * 0x90];
    int eventCount;
    Event_00232D00 events[20];
};

struct Player_00232D00 {
    char pad0[0x18];
    unsigned short id;
    char pad1A[0x2DC - 0x1A];
    Ring_00232D00* ring;
};

struct Msg_00232D00 {
    char* data;
    unsigned char type;
    char pad5[0x1C - 5];
    void* ctx;
};

/* Wire layout of message 0x29, unpacked field by field. */
struct Trick_00232D00 {
    int score;
    unsigned char id2;
    unsigned char id;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
};

extern void* D_00392068;

extern "C" void* func_0022E040(void* ctx);
extern "C" Player_00232D00* func_00187B48(void* list, int id);
extern "C" Player_00232D00* func_0022DF08(void* ctx, int id);
extern "C" bool func_002A19A8(void* mgr);
extern "C" void* func_002A52F0(void* mgr, int id);
extern "C" void* func_002A49B0(void* mgr);
extern "C" unsigned int func_00279F48(Snap_00232D00* s);
extern "C" void func_00279FB8(Event_00232D00* e, unsigned int t);
extern "C" float func_00232768(signed char flags, unsigned int kind);

/* Takes the next event slot of the player's ring, stamped with the newest snapshot's time. */
static inline Event_00232D00* NewEvent_00232D00(Player_00232D00* p, unsigned char type)
{
    Ring_00232D00* r = p->ring;
    Event_00232D00* e = &r->events[r->eventCount % 20];
    e->type = type;
    Ring_00232D00* r2 = p->ring;
    func_00279FB8(e, func_00279F48(&r2->snaps[(r2->count + 19) % 20]));
    return e;
}

static inline void Done_00232D00(Player_00232D00* p)
{
    p->ring->eventCount++;
}

static inline Player_00232D00* Find_00232D00(Msg_00232D00* m, int id)
{
    return func_00187B48(func_0022E040(m->ctx), id);
}

/* Queues a received remote-player event (tricks, scores, flags, poses...) for playback. */
int func_00232D00(Msg_00232D00* msg)
{
    unsigned char type = msg->type;
    void* ctx = msg->ctx;
    if (type == 0x29) {
        char* p = msg->data;
        Trick_00232D00 t;
        __builtin_memcpy(&t.id2, p, 1);
        p += 1;
        __builtin_memcpy(&t.id, p, 1);
        p += 1;
        __builtin_memcpy(&t.score, p, 4);
        p += 4;
        __builtin_memcpy(&t.a, p, 2);
        p += 2;
        __builtin_memcpy(&t.b, p, 2);
        p += 2;
        __builtin_memcpy(&t.c, p, 2);
        p += 2;
        __builtin_memcpy(&t.d, p, 2);
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), (signed char)t.id);
        if (pl) {
            float c = (float)t.c * (1.0f / 4096.0f);
            if (func_002A19A8(D_00392068)) {
                void* mgr = D_00392068;
                void* mine = func_002A52F0(mgr, pl->id);
                void* active = func_002A49B0(mgr);
                if (!active || mine != active)
                    c = 0.0f;
            }
            Event_00232D00* e = NewEvent_00232D00(pl, 0x29);
            e->id = t.id;
            e->m28 = t.score;
            e->m18 = (float)t.a * (1.0f / 4096.0f);
            e->m20 = c;
            e->m1C = (float)t.b * (1.0f / 4096.0f);
            e->m24 = (float)t.d * (1.0f / 4096.0f);
            e->m2 = t.id2;
            Done_00232D00(pl);
        }
    } else if (type == 0x2B) {
        unsigned char* p = (unsigned char*)msg->data;
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), (signed char)p[0]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[0];
            e->m14 = (float)p[1] * 0.003921568859f;
            Done_00232D00(pl);
        }
    } else if (type == 0x2A) {
        signed char* p = (signed char*)msg->data;
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), p[0]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[0];
            e->mC = p[1] != 0;
            Done_00232D00(pl);
        }
    } else if (type == 0x3C) {
        signed char* p = (signed char*)msg->data;
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), p[1]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[1];
            e->m30[0] = func_00232768(p[0], 0);
            e->m30[1] = func_00232768(p[0], 1);
            e->m30[2] = func_00232768(p[0], 2);
            e->m30[3] = func_00232768(p[0], 3);
            e->m30[4] = func_00232768(p[0], 4);
            Done_00232D00(pl);
        }
    } else if (type == 0x3D) {
        signed char* p = (signed char*)msg->data;
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), p[0]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[0];
            e->m2 = p[1];
            Done_00232D00(pl);
        }
    } else if (type == 0x3E) {
        signed char* p = (signed char*)msg->data;
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), p[4]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[4];
            e->m28 = *(int*)p;
            e->m10 = p[5] != 0;
            Done_00232D00(pl);
        }
    } else if (type == 0x41) {
        signed char* p = (signed char*)msg->data;
        Player_00232D00* pl = func_00187B48(func_0022E040(ctx), p[4]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[4];
            e->m24 = *(float*)p;
            Done_00232D00(pl);
        }
    } else if (type == 0x2C) {
        signed char* p = (signed char*)msg->data;
        if (!Find_00232D00(msg, p[0]))
            return 1;
        Player_00232D00* pl = func_0022DF08(ctx, p[0]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->m8 = p[1] != 0;
            e->id = p[0];
            Done_00232D00(pl);
            return 3;
        }
    } else if (type == 0x76) {
        signed char* p = (signed char*)msg->data;
        if (!Find_00232D00(msg, p[0xC]))
            return 1;
        Player_00232D00* pl = func_0022DF08(ctx, p[0xC]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, type);
            e->id = p[0xC];
            e->m44 = *(int*)p;
            e->m48 = *(int*)(p + 4);
            e->m50 = (float)*(short*)(p + 8);
            e->m54 = (float)*(short*)(p + 0xA);
            e->m58 = *(int*)(p + 0x10);
            e->m3 = p[0x14];
            Done_00232D00(pl);
        }
    } else if (type == 0x8C) {
        signed char* p = (signed char*)msg->data;
        if (!Find_00232D00(msg, p[0]))
            return 1;
        Player_00232D00* pl = func_0022DF08(ctx, p[0]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, 0x8C);
            e->id = p[0];
            Done_00232D00(pl);
        }
    } else if (msg->type == 0x77) {
        signed char* p = (signed char*)msg->data;
        if (!Find_00232D00(msg, p[8]))
            return 1;
        Player_00232D00* pl = func_0022DF08(ctx, p[8]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, 0x77);
            e->id = p[8];
            e->m2C = *(int*)(p + 4);
            e->m4C = p[9];
            e->m28 = *(int*)p;
            Done_00232D00(pl);
        }
    } else if (msg->type == 0x78) {
        signed char* p = (signed char*)msg->data;
        if (!Find_00232D00(msg, p[8]))
            return 1;
        Player_00232D00* pl = func_0022DF08(ctx, p[8]);
        if (pl) {
            Event_00232D00* e = NewEvent_00232D00(pl, 0x78);
            e->id = p[8];
            e->m4C = p[9];
            Done_00232D00(pl);
        }
    }
    return 1;
}
