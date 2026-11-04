extern "C" void* func_002568D8(void* self);
extern "C" void* func_00104008(void* p);
extern "C" void func_00189628(void* mgr, unsigned int id, void* obj);
extern "C" int func_00103F28(const char* fmt, const char* file, int line, int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int value);
extern "C" void func_00185300(void* self, void* s, int flag);
extern "C" int func_00185578(void* self, unsigned int name);
extern "C" void func_001E6AE8(void* p, int flags);
extern char D_00366EB0[];
extern char D_00366F50[];
extern char D_00366DA7[];
extern char D_00366E00[];
extern char D_00366E20[];
extern void* D_0038C7B0;

struct Node_00204200 {
    int m0;
    void* m_owner;
    int m8;
    Node_00204200* m_prev;
    Node_00204200* m_next;
    void* m_vt;
};

class Owner_00204200 {
public:
    char pad[0x2C];
    virtual void V0();
    virtual void Add(void* obj);
};

struct Obj_00204200 {
    char pad0[8];
    void* m_vt;
    char pad0C[0x18 - 0xC];
    int m_id;
    int m1C;
    char pad20[0x34 - 0x20];
    int m34;
    char pad38[0x1B4 - 0x38];
    char m1B4[0x298 - 0x1B4];
    Node_00204200 m_node;
    int m2B0;
    int m2B4;
    int m2B8;
    int m2BC;
    int m2C0;
    int m2C4;
    int m2C8;
    int m2CC;
    int m2D0;
    int m2D4;
    int m2D8;
    int m2DC;
    int m2E0;
    int m2E4;
    int m2E8;
    int m2EC;
    char pad2F0[0x318 - 0x2F0];
    int m318;
    int m31C;
    int m_skater_number;
    char pad324[4];
    int m328;
};

static inline void AddFlag(Obj_00204200* self, void* s, unsigned int value)
{
    func_001E7360(s, 0xB6015EA8, value);
    func_00185300(self, s, 0);
}

Obj_00204200* Construct_00204200(Obj_00204200* self, int skater_number, Owner_00204200* owner, int a3, int id, int type)
{
    func_002568D8(self);
    self->m_vt = D_00366EB0;
    func_00104008(self->m1B4);
    Node_00204200* node = &self->m_node;
    node->m_vt = D_00366F50;
    node->m_owner = self;
    node->m8 = 0;
    node->m_prev = node;
    node->m_next = node;
    self->m31C = a3;
    self->m_id = id;
    self->m1C = 1;
    self->m328 = 0;
    self->m318 = type;
    if (type == 0) {
        func_00189628(D_0038C7B0, 0x5B8AB877, self);
    }
    if (type == 1) {
        func_00189628(D_0038C7B0, 0x06ED3FA7, self);
    }
    self->m34 = -500;
    owner->Add(self);
    self->m_skater_number = skater_number;
    func_00103F28(D_00366E00, D_00366DA7, 0x434, skater_number);
    func_00103F28(D_00366E20, D_00366DA7, 0x435, self->m_id);
    self->m2B0 = 0;
    self->m2B4 = 0;
    self->m2B8 = 0;
    self->m2BC = 0;
    self->m2C0 = 0;
    self->m2C8 = 0;
    self->m2CC = 0;
    self->m2D0 = 0;
    self->m2D8 = 0;
    self->m2E0 = 0;
    self->m2EC = 0;
    self->m2E8 = 0;
    self->m2E4 = 0;
    void* s = func_001E6978(func_001190D0(8));
    AddFlag(self, s, 0x43686585);
    if (self->m31C != 0) {
        AddFlag(self, s, 0x27D7CD28);
        self->m2C8 = func_00185578(self, 0x27D7CD28);
        AddFlag(self, s, 0xD262802F);
        self->m2D8 = func_00185578(self, 0xD262802F);
        AddFlag(self, s, 0xBF518E27);
        AddFlag(self, s, 0x270F56E1);
        self->m2BC = func_00185578(self, 0x270F56E1);
        AddFlag(self, s, 0xD9151D4D);
        self->m2E4 = func_00185578(self, 0xD9151D4D);
        AddFlag(self, s, 0x5BD63B29);
        self->m2E0 = func_00185578(self, 0x5BD63B29);
        AddFlag(self, s, 0x52D61A0D);
        AddFlag(self, s, 0x11B4C67F);
        self->m2D0 = func_00185578(self, 0x11B4C67F);
        AddFlag(self, s, 0x9F9CC949);
        AddFlag(self, s, 0xE594F0A2);
        AddFlag(self, s, 0x9B373E58);
        AddFlag(self, s, 0xD8CC3428);
        AddFlag(self, s, 0x726E85AA);
        self->m2E8 = func_00185578(self, 0x726E85AA);
        AddFlag(self, s, 0x7CD3E6D5);
        AddFlag(self, s, 0xB1D5A3E1);
        AddFlag(self, s, 0x589E5FB3);
        AddFlag(self, s, 0xB5F1E9D2);
        AddFlag(self, s, 0x4FF8DAC6);
        self->m2EC = func_00185578(self, 0x4FF8DAC6);
        AddFlag(self, s, 0x408D2AA9);
        AddFlag(self, s, 0x8BCE7E66);
    } else {
        AddFlag(self, s, 0xD262802F);
        self->m2D8 = func_00185578(self, 0xD262802F);
        AddFlag(self, s, 0x850EEF66);
        AddFlag(self, s, 0xD8CC3428);
        AddFlag(self, s, 0x125044E2);
        AddFlag(self, s, 0xB1D5A3E1);
        AddFlag(self, s, 0xB5F1E9D2);
    }
    AddFlag(self, s, 0x18223FD6);
    self->m2DC = func_00185578(self, 0x18223FD6);
    AddFlag(self, s, 0x488AF07A);
    if (s) {
        func_001E6AE8(s, 3);
    }
    return self;
}
