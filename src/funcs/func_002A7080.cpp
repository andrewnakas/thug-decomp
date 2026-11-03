extern char D_00378888[];
extern char D_00392160[];
extern char D_00392168[];
extern char D_00378898[];
extern char D_003788B0[];
extern char D_003920A0[];
extern char D_003788C0[];
extern char D_003788D0[];
extern char D_00378328[];

struct Obj_002A7080;
extern "C" int func_001F0D78(char* s);
extern "C" int func_002A19A8(Obj_002A7080* o);
extern "C" void* func_002A6070(Obj_002A7080* o);
extern "C" int func_00203018(void* p, unsigned int a, unsigned int b);

struct Obj_002A7080 {
    char pad[0x24];
    int m24;
    bool IsAllowed();
};

bool Obj_002A7080::IsAllowed()
{
    if (m24 == func_001F0D78(D_00378888) || m24 == func_001F0D78(D_00392160) ||
        m24 == func_001F0D78(D_00392168) || m24 == func_001F0D78(D_00378898) ||
        m24 == func_001F0D78(D_003788B0))
        return true;
    if (!func_002A19A8(this)) return false;
    if (m24 == func_001F0D78(D_003920A0)) {
        if (func_00203018(func_002A6070(this), func_001F0D78(D_003788C0), func_001F0D78(D_00378328)) != 0x938AB24B)
            return true;
    }
    return func_00203018(func_002A6070(this), func_001F0D78(D_003788D0), func_001F0D78(D_00378328)) == 0xF81BC89B;
}
