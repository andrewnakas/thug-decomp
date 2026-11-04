typedef int qword_0024A880 __attribute__((mode(TI)));

struct Vec_0024A880 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0024A880 q;
    };
    Vec_0024A880() {}
    Vec_0024A880(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float LengthSqr() const { return x * x + y * y + z * z; }
};

static inline Vec_0024A880 operator-(const Vec_0024A880& a, const Vec_0024A880& b)
{
    return Vec_0024A880(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Camera_0024A880 {
    char m_pad[0x50];
    Vec_0024A880 m_pos;
};

struct Goal_0024A880 {
    char m_pad[0x20];
    void* m_params;
    char m_pad2[0xAC - 0x24];
    unsigned int m_activeId;
    unsigned int m_node;
};

extern char D_00373E50[];
extern char D_00373E68[];
extern char D_00373E78[];
extern char D_00373E88[];
extern char D_00373EA8[];
extern char D_00390198[];
extern void* D_0038C608;
extern void* D_0038FC78;

extern "C" void* func_00240850();
extern "C" unsigned int func_0023ECD8(void* mgr);
extern "C" void* func_0023BAD8(void* owner, unsigned int id, int create);
extern "C" void* func_00244528(void* goal);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void func_0024A860(Goal_0024A880* self);
extern "C" void func_0024AE78(Goal_0024A880* self);
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned int func_00246258(Goal_0024A880* self);
extern "C" void func_001E73C8(void* p, char* name, unsigned int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_00185058(void* obj);
extern "C" Camera_0024A880* func_0022DD38(void* mgr);
extern "C" void* func_00229668(unsigned int name, int a);
extern "C" void func_0022A090(void* node, Vec_0024A880* out);

bool Goal_0024A880_Activate(Goal_0024A880* self, int force)
{
    void* mgr = func_00240850();
    unsigned int id = func_0023ECD8(mgr);
    if (!id) {
        return false;
    }
    if (id == self->m_activeId) {
        return false;
    }
    unsigned int node;
    func_001E84E8(func_00244528(func_0023BAD8(mgr, id, 1)), D_00373E50, &node, 1);
    if (force) {
        func_0024A860(self);
        self->m_activeId = id;
        func_0024AE78(self);
        unsigned int objId;
        func_001E84E8(self->m_params, D_00373E68, &objId, 1);
        void* obj = func_00187B48(D_0038C608, objId);
        void* s = func_001E6978(func_001190D0(8));
        func_001E73C8(s, D_00390198, func_00246258(self));
        func_001E73C8(s, D_00373E78, node);
        func_001F0370(D_00373E88, s, 0, 0);
        if (s) {
            func_001E6AE8(s, 3);
        }
        func_00185058(obj);
    } else {
        Vec_0024A880 cam;
        cam.q = func_0022DD38(D_0038FC78)->m_pos.q;
        Vec_0024A880 pos;
        if (self->m_node) {
            func_0022A090(func_00229668(self->m_node, 1), &pos);
            if ((cam - pos).LengthSqr() < 1000001.0f) {
                return false;
            }
        }
        Vec_0024A880 pos2;
        func_0022A090(func_00229668(node, 1), &pos2);
        if ((cam - pos2).LengthSqr() < 1000001.0f) {
            return false;
        }
        func_0024A860(self);
        self->m_activeId = id;
        func_0024AE78(self);
        void* s = func_001E6978(func_001190D0(8));
        func_001E73C8(s, D_00390198, func_00246258(self));
        func_001E73C8(s, D_00373E78, node);
        func_001F0370(D_00373E88, s, 0, 0);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
    func_001E73C8(self->m_params, D_00373EA8, id);
    self->m_node = node;
    return true;
}
