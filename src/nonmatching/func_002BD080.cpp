/* fuzzy: 79.8 */
struct Game_002BD080 {
    char pad[0xAC];
    int mAC;
};

extern "C" Game_002BD080* func_002C4970(int v);
extern "C" void func_002C49C0();

struct Ref_002BD080 {
    int m0;
    Game_002BD080* m4;
    Ref_002BD080(Game_002BD080* p) { m4 = p; }
};

class Ctx_002BD080 {
public:
    int m0;
    Ref_002BD080 m4;
    Ctx_002BD080() : m4(func_002C4970(0)) {}
    Ref_002BD080* GetRef() { return &m4; }
    Game_002BD080* GetGame() { return GetRef()->m4; }
    virtual void Dummy();
    virtual ~Ctx_002BD080() { func_002C49C0(); }
};

struct Mgr_002BD080 {
    int m0;
};

extern int D_00391ED8;
extern Mgr_002BD080* D_0039274C;
extern char D_0037A530[];
extern "C" void* func_002977B0();
extern "C" void func_002965D8(void* c);
extern "C" int func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" void func_002957A0(void* c, int v, int f);
extern "C" void* func_0029C320();
extern "C" void func_0029AE78(void* p, void* params);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" void func_002B74E8(int a, int b);
extern "C" int func_002BD248(void* p);
extern "C" void func_002BCDF8(void* p);
extern "C" int* func_002BCE20(void* p, int v);
extern "C" int func_001E8AA0(void* params, char* name, int* out, int required);
extern "C" int func_001E9270(int a, int i);
extern "C" void func_002C5150(Game_002BD080* g, int* data, int n);

struct Obj_002BD080 {
    void Load(void* params, int apply);
};

void Obj_002BD080::Load(void* params, int apply)
{
    void* c = func_002977B0();
    func_002965D8(c);
    int v = 0;
    if (func_001E8180(params, 0xD8EB825E, &v, 0)) func_002957A0(c, v, 1);
    Ctx_002BD080 ctx;
    if (ctx.GetGame()->mAC != 0x7ECA21E5) D_00391ED8 = 0;
    func_0029AE78(func_0029C320(), params);
    int w = 2;
    D_00391ED8 = 1;
    func_001E7DE8(params, 0xB7E39B53, &w, 0);
    func_002B74E8(D_0039274C->m0, w);
    int n = func_002BD248(this);
    func_002BCDF8(this);
    int* data = func_002BCE20(this, 0);
    int arr = 0;
    if (func_001E8AA0(params, D_0037A530, &arr, 1)) {
        for (int i = 0; i < 0xEA6; i++) data[i] = func_001E9270(arr, i);
        if (apply) {
            Ctx_002BD080 ctx2;
            func_002C5150(ctx2.GetGame(), data, n);
        }
    }
}
