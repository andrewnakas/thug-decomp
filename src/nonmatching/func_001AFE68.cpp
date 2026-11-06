/* fuzzy: 61.1 */
/* Skater trick/score component script member functions: trick-name lists, recent-event queries,
   pending trick bookkeeping (spin, landing), score blocks. Returns 2 for names it does not handle. */
extern "C" float fabsf(float);

struct Param_001AFE68 {
    char pad0;
    unsigned char type;         /* 0x01, 0xD = checksum */
    char pad2[2];
    unsigned int name;          /* 0x04 */
    unsigned int value;         /* 0x08 */
};

struct Array_001AFE68 {
    char pad0[0xC];
    int size;                   /* 0x0C */
};

struct Script_001AFE68 {
    char pad0[0x18];
    void* params;               /* 0x18 */
};

struct Event_001AFE68 {
    unsigned int time;          /* 0x00 */
    int pad4;
    unsigned int type;          /* 0x08 */
    int padC[2];
    unsigned int flags;         /* 0x14 */
};

/* list of trick checksums given by a script command */
struct TrickList_001AFE68 {
    int count;
    unsigned int ids[10];
    unsigned int flag;          /* +0x2C */
};

struct Object_001AFE68 {
    char pad0[0x18];
    unsigned int id;            /* 0x18 */
    char pad1C[0x31C - 0x1C];
    int active;                 /* 0x31C */
};

struct State_001AFE68 {
    char pad0[0x1C];
    int mode;                   /* 0x1C */
    char pad20[0x14];
    int flipped;                /* 0x34 */
    char pad38[8];
    int inAir;                  /* 0x40 */
};

struct Skater_001AFE68 {
    char pad0[0xC];
    struct { char pad[0x164]; int regular; }* profile; /* 0x0C */
    char pad10[0x37C - 0x10];
    int pending;                /* 0x37C */
    char pad380[0x3E8 - 0x380];
    int vert;                   /* 0x3E8 */
    char pad3EC[0x5B0 - 0x3EC];
    State_001AFE68* state;      /* 0x5B0 */
};

struct Score_001AFE68 {
    char pad0[0xC];
    int a;                      /* 0x0C */
    char pad10[0x5C - 0x10];
    int b;                      /* 0x5C */
    char pad60[0x1544 - 0x60];
    float multiplier;           /* 0x1544 */
};

struct TrickComponent_001AFE68 {
    char pad0[0xC];
    Object_001AFE68* object;    /* 0x0C */
    char pad10[0x10];
    Score_001AFE68* score;      /* 0x20 */
    char pad24[4];
    void* balance;              /* 0x28 */
    Skater_001AFE68* skater;    /* 0x2C */
    char pad30[8];
    void* stats;                /* 0x38 */
    Event_001AFE68 events[100]; /* 0x3C */
    unsigned short numEvents;   /* 0x99C */
    unsigned short lastEvent;   /* 0x99E */
    char pad9A0[0xA68 - 0x9A0];
    int graffiti;               /* 0xA68 */
    void* trickStruct;          /* 0xA6C */
    char padA70[0x1248 - 0xA70];
    TrickList_001AFE68 list1;   /* 0x1248 */
    int padding;                /* 0x1278 */
    TrickList_001AFE68 list2;   /* 0x127C */
    char pad12AC[0x12C4 - 0x12AC];
    TrickList_001AFE68 list3;   /* 0x12C4 */
    char pad12F4[0x1378 - 0x12F4];
    int manualOk;               /* 0x1378 */
    char trickName[0x34];       /* 0x137C */
    int trickScore;             /* 0x13B0 */
    char pendingName[0x34];     /* 0x13B4 */
    int pendingScore;           /* 0x13E8 */
    unsigned int pendingFlags;  /* 0x13EC */
    float spin;                 /* 0x13F0 */
    int landed;                 /* 0x13F4 */
    int done;                   /* 0x13F8 */
    int bailed;                 /* 0x13FC */
    char pad1400[4];
    char timer[1];              /* 0x1404 */

    int CallMemberFunction(unsigned int name, void* params, Script_001AFE68* script);
    void ReadList(TrickList_001AFE68* list, void* params);
    bool IsSwitch() const;
};

extern char D_00362A28[];

extern "C" void func_00103F28(const char* fmt, int score, int mult, int total);
extern "C" unsigned int func_0010FC30();    /* time in ms */
extern "C" void* func_001190D0(int size);
extern "C" void func_00184920(Object_001AFE68* obj, unsigned int event, float delay, void* params);
extern "C" void* func_00185578(Object_001AFE68* obj, unsigned int type);
extern "C" void func_001AB758(TrickComponent_001AFE68* self);
extern "C" void func_001AB788(TrickComponent_001AFE68* self);
extern "C" void func_001ABA28(TrickComponent_001AFE68* self, unsigned int trick, int flags);
extern "C" bool func_001ABFF8(TrickComponent_001AFE68* self, unsigned int trick);
extern "C" void func_001ADCF0(TrickComponent_001AFE68* self);
extern "C" void func_001ADDC8(TrickComponent_001AFE68* self, unsigned int trick);
extern "C" void func_001AE488(TrickComponent_001AFE68* self);
extern "C" void func_001AE520(TrickComponent_001AFE68* self, void* params);
extern "C" void func_001AEC48(TrickComponent_001AFE68* self, void* params, Script_001AFE68* script);
extern "C" void func_001AEE60(TrickComponent_001AFE68* self);
extern "C" void func_001AEE68(TrickComponent_001AFE68* self);
extern "C" void func_001AF7E0(TrickComponent_001AFE68* self);
extern "C" void func_001B0EB8(TrickComponent_001AFE68* self, int a);
extern "C" void func_001B0EF0(TrickComponent_001AFE68* self, unsigned int id);
extern "C" void* func_001E5548(unsigned int id, int a);
extern "C" bool func_001E55B8(unsigned int id, int a);
extern "C" Param_001AFE68* func_001E6E90(void* params, Param_001AFE68* prev);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6AE8(void* params, int a);
extern "C" void func_001E6B30(void* params);
extern "C" void func_001E72B0(void* params, unsigned int name, float v);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int v);
extern "C" void func_001E7B18(void* params, unsigned int name, float a, float b);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_001AFE68** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" unsigned int func_001E9300(Array_001AFE68* a, int i);
extern "C" int func_001F0D78(const char* name);
extern "C" void func_001F49F8(void* stats);
extern "C" void func_001F4A90(void* stats);
extern "C" float func_002032A0(unsigned int name, int a);
extern "C" int func_00236DA0(Score_001AFE68* s);
extern "C" void func_00237100(Score_001AFE68* s, const char* name, int score, unsigned int flags);
extern "C" void func_002376C0(Score_001AFE68* s, int spin);
extern "C" void func_00237728(Score_001AFE68* s, int spin);
extern "C" void func_00237B88(Score_001AFE68* s);
extern "C" void func_00238088(Score_001AFE68* s, int a);
extern "C" void func_0023D2C0(void* p);
extern "C" void* func_00240850();
extern "C" void func_00266698(void* timer);
extern "C" void func_002714B0(void* comp);
extern "C" void func_002714D8(void* comp);
extern "C" void func_0028EAC0(Skater_001AFE68* skater);
extern "C" void func_002910A8(void* balance);
extern "C" void func_002910E8(void* balance);
extern "C" void func_00331A9C(char* dst, const char* src);   /* strcpy */
extern "C" int func_0033ECA8(float f);

inline void TrickComponent_001AFE68::ReadList(TrickList_001AFE68* list, void* params)
{
    list->count = 0;
    for (Param_001AFE68* p = func_001E6E90(params, 0); p; p = func_001E6E90(params, p)) {
        if (p->name == 0 && p->type == 0xD)
            list->ids[list->count++] = p->value;
    }
}

inline bool TrickComponent_001AFE68::IsSwitch() const
{
    State_001AFE68* st = skater->state;
    if (skater->profile->regular)
        return st->flipped;
    return st->flipped ^ 1;
}

/* the score block finished: send the "score landed" event to the object */
static inline void SendScoreEvent(TrickComponent_001AFE68* self, Score_001AFE68* s)
{
    if (s->a * s->b) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7360(p, 0x5B24FAAA, self->object->id);
        func_00184920(self->object, 0x4B3CE1FE, 0.0f, p);
        if (p)
            func_001E6AE8(p, 3);
    }
}

int TrickComponent_001AFE68::CallMemberFunction(unsigned int name, void* params, Script_001AFE68* script)
{
    switch (name) {
    case 0x86928082: {
        Array_001AFE68* list = 0;
        if (func_001E8248(params, 0xBCA37A49, &list, 0)) {
            int flags = 0;
            func_001E7DE8(params, 0xCDCFEE8A, &flags, 0);
            int n = list->size;
            for (int i = 0; i < n; i++)
                func_001ABA28(this, func_001E9300(list, i), flags);
        } else {
            func_001AB758(this);
        }
        return 1;
    }

    case 0xEDA2772E: {
        Array_001AFE68* list = 0;
        if (func_001E8248(params, 0xBCA37A49, &list, 0)) {
            int n = list->size;
            for (int i = 0; i < n; i++) {
                if (func_001ABFF8(this, func_001E9300(list, i)))
                    return 1;
            }
            return 0;
        }
        unsigned int id = 0;
        func_001E8398(params, 0, &id, 0);
        if (!id)
            return 0;
        return func_001ABFF8(this, id) != 0;
    }

    case 0x04BA9EE9: {
        unsigned int id = 0;
        func_001E8398(params, 0, &id, 0);
        if (!id)
            return 0;
        return func_001ABFF8(this, id) == 0;
    }

    case 0x070E934D:
        for (int i = 0; i < numEvents; i++) {
            if (events[i].type == 0x7323E97C)
                events[i].flags = 1;
        }
        return 1;

    case 0x54D43789: {
        /* clear a flag on every event newer than the given time */
        int timeout = 200;
        func_001E7DE8(params, 0x79A07F3F, &timeout, 0);
        unsigned int mask = 0;
        unsigned int kind = 0;
        func_001E8398(params, 0x9694FC41, &kind, 0);
        switch (kind) {
        case 0xB58EFC2B: mask = 1; break;
        case 0xB2C0F29A: mask = 2; break;
        case 0xEC066B6A: mask = 8; break;
        case 0xEF24413B: mask = 4; break;
        }
        int idx = lastEvent;
        for (int n = 0; n < numEvents; n++) {
            if (func_0010FC30() - events[idx].time >= (unsigned int)timeout)
                break;
            if (events[idx].flags & mask)
                events[idx].flags &= ~mask;
            idx--;
            if (idx < 0)
                idx += 100;
        }
        return 1;
    }

    case 0xCB30572D:
        for (Param_001AFE68* p = func_001E6E90(params, 0); p; p = func_001E6E90(params, p)) {
            if (p->name == 0 && p->type == 0xD)
                func_001ADDC8(this, p->value);
        }
        return 1;

    case 0xD8C79BB0:
        ReadList(&list1, params);
        if (list1.count == 1 && !func_001E55B8(list1.ids[0], 0))
            list1.ids[0] = 0x9E22D268;
        list1.flag = 0;
        func_001E8398(params, 0xB394C01C, &list1.flag, 0);
        return 1;

    case 0x1FCF080A:
        ReadList(&list2, params);
        list2.flag = 0;
        func_001E8398(params, 0xB394C01C, &list2.flag, 0);
        return 1;

    case 0x6BA35AB4:
        ReadList(&list3, params);
        list3.flag = 0;
        func_001E8398(params, 0xB394C01C, &list3.flag, 0);
        return 1;

    case 0xD4099D35:
        padding = 8;
        return 1;

    case 0x72C926CA: func_001AF7E0(this); return 1;
    case 0xDE98DE7A: func_001AE488(this); return 1;
    case 0x54C33B20: func_001ADCF0(this); return 1;
    case 0x788F9A4E: func_001AE520(this, params); return 1;
    case 0x8E3D3BEC: func_001AB788(this); return 1;
    case 0xAB6B8DD9: func_001AEE68(this); return 1;
    case 0x7627DC71: func_001AEC48(this, params, script); return 1;
    case 0xD5813251: func_001AEE60(this); return 1;

    case 0xB42A1230: {
        unsigned int a = 0;
        func_001E8398(params, 0x53F1DF98, &a, 0);
        unsigned int b = 0;
        func_001E8398(params, 0x270F56E1, &b, 0);
        func_001E7B18(trickStruct, a, 13.0f, (float)b);
        return 1;
    }

    case 0xABFF7889: {
        Param_001AFE68* p = func_001E6E90(params, 0);
        if (p && p->name == 0 && p->type == 0xD) {
            void* src = func_001E5548(p->value, 0);
            if (src) {
                func_001E6B30(trickStruct);
                func_001E6AC8(trickStruct, src);
            }
        }
        return 1;
    }

    case 0xD872002D:
        manualOk = 1;
        func_001AB758(this);
        return 1;

    case 0x290F6010:
        manualOk = 0;
        return 1;

    case 0x4B2EE2BC: {
        const char* s = 0;
        func_001E7C80(params, 0, &s, 0);
        if (s)
            func_00331A9C(trickName, s);
        else
            trickName[0] = 0;
        return 1;
    }

    case 0xCB3A8FD2:
        func_001E7DE8(params, 0, &trickScore, 0);
        return 1;

    case 0x4BA7719F: {
        float f = fabsf(spin) + func_002032A0(0x50C5CC2F, 0);
        func_001E72B0(script->params, 0xEDF5DB70, (float)((int)f / 180) * 180.0f);
        return 1;
    }

    case 0xE50D471E:
        spin = 0.0f;
        return 1;

    case 0xF32E8D5C: {
        /* do a trick: score it now or keep it pending until landing */
        char* trick = trickName;
        if (trick) {
            Score_001AFE68* s = score;
            int extra = 0;
            if (func_001E8708(params, 0x5C9B1765)) {
                func_00331A9C(pendingName, trick);
                pendingScore = trickScore;
                if (IsSwitch())
                    pendingFlags |= 4;
            } else if (func_001E7DE8(params, 0x83CB0082, &extra, 0) && func_00236DA0(s) == func_001F0D78(trick)) {
                spin += (float)extra;
                if (object->active)
                    func_002376C0(s, (int)spin);
            } else {
                unsigned int flags = 0;
                if (func_001E8708(params, 0xC2150BB0))
                    flags = 2;
                if (func_001E8708(params, 0x3C24AC46))
                    flags |= 0x40;
                if (IsSwitch())
                    flags |= 4;
                if (graffiti)
                    flags |= 0x20;
                if (func_001E8708(params, 0x61A1BC57))
                    flags |= 0x80;
                if (object->active) {
                    if (skater->state->mode == 4) {
                        int base = trickScore;
                        if (base) {
                            func_00103F28(D_00362A28, base, func_0033ECA8(s->multiplier),
                                          (int)(s->multiplier * (float)base));
                            trickScore = (int)((float)trickScore * s->multiplier);
                        }
                    }
                    func_00237100(s, trick, trickScore, flags);
                    if (trickName[0]) {
                        func_00184920(object, 0x11D8BC9E, 0.0f, 0);
                        if (skater->state->inAir || skater->vert) {
                            float f = fabsf(spin);
                            if (360.0f - func_002032A0(0x50C5CC2F, 0) + 0.1f <= f)
                                func_00237728(s, (int)spin);
                        } else {
                            func_00237728(s, (int)spin);
                        }
                    }
                }
                if (func_001E8708(params, 0xC2150BB0))
                    spin = 0.0f;
                pendingName[0] = 0;
            }
        }
        if (trickName[0])
            graffiti = 0;
        return 1;
    }

    case 0x11CA5C42: {
        /* landed */
        Score_001AFE68* s = score;
        if (object->active) {
            if (pendingName[0]) {
                float f;
                if (skater->vert) {
                    f = fabsf(spin);
                    if (360.0f - func_002032A0(0x50C5CC2F, 0) + 0.1f <= f) {
                        func_00237100(s, pendingName, pendingScore, pendingFlags);
                        func_00237728(s, (int)spin);
                    }
                } else {
                    f = fabsf(spin);
                    if (180.0f - func_002032A0(0x50C5CC2F, 0) + 0.1f <= f) {
                        func_00237100(s, pendingName, pendingScore, pendingFlags);
                        func_00237728(s, (int)spin);
                    }
                }
                pendingName[0] = 0;
            }
            func_0023D2C0(func_00240850());
            SendScoreEvent(this, s);
            func_002714D8(func_00185578(object, 0x11B4C67F));
            func_00237B88(s);
            spin = 0.0f;
            func_001F4A90(stats);
        }
        func_00184920(object, 0xC98BA111, 0.0f, 0);
        if (landed)
            done = 1;
        bailed = 0;
        func_002910A8(balance);
        func_002910E8(balance);
        skater->pending = 0;
        return 1;
    }

    case 0xB8045433:
        /* bailed */
        if (object->active) {
            SendScoreEvent(this, score);
            func_00238088(score, 0);
        }
        func_00184920(object, 0x6045A960, 0.0f, 0);
        done = 1;
        landed = 1;
        func_001B0EB8(this, 0);
        bailed = 0;
        func_002910E8(balance);
        func_0028EAC0(skater);
        spin = 0.0f;
        skater->pending = 0;
        func_00266698(timer);
        func_002714B0(func_00185578(object, 0x11B4C67F));
        func_001F49F8(stats);
        return 1;

    case 0x36B2BE57: {
        unsigned int id;
        func_001E8398(params, 0, &id, 1);
        func_001B0EF0(this, id);
        return 1;
    }
    }
    return 2;
}
