struct Mem_00204900 {
    char pad0[0x188];
    int m_heaps[(0x3EC - 0x188) / 4];
    int m_skater_heap;
};

struct Info_00204900 {
    int m_color;
    int m_lo;
    int m_hi;
    int pad;
};

struct Game_00204900 {
    char pad0[0x3C8];
    Info_00204900 m_info[8];
};

struct Cam_00204900 {
    char pad0[0xC];
    unsigned int m_flags;
};

struct Lod_00204900 {
    char pad0[0x1C];
    int m_mode;
};

struct Flagged_00204900 {
    int m0;
    unsigned short m_flags;
};

struct Model_00204900 {
    char pad0[0x1C];
    int m_shadow;
};

struct Shadow_00204900 {
    char pad0[0x20];
    int m_shadow;
};

struct Board_00204900 {
    char pad0[0x50];
    int m_shadow;
};

struct Phys_00204900 {
    char pad0[0x364];
    int m_lo;
    int m_hi;
};

struct Sound_00204900 {
    char pad0[0x2C];
    float m_volume;
};

class Comp_00204900 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void InitFromProfile(void* info, int a, int skater, int b);
};

struct Profile_00204900 {
    int m0;
    char m_info[4];
};

struct Skater_00204900 {
    char pad0[0x14];
    void* m_script;
    int m_id;
    char pad1C[0x238 - 0x1C];
    int m_inited;
    char pad23C[0x248 - 0x23C];
    void* m_tricks[11];
    char pad274[0x2B0 - 0x274];
    void* m_anim;
    Comp_00204900* m_model;
    void* m_m2B8;
    Shadow_00204900* m_shadow;
    void* m_m2C0;
    char pad2C4[0x2CC - 0x2C4];
    void* m_m2CC;
    Board_00204900* m_board;
    char pad2D4[0x2D8 - 0x2D4];
    Model_00204900* m_m2D8;
    char pad2DC[0x2E0 - 0x2DC];
    Phys_00204900* m_phys;
    char pad2E4[0x318 - 0x2E4];
    int m_heap;
    int m_local;
    int m_skater_number;
};

extern "C" void* func_0022E358(Game_00204900* game);
extern "C" int func_0024F860(void* p);
extern "C" void func_0010A950(Mem_00204900* mem, int heap);
extern "C" void func_0010A9B0(Mem_00204900* mem);
extern "C" void* func_00187B48(void* man, unsigned int id);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001BA430(void* comp, Skater_00204900* skater);
extern "C" void func_001CDFB0(void* comp, Skater_00204900* skater);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_001E7200(void* s, unsigned int name, int value);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void* func_001E55F8(char* name, int a);
extern "C" Cam_00204900* func_00186D60(void* man, void* structure, void* s, int a);
extern "C" void func_001BEBE8(void* comp, Cam_00204900* cam);
extern "C" int func_0020B0A0(unsigned int id, int skater, int a);
extern "C" void func_001B99A0(void* comp, int a, float b);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* p);
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E84E8(void* s, char* name, unsigned int* out, int required);
extern "C" bool func_001E8398(void* s, unsigned int name, int* out, int required);
extern "C" void func_002569A8(Skater_00204900* skater);
extern "C" void func_00185300(Skater_00204900* skater, void* s, int a);
extern "C" void func_0019FB18(void* anim, int value);
extern "C" void func_001A1AD8(void* anim, int value);
extern "C" void* func_001D0AA0(void* p);
extern "C" void func_001D0A98(void* p, void* value);
extern "C" void func_00185500(Skater_00204900* skater);
extern "C" void func_001BAD28(void* comp, int color);
extern "C" void func_001EE8F0(void* script, char* name, int a, Skater_00204900* skater);
extern "C" void func_00205428(Skater_00204900* skater, Profile_00204900* profile);
extern "C" void func_00205290(Skater_00204900* skater, Profile_00204900* profile);
extern "C" float func_00203D40(Skater_00204900* skater, unsigned int name);
extern "C" void func_001AB7C0(Shadow_00204900* p, Profile_00204900* profile);
extern "C" void func_001AB758(Shadow_00204900* p);
extern "C" void func_001ADCF0(Shadow_00204900* p);
extern "C" void func_001AB788(Shadow_00204900* p);
extern "C" void func_001AEE68(Shadow_00204900* p);
extern "C" Flagged_00204900* func_001A41C8(void* comp);
extern "C" void func_0018DC18(Comp_00204900* model);
extern "C" void func_001F0210(unsigned int name, int a, Skater_00204900* skater, int b, int c);
extern "C" void func_001A0F10(void* anim, unsigned int name, float value);
extern "C" void* func_0010A638(Mem_00204900* mem, int size, int a, int b);
extern "C" void* func_00252BA0(void* p);
extern "C" void func_001855A8(Skater_00204900* skater, unsigned int name, int a, int b);

extern Game_00204900* D_0038FC78;
extern Mem_00204900* D_00388A70;
extern void* D_0038C608;
extern void* D_0038DB38;
extern char D_00366E38[];
extern char D_00366E58[];
extern char D_00366E68[];

static inline void AddComp_00204900(Skater_00204900* self, unsigned int type)
{
    void* s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0xB6015EA8, type);
    func_00185300(self, s, 0);
    if (s) {
        func_001E6AE8(s, 3);
    }
}

void Init_00204900(Skater_00204900* self, Profile_00204900* profile)
{
    Game_00204900* game = D_0038FC78;
    int need_cam = 0;
    if (!func_0024F860(func_0022E358(game)) || !self->m_skater_number) {
        need_cam = 1;
    }
    if (self->m_local && need_cam) {
        func_0010A950(D_00388A70, D_00388A70->m_skater_heap);
        unsigned int id = self->m_skater_number == 1 ? 0xE17B231A : 0x967C138C;
        Cam_00204900* cam = (Cam_00204900*)func_00187B48(D_0038C608, id);
        if (cam) {
            func_001BA430(func_00185578(cam, 0x5E43A604), self);
            Lod_00204900* lod = (Lod_00204900*)func_00185578(cam, 0xC7D37EC2);
            func_001CDFB0(lod, self);
            lod->m_mode = 3;
        } else {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0x4C48DA58, self->m_id);
            func_001E7360(s, 0xA1DC81F9, id);
            void* man = D_0038C608;
            cam = func_00186D60(man, func_001E55F8(D_00366E38, 0), s, 1);
            if (s) {
                func_001E6AE8(s, 3);
            }
        }
        func_001BEBE8(func_00185578(self, 0x726E85AA), cam);
        func_0020B0A0(id, self->m_skater_number, 0);
        cam->m_flags |= 2;
        func_001B99A0(func_00185578(cam, 0x5E43A604), 2, 0.0f);
        func_0010A9B0(D_00388A70);
    }
    self->m_script = func_001EE428(func_00121960(0xF4));
    void* prefs = func_001E5548(0x962E5CF7, 0);
    unsigned int skeleton = 0x5A9D2A0A;
    if (prefs) {
        func_001E84E8(prefs, D_00366E58, &skeleton, 0);
    }
    func_002569A8(self);
    {
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0xB6015EA8, 0x72AD7B23);
        func_001E7360(s, 0x5B8C6DC2, 0x3FEC31A6);
        func_00185300(self, s, 0);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
    self->m_anim = func_00185578(self, 0x72AD7B23);
    {
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0xB6015EA8, 0x222756D5);
        func_001E7360(s, 0x222756D5, skeleton);
        func_001E7200(s, 0xD3982061, 0);
        func_00185300(self, s, 0);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
    int anims = 0x501949BD;
    if (prefs) {
        func_001E8398(prefs, 0x08B7488E, &anims, 0);
    }
    func_0019FB18(self->m_anim, anims);
    func_001A1AD8(self->m_anim, 1);
    {
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0, 0x10079F2D);
        func_001E7200(s, 0x2A1F92C0, self->m_local != 0);
        func_001E7360(s, 0xB6015EA8, 0x286A8D26);
        func_00185300(self, s, 0);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
    self->m_model = (Comp_00204900*)func_00185578(self, 0x286A8D26);
    func_0010A950(D_00388A70, D_00388A70->m_heaps[self->m_heap]);
    void* tex = D_0038DB38;
    void* old = func_001D0AA0(tex);
    func_001D0A98(tex, 0);
    self->m_model->InitFromProfile(profile->m_info, 0, self->m_heap, 0);
    func_001D0A98(tex, old);
    func_0010A9B0(D_00388A70);
    {
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0xB6015EA8, 0x8A897DD2);
        func_001E7360(s, 0x9AC24B18, 0x76A54CD1);
        func_00185300(self, s, 0);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
    self->m_m2B8 = func_00185578(self, 0x8A897DD2);
    if (self->m_local) {
        AddComp_00204900(self, 0x404EB936);
        self->m_m2C0 = func_00185578(self, 0x404EB936);
        AddComp_00204900(self, 0x21FC3301);
    } else {
        self->m_m2C0 = 0;
    }
    if (self->m_local) {
        AddComp_00204900(self, 0x187574FA);
        self->m_m2CC = func_00185578(self, 0x187574FA);
    }
    func_00185500(self);
    if (self->m_local) {
        self->m_phys->m_lo = game->m_info[self->m_skater_number].m_lo;
        self->m_phys->m_hi = game->m_info[self->m_skater_number].m_hi;
        func_001BAD28(self->m_m2C0, game->m_info[self->m_skater_number].m_color);
        if (self->m_local) {
            func_001EE8F0(self->m_script, D_00366E68, 0, self);
        }
    }
    func_00205428(self, profile);
    func_00205290(self, profile);
    if (self->m_local) {
        Sound_00204900* snd = (Sound_00204900*)func_00185578(self, 0x187574FA);
        snd->m_volume = func_00203D40(self, 0xCC5F87AA);
    }
    if (self->m_shadow) {
        func_001AB7C0(self->m_shadow, profile);
        func_001AB758(self->m_shadow);
        func_001ADCF0(self->m_shadow);
        func_001AB788(self->m_shadow);
        func_001AEE68(self->m_shadow);
        self->m_shadow->m_shadow = self->m_m2D8->m_shadow;
    }
    if (self->m_board) {
        self->m_board->m_shadow = self->m_m2D8->m_shadow;
    }
    self->m_inited = 1;
    void* skel = func_00185578(self, 0xA432DC41);
    if (skel && func_001A41C8(skel)) {
        func_001A41C8(skel)->m_flags |= 2;
    }
    func_0018DC18(self->m_model);
    func_001F0210(0xAE5438AF, 0, self, 0, 0);
    func_001A0F10(self->m_anim, 0x1CA1FF20, 0.3f);
    if (self->m_local) {
        for (int i = 0; i < 11; i++) {
            self->m_tricks[i] = func_00252BA0(func_0010A638(D_00388A70, 0x10, 1, 0));
        }
        func_001F0210(0x0BDC1C89, 0, self, 0, 0);
        func_001855A8(self, 0x5C038F9B, 0, 0);
    }
}
