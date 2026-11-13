/* fuzzy: 98.4 */
/* sym: AddLines__15Goals_0024C590i = 0x0024C590 */
// Adds `count` message lines to an on-screen goal/trick list. Each line takes a free slot of the
// 30-entry table at this+0xA4, builds its text from script params (a random entry of a list, or
// the entry chosen by func_00245FB8, with an optional "Perfect"/rotation prefix), creates a
// container element plus one or two text elements under the 0xE35EC715 element, and spawns a
// script on the new element. Once more than 0.75 of the expected total is shown, every used line
// gets the 0xEB016D1E script.

struct Obj_0024C590;

extern "C" void func_00183C98(Obj_0024C590* obj, void* handle);
extern "C" void func_00183CB8(Obj_0024C590* obj, void* handle);

// Reference-counted pointer to a screen element (the element keeps a list of the handles on it).
struct Handle_0024C590 {
    Obj_0024C590* m_obj;
    void* m_prev;
    void* m_next;
    Handle_0024C590(Obj_0024C590* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_0024C590()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    void operator=(Obj_0024C590* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
};

// Screen element: vtable after two words, id at +0x18.
class ElemBase_0024C590 {
public:
    int m0;
    int m4;
    virtual void V1();
    virtual void SetProperties(void* params);
};

class Elem_0024C590 : public ElemBase_0024C590 {
public:
    int mC;
    int m10;
    int m14;
    unsigned int m_id;
};

// Screen element manager (D_00389A30).
class Mgr_0024C590 {
public:
    char pad[0x2C];
    virtual void V1();
    virtual void Add(Elem_0024C590* elem);
};

struct Script_0024C590 {
    char pad[0xBC];
    Handle_0024C590 m_elem;
};

struct Array_0024C590 {
    int m0;
    int m4;
    int m_type;
    int m_size;
};

struct Slot_0024C590 {
    unsigned int m_name;        // +0xA4: checksum of the line's name
    unsigned int m_name2;       // +0xA8: checksum of the alternate name
    unsigned int m_checksum;    // +0xAC
    unsigned int m_elemId;      // +0xB0: id of the line's container element
    int m_free;                 // +0xB4
    int m_perfect;              // +0xB8
    int m_group;                // +0xBC
    int m_rotations;            // +0xC0: shown as rotations * 180
    int m_mode;                 // +0xC4
};

union Str4_0024C590 {
    char c[4];
    int w;
};

struct Players_0024C590 {
    char pad[0x248];
    void** m_params[1];
};

class Goals_0024C590 {
public:
    char pad0[0x20];
    void* m_params;
    char pad24[0xA4 - 0x24];
    Slot_0024C590 m_slots[30];
    int m_shown;
    int pad4E0;
    int m_groupUsed[30];

    void AddLines(int count);
};

extern Mgr_0024C590* D_00389A30;
extern unsigned int D_0038C6D4;
extern void* D_0038FC78;
extern Str4_0024C590 D_00390350[];
extern Str4_0024C590 D_00390358[];
extern char D_00390360[];
extern char D_003743F0[];
extern char D_00374400[];

extern "C" int func_00100030(int range);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001190D0(int size);
extern "C" void func_00124118(Obj_0024C590* elem, int shown);
extern "C" Elem_0024C590* func_00125C28(void* mem);
extern "C" Elem_0024C590* func_00125F10(void* mem);
extern "C" void func_0012DA10(Mgr_0024C590* mgr, const Handle_0024C590& parent, const Handle_0024C590& child,
                              int flag);
extern "C" Handle_0024C590 func_0012DB48(Mgr_0024C590* mgr, unsigned int id, int flag);
extern "C" void func_00183E90(Elem_0024C590* elem, unsigned int id);
extern "C" void* func_001E5548(unsigned int name, int flag);
extern "C" void* func_001E55B8(unsigned int name, int flag);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AE8(void* params, int flags);
extern "C" void func_001E70C0(void* params, unsigned int name, const char* str);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E7558(void* params, unsigned int name, float x, float y);
extern "C" int func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" int func_001E8248(void* params, unsigned int name, void** out, int required);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E88B0(void* params, unsigned int name, const char** out, int required);
extern "C" unsigned int func_001E9300(void* array, int index);
extern "C" void* func_001E9378(void* array, int index);
extern "C" void func_001EFDC0(Script_0024C590* script);
extern "C" Script_0024C590* func_001F0750(unsigned int name, void* params, void* data, void* extra, int t0, int t1,
                                          int t2, int t3, int b1, int b3);
extern "C" unsigned int func_001F0D78(const char* str);
extern "C" Players_0024C590* func_0022DD38(void* mgr);
extern "C" void* func_0022E368(void* mgr, int index);
extern "C" void func_0023BE68(void* mgr, unsigned int id);
extern "C" void* func_00240850();
extern "C" int func_00245FB8(Goals_0024C590* self, void* list);
extern "C" unsigned int func_00246258(Goals_0024C590* self);
extern "C" int func_0024DFD0(Goals_0024C590* self);
extern "C" int func_0024E048(Goals_0024C590* self);
extern "C" int func_0024E0C0(Goals_0024C590* self);
extern "C" void* func_00262330(void* obj, unsigned int name);
extern "C" void func_00331678(char* dst, const char* src);
extern "C" void func_00331A9C(char* dst, const char* src);
extern "C" void func_003331D0(char* dst, const char* fmt, ...);

static inline void* NewParams_0024C590()
{
    return func_001E6978(func_001190D0(8));
}

void Goals_0024C590::AddLines(int count)
{
    int total;
    func_001E7DE8(m_params, 0x89473DB7, &total, 1);
    int left = count;
    int grouped = 0;
    int wanted = m_shown + left;
    if (func_0024DFD0(this) || func_0024E048(this))
        grouped = 1;
    if (total < wanted) {
        unsigned int id = func_00246258(this);
        func_0023BE68(func_00240850(), id);
        return;
    }

    int group = 0;
    if (grouped) {
        for (int i = 0; i < 30; i++) {
            if (m_groupUsed[i] == 0) {
                group = i;
                m_groupUsed[i] = 1;
                break;
            }
        }
    }

    while (left > 0) {
        char text[0x200];
        Mgr_0024C590* mgr = D_00389A30;
        void* list = 0;
        int index = 0;
        func_001E8248(m_params, 0x7BE1E689, &list, 0);
        unsigned int checksum = 0;
        unsigned int descName = 0;
        for (int i = 0; i < 30; i++) {
            if (m_slots[i].m_free == 1) {
                m_slots[i].m_free = 0;
                m_slots[i].m_group = group;
                m_slots[i].m_checksum = 0;
                m_slots[i].m_name = 0;
                m_slots[i].m_name2 = 0;
                m_slots[i].m_rotations = 0;
                m_slots[i].m_mode = 1;
                index = i;
                m_slots[i].m_perfect = 0;
                break;
            }
        }
        const char* altText = 0;
        int mode = 1;

        if (list == 0) {
            void* choices = 0;
            func_001E8248(m_params, 0xEB79FB49, &choices, 1);
            void* entry = func_001E9378(choices, func_00100030(((Array_0024C590*)choices)->m_size));
            const char* name;
            func_001E7C80(entry, 0x270F56E1, &name, 1);
            if (func_001E8708(entry, 0x255ED86F)) {
                char buf[0x80];
                *(Str4_0024C590*)buf = D_00390350[0];
                func_00331678(buf, name);
                m_slots[index].m_name = func_001F0D78(buf);
                *(Str4_0024C590*)buf = D_00390358[0];
                func_00331678(buf, name);
                m_slots[index].m_name2 = func_001F0D78(buf);
            } else {
                m_slots[index].m_name = func_001F0D78(name);
            }
            const char* str;
            func_001E7C80(entry, 0xC4745838, &str, 1);
            func_00331A9C(text, str);
            if (!func_001E8398(entry, 0xACFDB27A, &checksum, 0))
                func_001E7C80(entry, 0xACFDB27A, &altText, 0);
        } else {
            int pick = func_00245FB8(this, list);
            if (pick == -1)
                return;
            if (((Array_0024C590*)list)->m_type == 0xD) {
                checksum = func_001E9300(list, pick);
            } else {
                void* entry = func_001E9378(list, pick);
                func_001E8398(entry, 0xACFDB27A, &checksum, 1);
                int angle = 0;
                if (func_001E7DE8(entry, 0x8C8ABD19, &angle, 0)) {
                    if (angle < 360)
                        angle = 360;
                    m_slots[index].m_rotations = func_00100030(angle / 180) + 1;
                    if (m_slots[index].m_rotations == 1)
                        m_slots[index].m_rotations = 0;
                }
                if (func_001E7DE8(entry, 0xEDF5DB70, &angle, 0))
                    m_slots[index].m_rotations = angle / 180;
                if (func_001E8708(entry, 0x1C39F1B9))
                    m_slots[index].m_perfect = 1;
                if (func_001E7DE8(entry, 0xA4BEE6A1, &mode, 0))
                    m_slots[index].m_mode = mode;
            }

            void* players = D_0038FC78;
            void* table = func_00262330(func_0022E368(players, 0), 0xD544AA2D);
            const char* desc = 0;
            if (!func_001E8398(table, checksum, &descName, 0)) {
                int which;
                func_001E7DE8(table, checksum, &which, 1);
                Players_0024C590* active = func_0022DD38(players);
                if (active) {
                    func_001E7C80(*active->m_params[which], 0xA1DC81F9, &desc, 1);
                    m_slots[index].m_mode = 1;
                }
            }
            if (desc == 0) {
                void* params = func_001E5548(descName, 0);
                if (params == 0)
                    params = func_001E9378(func_001E55B8(descName, 1), 0);
                void* node;
                func_001E8180(params, 0x7031F10C, &node, 1);
                while (mode >= 2) {
                    mode--;
                    unsigned int next;
                    func_001E8398(node, 0x6E855102, &next, 1);
                    func_001E8180(func_001E9378(func_001E55B8(next, 1), 0), 0x7031F10C, &node, 1);
                }
                func_001E88B0(node, 0xA1DC81F9, &desc, 1);
            }

            text[0] = D_00390360[0];
            if (m_slots[index].m_rotations) {
                if (m_slots[index].m_perfect)
                    func_003331D0(text, D_003743F0);
                func_003331D0(text, D_00374400, m_slots[index].m_rotations * 180);
            }
            func_00331678(text, desc);
            m_slots[index].m_checksum = checksum;
        }

        // the line's container element
        void* props = NewParams_0024C590();
        Elem_0024C590* line = func_00125C28(func_001046B0(0x1B0));
        func_00183E90(line, D_0038C6D4);
        mgr->Add(line);
        int height = 20;
        if (grouped)
            height = (left == 1) ? 40 : 20;
        func_001E7558(props, 0x34A68574, 100.0f, (float)height);
        line->SetProperties(props);
        Obj_0024C590* parent = func_0012DB48(mgr, 0xE35EC715, 1).m_obj;
        func_00124118(parent, 0);
        func_0012DA10(mgr, Handle_0024C590(parent), Handle_0024C590((Obj_0024C590*)line), 1);
        if (props)
            func_001E6AE8(props, 3);

        // its text
        props = NewParams_0024C590();
        func_001E70C0(props, 0xC4745838, text);
        func_001E7360(props, 0x2F6BF72D, 0xBC19C379);
        func_001E7360(props, 0, 0x1D944426);
        Elem_0024C590* label = func_00125F10(func_001046B0(0x1E0));
        func_00183E90(label, D_0038C6D4);
        mgr->Add(label);
        label->SetProperties(props);
        func_0012DA10(mgr, Handle_0024C590((Obj_0024C590*)line), Handle_0024C590((Obj_0024C590*)label), 1);
        if (props)
            func_001E6AE8(props, 3);

        // optional second text
        if (altText || checksum) {
            void* strings;
            if (m_slots[index].m_mode == 2)
                strings = func_001E5548(0xE7ABFB95, 1);
            else
                strings = func_001E5548(0x8856C817, 1);
            if (altText == 0)
                func_001E7C80(strings, checksum, &altText, 0);
            props = NewParams_0024C590();
            func_001E70C0(props, 0xC4745838, altText);
            func_001E7360(props, 0x2F6BF72D, 0x8ABA15EC);
            func_001E7360(props, 0, 0x1D944426);
            Elem_0024C590* extra = func_00125F10(func_001046B0(0x1E0));
            func_00183E90(extra, D_0038C6D4);
            mgr->Add(extra);
            extra->SetProperties(props);
            func_0012DA10(mgr, Handle_0024C590((Obj_0024C590*)line), Handle_0024C590((Obj_0024C590*)extra), 1);
            if (props)
                func_001E6AE8(props, 3);
        }

        m_slots[index].m_elemId = line->m_id;
        m_shown++;

        void* sprops = NewParams_0024C590();
        if (altText == 0)
            func_001E7360(sprops, 0, 0x7B716096);
        unsigned int script = 0x668CC9E3;
        if (!func_0024E0C0(this) && !func_0024E048(this) && (float)total * 0.75f < (float)m_shown)
            script = 0x8E68AFC2;
        Script_0024C590* s = func_001F0750(script, sprops, 0, 0, -1, 0, 0, 0, 0, 0);
        s->m_elem = (Obj_0024C590*)line;
        func_001EFDC0(s);
        if (sprops)
            func_001E6AE8(sprops, 3);

        if (!func_0024E0C0(this) && !func_0024E048(this) && (float)total * 0.75f < (float)m_shown) {
            func_001E7200(m_params, 0xD02AC196, 1);
            for (int i = 0; i < 30; i++) {
                if (m_slots[i].m_free == 0) {
                    Obj_0024C590* e = func_0012DB48(mgr, m_slots[i].m_elemId, 1).m_obj;
                    Script_0024C590* t = func_001F0750(0xEB016D1E, 0, 0, 0, -1, 0, 0, 0, 0, 0);
                    t->m_elem = e;
                    func_001EFDC0(t);
                }
            }
        }
        left--;
    }
}
