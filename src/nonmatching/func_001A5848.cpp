/* fuzzy: 47.4 */
/* Ped/vehicle AI (path-follow) component script member functions. Returns 0/1 for handled
   commands and queries, 2 when the name is not one of this component's. */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_001A5848 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Script_001A5848 {
    char pad0[0x18];
    void* params;               /* 0x18, return-value structure */
};

struct Model_001A5848 {
    char pad0[0x50];
    Vec_001A5848 pos;           /* 0x50 */
    Vec_001A5848 oldPos;        /* 0x60 */
    Vec_001A5848 right;         /* 0x70 */
    Vec_001A5848 up;            /* 0x80 */
    Vec_001A5848 at;            /* 0x90 */
    char padA0[0x10];
    Vec_001A5848 vel;           /* 0xB0 */
    char padC0[0x20];
    Vec_001A5848 facing;        /* 0xE0 */
};

struct Suspend_001A5848 {
    char pad0[0x60];
    int active;                 /* 0x60 */
};

struct Comp_001A5848 {
    char pad0[0x18];
    virtual void V0();
    virtual void Refresh();
};

struct Node_001A5848 {
    char pad0[0x18];
    int index;                  /* 0x18 */
};

struct Path_001A5848 {
    char pad0[0x74];
    void* link;                 /* 0x74 */
    char pad78[0xB0 - 0x78];
    float speed;                /* 0xB0 */
};

struct AIComponent_001A5848 {
    char pad0[0xC];
    Model_001A5848* model;      /* 0x0C */
    char pad10[0xC];
    unsigned int state;         /* 0x1C */
    unsigned int flags;         /* 0x20 */
    float fixedSpeed;           /* 0x24 */
    char block28[4];            /* 0x28 */
    char block2C[4];            /* 0x2C */
    char block30[4];            /* 0x30 */
    float savedSpeed;           /* 0x34 */
    float targetSpeed;          /* 0x38 */
    float turnX;                /* 0x3C */
    float turnY;                /* 0x40 */
    char pad44[0x1D0 - 0x44];
    int accelTime;              /* 0x1D0 */
    float lastSpeed;            /* 0x1D4 */
    float accel;                /* 0x1D8 */
    char pad1DC[4];
    Vec_001A5848 target;        /* 0x1E0 */
    void* targetNode;           /* 0x1F0 */
    char pad1F4[0x200 - 0x1F4];
    float waitHeight;           /* 0x200 */
    int waitCount;              /* 0x204 */
    float waitTime;             /* 0x208 */
    int waitInterval;           /* 0x20C */
    char pad210[0x218 - 0x210];
    void* links;                /* 0x218 */
    char pad21C[0xC];
    float jumpSpeed;            /* 0x228 */
    float jumpGravity;          /* 0x22C */
    Vec_001A5848 jumpDir;       /* 0x230 */
    int jumpHasDir;             /* 0x240 */
    char pad244[0x260 - 0x244];
    float jumpInitSpeed;        /* 0x260 */
    float jumpRise;             /* 0x264 */
    float jumpLand;             /* 0x268 */
    char pad26C[4];
    int jumpHasHeight;          /* 0x270 */
    float jumpHeight;           /* 0x274 */
    char pad278[8];
    Vec_001A5848 jumpStart;     /* 0x280 */

    int CallMemberFunction(unsigned int name, void* params, Script_001A5848* script);
};

extern char D_0038CE40[];

extern "C" int func_00100030(int n);    /* random */
extern "C" float func_0010FAB8();       /* frame time */
extern "C" Comp_001A5848* func_00185578(Model_001A5848* obj, unsigned int type);
extern "C" bool func_001A5620(AIComponent_001A5848* self);
extern "C" bool func_001A5630(AIComponent_001A5848* self);
extern "C" void func_001A5640(void* params, void* out);
extern "C" void func_001A56D0(void* params, void* out);
extern "C" void func_001A5760(AIComponent_001A5848* self);
extern "C" void func_001A6758(AIComponent_001A5848* self, Model_001A5848* model);
extern "C" Path_001A5848* func_001A67A8(AIComponent_001A5848* self);
extern "C" void func_001A6B38(AIComponent_001A5848* self, void* params);
extern "C" void func_001A6CA0(AIComponent_001A5848* self, void* params, Vec_001A5848* pos);
extern "C" void func_001A6FB0(AIComponent_001A5848* self, void* params);
extern "C" void func_001A71F0(AIComponent_001A5848* self, void* params, Script_001A5848* script, int mode);
extern "C" void func_001A7548(AIComponent_001A5848* self, void* params, Script_001A5848* script);
extern "C" void func_001A75F8(AIComponent_001A5848* self, void* params, Script_001A5848* script);
extern "C" void func_001A7670(AIComponent_001A5848* self, void* params, int on);
extern "C" void func_001A7970(AIComponent_001A5848* self, void* params, Script_001A5848* script);
extern "C" void func_001A7A38(AIComponent_001A5848* self, void* params);
extern "C" void func_001A7BA0(AIComponent_001A5848* self, void* params, Script_001A5848* script, Vec_001A5848* pos,
                              int node);
extern "C" void func_001A7DF0(AIComponent_001A5848* self, void* params, Script_001A5848* script);
extern "C" void func_001A7EB0(AIComponent_001A5848* self, void* params, Script_001A5848* script, int mode);
extern "C" void func_001A7FB0(AIComponent_001A5848* self, void* params, Script_001A5848* script);
extern "C" void func_001A8210(AIComponent_001A5848* self, void* obj);
extern "C" void func_001A8BE0(AIComponent_001A5848* self);
extern "C" Node_001A5848* func_001A9480(AIComponent_001A5848* self, float radius);
extern "C" void func_001A9718(AIComponent_001A5848* self, void* params);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int v);
extern "C" void func_001E7318(void* params, const char* name, float v);
extern "C" void func_001E7360(void* params, unsigned int name, int v);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_001A5848* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001EE5D8(Script_001A5848* script, int event, AIComponent_001A5848* self);
extern "C" void* func_00229668(unsigned int id, int create);
extern "C" void* func_00229DF0(void* obj);
extern "C" int func_00229EB0(void* group);
extern "C" void func_00229FF8(void* obj, Vec_001A5848* out);
extern "C" void func_0022A090(void* obj, Vec_001A5848* out);

static inline bool IsOff(void* params) { return func_001E8708(params, 0xD443A2BC); }

int AIComponent_001A5848::CallMemberFunction(unsigned int name, void* params, Script_001A5848* script)
{
    switch (name) {
    case 0x8D95F1E1:
        func_001EE5D8(script, 7, this);
        return 1;
    case 0x1E094B84:
        func_001EE5D8(script, 6, this);
        return 1;
    case 0xBDC4C878:
        func_001EE5D8(script, 8, this);
        return 1;
    case 0xDBFDD02F:
        func_001EE5D8(script, 4, this);
        return 1;

    case 0x434EA1FB:
        if (IsOff(params))
            flags &= ~0x200;
        else
            flags |= 0x200;
        return 1;

    case 0xD8F4BC32:
        if (IsOff(params))
            flags |= 0x10;
        else
            flags &= ~0x10;
        return 1;

    case 0xAA3CB476:
        if (IsOff(params)) {
            flags &= ~0x100;
            return 1;
        }
        flags |= 0x100;
        func_001E7EB0(params, 0, &model->pos.y, 0);
        return 1;

    case 0xC5ECA638:
        func_001E7EB0(params, 0xA8A5A3C7, &turnX, 0);
        func_001E7EB0(params, 0x182D87A7, &turnY, 0);
        if (IsOff(params)) {
            flags &= ~4;
            return 1;
        }
        flags |= 4;
        if (turnX == 0.0f && turnY == 0.0f)
            return 0;
        func_001A8BE0(this);
        return 1;

    case 0x21ACCF0D:
        return func_001A5620(this) != 0;
    case 0x7BC461AE:
        return func_001A5630(this) != 0;

    case 0x103BD253:
        func_001A75F8(this, params, script);
        return 1;
    case 0x6419CEFF:
        func_001A7548(this, params, script);
        return 1;
    case 0x3BCAAC3F:
        func_001A7FB0(this, params, script);
        return 1;
    case 0x8819DD8B:
        func_001A7DF0(this, params, script);
        return 1;
    case 0x0B231A9D:
        func_001A71F0(this, params, script, 0);
        return 1;
    case 0x7C242A0B:
        func_001A71F0(this, params, script, 1);
        return 1;
    case 0xE52D7BB1:
        func_001A71F0(this, params, script, 2);
        return 1;
    case 0x84EC6600:
        func_001A7EB0(this, params, script, 1);
        return 1;
    case 0xEA81A32B:
        func_001A7EB0(this, params, script, 0);
        return 1;
    case 0x33DF698F:
        func_001A7670(this, params, 0);
        return 1;
    case 0x74C30242:
        func_001A7670(this, params, 1);
        return 1;
    case 0x5CF1B7D4:
        func_001A6FB0(this, params);
        return 1;
    case 0x2FAD370D:
        func_001A9718(this, params);
        return 1;
    case 0xCC19C48A:
        func_001A7A38(this, params);
        return 1;

    case 0x0DA2D86D:
        flags &= ~8;
        func_001A7970(this, params, script);
        return 1;
    case 0xBFB0031D:
        flags &= ~8;
        func_001A6B38(this, params);
        return 1;
    case 0xBD6C6807:
        flags &= ~8;
        return 1;

    case 0x68E1F022:
        state &= ~0x18;
        return 1;
    case 0xDFBE3DB3:
        state &= ~0x67;
        return 1;

    case 0xFB603EA9:
        func_001A5640(params, block30);
        return 1;
    case 0x2CA63CDF:
        func_001A5640(params, &accel);
        return 1;
    case 0xD6697AD0:
        func_001A56D0(params, block28);
        return 1;
    case 0xA67FC783:
        func_001A56D0(params, block2C);
        return 1;

    case 0x8E52ABEA:
        target = model->pos;
        return 1;
    case 0xC8CC6820:
        targetNode = func_001A67A8(this)->link;
        return 1;
    case 0xE8D121CB:
        func_001A6CA0(this, params, &target);
        return 1;
    case 0xA5A2D218: {
        Vec_001A5848 p;
        func_0022A090(targetNode, &p);
        func_001A6CA0(this, params, &p);
        return 1;
    }
    case 0x8B669799: {
        Vec_001A5848 p = target;
        func_001A7BA0(this, params, script, &p, -1);
        return 1;
    }
    case 0x5CE058FD:
    case 0xF389285D: {
        /* move to a point straight ahead / to the side */
        float d = 0.0f;
        func_001E7EB0(params, 0x7E832F08, &d, 0);
        Model_001A5848* m = model;
        const Vec_001A5848& dir = (name == 0xF389285D) ? m->at : m->right;
        Vec_001A5848 off;
        off.x = dir.x * d;
        off.y = dir.y * d;
        off.z = dir.z * d;
        off.w = dir.w * d;
        Vec_001A5848 p;
        p.x = m->pos.x + off.x;
        p.y = m->pos.y + off.y;
        p.z = m->pos.z + off.z;
        p.w = m->pos.w + off.w;
        func_001A7BA0(this, params, script, &p, -1);
        return 1;
    }

    case 0x3407AD3D: {
        unsigned int id = 0;
        func_001E8398(params, 0, &id, 0);
        void* obj = func_00229DF0(func_00229668(id, 1));
        Vec_001A5848 p;
        func_00229FF8(obj, &p);
        model->pos = p;
        func_001A8210(this, obj);
        func_00185578(model, 0x286A8D26)->Refresh();
        return 1;
    }

    case 0x76003D82: {
        float speed;
        if (func_001E7EB0(params, 0, &speed, 0)) {
            if (!func_001E8708(params, 0xF915B4F3))
                speed *= 12.0f;
            func_001A6758(this, model);
            func_001A67A8(this)->speed = speed;
        }
        return 1;
    }

    case 0xFE71453F:
        targetSpeed = 0.0f;
        accelTime = 0;
        if (accel == targetSpeed)
            accel = 15.0f;
        func_001E7EB0(params, 0, &targetSpeed, 0);
        if (!func_001E8708(params, 0xF915B4F3)) {
            lastSpeed = savedSpeed;
            targetSpeed *= 12.0f;
        }
        if (targetSpeed == 0.0f)
            savedSpeed = 0.0f;
        flags |= 8;
        return 1;

    case 0x6866312F: {
        int n = func_00229EB0(links);
        if (n)
            func_001E7200(script->params, 0xC953660E, func_00100030(n) + 1);
        return 1;
    }

    case 0xB75589CE: {
        float radius = 100.0f;
        func_001E7EB0(params, 0x6C78A5B6, &radius, 0);
        radius *= 12.0f;
        func_001E6B90(script->params, 0xFFFF9A1C);
        Node_001A5848* node = func_001A9480(this, radius);
        if (node)
            func_001E7360(script->params, 0xFFFF9A1C, node->index);
        return 1;
    }

    case 0xE606EBA2:
        if (IsOff(params)) {
            func_001A5760(this);
            state &= ~0x80;
            return 1;
        }
        waitCount = 0;
        func_001E7EB0(params, 0xC9FDE32C, &waitTime, 0);
        {
            float rate = 1.0f;
            func_001E7EB0(params, 0xA80BEA4A, &rate, 0);
            int n = (int)(1000.0f / rate);
            waitInterval = n;
            int r = func_00100030(n * 2);
            waitInterval = waitInterval + (r - waitInterval / 10);
            if (waitInterval <= 0)
                waitInterval = 1;
        }
        state |= 0x80;
        waitHeight = model->pos.y;
        return 1;

    case 0xE76D73D2: {
        /* report the current speed (mph by default, feet/s or raw on request) */
        float speed = 0.0f;
        if (state & 8) {
            speed = fixedSpeed;
        } else if (func_00185578(model, 0x5CB5CB7E) &&
                   ((Suspend_001A5848*)func_00185578(model, 0x5CB5CB7E))->active) {
            Model_001A5848* m = model;
            Vec_001A5848 d;
            d.x = m->pos.x - m->oldPos.x;
            d.y = m->pos.y - m->oldPos.y;
            d.z = m->pos.z - m->oldPos.z;
            d.w = m->pos.w - m->oldPos.w;
            float t = func_0010FAB8();
            if (t != speed)
                speed = d.Length() / t;
        } else {
            speed = model->vel.Length();
        }
        if (!func_001E8708(params, 0xA18B8F32)) {
            if (func_001E8708(params, 0xAAD7C80F))
                speed *= 1.0f / 12.0f;
            else
                speed *= 0.056818180f;
        }
        func_001E7318(script->params, D_0038CE40, speed);
        return 1;
    }

    case 0x1AE46261:
        /* jump setup */
        jumpSpeed = 150.0f;
        func_001E7EB0(params, 0xF0D90109, &jumpSpeed, 0);
        jumpInitSpeed = jumpSpeed;
        jumpGravity = -360.0f;
        func_001E7EB0(params, 0xA5E2DA58, &jumpGravity, 0);
        jumpRise = 6.0f;
        jumpStart = model->pos;
        func_001E7EB0(params, 0xECC2C699, &jumpRise, 0);
        jumpLand = 6.0f;
        func_001E7EB0(params, 0x5C4AE2F9, &jumpLand, 0);
        if (func_001E7FA8(params, 0xFD4BC03E, &jumpDir, 0)) {
            jumpHasDir = 1;
            jumpSpeed *= jumpDir.y;
            jumpDir.y = 0.0f;
        } else if (func_001E8708(params, 0xFECFFE49)) {
            jumpHasDir = 1;
            jumpDir = model->facing;
            jumpSpeed *= jumpDir.y;
            jumpDir.y = 0.0f;
        } else {
            jumpHasDir = 0;
        }
        jumpHasHeight = 0;
        if (func_001E7EB0(params, 0xA1810C27, &jumpHeight, 0))
            jumpHasHeight = 1;
        state |= 0x100;
        return 1;

    case 0xBF9FFFE5:
        return 1;
    }
    return 2;
}
