/* fuzzy: 99.7 */
/* Script member-function dispatcher of the component whose scene object lives at 0x260: one case per command
   checksum; returns 2 for an unknown command, otherwise the command's result as 0/1. */
/* sym: __12Msg_0018CB18 = 0x001FA800 */
typedef int qword_0018CB18 __attribute__((mode(TI)));

struct Vec_0018CB18 {
    union {
        qword_0018CB18 q;
        struct {
            float x, y, z, w;
        };
    };
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Mat_0018CB18 {
    Vec_0018CB18 r[4];
    void operator*=(Mat_0018CB18& o);
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
};

struct Color_0018CB18 {
    unsigned char r, g, b, a;
    /* game reads r with lbu (0x0018D210, 0x0018D3FC) but g/b with lw: r_ is a byte parameter */
    Color_0018CB18(unsigned char r_, int g_, int b_, int a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct Array_0018CB18 {
    char pad0[0xC];
    unsigned int m_size;
    unsigned int GetSize() { return m_size; }
};

struct Script_0018CB18 {
    char pad0[0x18];
    void* m_params;
};

struct Owner_0018CB18 {
    char pad0[0x18];
    int m_id;
    int GetId() { return m_id; }
};

/* script structure built from a parameter (ctor func_0011F880, dtor func_0011F8C8) */
struct Struct_0018CB18 {
    char pad[0x58];
};

class Msg_0018CB18 {
public:
    unsigned char m_type;
    char pad1;
    unsigned short m_size;
    void* m_data;
    char pad8[0x18];
    Msg_0018CB18();
};

struct Track_0018CB18 {
    char pad[0xAC];
};

/* payload of message 0x76 */
struct FadeData_0018CB18 {
    int m_time;
    int m_type;
    short m_start;
    short m_range;
    unsigned char m_id;
    int m_flag;
    unsigned char m_mask;
};

/* payload of message 0x8C */
struct StopData_0018CB18 {
    unsigned char m_id;
};

extern void* D_00392068;

extern "C" bool func_001E7DE8(void* s, unsigned int name, int* out, int required);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* s, unsigned int name, Vec_0018CB18* out, int required);
extern "C" bool func_001E8180(void* s, unsigned int name, void** out, int required);
extern "C" bool func_001E8248(void* s, unsigned int name, Array_0018CB18** out, int required);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8870(void* s, unsigned int name, int* out, int required);
extern "C" bool func_001E88D8(void* s, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* s, unsigned int name);
extern "C" void* func_001E9378(Array_0018CB18* a, unsigned int i);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void* func_0013D8A8(void* scene);
extern "C" void func_00137A98(void* o, Color_0018CB18* c);
extern "C" void func_00137AF0(void* o, int i, Vec_0018CB18* v);
extern "C" void func_00137B18(void* o, int i, Color_0018CB18* c);
extern "C" void func_00137B98(void* o, int v);
extern "C" void func_00137BC0(void* o, int i, int v);
extern "C" void func_00137CF0(void* o);
extern "C" int func_0013DAC0(void* scene, unsigned int a, int b, int c);
extern "C" int func_0013DC60(void* scene, unsigned int a, int b, unsigned int c);
extern "C" void func_0013DDE0(void* scene, unsigned int a);
extern "C" void func_0013DEA0(void* scene, unsigned int a, float b, float c, float d);
extern "C" void func_0013E038(void* scene, unsigned int a, int b, float c, float d);
extern "C" void func_0013E108(void* scene, unsigned int a, int b, Mat_0018CB18* m);
extern "C" void func_0013EA58(void* scene);
extern "C" void func_0013EDD0(void* scene, Vec_0018CB18* v);
extern "C" void func_0013EE48(void* scene, int v);
extern "C" bool func_00131288(Vec_0018CB18* out, void* params);
extern "C" Struct_0018CB18* func_0011F880(Struct_0018CB18* s);
extern "C" void func_0011FAB8(Struct_0018CB18* s, void* params, int a);
extern "C" void func_0011F8C8(Struct_0018CB18* s, int flags);
extern "C" Mat_0018CB18* func_001009C0(Mat_0018CB18* out, float angle);
extern "C" void func_00323318(Mat_0018CB18* d, Mat_0018CB18* a, Mat_0018CB18* b);
inline void Mat_0018CB18::operator*=(Mat_0018CB18& o) { func_00323318(this, &o, this); }
extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" unsigned int func_0010FC30();
extern "C" void* func_002A52F0(void* net, int id);
extern "C" int func_002B1FC8(void* player);
extern "C" int func_002B30A0(void* player);
extern "C" void* func_002A39E0(void* net, int conn);
extern "C" void func_00200C00(void* conn, Msg_0018CB18* msg);
extern "C" void func_0018DCB0(Track_0018CB18* t);
extern "C" void func_0018DD00(Track_0018CB18* t, unsigned int now, float time, float start, float range, int type, int flag);

static inline void RotateX_0018CB18(Vec_0018CB18& v, float ang)
{
    float s = func_00341068(ang);
    float c = func_00340F60(ang);
    float y = c * v.y - s * v.z;
    v.z = s * v.y + c * v.z;
    v.y = y;
}

static inline void RotateY_0018CB18(Vec_0018CB18& v, float ang)
{
    float s = func_00341068(ang);
    float c = func_00340F60(ang);
    float x = c * v.x + s * v.z;
    v.z = -s * v.x + c * v.z;
    v.x = x;
}

/* shared component base: fields 0x0-0x17, vptr at 0x18 */
class Base_0018CB18 {
public:
    char pad0[0xC];
    Owner_0018CB18* m_owner;
    char pad10[0x8];

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
    virtual void ApplyStruct(Struct_0018CB18* s, bool a, int b, unsigned int c);
};

class Comp_0018CB18 : public Base_0018CB18 {
public:
    Vec_0018CB18 m20;
    Vec_0018CB18 m30;
    Track_0018CB18 m_tracks[3];
    int m244;
    char pad248[0x260 - 0x248];
    void* m_scene;

    int CallMemberFunction(unsigned int id, void* params, Script_0018CB18* script);
};

extern "C" void func_0018C230(Comp_0018CB18* self, unsigned int anim, int flag, int send);
extern "C" int func_0018C320(Comp_0018CB18* self, unsigned int name);
extern "C" void func_0018CAC8(Comp_0018CB18* self, Vec_0018CB18* c);
extern "C" void func_0018BAF8(Comp_0018CB18* self, void* params);

int Comp_0018CB18::CallMemberFunction(unsigned int id, void* params, Script_0018CB18* script)
{
    int result = 1;
    switch (id) {
    case 0x347FF11B:
        if (m_scene)
            func_0013EE48(m_scene, 1);
        break;
    case 0xF951AA64:
        if (m_scene)
            func_0013EE48(m_scene, 0);
        break;
    case 0x657FF1ED:
        if (m_scene) {
            Vec_0018CB18 c;
            c.Set(1.0f, 1.0f, 1.0f, 1.0f);
            if (func_00131288(&c, params)) {
                func_0013EDD0(m_scene, &c);
                func_0013EE48(m_scene, 1);
            }
        }
        break;
    case 0x6052480A:
        if (m_scene)
            func_0013DDE0(m_scene, 0xC4E78E22);
        break;
    case 0x76ECFA1C: {
        int a, b, c;
        if (m_scene && func_001E88D8(params, 0x6E94F918, &a, 0) && func_001E88D8(params, 0xE4F130F4, &b, 0) &&
            func_001E88D8(params, 0x949BC47B, &c, 0))
            func_0013DEA0(m_scene, 0xC4E78E22, (float)a, (float)b * 0.01f, (float)c * 0.01f);
        break;
    }
    case 0x83F9BE15: {
        Array_0018CB18* list;
        int a, b;
        result = 0;
        if (func_001E8248(params, 0x5EF31148, &list, 0)) {
            for (unsigned int i = 0; i < list->GetSize(); i++) {
                void* item = func_001E9378(list, i);
                func_001E8870(item, 0x9FBBDB72, &a, 1);
                func_001E8870(item, 0x7799D66C, &b, 1);
                unsigned int name = 0xC4E78E22;
                func_001E8398(item, 0xA01371B1, &name, 0);
                if (m_scene && func_0013DAC0(m_scene, name, a, b))
                    result = 1;
            }
        } else {
            func_001E8870(params, 0x9FBBDB72, &a, 1);
            func_001E8870(params, 0x7799D66C, &b, 1);
            unsigned int name = 0xC4E78E22;
            func_001E8398(params, 0xA01371B1, &name, 0);
            if (m_scene)
                result = func_0013DAC0(m_scene, name, a, b) != 0;
        }
        break;
    }
    case 0x9A478AFE: {
        int a;
        unsigned int b = 0;
        func_001E8870(params, 0x9FBBDB72, &a, 1);
        func_001E8398(params, 0x7799D66C, &b, 1);
        unsigned int name = 0xC4E78E22;
        func_001E8398(params, 0xA01371B1, &name, 0);
        if (m_scene)
            result = func_0013DC60(m_scene, name, a, b);
        else
            result = 0;
        break;
    }
    case 0xBD18E2E3:
        if (m_scene)
            func_0013EA58(m_scene);
        break;
    case 0xE11F85E8:
        return func_0013D8A8(m_scene) != 0;
    case 0x1C16332E:
        func_00137CF0(func_0013D8A8(m_scene));
        break;
    case 0x8A445E26:
        func_00137B98(func_0013D8A8(m_scene), 0);
        break;
    case 0xED5D1550: {
        int i;
        func_001E7DE8(params, 0x7F8C98FE, &i, 0);
        func_00137BC0(func_0013D8A8(m_scene), i, 1);
        break;
    }
    case 0xC6542804: {
        int i;
        func_001E7DE8(params, 0x7F8C98FE, &i, 0);
        func_00137BC0(func_0013D8A8(m_scene), i, 0);
        break;
    }
    case 0x3CF63049: {
        int r, g, b;
        func_001E7DE8(params, 0x93F60062, &r, 0);
        func_001E7DE8(params, 0xFE2BE489, &g, 0);
        func_001E7DE8(params, 0x8E411006, &b, 0);
        Color_0018CB18 c(r, g, b, 0x80);
        func_00137A98(func_0013D8A8(m_scene), &c);
    }
        /* fall through */
    case 0xA14D6372:
        func_00137B98(func_0013D8A8(m_scene), 1);
        break;
    case 0x46A1F4A4: {
        int i;
        float yaw, pitch;
        func_001E7DE8(params, 0x7F8C98FE, &i, 0);
        Vec_0018CB18 v;
        v.x = 0.0f;
        v.z = 1.0f;
        v.y = 0.0f;
        v.w = 0.0f;
        if (func_001E7FA8(params, 0xC1B52E4C, &v, 0)) {
            v.w = 0.0f;
        } else if (func_001E7EB0(params, 0xFD4BC03E, &yaw, 0) && func_001E7EB0(params, 0xD8604126, &pitch, 0)) {
            RotateX_0018CB18(v, pitch * 0.017453294f);
            RotateY_0018CB18(v, yaw * 0.017453294f);
        }
        func_00137AF0(func_0013D8A8(m_scene), i, &v);
        break;
    }
    case 0x70E6466B: {
        int i, r, g, b;
        func_001E7DE8(params, 0x7F8C98FE, &i, 0);
        func_001E7DE8(params, 0x93F60062, &r, 0);
        func_001E7DE8(params, 0xFE2BE489, &g, 0);
        func_001E7DE8(params, 0x8E411006, &b, 0);
        Color_0018CB18 c(r, g, b, 0x80);
        func_00137B18(func_0013D8A8(m_scene), i, &c);
        func_00137BC0(func_0013D8A8(m_scene), i, 1);
        break;
    }
    case 0x57EB306E: {
        unsigned int name;
        float a, b;
        int flag;
        func_001E8398(params, 0x83418A6A, &name, 0);
        flag = 0;
        func_001E7EB0(params, 0x0D9295C1, &a, 0);
        func_001E7EB0(params, 0x949BC47B, &b, 0);
        func_001E7DE8(params, 0x318F2BDB, &flag, 0);
        func_0013E038(m_scene, name, flag, a, b);
        break;
    }
    case 0x812FF44D: {
        unsigned int name;
        int flag;
        func_001E8398(params, 0x83418A6A, &name, 0);
        func_001E7DE8(params, 0x318F2BDB, &flag, 0);
        Mat_0018CB18 m;
        m.Ident();
        float sx = 1.0f;
        float sy = 1.0f;
        int gotX = func_001E7EB0(params, 0x3FB610B7, &sx, 0);
        gotX = func_001E7EB0(params, 0xB9226219, &sy, 0) || gotX;
        if (gotX) {
            m.r[0].x *= sx;
            m.r[1].y *= sy;
        }
        float angle;
        if (func_001E7EB0(params, 0xE2C6589E, &angle, 0)) {
            Mat_0018CB18 rot;
            m *= *func_001009C0(&rot, angle * 0.017453294f);
        }
        float u = 0.0f;
        float v = 0.0f;
        int gotU = func_001E7EB0(params, 0x56A7F41C, &u, 0);
        gotU = func_001E7EB0(params, 0x44125BF2, &v, 0) || gotU;
        if (gotU) {
            m.r[3].x = u;
            m.r[3].y = v;
        }
        func_0013E108(m_scene, name, flag, &m);
        break;
    }
    case 0x721184C7:
        m244 = 1;
        break;
    case 0x4AF3B1F7:
        m244 = 0;
        break;
    case 0x4D8E11AB:
        func_0018BAF8(this, params);
        break;
    case 0xE48FD084: {
        unsigned int anim;
        func_001E8398(params, 0, &anim, 1);
        func_0018C230(this, anim, 1, 1);
        break;
    }
    case 0x07D0C128: {
        unsigned int anim;
        func_001E8398(params, 0, &anim, 1);
        func_0018C230(this, anim, 0, 1);
        break;
    }
    case 0xE7FA7DD0: {
        unsigned int name;
        func_001E8398(params, 0, &name, 1);
        if (func_0018C320(this, name))
            func_001E7200(script->m_params, 0x77A21642, 1);
        else
            func_001E7200(script->m_params, 0x77A21642, 0);
        break;
    }
    case 0x98ED5C8B:
        if (m_scene) {
            int a = 0;
            func_001E7DE8(params, 0xF891AC27, &a, 0);
            int b = 0;
            func_001E7DE8(params, 0xC63C8D38, &b, 0);
            void* sub;
            func_001E8180(params, 0x456D28D1, &sub, 1);
            unsigned int c = 0;
            func_001E8398(params, 0x299EE352, &c, 0);
            Struct_0018CB18 s;
            func_0011F880(&s);
            func_0011FAB8(&s, sub, 1);
            ApplyStruct(&s, b != 0, a, c);
            func_0011F8C8(&s, 2);
        }
        break;
    case 0x452FB315: {
        float a;
        func_001E7EB0(params, 0, &a, 1);
        Vec_0018CB18 c;
        c.x = 0.0f;
        c.w = a;
        c.y = 0.0f;
        c.z = 0.0f;
        func_0018CAC8(this, &c);
        break;
    }
    case 0x5B41DA8F:
        func_0018CAC8(this, &m20);
        break;
    case 0xA4C25C2F: {
        float time = 0.0f;
        func_001E7EB0(params, 0x79A07F3F, &time, 0);
        if (func_001E8708(params, 0xD029F619) || func_001E8708(params, 0x49E0EE96))
            time *= 1000.0f;
        else if (func_001E8708(params, 0x019176C5) || func_001E8708(params, 0x4A07C332))
            time *= 16.666668f;
        float start = 0.0f;
        int mask = 0;
        func_001E7EB0(params, 0x9DE2A72F, &start, 0);
        float end = 0.0f;
        func_001E7EB0(params, 0x8C9946A9, &end, 0);
        int type = 0;
        func_001E7DE8(params, 0xF164F03D, &type, 0);
        m30.Set(0.0f, 30.0f, 0.0f, 1.0f);
        func_001E7FA8(params, 0x8F38F109, &m30, 0);
        int flag = func_001E8708(params, 0xE14BC9AC);
        unsigned int now = func_0010FC30();
        if (func_001E8708(params, 0x7323E97C)) {
            mask = 1;
            func_0018DD00(&m_tracks[0], now, time, start, end - start, type, flag);
        }
        if (func_001E8708(params, 0x0424D9EA)) {
            mask |= 2;
            func_0018DD00(&m_tracks[1], now, time, start, end - start, type, flag);
        }
        if (func_001E8708(params, 0x9D2D8850)) {
            mask |= 4;
            func_0018DD00(&m_tracks[2], now, time, start, end - start, type, flag);
        }
        void* net = D_00392068;
        void* player = func_002A52F0(net, (unsigned short)m_owner->m_id);
        if (player && func_002B1FC8(player)) {
            FadeData_0018CB18 data;
            Msg_0018CB18 msg;
            void* conn = func_002A39E0(net, func_002B30A0(player));
            data.m_start = (int)start;
            data.m_time = (int)time;
            data.m_type = type;
            data.m_range = (int)(end - start);
            data.m_id = m_owner->GetId();
            data.m_flag = flag;
            data.m_mask = mask;
            msg.m_size = sizeof(data);
            msg.m_type = 0x76;
            msg.m_data = &data;
            func_00200C00(conn, &msg);
        }
        break;
    }
    case 0x4424C267: {
        func_0018DCB0(&m_tracks[0]);
        func_0018DCB0(&m_tracks[1]);
        func_0018DCB0(&m_tracks[2]);
        void* net = D_00392068;
        void* player = func_002A52F0(net, (unsigned short)m_owner->m_id);
        if (player && func_002B1FC8(player)) {
            Msg_0018CB18 msg;
            StopData_0018CB18 data;
            void* conn = func_002A39E0(net, func_002B30A0(player));
            data.m_id = m_owner->GetId();
            msg.m_data = &data;
            msg.m_type = 0x8C;
            msg.m_size = 1;
            func_00200C00(conn, &msg);
        }
        break;
    }
    default:
        return 2;
    }
    return result != 0;
}
